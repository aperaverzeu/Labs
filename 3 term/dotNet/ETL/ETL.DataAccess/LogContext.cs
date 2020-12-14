using ETL.Models;
using Microsoft.EntityFrameworkCore;

namespace ETL.DataAccess
{
    public class LogContext : DbContext
    {
        public DbSet<Log> Logs { get; set; }

        public string _connectionString;
        
        public LogContext(string connectionString)
        {
            _connectionString = connectionString;
        }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer(_connectionString);
        }
    }
}