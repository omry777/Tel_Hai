using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DAL;


namespace DbConnector
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello DbConnector");
            DAL.Student s1 = new DAL.Student("Moshe ", "Cohen ", "0123 ");
            s1.PrintTo();
            StudentDB studentdb = new StudentDB();
            Console.WriteLine(studentdb.AddNewStudent(s1));
            Console.ReadKey();
        }
    }
}
