using System;
using System.Collections.Generic;

namespace Thirti
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter a string:");
            string line = Console.ReadLine();

            string englishLetters = "asdfghjklqwertyuiopzxcvbnm";

            if (line.Length != 256)
            {
                Console.WriteLine("Error!");
                Environment.Exit(1);
            }
            for (int i = 0; i < line.Length; i++)
            {
                if (!englishLetters.Contains(line[i].ToString().ToLower()))
                {
                    Console.WriteLine("Error 2!");
                    Environment.Exit(1);
                }
            }
            

            Random random = new Random();
            List<int> randomList = new List<int>();

            int indexNumber = 0;
            while (randomList.Count != 30)
            {
                indexNumber = random.Next(0, 256);
                if (!randomList.Contains(indexNumber))
                {
                    randomList.Add(indexNumber);
                }
            }

            for (int i = 0; i < 30; i++)
            {
                Console.Write(" {0}",line[randomList[i]]);
            }

        }
    }
}
