using System;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;

namespace Fullstack_Project
{
    public partial class Leaderboard : System.Web.UI.Page
    {
        SqlConnection con;

        protected void Page_Load(object sender, EventArgs e)
        {

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


        protected void table_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        protected void searchButton(object sender, EventArgs e)
        {
            string connectionString = ConfigurationManager.ConnectionStrings["DataBaseConnectionString"].ConnectionString;
            con = new SqlConnection(connectionString);
            con.Open();
            string queryString = "SELECT Username, HighScore FROM TKUsersTable WHERE Username=@username";
            SqlCommand command = new SqlCommand("SELECT Username, HighScore FROM TKUsersTable WHERE Username=@username", con);
            command.Parameters.AddWithValue("@username", username.Text);

            using (SqlDataReader reader = command.ExecuteReader())
            {
                if (reader.Read())
                {
                    message.Text = "The best score of this user is: " + reader.GetInt32(1).ToString();
                    /*var dataAda = new SqlDataAdapter(queryString, con);
                    var cmdBuilder = new SqlCommandBuilder(dataAda);
                    var ds = new DataSet();
                    dataAda.Fill(ds);
                    table.DataSource = ds.Tables[0];
                    table.DataBind();*/
                }
                else
                {
                    message.Text = "Username doesn't exist!";
                }

            }
        }
    }
}