using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Fullstack_Project
{
    public partial class Signup : System.Web.UI.Page
    {
        SqlConnection con;
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void insert_user(object sender, EventArgs e)
        {
            string connectionString = ConfigurationManager.ConnectionStrings["DataBaseConnectionString"].ConnectionString;
            con = new SqlConnection(connectionString);
            con.Open();
            int userCount = getLastId();
            
            SqlCommand command = new SqlCommand("SELECT * FROM TKUsersTable Where Username=@username", con);
            command.Parameters.AddWithValue("@username", username.Text);

            using (SqlDataReader reader = command.ExecuteReader())
            {
                if (reader.Read())
                    massage.Text = "username taken";
                else
                {
                    reader.Close();
                    command = new SqlCommand("INSERT INTO TKUsersTable VALUES (@id, @username, @password, 0);", con);
                    command.Parameters.AddWithValue("@username", username.Text);
                    command.Parameters.AddWithValue("@id",userCount++);
                    command.Parameters.AddWithValue("@password", password.Text);
                    
                    command.ExecuteNonQuery();
                    
                    massage.Text = String.Format("{0} was added successfuly!", username.Text);
                }
                reader.Close();
            }
        }

        private int getLastId()
        {
            int count = 0;
            SqlCommand command = new SqlCommand("SELECT Id from TKUsersTable ORDER BY Id DESC", con);
            using (SqlDataReader reader = command.ExecuteReader())
            {
                if (reader.Read())
                    count = reader.GetInt32(0) + 1;

                reader.Close();
                return count;
            }
        }
    }
}