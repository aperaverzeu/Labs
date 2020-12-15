using System;
using System.Linq;
using ETL.DataAccess;
using ETL.Models;

namespace ETL.DataManager
{
    public class MoveDb
    {
        private readonly NoteContext _noteContext;
        
        
        public MoveDb(NoteContext noteContext)
        {
            _noteContext = noteContext;
        }
        
        public int GenerateId()
        {
            var id = _noteContext.Notes.DefaultIfEmpty().Max(note => note == null ? 0 : note.Id);
            return id + 1;
        }

        public void CreateNote(int id, string creationDate, string content)
        {
            var note = new Note {Id = id, CreationDate = creationDate, Content = content};
            /*
             * INSERT INTO Notes (Id, CreationDate, Content) VALUES (id, creationDate, content);
             */
            _noteContext.Notes.Add(note);
            _noteContext.SaveChanges();
        }

        public void ChangeNote(int id, string newContent)
        {
            Console.WriteLine("\nChange the content of Note {0}", id);
            var changeNote = _noteContext.Notes.Find(id);
            changeNote.Content = newContent;
            _noteContext.SaveChanges();
        }
        
        public void ShowNote(int id)
        {
            Console.WriteLine("\nShow Note {0}", id);
            var note = _noteContext.Notes.Find(id);
            Console.WriteLine(note.ToString());
        }
        
        public void ShowNotes()
        {
            Console.WriteLine("\nShow all Notes\n");
            var notes = (from t in _noteContext.Notes select t).ToList();
            if (notes.Count == 0)
            {
                Console.WriteLine("There are no notes");
            }
            else
            {
                var query = from note in _noteContext.Notes
                    select note;
                foreach (var n in query)
                {
                    Console.WriteLine(n.ToString());
                }
            }
        }
        
        public void DeleteNote(int id)
        {
            Console.WriteLine("/nDelete Note {0}", id);
            var note = _noteContext.Notes.Find(id);
            _noteContext.Notes.Remove(note);
            _noteContext.SaveChanges();
        }
    }
}