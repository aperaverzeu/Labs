using System;
using System.Collections.Generic;
using System.Text;

namespace UniProject
{
    public struct SubjectWithoutExam : ISubject
    {
        public string Name { get; }
        public bool IsCredited { get; private set; }

        public SubjectWithoutExam(string name)
        {
            Name = name;
            IsCredited = false;
        }

        public void Exam()
        {
            Console.WriteLine($"Are you were credited for {Name}? y/n");
            string answer = Console.ReadLine().ToLower();
            if (answer == "y")
            {
                IsCredited = true;
            }
            else
            {
                IsCredited = false;
            }
        }
    }
}
