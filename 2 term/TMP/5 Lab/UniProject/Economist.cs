using System;
namespace UniProject
{
    public class Economist : Student
    {
        public Economist(string university, string faculty, string hometown,
                            bool isFullTime, string name, string surname, int age)
                 : base(university, faculty, hometown, isFullTime, name, surname, age)
        {
        }
    }
}
