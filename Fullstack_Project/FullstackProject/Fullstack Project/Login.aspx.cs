using System;
using System.Configuration;
using System.Data.SqlClient;

namespace Fullstack_Project
{
    public partial class Login : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if ( Session["username"] != null )
            {
                DitsPanel.Visible = false;
                loggedInLabel.Visible = true;
                loggedInLabel.Text = $"Currently logged in as {Session["username"].ToString()}";
            }
        }

        protected void loginButton(object sender, EventArgs e)
        {
            string connectionString = ConfigurationManager.ConnectionStrings["DataBaseConnectionString"].ConnectionString;
            string queryString = "SELECT Username, Password, HighScore from TKUsersTable WHERE Username=@uname AND Password=@password";
            var con = new SqlConnection(connectionString);
            con.Open();
            SqlCommand cmd = new SqlCommand(queryString, con);
            cmd.Parameters.AddWithValue("@uname", username.Text);
            cmd.Parameters.AddWithValue("@password", password.Text);
            using ( SqlDataReader reader = cmd.ExecuteReader() )
            {
                if ( reader.Read() )
                {
                    Session["username"] = username.Text;
                    Session["highscore"] = reader.GetInt32(2);
                    Response.Redirect("Categories.aspx");
                } else
                {
                    message.Text = "username or password does not match";
                }
            }
        }

    }
}