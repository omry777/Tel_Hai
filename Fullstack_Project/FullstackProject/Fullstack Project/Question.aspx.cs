using Newtonsoft.Json.Linq;
using Newtonsoft.Json.Serialization;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.IO;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Fullstack_Project
{
    public partial class Question : System.Web.UI.Page
    {
        const int numberOfQuestions = 10;
        const int timerStart = 5;
        static int qCount = 0;
        static int maxQuestion = 0;
        SqlConnection con;
        static int score = 0;
        static Button[] buttons;
        static int[] wasAsked;
        static JObject json;
        string dir;
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["username"] == null)
            {
                Response.Redirect("Login.aspx");
            }

            buttons = new Button[4];
            buttons[0] = ans0;
            buttons[1] = ans1;
            buttons[2] = ans2;
            buttons[3] = ans3;

            wasAsked = new int[numberOfQuestions];
            for (int i = 0; i < numberOfQuestions; i++)
                wasAsked[i] = -1;

            dir = $"C:\\Users\\Yair Charit\\Documents\\Tel Hai Collage\\SemE\\Tel_Hai\\Fullstack_Project\\FullstackProject\\Fullstack Project\\Questions\\{Session["category"].ToString()}.json";
            json = JObject.Parse(File.ReadAllText(@dir));
            getQuestionsAmount();
        }

        protected void updateHS(int score)
        {
            string connectionString = ConfigurationManager.ConnectionStrings["DataBaseConnectionString"].ConnectionString;
            con = new SqlConnection(connectionString);
            con.Open();
            SqlCommand command = new SqlCommand("SELECT HighScore FROM TKUsersTable Where Username=@username", con);
            command.Parameters.AddWithValue("@username", Session["username"]);
            using (SqlDataReader reader = command.ExecuteReader())
            {
                if(reader.Read())
                {
                    //massage.Text = String.Format("curr HS:{0}", reader.GetString(reader.GetOrdinal("HighScore")));
                    if (reader.GetInt32(0) < score)
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
        }

        protected void tick(object sender, EventArgs e)
        {
                if (timerLabel.Text == "")
                    timerLabel.Text = (timerStart + 1).ToString();
                timerLabel.Text = (int.Parse(timerLabel.Text) - 1).ToString();
                massage.Text = timerLabel.Text;
                if (timerLabel.Text == "0")
                {
                    qCount++;
                    loadQuestion(sender, e);
                }
        }

        protected void loadQuestion(object sender, EventArgs e)
        {

            if (qCount == numberOfQuestions+1)
            {
                updateHS(score);
                Timer1.Enabled = false;
                questionText.Text = $"Good Job!\nFinal Score: {score}";
                qNum.Text = "";
                for (int num = 0; num < 4; num++)
                {
                    buttons[num].ID = $"ans{num}";
                    buttons[num].Text = "Back";
                }
                if (json["HighScores"][Session["username"]] != null)
                {
                    int currScore = int.Parse(json["HighScores"][Session["username"]].ToString());
                    if (score > currScore)
                    {
                        dynamic jsonObj = Newtonsoft.Json.JsonConvert.DeserializeObject(json.ToString());
                        jsonObj["HighScores"][Session["username"]] = score;
                        string output = Newtonsoft.Json.JsonConvert.SerializeObject(jsonObj, Newtonsoft.Json.Formatting.Indented);
                        File.WriteAllText(dir, output);
                    }
                }
                else
                {
                    dynamic jsonObj = Newtonsoft.Json.JsonConvert.DeserializeObject(json.ToString());
                    jsonObj["HighScores"].Add(Session["username"].ToString(), score);
                    string output = Newtonsoft.Json.JsonConvert.SerializeObject(jsonObj, Newtonsoft.Json.Formatting.Indented);
                    File.WriteAllText(dir, output);
                }
                scoreLabel.Text = "";
                timerLabel.Text = "";
                score = 0;
            }
            else if (qCount <= numberOfQuestions)
            {
                int r = getRandomQuestion();
                wasAsked[qCount-1] = r;
                qNum.Text = $"#{qCount}";
                scoreLabel.Text = $"Score: {score}";

                var currQ = json["Questions"][r];
                massage.Text = qCount + currQ.ToString();
                questionText.Text = currQ["question"].ToString();
                if(currQ["url"] != null)
                {
                    Image1.ImageUrl = currQ["url"].ToString();
                    Image1.Visible = true;
                }
                else
                {
                    Image1.Visible= false;
                }


                Random rand = new Random();
                int count = rand.Next(4);

                for (int num = 0; num < 4; num++)
                {
                    buttons[(num + count) % 4].ID = $"ans{num}";
                    buttons[(num + count) % 4].Text = currQ["answers"][num]["txt"].ToString();
                }
                timerLabel.Text = timerStart.ToString();

            }


        }


        protected void buttonClick(object sender, EventArgs e)
        {
            if (((Button)sender).Text == "Back")
                Response.Redirect("Categories.aspx");

            if (((Button)sender).ID.ToString() == "ans0" && ((Button)sender).Text != "Click me!")
                score += 10*int.Parse(timerLabel.Text);

            if (((Button)sender).Text == "Click me!")
            {
                qCount = 1;
                Timer1.Enabled = true;
            }
            else
                qCount++;

            loadQuestion(sender, e);
        }

        private int getRandomQuestion()
        {
            Random rand = new Random();
            int temp;
            do
            {
                temp = rand.Next(maxQuestion);
            } while (wasAsked.Contains<int>(temp));

            return temp;
        }

        private void getQuestionsAmount()
        {
            maxQuestion = 0;
            foreach (var x in json["Questions"])
            {
                maxQuestion++;
            }
        }
    }
}