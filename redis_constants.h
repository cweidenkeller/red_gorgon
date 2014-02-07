#include <string>
using namespace std;
namespace redis
{
    //Redis responses.
    static const string STRING_RESPONSE = "+";
    static const string STRING_DESCRIPTION = "String.";
    static const string ERROR_RESPONSE = "-";
    static const string ERROR_DESCRIPTION = "Error.";
    static const string INTEGER_RESPONSE = ":";
    static const string INTEGER_DESCRIPTION = "Integer.";
    static const string MULTIPART_RESPONSE = "*";
    static const string MULTIPART_DESCRIPTION = "Multipart string response.";
    static const string CERROR_RESPONSE = "cerror";
    static const string CERROR_DESCRIPTION = "Client error.";
    static const string UNSUPPORTED_RESPONSE = "unsupported";
    static const string UNSUPPORTED_DESCRIPTION = "Unsupported response type.";
    static const string SERROR_RESPONSE = "serror";
    static const string SERROR_DESCRIPTION = "Redis server error.";
    static const string STIMEOUT_RESPONSE = "stimeout";
    static const string STIMEOUT_DESCRIPTION = "Redis server timeout.";
    static const string CTIMEOUT_RESPONSE = "ctimeout";
    static const string CTIMEOUT_DESCRIPTION = "Redis client timed out.";
    static const string CCONNECTED_RESPONSE = "cconnected";
    static const string CCONNECTED_DESCRIPTION = "Redis client connected.";
    static const string CCONNECTION_ERR_RESPONSE = "sconnection_err";
    static const string CCONNECTION_ERR_DESCRIPTION = "Redis client unable "
                                                       "to connect.";
    static const string CMESSAGE_SENT_RESPONSE = "cmessage_sent";
    static const string CMESSAGE_SENT_DESCRIPTION = "Redis client"
                                                    "sent message.";
    static const string CNOTHING_TO_DO_RESPONSE  = "cnothing";
    static const string CNOTHING_TO_DO_DESCRIPTION = "No command sent "
                                                     "nothing to do.";
    //Client options.
    static const string DEFAULT_REDIS_CONFIG = "/etc/redis/redis.conf";
    static const string CRLF = "\r\n";
    static const int CRLF_LEN = 2;
    static const int SOCK_ERROR = -1;
    static const int MAX_RETRIES = 100;
    static const int FIRST_BYTE_READ = 1;
    static const int READ_LEN = 2048;
    //Marked up commands.
    static const string AUTH_COMMAND = "*2\r\n$4\r\nAUTH\r\n";
    static const string PING_COMMAND = "*1\r\n$4\r\nPING\r\n";
    static const string BGSAVE_COMMAND = "*1\r\n$6\r\nBGSAVE\r\n";
    static const string SAVE_COMMAND  = "*1\r\n$4\r\nSAVE\r\n";
    static const string LAST_SAVE_COMMAND = "*1\r\n$8\r\nLASTSAVE\r\n";
    static const string CLIENT_SET_COMMAND = "*3\r\n$6\r\nCLIENT\r\n$7\r\n"
                                             "SETNAME\r\n";
    static const string CONFIG_SET_COMMAND = "*4\r\n$6\r\nCONFIG\r\n$3\r\n" 
                                             "SET\r\n";
    static const string CONFIG_GET_COMMAND = "*3\r\n$6\r\nCONFIG\r\n$3\r\n"
                                             "GET\r\n";
    static const string CONFIG_REWRITE_COMMAND = "*2\r\n$6\r\nCONFIG"
                                                "\r\n$7\r\nREWRITE\r\n";
    static const string DSIGN  = "$";
    //Config keys.
    static const string DISABLE = "#";
    static const string INCLUDE_FILE = "include";
    static const string DAEMONIZE = "daemonize";
    static const string PIDFILE = "pidfile";
    static const string PORT = "port";
    static const string TCP_BACKLOG = "tcp-backlog";
    static const string BIND_ADDR = "bind";
    static const string UNIX_SOCKET = "unixsocket";
    static const string UNIX_SOCKET_PERMISSION "unixsocketperm";
    static const string TCP_KEEPALIVE = "tcp-keepalive";
    static const string LOG_LEVEL = "loglevel";
    static const string LOG_FILE = "logfile";
    static const string SYSLOG = "syslog-enabled";
    static const string SYSLOG_IDENT = "syslog-ident";
    static const string SYSLOG_FACILITY = "syslog-facility";
    static const string DATABASES = "databases";
    static const string SAVE = "save";
    static const string STOP_WRITES_ON_BGSAVE_ERROR = "stop-writes-on-bgsave"
                                                      "-error";
    static const string RDB_COMPRESSION = "rdbcompression";
    static const string RDB_CHECKSUM = "rdbchecksum";
    static const string DB_FILENAME = "dbfilename";
    static const string DB_DIR = "dir";
    static const string SLAVE_OF = "slaveof";
    static const string MASTER_AUTH = "masterauth";
    static const string SLAVE_SERVER_STALE_DATA = "slave-serve-stale-data";
    static const string SLAVE_READ_ONLY = "slave-read-only";
    static const string REPL_PING_SLAVE_PERIOD = "repl-ping-slave-period";
    static const string REPL_TIMEOUT = "repl-timeout";
    static const string REPL_DISABLE_TCP_NODELAY = "repl-disable-tcp-nodelay";
    static const string REPL_BACKLOG_SIZE = "repl-backlog-size";
    static const string REPL_BACKLOG_TTL = "repl-backlog-ttl";
    static const string SLAVE_PRIORITY = "slave-priority";
    static const string MIN_SLAVES_TO_WRITE = "min-slaves-to-write";
    static const string MIN_SLAVES_MAX_LAG = "min-slaves-max-lag";
    static const string REQUIRE_PASS = "requirepass";
    static const string RENAME_COMMAND = "rename-command";
    static const string MAX_CLIENTS = "maxclients";
    static const string MAX_MEMORY = "maxmemory";
    static const string MAX_MEMORY_POLICY = "maxmemory-policy";
    static const string MAX_MEMORY_SAMPLES = "maxmemory-samples";
    static const string APPEND_ONLY = "appendonly";
    static const string APPEND_FILENAME = "appendfilename";
    static const string APPEND_FSYNC = "appendfsync";
    static const string NO_APPEND_FSYNC_ON_REWRITE = "no-appendfsync-on-"
                                                     "rewrite";
    static const string AUTO_AOF_REWRITE_PERCENTAGE = "auto-aof-rewrite-"
                                                      "percentage";
    static const string AUTO_AOF_REWRITE_MIN_SIZE = "auto-aof-rewrite-"
                                                    "min-size";
    static const string LUA_TIME_LIMIT = "lua-time-limit";
    static const string SLOW_LOG_LOG_SLOWER_THAN = "slowlog-log-slower-"
                                                    "than";
    static const string SLOW_LOG_MAX_LEN = "slowlog-max-len";
    static const string NOTIFY_KEYSPACE_EVENTS = "notify-keyspace-events";
    static const string HASH_MAX_ZIP_LIST_ENTRIES = "hash-max-ziplist-"
                                                    "entries";
    static const string HAS_MAX_ZIP_LIST_VAULE = "hash-max-ziplist-"
                                                 "value";
    static const string LIST_MAX_ZIP_LIST_ENTRIES = "list-max-ziplist-"
                                                    "entries";
    static const string LIST_MAX_ZIP_LIST_VALUE = "list-max-ziplist-"
                                                  "value";
    static const string SET_MAX_INTSET_ENTRIES = "set-max-intset-entries";
    static const string ZSET_MAX_ZIP_LIST_ENTRIES = "zset-max-ziplist-entries";
    static const string ZSET_MAX_ZIP_LIST_VALUE = "zset-max-ziplist-value";
    static const string ACTIVE_REHASHING = "activerehashing";
    static const string CLIENT_OUTPUT_BUFFER_LIMIT = "client-output-"
                                                     "buffer-limit";
    static const string HZ = "hz";
    static const string AOF_REWRITE_INCREMENTAL_FSYNC = "aof-rewrite-"
                                                        "incremental-fsync";
    //Config value types.
    static const string TYPE_STRING = "string";
    static const string TYPE_INT = "int";
    static const string TYPE_MEMORY = "memory";
    static const string TYPE_BYTES = "bytes";
    static const string TYPE_KILOBYTES = "kilobytes":
    static const string TYPE_MEGABYTES = "megabytes":
    static const string TYPE_GIGABYTES = "gigabytes";
    static const string TYPE_BOOL = "bool";
    static const string TYPE_TRUE = "yes";
    static const string TYPE_FALSE = "no";
    //Save keys.
    static const string SAVE_SECONDS = "seconds";
    static const string SAVE_CHANGES = "changes";
    //Loglevel.
    static const string LOG_LEVEL_DEBUG = "debug";
    static const string LOG_LEVEL_VERBOSE = "verbose";
    static const string LOG_LEVEL_NOTICE = "notice";
    static const string LOG_LEVEL_WARNING = "warning";
    //Slave of keys.
    static const string MASTER_IP = "master_ip";
    static const string MASTER_PORT = "master_port";
    //Rename command keys.
    static const string RENAMED_COMMAND = "renamed_command";
    static const string NEW_COMMAND_NAME = "new_command_name";
    //Max memory policy values.
    static const string VOLATILE_LRU = "volatile-lru";
    static const string ALLKEYS_LRU = "allkeys-lru";
    static const string VOLATILE_RANDOM = "volatile-random";
    static const string ALLKEYS_RANDOM = "allkeys-random";
    static const string VOLATILE_TTL = "volatile-ttl";
    static const string NO_EVICTION = "noevection";
    //Append sync values.
    static const string APPEND_FSYNC_ALWAYS = "always";
    static const string APPEND_FSYNC_EVERYSEC = "everysec";
    static const string APPEND_FSYNC_NO = "no";
    //Client output buffer limit class values.
    static const string NORMAL_CLIENTS = "normal";
    static const string SLAVE_CLIENTS = "slave";
    static const string PUBSUB_CLIENTS = "pubsub";
    //Client output buffer limit keys.
    static const string CLIENT_BUFFER_LIMIT_CLASS = "class";
    static const string CLIENT_BUFFER_LIMIT_HARD_LIMIT = "hard_limit";
    static const string CLIENT_BUFFER_LIMIT_SOFT_LIMIT = "soft_limit";
    static const string CLIENT_BUFFER_LIMIT_SOFT_SECONDS = "soft_seconds";
    //Memory units.
    static const string KILOBYTES = "kb";
    static const string MEGABYTES = "mb";
    static const string GIGABYTES = "gb";
    //Redis key command names.
    static const string COMMAND_DEL = "DEL";
    static const string COMMAND_DUMP = "DUMP";
    static const string COMMAND_EXISTS = "EXISTS";
    static const string COMMAND_EXPIRE = "EXPIRE";
    static const string COMMAND_EXPIRE_AT = "EXPIREAT";
    static const string COMMAND_KEYS = "KEYS";
    static const string COMMAND_MIGRATE = "MIGRATE";
    static const string COMMAND_MOVE = "MOVE";
    static const string COMMAND_OBJECT = "OBJECT";
    static const string COMMAND_PERSIST = "PERSIST";
    static const string COMMAND_PEXIPRE = "PEXPIRE";
    static const string COMMAND_PEXPIRE_AT = "PEXPIREAT";
    static const string COMMAND_PTTL = "PTTL";
    static const string COMMAND_RANDOMKEY = "RANDOMKEY";
    static const string COMMAND_RENAME = "RENAME";
    static const string COMMAND_RENAMENX = "RENAMENX";
    static const string COMMAND_RESTORE = "RESTORE";
    static const string COMMAND_SORT = "SORT";
    static const string COMMAND_TTL = "TTL";
    static const string COMMAND_TYPE = "TYPE";
    static const string COMMAND_SCAN = "SCAN";
    //Redis string command names.
    static const string COMMAND_APPEND = "APPEND";
    static const string COMMAND_BITCOUNT = "BITCOUT";
    static const string COMMAND_BITOP = "BITOP";
    static const string COMMAND_DECR = "DECR";
    static const string COMMAND_DECR_BY = "DECRBY";
    static const string COMMAND_GET = "GET";
    static const string COMMAND_GET_BIT = "GETGIT";
    static const string COMMAND_GET_RANGE = "GETRANGE";
    static const string COMMAND_GET_SET = "GETSET";
    static const string COMMAND_INCR = "INCR";
    static const string COMMAND_INCR_BY = "INCRBY";
    static const string COMMAND_INCR_BY_FLOAT = "INCRBYFLOAT";
    static const string COMMAND_MGET = "MGET";
    static const string COMMAND_MSET = "MSET";
    static const string COMMAND_MSETNX = "MSETNX";
    static const string COMMAND_PSETEX = "PSETEX";
    static const string COMMAND_SET = "SET";
    static const string COMMAND_SET_BIT = "SETBIT";
    static const string COMMAND_SETEX = "SETEX";
    static const string COMMAND_SET_RANGE = "SETRANGE";
    static const string COMMAND_STRLEN = "STRLEN";
    //Redis hash command names.
    static const string COMMAND_HDEL = "HDEL";
    static const string COMMAND_HEXISTS = "HEXISTS";
    static const string COMMAND_HGET = "HGET";
    static const string COMMAND_HGET_ALL = "HGETALL";
    static const string COMMAND_HINCR_BY = "HINCRBY";
    static const string COMMAND_HINCR_BY_FLOAT = "HINCRBYFLOAT";
    static const string COMMAND_HKEYS = "HKEYS";
    static const string COMMAND_HLEN = "HLEN";
    static const string COMMAND_HMGET = "HMGET";
    static const string COMMAND_HMSET = "HMSET";
    static const string COMMAND_HSET = "HSET";
    static const string COMMAND_HSETNX = "HSETNX";
    static const string COMMAND_HVALS = "HVALS";
    static const string COMMAND_HSCAN = "HSCAN";
    //Redis list command names.
    static const string COMMAND_BLPOP = "BLPOP";
    static const string COMMAND_BRPOP = "BRPOP";
    static const string COMMAND_BRPOPLPUSH = "BRPOPLPUSH";
    static const string COMMAND_LINDEX = "LINDEX";
    static const string COMMAND_LINSTER = "LINSTER";
    static const string COMMAND_LLEN = "LLEN";
    static const string COMMAND_LPOP = "LPOP";
    static const string COMMAND_LPUSH = "LPUSH";
    static const string COMMAND_LPUSHX = "LPUSHX";
    static const string COMMAND_LRANGE = "LRANGE";
    static const string COMMAND_LREM = "LREM";
    static const string COMMAND_LSET = "LSET";
    static const string COMMAND_LTRIM = "LTRIM";
    static const string COMMAND_RPOP = "RPOP";
    static const string COMMAND_RPOPLPUSH = "RPOPLPUSH";
    static const string COMMAND_RPUSH = "RPUSH";
    static const string COMMAND_RPUSHX = "RPUSHX";
    //Redis set command names.
    static const string COMMAND_SADD = "SADD";
    static const string COMMAND_SCARD = "SCARD";
    static const string COMMAND_SDIFF = "SDIFF";
    static const string COMMAND_SDIFFSTORE = "SDIFFSTORE";
    static const string COMMAND_SINTER = "SINTER";
    static const string COMMAND_SINTERSORE = "SINTERSTORE";
    static const string COMMAND_SISMEMEBER = "SISMEMBER";
    static const string COMMAND_SMEMBERS = "SMEMBERS";
    static const string COMMAND_SMOVE = "SMOVE";
    static const string COMMAND_SPOP = "SPOP";
    static const string COMMAND_SRANDMEMEBER = "SRANDMEMEBER";
    static const string COMMAND_SREM = "SREM";
    static const string COMMAND_SUNION = "SUNION";
    static const string COMMAND_SUINIONSTORE = "SUNIONSTORE";
    static const string COMMAND_SSCAN = "SSCAN";
    //Redis sorted set command names.
    static const string COMMAND_ZADD = "ZADD";
    static const string COMMAND_ZCARD = "ZCARD";
    static const string COMMAND_ZCOUNT = "ZCOUNT";
    static const string COMMAND_ZINCR_BY = "ZINCRBY";
    static const string COMMAND_ZINTERSTORE = "ZINTERSTORE";
    static const string COMMAND_ZRANGE = "ZRANGE";
    static const string COMMAND_ZRANGEBYSCORE = "ZRANGEBYSCORE";
    static const string COMMAND_ZRANK = "ZRANK";
    static const string COMMAND_ZREM = "ZREM";
    static const string COMMAND_ZREMRANGEBYRANK = "ZREMRANGEBYRANK";
    static const string COMMAND_ZREMRANGEBYSCORE = "ZREMRANGEBYSCORE";
    static const string COMMAND_ZREVRANK = "ZREVERANK";
    static const string COMMAND_ZSCORE = "ZSCORE";
    static const string COMMAND_ZUNIONSTORE = "ZUNIONSTORE";
    static const string COMMAND_ZSCAN = "ZSCAN";
    //Redis pub/sub command names.
    static const string COMMAND_PSUBSCRIBE = "PSUBSCRIBE";
    static const string COMMAND_PUBSUB = "PUBSUB";
    static const string COMMAND_PUBLISH = "PUBLISH";
    static const string COMMAND_PUNSUBSCRIBE = "PUNSUBSCRIBE";
    static const string COMMAND_SUBSCRIBE = "SUBSCRIBE";
    static const string COMMAND_UNSUBSCRIBE = "UNSUBSCRIBE";
    //Redis transaction command names.
    static const string COMMAND_DISCARD = "DISCARD";
    static const string COMMAND_EXEC = "EXEC";
    static const string COMMAND_MULTI = "MULTI"; 
    static const string COMMAND_UNWATCH = "UNWATCH";
    static const string COMMAND_WATCH = "WATCH";
    //Redis scripting command namees.
    static const string COMMAND_EVAL = "EVAL";
    static const string COMMAND_EVALSHA = "EVALSHA";
    static const string COMMAND_SCRIPT_EXISTS = "SCRIPT EXISTS";
    static const string COMMAND_SCRIPT_FLUSH = "SCRIPT FLUSH";
    static const string COMMAND_SCRIPT_KILL = "SCRIPT KILL";
    static const string COMMAND_SCRIPT_LOAD = "SCRIPT LOAD";
    //Redis connection command names.
    static const string COMMAND_AUTH = "AUTH";
    static const string COMMAND_ECHO = "ECHO";
    static const string COMMAND_PING = "PING";
    static const string COMMAND_QUIT = "QUIT";
    static const string COMMAND_SELECT = "SELECT";
    //Redis server command names.
    static const string COMMAND_BGREWRITEAOF = "BGREWRITEAOF";
    static const string COMMAND_BGSAVE = "BGSAVE";
    static const string COMMAND_CLIENT_KILL = "CLIENT KILL";
    static const string COMMAND_CLIENT_LIST = "CLIENT LIST";
    static const string COMMAND_CLIENT_GETNAME = "CLIENT GETNAME";
    static const string COMMAND_CLIENT_SETNAME = "CLIENT SETNAME";
    static const string COMMAND_CONFIG_GET = "CONFIG GET";
    static const string COMMAND_CONFIG_REWRITE = "CONFIG REWRITE";
    static const string COMMAND_CONFIG_SET = "CONFIG SET";
    static const string COMMAND_CONFIG_RESETSTAT = "CONFIG RESETSTAT";
    static const string COMMAND_DBSIZE = "DBSIZE";
    static const string COMMAND_DEBUG_OBJECT = "DEBUG OBJECT";
    static const string COMMAND_DEBUG_SEGFAULT = "DEBUG SEGFAULT";
    static const string COMMAND_FLUSHALL = "FLUSHALL";
    static const string COMMAND_FLUSHDB = "FLUSHDB";
    static const string COMMAND_INFO = "INFO";
    static const string COMMAND_LASTSAVE = "LASTSAVE";
    static const string COMMAND_MONITOR = "MONITOR";
    static const string COMMAND_SAVE = "SAVE";
    static const string COMMAND_SHUTDOWN = "SHUTDOWN";
    static const string COMMAND_SLAVEOF = "SLAVEOF";
    static const string COMMAND_SLOWLOG = "SLOWLOG";
    static const string COMMAND_SYNC = "SYNC";
    static const string COMMAND_TIME = "TIME";
}
