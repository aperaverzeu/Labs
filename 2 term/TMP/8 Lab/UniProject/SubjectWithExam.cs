using System;
using System.Collections.Generic;
using System.Text;

namespace UniProject
{
    public struct SubjectWithExam : ISubject
    {
        public string Name { get; }
        public int Mark { get; private set; }

        public SubjectWithExam(string name)
        {
            Name = name;
            Mark = -1;
        }

        public void Exam()
        {
            Console.WriteLine($"What is your mark for {Name}?");
            int answer = 0;
            try
            {
                answer = Convert.ToInt32(Console.ReadLine());
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                Exam();
                return;
            }

            if (answer >= 0 && answer <= 10)
            {
                Mark = answer;
            }
            else
            {
                Console.WriteLine("You can set your mark only in range from 0 to 10");
                Exam();
                return;
            }
        }
    }
}

