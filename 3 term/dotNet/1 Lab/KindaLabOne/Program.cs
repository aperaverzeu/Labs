using System;

namespace KindaLabOne
{
    public static class Program
    {
        private static void WriteOptions()
        {
            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine("+ + + + + + + + + + + + + + + + + + + + + + + + +");
            Console.WriteLine("+   Enter a number of operation to do it now!   +");
            Console.WriteLine("+   >> 1 is create                       file   +");
            Console.WriteLine("+   >> 2 is write      #          #      file   +");
            Console.WriteLine("+   >> 3 is read       #          #      file   +");
            Console.WriteLine("+   >> 4 is copy                         file   +");
            Console.WriteLine("+   >> 5 is move                         file   +");
            Console.WriteLine("+   >> 6 is show      info     'bout     file   +");
            Console.WriteLine("+   >> 7 is delete                       file   +");
            Console.WriteLine("+   >> 8 is compress                     file   +");
            Console.WriteLine("+   >> 9 is decompress                   file   +");
            Console.WriteLine("+   >> 10 is rename                      file   +");
            Console.WriteLine("+   >> 0 is exit            the       program   +");
            Console.WriteLine("+ + + + + + + + + + + + + + + + + + + + + + + + +");
            Console.WriteLine();
        }

        private static int WriteToOption()
        {
            int option;
            try 
            {
                option = Convert.ToInt32(Console.ReadLine());
            }
            catch (Exception)
            {
                Console.WriteLine("Please, enter a right number!");
                option = WriteToOption();
            }
            return option;
        }

        public static string WriteToPath()
        {
            Console.Write("Enter a path to a file: ");
            var path = Console.ReadLine();
            if (path != null && path.EndsWith(".txt")) return path;
            Console.WriteLine("Check an extension!");
            path = WriteToPath();
            return path;
        }
        
        private static string WriteToCompressedPath()
        {
            Console.Write("Enter a path to compressed file: ");
            var path = Console.ReadLine();
            if (path != null && path.EndsWith(".gz")) return path;
            Console.WriteLine("Check an extension!");
            path = WriteToCompressedPath();
            return path;
        }

        private static void Main(string[] args)
        {
            var invoker = new Invoker();
            
            while (true)
            {
                WriteOptions();

                var option = WriteToOption();
                
                switch (option)
                {
                    case 1:
                        invoker.SetCommand(new CreateFile(WriteToPath()));
                        invoker.DoIt();
                        break;
                    case 2:
                        invoker.SetCommand(new WriteFile(WriteToPath()));
                        invoker.DoIt();
                        break;
                    case 3:
                        invoker.SetCommand(new ReadFile(WriteToPath()));
                        invoker.DoIt();
                        break;
                    case 4:
                        invoker.SetCommand(new CopyFile(WriteToPath(), WriteToPath()));
                        invoker.DoIt();
                        break;
                    case 5:
                        invoker.SetCommand(new MoveFile(WriteToPath(), WriteToPath()));
                        invoker.DoIt();
                        break;
                    case 6:
                        invoker.SetCommand(new InfoFile(WriteToPath()));
                        invoker.DoIt();
                        break;
                    case 7:
                        invoker.SetCommand(new DeleteFile(WriteToPath()));
                        invoker.DoIt();
                        break;
                    case 8:
                        invoker.SetCommand(new CompressFile(WriteToPath(), WriteToCompressedPath()));
                        invoker.DoIt();
                        break;
                    case 9:
                        invoker.SetCommand(new DecompressFile(WriteToCompressedPath(), WriteToPath()));
                        invoker.DoIt();
                        break;
                    case 10:
                        invoker.SetCommand(new RenameFile(WriteToPath()));
                        invoker.DoIt();
                        break;
                    case 0:
                        goto Exit;
                    default:
                        Console.WriteLine("You've entered something not suitable for us, " +
                                          "please be patient and next time enter a right value!");
                        break;
                }
            }
            
            Exit:
                Console.WriteLine("Exit!");
        }
    }
}
