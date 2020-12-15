using ETL.DataAccess;
using ETL.Models;
using System.Linq;

namespace ETL.DataManager
{
    public class MoveLogDb
    {
        private readonly LogContext _logContext;

        public MoveLogDb(LogContext logContext)
        {
            _logContext = logContext;
        }
        
        public int GenerateId()
        {
            var id = _logContext.Logs.DefaultIfEmpty().Max(note => note == null ? 0 : note.Id);
            return id + 1;
        }
        
        public void CreateLog(int id, string time, string message)
        {
            var log = new Log {Id = id, Time = time, Message = message};
            _logContext.Logs.Add(log);
            _logContext.SaveChanges();
        }
    }
}