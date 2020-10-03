using Microsoft.Ajax.Utilities;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Fullstack_Project
{
    public partial class Categories : System.Web.UI.Page
    {
        JObject json;
        string Hs;
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["username"] == null)
            {
                Response.Redirect("Login.aspx");
            }

            string fileName;
            int start;
            List<Button> buttons = new List<Button>();

            foreach (string file in Directory.EnumerateFiles("C:\\Users\\omryb\\source\\repos\\FullstackProject2\\Fullstack Project\\Questions\\", "*.json"))
            {
                start = file.LastIndexOf("\\") +1;
                fileName = file.Substring(start, file.LastIndexOf(".") - start);
                buttons.Add(new Button
                {
                    ID = fileName,
                    Text = fileName,
                    CssClass = "menuButton",
                });

                buttons[buttons.Count-1].Click += buttonClick;
                container.Controls.Add(buttons[buttons.Count - 1]);
                string dir = $"C:\\Users\\omryb\\source\\repos\\FullstackProject2\\Fullstack Project\\Questions\\{fileName}.json";
                json = JObject.Parse(File.ReadAllText(@dir));

                if (json["HighScores"][Session["username"]] != null)
                {
                    Hs = json["HighScores"][Session["username"]].ToString();
                }
                else
                {
                    Hs = "0";
                }

                Label l = new Label();
                l.Text = String.Format("HighScore: {0}", Hs);
                container.Controls.Add(l) ;

            }
        }

        protected void buttonClick(object sender, EventArgs e)
        {
            Session["category"] = ((Button)sender).ID;
            Response.Redirect("Question.aspx");
        }
    }
}