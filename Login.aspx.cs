using System;
using System.Configuration;
using System.Data.SqlClient;
using System.IO;
using System.Security.Cryptography;
using System.Text;

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
            string queryString = "SELECT Username, Password, HighScore from TKUsersTable WHERE Username=@uname";
            var con = new SqlConnection(connectionString);
            con.Open();
            SqlCommand cmd = new SqlCommand(queryString, con);
            cmd.Parameters.AddWithValue("@uname", username.Text);
            using ( SqlDataReader reader = cmd.ExecuteReader() )
            {
                if ( reader.Read() )
                {
                    if ( Decrypt(reader.GetString(1)) != password.Text )
                    {
                        message.Text = "password doesn't match";
                        return;
                    }
                    Session["username"] = username.Text;
                    Session["highscore"] = reader.GetInt32(2);
                    Response.Redirect("Categories.aspx");
                } else
                {
                    message.Text = "username doesn't exist";
                }
            }
        }

        public static string strKey = "Q23weS!#%s2(*&^%-d";
        public static string Decrypt(string strData)
        {
            string strValue = "";
            if ( !string.IsNullOrEmpty(strKey) )
            {
                // convert key to 16 characters for simplicity
                if ( strKey.Length < 16 )
                    strKey = strKey + strKey.Substring(0, 16 - strKey.Length);

                if ( strKey.Length > 16 )
                    strKey = strKey.Substring(0, 16);

                // create encryption keys
                byte[] byteKey = Encoding.UTF8.GetBytes(strKey.Substring(0, 8));
                byte[] byteVector = Encoding.UTF8.GetBytes(strKey.Substring(strKey.Length - 8, 8));

                // convert data to byte array and Base64 decode
                byte[] byteData = new byte[strData.Length + 1];
                try
                {
                    byteData = Convert.FromBase64String(strData);
                }
                catch{
                    strValue = strData;
                }


                if ( string.IsNullOrEmpty(strValue) )
                {
                    // decrypt
                    DESCryptoServiceProvider objDES = new DESCryptoServiceProvider();
                    MemoryStream objMemoryStream = new MemoryStream();
                    CryptoStream objCryptoStream = new CryptoStream(objMemoryStream, objDES.CreateDecryptor(byteKey, byteVector), CryptoStreamMode.Write);
                    objCryptoStream.Write(byteData, 0, byteData.Length);
                    objCryptoStream.FlushFinalBlock();

                    // convert to string
                    Encoding objEncoding = Encoding.UTF8;
                    strValue = objEncoding.GetString(objMemoryStream.ToArray());

                }
            } else
            {
                strValue = strData;
            }

            return strValue;
        }        
    }
}