using System.Linq;
using ETL.DataAccess;
using ETL.Models;

namespace ETL.DataManager
{
    public class MoveDb
    {
        private readonly NoteContext _noteContext;
        private readonly LogContext _logContext;
        
        public MoveDb(NoteContext noteContext, LogContext logContext)
        {
            _noteContext = noteContext;
            _logContext = logContext;
        }
        
        public int GenerateId()
        {
            var id = _noteContext.Notes.DefaultIfEmpty().Max(note => note == null ? 0 : note.Id);
            return id + 1;
        }
        
        public int GenerateLogId()
        {
            var id = _logContext.Logs.DefaultIfEmpty().Max(note => note == null ? 0 : note.Id);
            return id + 1;
        }
        
        public void CreateNote(int id, string creationDate, string content)
        {
            var note = new Note {Id = id, CreationDate = creationDate, Content = content};
            _noteContext.Notes.Add(note);
            _noteContext.SaveChanges();
        }
        
        public void CreateLog(int id, string time, string message)
        {
            var log = new Log {Id = id, Time = time, Message = message};
            _logContext.Logs.Add(log);
            _logContext.SaveChanges();
        }
    }
}