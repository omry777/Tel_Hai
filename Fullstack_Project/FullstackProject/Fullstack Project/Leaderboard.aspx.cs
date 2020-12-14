using System;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Text;
using System.Web.UI.WebControls;
using System.Windows.Documents;
//using System.Windows.Documents;

namespace Fullstack_Project
{
    public partial class Leaderboard : System.Web.UI.Page
    {
        SqlConnection con;
        SqlDataAdapter da;
        DataSet ds = new DataSet();
        StringBuilder htmlTable = new StringBuilder();
        protected void Page_Load(object sender, EventArgs e)
        {

            string connectionString = ConfigurationManager.ConnectionStrings["DataBaseConnectionString"].ConnectionString;
            string queryString = "SELECT Username, HighScore from TKUsersTable Order by HighScore Desc ";
            var con = new SqlConnection(connectionString);
            SqlCommand cmd = new SqlCommand(queryString, con);
            da = new SqlDataAdapter(cmd);
            da.Fill(ds);
            con.Open();
            cmd.ExecuteNonQuery();
            con.Close();
            //var dataAda = new SqlDataAdapter(queryString, con);
            //var cmdBuilder = new SqlCommandBuilder(dataAda);
            //DataSet ds = new DataSet();
            //dataAda.Fill(ds);
            //table.DataSource = ds.Tables[0];
            //table.DataBind();
            createTable();
        }

        protected void createTable()
        {
            htmlTable.Append("<table style='width: 75%; text-align: left; align-content: center;"
            + "background-color: #808080; font-family: Calibri;"
            + "font-size: 16px; border: 1px solid black;"
            + "margin: 0 auto; table-layout: fixed;'>");
            htmlTable.Append("<tr style='color: White;'>" +
                "<th style='border: 1px solid black;'>Rate</th>" +
                "<th style='border: 1px solid black;'>Username</th>" +
                "<th style='border: 1px solid black;'>Score</th>");
            int j = 1;
            if (!object.Equals(ds.Tables[0], null))
            {
                if (ds.Tables[0].Rows.Count > 0)
                {
                    for (int i = 0; (i < ds.Tables[0].Rows.Count); i++)
                    {
                        htmlTable.Append("<tr style='color: White;'>");
                        htmlTable.Append("<td style='border: 1px solid black;'>" + j.ToString() + "</td>");
                        htmlTable.Append("<td style='border: 1px solid black;'>" + ds.Tables[0].Rows[i]["Username"] + "</td>");
                        htmlTable.Append("<td style='border: 1px solid black;'>" + ds.Tables[0].Rows[i]["HighScore"] + "</td>");
                        htmlTable.Append("</tr>");
                        j++;
                    }
                    htmlTable.Append("</table>");
                    DBDataPlaceHolder.Controls.Add(new Literal { Text = htmlTable.ToString() });
                }
                else
                {
                    htmlTable.Append("<tr>");
                    htmlTable.Append("<td align='center' colspan='4'>There is no Record.</td>");
                    htmlTable.Append("</tr>");
                }
            }
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