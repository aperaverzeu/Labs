using System;
using System.Collections.Generic;
using System.Linq;

namespace UniProject
{
    public class Student : Human
    {
        public string University { get; private set; }
        public string Faculty { get; private set; }
        public string Hometown { get; private set; }
        public bool IsFullTime { get; private set; }
        public Scholarship Scholarship { get; private set; }
        public AcademicPerformance AcademicPerformance { get; private set; }
        public RecordBook RecordBook { get; private set; }


        public Student(string university, string faculty, string hometown,
                       bool isFullTime, string name, string surname, int age)
            : base(name, surname, age)
        {
            University = university;
            Faculty = faculty;
            Hometown = hometown;
            IsFullTime = isFullTime;
            AcademicPerformance = AcademicPerformance.Basic;
            Scholarship = Scholarship.None;
            RecordBook = new RecordBook();
        }

        public virtual void PassTheSession(int examsAmount)
        {
            for (int i = 0; i < examsAmount; i++)
            {
                Console.WriteLine("Enter subject & mark:");
                string subject = Console.ReadLine();
                int mark = Convert.ToInt32(Console.ReadLine());
                AddExamToRecordBook(subject, mark);
            }

            if (NotPassedAllExams())
            {
                Expel();
                return;
            }

            CalculateScholarship();
        }

        public virtual bool NotPassedAllExams()
        {
            return RecordBook.Results.Where(result => result.Mark < 4).Any();
        }

        private void CalculateScholarship()
        {
            double averageMark = RecordBook.Results.Average(result => result.Mark);

            if (averageMark >= 9)
            {
                Scholarship = Scholarship.Special;
                return;
            }
            if (averageMark >= 8)
            {
                Scholarship = Scholarship.Advanced;
                return;
            }
            if (averageMark >= 6)
            {
                Scholarship = Scholarship.Basic;
                return;
            }
            Scholarship = Scholarship.None;
        }

        public virtual void Expel()
        {
            Console.WriteLine("Goodbuy");
        }

        private void AddExamToRecordBook(string subject, int mark)
        {
            ExamResult examResult = new ExamResult(subject, mark);
            RecordBook.Results.Add(examResult);
        }
    }
}

