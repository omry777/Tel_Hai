using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.IO;
using System.Web.UI.WebControls;

namespace Fullstack_Project
{
    public partial class Categories : System.Web.UI.Page
    {
        JObject json;
        string Hs;
        protected void Page_Load(object sender, EventArgs e)
        {
            if ( Session["username"] == null )
            {
                Response.Redirect("Login.aspx");
            }

            string fileName;
            int start;
            List<ImageButton> buttons = new List<ImageButton>();

            foreach ( string file in Directory.EnumerateFiles( ConfigurationManager.ConnectionStrings["QuestionsDirectoryString"].ConnectionString, "*.json") )
            {
                start = file.LastIndexOf("\\") + 1;
                fileName = file.Substring(start, file.LastIndexOf(".") - start);
                string dir = $"{ConfigurationManager.ConnectionStrings["QuestionsDirectoryString"].ConnectionString}{fileName}.json";
                json = JObject.Parse(File.ReadAllText(@dir));

                //DataGrid dg = new DataGrid();
                //container.Controls.Add(dg);
                buttons.Add(new ImageButton {
                    ID = fileName,
                    //Text = fileName,
                    CssClass = "menuButton",
                    ImageUrl= json["ImageUrl"]["url"].ToString()
                });;

                buttons[buttons.Count - 1].Click += buttonClick;
                container.Controls.Add(buttons[buttons.Count - 1]);
                

                if ( json["HighScores"][Session["username"]] != null )
                {
                    Hs = json["HighScores"][Session["username"]].ToString();
                } else
                {
                    Hs = "0";
                }

                Label l = new Label();
                l.CssClass = "textHandler2";
                l.Text = String.Format("HighScore: {0}", Hs);
                container.Controls.Add(l);
            }
        }

        protected void buttonClick(object sender, EventArgs e)
        {
            Session["category"] = ((ImageButton)sender).ID;
            Response.Redirect("Question.aspx");
        }
    }
}