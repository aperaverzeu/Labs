using System;
using System.Collections.Generic;
using System.Text;

namespace _2._6
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter your text line");
            string line = Console.ReadLine();

            Random a = new Random();
            List<int> randomList = new List<int>();

            int MyNumber = 0;
            while(randomList.Count != line.Length)
            {
                MyNumber = a.Next(0, line.Length);
                if (!randomList.Contains(MyNumber))
                    randomList.Add(MyNumber);
            }

            string newLine = line;
            StringBuilder stringBuilder = new StringBuilder(newLine);

            for (int i = 0; i < line.Length; i++)
            {
                stringBuilder[i] = line[randomList[i]];
            }

            newLine = stringBuilder.ToString();

            Console.WriteLine(newLine);
        }
    }
}
