using System;

namespace UniProject
{
    class Program
    {
        static void Main(string[] args)
        {
            //Programmer programmer = new Programmer("BSUIR", "KSIS", "Minsk", true, "Aleksey", "Peraverzev", 18);
            //// Console.WriteLine(programmer.PassportNumber);

            //programmer.PassTheSession();
            //Console.WriteLine($"Your scholarship is {(int)programmer.Scholarship}");
            //Console.WriteLine($"Your academic performance is {programmer.AcademicPerformance}");

            Student student = new Student("U", "f", "Horandia", true, "Lavon", "Icha", 29);
            student.PassTheSession();
            Console.WriteLine($"Your scholarship is {student.Scholarship}");
        }
    }
}
