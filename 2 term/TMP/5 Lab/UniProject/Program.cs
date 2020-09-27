using System;

namespace UniProject
{
    class Program
    {
        static void Main(string[] args)
        {
            Programmer programmer = new Programmer("BSUIR", "KSIS", "Minsk", true, "Leshka", "Kartoshka", 18);

            programmer.PassTheSession(2);
            Console.WriteLine(programmer.Scholarship);
        }
    }
}
