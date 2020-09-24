using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

namespace ConsoleApp1
{
    class Program
    {
        static SqlConnection con;
        static void Main(string[] args)
        {
            string connectionString;
            connectionString = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=C:\Users\Yair Charit\Documents\TKUsers.mdf;Integrated Security=True;Connect Timeout=30";
            con = new SqlConnection(connectionString);
            try
            {
                con.Open();
                Console.WriteLine("Success to log in");
                InitUsersCount();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            Console.WriteLine("Hello World!");
            print_all_members();

            con.Close();
        }

        public static void InitUsersCount()
        {
            SqlCommand command = new SqlCommand("SELECT Id from TKUsersTable ORDER BY Id DESC", con);
            using (SqlDataReader reader = command.ExecuteReader())
            {
                if (reader.Read())
                    User.usersCount = reader.GetInt32(0) + 1;
                else
                    Console.WriteLine("No users registered!");
                reader.Close();
            }
        }

        public static void getDits()
        {
            Console.WriteLine("Enter username:");
            string name = Console.ReadLine();
            Console.WriteLine("Enter Password:");
            string pass = Console.ReadLine();
            insert_user(name, pass);
        }

        public static void print_all_members()
        {
            SqlCommand command = new SqlCommand("SELECT Id, Username,HighScore from TKUsersTable", con);

            using (SqlDataReader reader = command.ExecuteReader())
            {
                while (reader.Read())
                {
                    Console.WriteLine(String.Format("{0}, {1}, {2}", reader.GetInt32(0), reader.GetString(1), reader.GetInt32(2)));
                }
                reader.Close();
            }
        }

        public static void insert_user(string name, string password)
        {
            SqlCommand cmd = new SqlCommand("SELECT * FROM TKUsersTable Where Username=@name", con);
            cmd.Parameters.AddWithValue("@name", name);

            using (SqlDataReader reader = cmd.ExecuteReader())
            {
                if (reader.Read())
                    Console.WriteLine("user already exists!");
                else
                {
                    SqlCommand command = new SqlCommand("INSERT INTO TKUsersTable VALUES (@id, @username, @password, 0);", con);
                    command.Parameters.AddWithValue("@id", User.usersCount++);
                    command.Parameters.AddWithValue("@username", name);
                    command.Parameters.AddWithValue("@password", password);

                    command.ExecuteNonQuery();
                    Console.WriteLine(String.Format("{0} was added successfuly!", name));
                }
                reader.Close();
            }
        }

        public static void updateHighScore(string name, int hs)
        {
            SqlCommand cmd = new SqlCommand("SELECT HighScore FROM TKUsersTable Where Username=@name", con);
            cmd.Parameters.AddWithValue("@name", name);

            using (SqlDataReader reader = cmd.ExecuteReader())
            {
                if (reader.Read())
                {
                    if (reader.GetInt32(0) < hs)
                    {
                        SqlCommand command = new SqlCommand("UPDATE TKUsersTable SET HighScore = @score Where Username=@name", con);
                        command.Parameters.AddWithValue("@name", name);
                        command.Parameters.AddWithValue("@score", hs);
                        reader.Close();
                        command.ExecuteNonQuery();
                    }
                }
                else
                    Console.WriteLine("No such user!");
                
            }
        }
    }
}

