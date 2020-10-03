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
        static int qCount = 0;
        static int maxQuestion = 0;
        SqlConnection con;
        static int score = 0;
        static Button[] buttons;
        static int[] wasAsked;
        JObject json;
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


            //using (WebClient wc = new WebClient())
            //{
            //    string jsontext = wc.DownloadString("https://www.npoint.io/docs/e6f3d2ed38e63ed9bc80");
            //}
            dir = $"C:\\Users\\omryb\\source\\repos\\FullstackProject2\\Fullstack Project\\Questions\\{Session["category"].ToString()}.json";
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

                        massage.Text = String.Format("Highscore has been updated {0}!", score);
                    }
                    massage.Text = String.Format("Better luck next time! ", score);
                }
                reader.Close();
            }
        }

        protected void loadQuestion(object sender, EventArgs e)
        {
            if (qCount == numberOfQuestions)
            {
                updateHS(score);
            }
            if (qCount < numberOfQuestions)
            {
                int r = getRandomQuestion();
                wasAsked[qCount++] = r;
                qNum.Text = $"#{qCount}";

                var currQ = json["Questions"][r];
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
            }
            else
            {
                questionText.Text = "Press any button to Start!";
                qNum.Text = "";
                for (int num = 0; num < 4; num++)
                {
                    buttons[num].ID = $"ans{num}";
                    buttons[num].Text = "Click me!";
                }
                qCount = 0;
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
                    score = 0;
                scoreLabel.Text = $"Score: {score}";
            }
        }

        protected void buttonClick(object sender, EventArgs e)
        {
            if (((Button)sender).ID.ToString() == "ans0" && ((Button)sender).Text != "Click me!")
                scoreLabel.Text = $"Score: {score += 50}";
            //else
              //  scoreLabel.Text = $"Score: {score}";

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