using System;

namespace ConsoleApp1
{
    public class User
    {
        public static int usersCount = 0;
        private string name { get; set; }
        private string password { get; set; }
        private int id { get; set; }
        private int highScore { get; set; }

        public User()
        {
        }
    }
}
