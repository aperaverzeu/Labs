using System;

namespace UniProject
{
    class Program
    {
        static void Main(string[] args)
        {
            Human h1 = new Human("Ałiaksiej", "Pieravierzieū", 18, Gender.Agender, "Biełarus", Race.White, 68, 181, "MCAllow");
            Console.WriteLine(h1.BMICalculate());
            Console.WriteLine(h1.ToString());

        }
    }
}
