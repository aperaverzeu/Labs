using Microsoft.EntityFrameworkCore;

namespace ETL.Db
{
    public class NoteContext : DbContext
    {
        public DbSet<Note> Notes { get; set; }
        
        private readonly string _connectionString;
        
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