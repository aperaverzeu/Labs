using System.Collections;
using System.Collections.Generic;

namespace UniProject
{
    public class RecordBook
    {
        public List<ExamResult> Results { get; set; }

        public RecordBook()
        {
            Results = new List<ExamResult>();
        }
    }
}
