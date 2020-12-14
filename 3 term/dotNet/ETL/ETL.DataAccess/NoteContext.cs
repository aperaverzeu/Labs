using ETL.Models;
using Microsoft.EntityFrameworkCore;

namespace ETL.DataAccess
{
    public class NoteContext : DbContext
    {
        public DbSet<Note> Notes { get; set; }

        public string _connectionString;
        
        public NoteContext(string connectionString)
        {
            _connectionString = connectionString;
        }
        
        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer(_connectionString);
        }
    }
}