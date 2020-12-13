using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
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
                    command = new SqlCommand("INSERT INTO TKUsersTable VALUES (@id, @username, @password, 0, '-');", con);
                    command.Parameters.AddWithValue("@username", username.Text);
                    command.Parameters.AddWithValue("@id",userCount++);
                    command.Parameters.AddWithValue("@password", Encrypt(password.Text));
                    
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
        public static string strKey = "Q23weS!#%s2(*&^%-d";
        public static string Encrypt(string strData)
        {
            string strValue = "";
            if ( !string.IsNullOrEmpty(strKey) )
            {
                if ( strKey.Length < 16 )
                {
                    strKey = strKey + strKey.Substring(0, 16 - strKey.Length);
                }

                if ( strKey.Length > 16 )
                {
                    strKey = strKey.Substring(0, 16);
                }

                // create encryption keys
                byte[] byteKey = Encoding.UTF8.GetBytes(strKey.Substring(0, 8));
                byte[] byteVector = Encoding.UTF8.GetBytes(strKey.Substring(strKey.Length - 8, 8));

                // convert data to byte array
                byte[] byteData = Encoding.UTF8.GetBytes(strData);

                // encrypt 
                DESCryptoServiceProvider objDES = new DESCryptoServiceProvider();
                MemoryStream objMemoryStream = new MemoryStream();
                CryptoStream objCryptoStream = new CryptoStream(objMemoryStream, objDES.CreateEncryptor(byteKey, byteVector), CryptoStreamMode.Write);
                objCryptoStream.Write(byteData, 0, byteData.Length);
                objCryptoStream.FlushFinalBlock();

                // convert to string and Base64 encode
                strValue = Convert.ToBase64String(objMemoryStream.ToArray());
            } else
            {
                strValue = strData;
            }

            return strValue;
        }
    }
}