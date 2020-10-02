namespace KindaLabOne
{
    public class Invoker
    {
        private ICommand _command;
       
        public void SetCommand(ICommand command)
        {
            _command = command;
        }

        public void DoIt()
        {
            _command?.Execute();
        }
    }
}
