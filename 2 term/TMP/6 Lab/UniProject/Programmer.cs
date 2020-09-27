using System;
using System.Linq;

namespace UniProject
{
    public class Programmer : Student
    {
        public Programmer(string university, string faculty, string hometown,
                            bool isFullTime, string name, string surname, int age)
                 : base(university, faculty, hometown, isFullTime, name, surname, age)
        {
        }

        //public override bool NotPassedAllExams()
        //{
        //    if (RecordBook.Results.Average(result => result.Mark) < 4)
        //        return true;
        //    return false;
        //}
    }
}
