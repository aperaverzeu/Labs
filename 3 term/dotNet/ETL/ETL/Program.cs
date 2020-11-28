using ETL.Library;

namespace ETL
{
    internal static class Program
    {
        private static void Main(string[] args)
        {
            var move = new Move("/Users/alex/Desktop/folder/source", "/Users/alex/Desktop/folder/target");
            move.Run();
        }
    }
}