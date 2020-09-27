using System;
using System.Collections.Generic;
using System.Linq;

namespace UniProject
{
    public class Student : Human, IComparable<Student>
    {
        public string University { get; private set; }
        public string Faculty { get; private set; }
        public string Hometown { get; private set; }
        public bool IsFullTime { get; private set; }
        public Scholarship Scholarship { get; protected set; }
        public AcademicPerformance AcademicPerformance { get; private set; }
        public RecordBook RecordBook { get; private set; }
        public List<ISubject> Subjects { get; set; }


        public Student(string university, string faculty, string hometown,
                       bool isFullTime, string name, string surname, int age)
            : base(name, surname, age)
        {
            University = university;
            Faculty = faculty;
            Hometown = hometown;
            IsFullTime = isFullTime;
            AcademicPerformance = AcademicPerformance.Basic;
            Scholarship = Scholarship.Basic;
            RecordBook = new RecordBook();
            AddSubjects();
        }

        protected virtual void AddSubjects()
        {
            Subjects = new List<ISubject>();
            List<ISubject> subjects = new List<ISubject>() { new SubjectWithoutExam("Belarusian language"),
                                                             new SubjectWithExam("Philosophy"),
                                                             new SubjectWithExam("English") };
            Subjects.AddRange(subjects);
        }

        public virtual void PassTheSession()
        {
            FillTheRecordBook();

            if (NotPassedAllExams())
            {
                Expel();
                return;
            }

            CalculateScholarshipAndSetPerformance();
        }

        private void FillTheRecordBook()
        {
            Subjects.ForEach(subject =>
            {
                subject.Exam();
                if (subject is SubjectWithExam)
                {
                    SubjectWithExam newSubject = (SubjectWithExam)subject;
                    RecordBook.ExamResults.Add(newSubject);
                }
                else if (subject is SubjectWithoutExam)
                {
                    SubjectWithoutExam newSubject = (SubjectWithoutExam)subject;
                    RecordBook.Credits.Add(newSubject);
                }
            });
        }

        public virtual bool NotPassedAllExams()
        {
            return RecordBook.ExamResults.Where(result => result.Mark < 4).Any();
        }

        private void CalculateScholarshipAndSetPerformance()
        {
            double averageMark = RecordBook.ExamResults.Average(result => result.Mark);

            if (averageMark >= 9)
            {
                Scholarship = Scholarship.Special;
                AcademicPerformance = AcademicPerformance.Excellent;
                return;
            }
            if (averageMark >= 8)
            {
                Scholarship = Scholarship.Advanced;
                AcademicPerformance = AcademicPerformance.Good;
                return;
            }
            if (averageMark >= 6)
            {
                Scholarship = Scholarship.Basic;
                AcademicPerformance = AcademicPerformance.Basic;
                return;
            }
            Scholarship = Scholarship.None;
            AcademicPerformance = AcademicPerformance.Bad;
        }

        public virtual void Expel()
        {
            Scholarship = Scholarship.None;
            Console.WriteLine("Goodbuy");
        }

        public virtual int CompareTo(Student other)
        {
            return this.AcademicPerformance.CompareTo(other.AcademicPerformance);
        }
    }
}

