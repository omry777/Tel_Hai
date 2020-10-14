using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Fullstack_Project
{
    public partial class SiteMaster : MasterPage
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["username"] != null)
            {
                cataButton.Visible = true;
                nameLabel.Text = "Hello " +Session["username"].ToString();
                HSLabel.Text = "Highscore: " +Session["highscore"].ToString();
                nameLabel.Visible = true;
                HSLabel.Visible = true;
                logOutButton.Visible = true;
            }
        }

        protected void logoutButton(object sender, EventArgs e)
        {
            Session["username"] = null;
            Response.Redirect("Login.aspx");
        }
    }
}