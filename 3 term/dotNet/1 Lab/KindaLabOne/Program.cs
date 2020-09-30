namespace KindaLabOne
{
    public static class Program
    {
        static void Main(string[] args)
        {
            var invoker = new Invoker();
            invoker.SetCommand(new CreateFile("/Users/alex/Desktop/folder/test.txt"));
            // invoker.SetOnFinish(new InfoFile("/Users/alex/Desktop/folder/test.txt"));
            invoker.DoIt();
        }
    }
}
