using System.Linq;

namespace ETL.Db
{
    public class MoveDb
    {
        private readonly NoteContext _context;

        public MoveDb(NoteContext context)
        {
            _context = context;
        }

        public int GenerateId()
        {
            var id = _context.Notes.DefaultIfEmpty().Max(note => note == null ? 0 : note.Id);
            return id + 1;
        }
    }
}