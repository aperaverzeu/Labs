
using System;

namespace FifthTaskSecondLab
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter a string:");
            string line = Console.ReadLine();
            string englishLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

            foreach (var letter in line)
            {
                if ((letter.ToString().ToUpper() == letter.ToString()) && (!englishLetters.Contains(letter)))
                {
                    Console.WriteLine(letter);
                }
            }
            
        }
    }
}
