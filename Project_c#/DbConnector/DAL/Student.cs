using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DAL
{
    public class Student
    {
        public string Id { get; set; }
        public string Name { get; set; }
        public string Family { get; set; }
        public string Tel { get; set; }

        public Student(string name, string family, string tel)
        {
            this.Id = Guid.NewGuid().ToString();
            this.Name = name;
            this.Family = family;
            this.Tel = tel;

        }

        public void PrintTo()
        {
            string str = "ID: " + Id + "Name: " + Name + "Family: " + Family + "Tel: " + Tel;
            Console.WriteLine(str);
        }

    }
}
