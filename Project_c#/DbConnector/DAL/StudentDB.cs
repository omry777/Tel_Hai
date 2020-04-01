using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DAL
{
    public class StudentDB
    {
        private SqlConnection connection = null;
        public StudentDB()
        {
            this.connection = new SqlConnection("Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=C:\\Users\\omryb\\OneDrive - Mellanox\\Documents\\StudentsDb.mdf;Integrated Security=True;Connect Timeout=30");
        }
        public Student GetStudentById(string id)
        {
            return null;
        }
        public bool AddNewStudent(Student newStudentToADD)
        {
            bool isInsertedOk = false;
            string InsertCommand =
                "INSERT INTO Students (Id, Name, Family, Tel)" +
                string.Format("VALUES('{0}', '{1}', '{2}', '{3}')", newStudentToADD.Id,
                newStudentToADD.Name, newStudentToADD.Family, newStudentToADD.Tel);
            SqlCommand command = new SqlCommand(InsertCommand, this.connection);
            this.connection.Open();
            int isAffected = command.ExecuteNonQuery();
            if(isAffected > 0)
            {
                isInsertedOk = true;

            }
            command.Dispose();
            this.connection.Close();
            return isInsertedOk;
        }
    }

}
