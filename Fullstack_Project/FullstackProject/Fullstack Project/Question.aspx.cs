using Newtonsoft.Json.Linq;
using System;
using System.Configuration;
using System.Data.SqlClient;
using System.IO;
using System.Linq;
using System.Web.UI.WebControls;

namespace Fullstack_Project
{
    public partial class Question : System.Web.UI.Page
    {
        const int numberOfQuestions = 10;
        const int timerStart = 10;
        static int qCount = 0;
        static int maxQuestion = 0;
        static SqlConnection con;
        static int score = 0;
        static Button[] buttons;
        static int[] wasAsked;
        static JObject json;
        static JToken currQ;
        string dir;
        protected void Page_Load(object sender, EventArgs e)
        {
            if ( Session["username"] == null )
                Response.Redirect("Login.aspx");

            buttons = new Button[4] { ans0, ans1, ans2, ans3 };
            wasAsked = new int[numberOfQuestions];
            for ( int i = 0; i < numberOfQuestions; i++ )
                wasAsked[i] = -1;

            dir = $"{ConfigurationManager.ConnectionStrings["QuestionsDirectoryString"].ConnectionString}{Session["category"].ToString()}.json";
            json = JObject.Parse(File.ReadAllText(@dir));
            getQuestionsAmount();
        }

        //Updates SQL and json if needed
        protected void updateHS(int score)
        {
            //update SQL
            string connectionString = ConfigurationManager.ConnectionStrings["DataBaseConnectionString"].ConnectionString;
            con = new SqlConnection(connectionString);
            con.Open();
            SqlCommand command = new SqlCommand("SELECT HighScore FROM TKUsersTable Where Username=@username", con);
            command.Parameters.AddWithValue("@username", Session["username"]);
            using ( SqlDataReader reader = command.ExecuteReader() )
            {
                if ( reader.Read() )
                {
                    if ( reader.GetInt32(0) < score )
                    {
                        reader.Close();
                        command = new SqlCommand("UPDATE TKUsersTable SET HighScore=@score Where Username=@username;", con);
                        command.Parameters.AddWithValue("@username", Session["username"]);
                        command.Parameters.AddWithValue("@score", score);
                        command.ExecuteNonQuery();
                        Session["highscore"] = score;
                        massage.Text = String.Format("Highscore has been updated {0}!", score);
                    }
                }
                reader.Close();
            }

            //update json file
            if ( json["HighScores"][Session["username"]] != null )
            {
                int currScore = int.Parse(json["HighScores"][Session["username"]].ToString());
                if ( score > currScore )
                {
                    dynamic jsonObj = Newtonsoft.Json.JsonConvert.DeserializeObject(json.ToString());
                    jsonObj["HighScores"][Session["username"]] = score;
                    string output = Newtonsoft.Json.JsonConvert.SerializeObject(jsonObj, Newtonsoft.Json.Formatting.Indented);
                    File.WriteAllText(dir, output);
                    massage.Text = String.Format("Highscore has been updated {0}!", score);
                }
            } else
            {
                dynamic jsonObj = Newtonsoft.Json.JsonConvert.DeserializeObject(json.ToString());
                jsonObj["HighScores"].Add(Session["username"].ToString(), score);
                string output = Newtonsoft.Json.JsonConvert.SerializeObject(jsonObj, Newtonsoft.Json.Formatting.Indented);
                File.WriteAllText(dir, output);
                massage.Text = String.Format("Highscore has been updated {0}!", score);
            }
        }

        protected void tick(object sender, EventArgs e)
        {
            if ( timerLabel.Text == "" )
                timerLabel.Text = (timerStart + 1).ToString();
            timerLabel.Text = (int.Parse(timerLabel.Text) - 1).ToString();

            if ( timerLabel.Text == "0" )
                loadQuestion(sender, e);
        }

        protected void loadQuestion(object sender, EventArgs e)
        {
            if ( qCount == numberOfQuestions )
            {
                //Finished all questions. set display accoridngly
                updateHS(score);
                Timer1.Enabled = false;
                questionText.Text = $"Good Job!\nFinal Score: {score}";
                qNum.Text = "";
                
                for ( int num = 0; num < 3; num++ )
                    buttons[num].Visible = false;

                buttons[3].Text = "Back";

                scoreLabel.Text = "";
                timerLabel.Text = "";
                Image1.Visible = false;

            } else if ( qCount <= numberOfQuestions )
            {
                //get new question
                int r = getRandomQuestion();
                wasAsked[qCount++] = r;
                currQ = json["Questions"][r];

                //update visuals
                questionText.Text = currQ["question"].ToString();
                qNum.Text = $"#{qCount}";
                scoreLabel.Text = $"Score: {score}";
                timerLabel.Text = timerStart.ToString();

                //show image if possible
                if ( currQ["url"] != null )
                {
                    Image1.ImageUrl = currQ["url"].ToString();
                    Image1.Visible = true;
                } else
                    Image1.Visible = false;

                //shuffle answers
                int randomPlace = new Random().Next(4);
                for ( int num = 0; num < 4; num++ )
                    buttons[(num + randomPlace) % 4].Text = currQ["answers"][num]["txt"].ToString();
            }
        }


        protected void buttonClick(object sender, EventArgs e)
        {
            switch ( ((Button)sender).Text )
            {
                case "Back":
                    Response.Redirect("Categories.aspx");
                    break;
                case "Click me!":
                    score = 0;
                    qCount = 0;
                    Timer1.Enabled = true;
                    break;
                default:
                    if ( ((Button)sender).Text.ToString() == currQ["answers"][0]["txt"].ToString() )
                        score += 10 * int.Parse(timerLabel.Text);
                    break;
            }


            loadQuestion(sender, e);
        }

        private int getRandomQuestion()
        {
            Random rand = new Random();
            int temp;
            do
            {
                temp = rand.Next(maxQuestion);
            } while ( wasAsked.Contains<int>(temp) );

            return temp;
        }

        private void getQuestionsAmount()
        {
            maxQuestion = 0;
            foreach ( var x in json["Questions"] )
                maxQuestion++;
        }
    }
}