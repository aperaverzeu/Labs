using System.Collections;
using System.Collections.Generic;

namespace UniProject
{
    public class RecordBook
    {
        public List<SubjectWithExam> ExamResults { get; set; }
        public List<SubjectWithoutExam> Credits { get; set; }

        public RecordBook()
        {
            ExamResults = new List<SubjectWithExam>();
            Credits = new List<SubjectWithoutExam>();
        }
    }
}
