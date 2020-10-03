using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Configuration;
using System.Data;
using System.Diagnostics;

namespace Fullstack_Project
{
    public partial class Leaderboard : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["username"] == null)
            {
                Response.Redirect("Login.aspx");
            }

            string connectionString = ConfigurationManager.ConnectionStrings["DataBaseConnectionString"].ConnectionString;
            string queryString = "SELECT Username, HighScore from TKUsersTable Order by HighScore Desc ";
            var con = new SqlConnection(connectionString);
            var dataAda = new SqlDataAdapter(queryString, con);
            var cmdBuilder = new SqlCommandBuilder(dataAda);
            var ds = new DataSet();
            dataAda.Fill(ds);
            table.DataSource = ds.Tables[0];
            table.DataBind();

        }

        protected void textButton_OnClick(object sender, EventArgs e)
        {
            //Console.WriteLine(textInput.Text);
            Debug.WriteLine(textInput.Text);
            textLabel.Text = textInput.Text;
        }

        protected void table_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}