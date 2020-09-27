namespace UniProject
{
    public class ExamResult
    {
        public string Subject { get; set; }
        public int Mark { get; set; }

        public ExamResult(string subject, int mark)
        {
            Subject = subject;
            Mark = mark;
        }
    }
}