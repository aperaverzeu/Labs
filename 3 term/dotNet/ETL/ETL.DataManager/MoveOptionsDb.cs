using ETL.DataAccess;
using ETL.Models;
using System.Linq;

namespace ETL.DataManager
{
    public class MoveOptionsDb
    {
        private readonly ArchiveOptionContext _archiveContext;
        private readonly DbConnectionOptionContext _dbConnectionContext;
        private readonly WatcherOptionContext _watcherContext;

        public MoveOptionsDb(ArchiveOptionContext archiveContext, DbConnectionOptionContext dbConnectionContext, WatcherOptionContext watcherContext)
        {
            _archiveContext = archiveContext;
            _dbConnectionContext = dbConnectionContext;
            _watcherContext = watcherContext;
        }
        
        public int GenerateArchiveId()
        {
            var id = _archiveContext.ArchiveOptions.DefaultIfEmpty().Max(note => note == null ? 0 : note.Id);
            return id + 1;
        }
        
        public void CreateArchiveOption(int id, string compressionLevel)
        {
            var archiveModel = new ArchiveModel {Id = id, CompressionLevel = compressionLevel};
            _archiveContext.ArchiveOptions.Add(archiveModel);
            _archiveContext.SaveChanges();
        }
        
        public int GenerateConnectionId()
        {
            var id = _dbConnectionContext.DbConnectionOptions.DefaultIfEmpty().Max(note => note == null ? 0 : note.Id);
            return id + 1;
        }
        
        public void CreateConnectionOption(int id, string datasource, string userID, string password, string initialCatalog)
        {
            var dbConnectionModel = new DbConnectionModel {Id = id, DataSource = datasource, UserID = userID, Password = password, InitialCatalog = initialCatalog};
            _dbConnectionContext.DbConnectionOptions.Add(dbConnectionModel);
            _dbConnectionContext.SaveChanges();
        }
        
        public int GenerateWatcherId()
        {
            var id = _watcherContext.WatcherOptions.DefaultIfEmpty().Max(note => note == null ? 0 : note.Id);
            return id + 1;
        }
        
        public void CreateWatcherOption(int id, string filter, string includeSubDirectories, string enableRaisingEvents)
        {
            var watcherModel = new WatcherModel {Id = id, Filter = filter, IncludeSubdirectories = includeSubDirectories, EnableRaisingEvents = enableRaisingEvents};
            _watcherContext.WatcherOptions.Add(watcherModel);
            _watcherContext.SaveChanges();
        }
    }
}