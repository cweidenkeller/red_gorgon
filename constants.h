#include <string>
#include <vector>
#ifndef CONSTANTS_H
#define CONSTANTS_H
namespace nova { namespace redis {
static const std::string REDIS_ENABLE = "update-rc.d redis-server enable";
static const std::string REDIS_DISABLE = "update-rc.d redis-server disable";
static const std::string REDIS_STOP = "/etc/init.d/redis-server stop";
static const std::string REDIS_START = "/etc/init.d/redis-server start";
//Redis responses.
static const std::string STRING_RESPONSE = "+";
static const std::string STRING_DESCRIPTION = "String.";
static const std::string ERROR_RESPONSE = "-";
static const std::string ERROR_DESCRIPTION = "Error.";
static const std::string INTEGER_RESPONSE = ":";
static const std::string INTEGER_DESCRIPTION = "Integer.";
static const std::string MULTIPART_RESPONSE = "*";
static const std::string MULTIPART_DESCRIPTION = "Multipart string response.";
static const std::string CERROR_RESPONSE = "cerror";
static const std::string CERROR_DESCRIPTION = "Client error.";
static const std::string UNSUPPORTED_RESPONSE = "unsupported";
static const std::string UNSUPPORTED_DESCRIPTION = "Unsupported response type.";
static const std::string SERROR_RESPONSE = "serror";
static const std::string SERROR_DESCRIPTION = "Redis server error.";
static const std::string STIMEOUT_RESPONSE = "stimeout";
static const std::string STIMEOUT_DESCRIPTION = "Redis server timeout.";
static const std::string CTIMEOUT_RESPONSE = "ctimeout";
static const std::string CTIMEOUT_DESCRIPTION = "Redis client timed out.";
static const std::string CCONNECTED_RESPONSE = "cconnected";
static const std::string CCONNECTED_DESCRIPTION = "Redis client connected.";
static const std::string CCONNECTION_ERR_RESPONSE = "sconnection_err";
static const std::string CCONNECTION_ERR_DESCRIPTION = "Redis client unable "
                                                        "to connect.";
static const std::string CMESSAGE_SENT_RESPONSE = "cmessage_sent";
static const std::string CMESSAGE_SENT_DESCRIPTION = "Redis client"
                                                        "sent message.";
static const std::string CNOTHING_TO_DO_RESPONSE  = "cnothing";
static const std::string CNOTHING_TO_DO_DESCRIPTION = "No command sent "
                                                        "nothing to do.";
//Client options.
static const std::string DEFAULT_REDIS_CONFIG = "/etc/redis/redis.conf";
static const std::string CRLF = "\r\n";
static const int CRLF_LEN = 2;
static const int SOCK_ERROR = -1;
static const int MAX_RETRIES = 100;
static const int FIRST_BYTE_READ = 1;
static const int READ_LEN = 2048;
//This is bad but it is a value that is never used by redis.
//So it means the item does not exist in the vector.
static const int INT_NULL = -42;
//Marked up commands.
static const std::string AUTH_COMMAND = "*2\r\n$4\r\nAUTH\r\n";
static const std::string PING_COMMAND = "*1\r\n$4\r\nPING\r\n";
static const std::string BGSAVE_COMMAND = "*1\r\n$6\r\nBGSAVE\r\n";
static const std::string SAVE_COMMAND  = "*1\r\n$4\r\nSAVE\r\n";
static const std::string LAST_SAVE_COMMAND = "*1\r\n$8\r\nLASTSAVE\r\n";
static const std::string CLIENT_SET_COMMAND = "*3\r\n$6\r\nCLIENT\r\n$7\r\n"
                                                "SETNAME\r\n";
static const std::string CONFIG_SET_COMMAND = "*4\r\n$6\r\nCONFIG\r\n$3\r\n" 
                                                "SET\r\n";
static const std::string CONFIG_GET_COMMAND = "*3\r\n$6\r\nCONFIG\r\n$3\r\n"
                                                "GET\r\n";
static const std::string CONFIG_REWRITE_COMMAND = "*2\r\n$6\r\nCONFIG"
                                                    "\r\n$7\r\nREWRITE\r\n";
static const std::string DSIGN  = "$";
//Config keys.
static const std::string DISABLE = "#";
static const std::string INCLUDE_FILE = "include";
static const std::string DAEMONIZE = "daemonize";
static const std::string PIDFILE = "pidfile";
static const std::string PORT = "port";
static const std::string TCP_BACKLOG = "tcp-backlog";
static const std::string BIND_ADDR = "bind";
static const std::string UNIX_SOCKET = "unixsocket";
static const std::string UNIX_SOCKET_PERMISSION = "unixsocketperm";
static const std::string TCP_KEEPALIVE = "tcp-keepalive";
static const std::string LOG_LEVEL = "loglevel";
static const std::string LOG_FILE = "logfile";
static const std::string SYSLOG = "syslog-enabled";
static const std::string SYSLOG_IDENT = "syslog-ident";
static const std::string SYSLOG_FACILITY = "syslog-facility";
static const std::string DATABASES = "databases";
static const std::string SAVE = "save";
static const std::string STOP_WRITES_ON_BGSAVE_ERROR = "stop-writes-on-bgsave"
                                                        "-error";
static const std::string RDB_COMPRESSION = "rdbcompression";
static const std::string RDB_CHECKSUM = "rdbchecksum";
static const std::string DB_FILENAME = "dbfilename";
static const std::string DB_DIR = "dir";
static const std::string SLAVE_OF = "slaveof";
static const std::string MASTER_AUTH = "masterauth";
static const std::string SLAVE_SERVE_STALE_DATA = "slave-serve-stale-data";
static const std::string SLAVE_READ_ONLY = "slave-read-only";
static const std::string REPL_PING_SLAVE_PERIOD = "repl-ping-slave-period";
static const std::string REPL_TIMEOUT = "repl-timeout";
static const std::string REPL_DISABLE_TCP_NODELAY = "repl-disable-tcp-nodelay";
static const std::string REPL_BACKLOG_SIZE = "repl-backlog-size";
static const std::string REPL_BACKLOG_TTL = "repl-backlog-ttl";
static const std::string SLAVE_PRIORITY = "slave-priority";
static const std::string MIN_SLAVES_TO_WRITE = "min-slaves-to-write";
static const std::string MIN_SLAVES_MAX_LAG = "min-slaves-max-lag";
static const std::string REQUIRE_PASS = "requirepass";
static const std::string RENAME_COMMAND = "rename-command";
static const std::string MAX_CLIENTS = "maxclients";
static const std::string MAX_MEMORY = "maxmemory";
static const std::string MAX_MEMORY_POLICY = "maxmemory-policy";
static const std::string MAX_MEMORY_SAMPLES = "maxmemory-samples";
static const std::string APPEND_ONLY = "appendonly";
static const std::string APPEND_FILENAME = "appendfilename";
static const std::string APPEND_FSYNC = "appendfsync";
static const std::string NO_APPEND_FSYNC_ON_REWRITE = "no-appendfsync-on-"
                                                        "rewrite";
static const std::string AUTO_AOF_REWRITE_PERCENTAGE = "auto-aof-rewrite-"
                                                    "percentage";
static const std::string AUTO_AOF_REWRITE_MIN_SIZE = "auto-aof-rewrite-"
                                                        "min-size";
static const std::string LUA_TIME_LIMIT = "lua-time-limit";
static const std::string SLOWLOG_LOG_SLOWER_THAN = "slowlog-log-slower-"
                                                    "than";
static const std::string SLOWLOG_MAX_LEN = "slowlog-max-len";
static const std::string NOTIFY_KEYSPACE_EVENTS = "notify-keyspace-events";
static const std::string HASH_MAX_ZIP_LIST_ENTRIES = "hash-max-ziplist-"
                                                        "entries";
static const std::string HASH_MAX_ZIP_LIST_VALUE = "hash-max-ziplist-"
                                                    "value";
static const std::string LIST_MAX_ZIP_LIST_ENTRIES = "list-max-ziplist-"
                                                        "entries";
static const std::string LIST_MAX_ZIP_LIST_VALUE = "list-max-ziplist-"
                                                    "value";
static const std::string SET_MAX_INTSET_ENTRIES = "set-max-intset-entries";
static const std::string ZSET_MAX_ZIP_LIST_ENTRIES = "zset-max-ziplist-entries";
static const std::string ZSET_MAX_ZIP_LIST_VALUE = "zset-max-ziplist-value";
static const std::string ACTIVE_REHASHING = "activerehashing";
static const std::string CLIENT_OUTPUT_BUFFER_LIMIT = "client-output-"
                                                        "buffer-limit";
static const std::string HZ = "hz";
static const std::string AOF_REWRITE_INCREMENTAL_FSYNC = "aof-rewrite-"
                                                            "incremental-fsync";
//Config value types.
static const std::string TYPE_STRING = "string";
static const std::string TYPE_INT = "int";
static const std::string TYPE_MEMORY = "memory";
static const std::string TYPE_BYTES = "bytes";
static const std::string TYPE_KILOBYTES = "kilobytes";
static const std::string TYPE_MEGABYTES = "megabytes";
static const std::string TYPE_GIGABYTES = "gigabytes";
static const std::string TYPE_BOOL = "bool";
static const std::string TYPE_TRUE = "yes";
static const std::string TYPE_FALSE = "no";
//Save keys.
static const std::string SAVE_SECONDS = "seconds";
static const std::string SAVE_CHANGES = "changes";
//Loglevel.
static const std::string LOG_LEVEL_DEBUG = "debug";
static const std::string LOG_LEVEL_VERBOSE = "verbose";
static const std::string LOG_LEVEL_NOTICE = "notice";
static const std::string LOG_LEVEL_WARNING = "warning";
//Slave of keys.
static const std::string MASTER_IP = "master_ip";
static const std::string MASTER_PORT = "master_port";
//Rename command keys.
static const std::string RENAMED_COMMAND = "renamed_command";
static const std::string NEW_COMMAND_NAME = "new_command_name";
//Max memory policy values.
static const std::string VOLATILE_LRU = "volatile-lru";
static const std::string ALLKEYS_LRU = "allkeys-lru";
static const std::string VOLATILE_RANDOM = "volatile-random";
static const std::string ALLKEYS_RANDOM = "allkeys-random";
static const std::string VOLATILE_TTL = "volatile-ttl";
static const std::string NO_EVICTION = "noevection";
//Append sync values.
static const std::string APPEND_FSYNC_ALWAYS = "always";
static const std::string APPEND_FSYNC_EVERYSEC = "everysec";
static const std::string APPEND_FSYNC_NO = "no";
//Client output buffer limit class values.
static const std::string NORMAL_CLIENTS = "normal";
static const std::string SLAVE_CLIENTS = "slave";
static const std::string PUBSUB_CLIENTS = "pubsub";
//Client output buffer limit keys.
static const std::string CLIENT_BUFFER_LIMIT_CLASS = "class";
static const std::string CLIENT_BUFFER_LIMIT_HARD_LIMIT = "hard_limit";
static const std::string CLIENT_BUFFER_LIMIT_SOFT_LIMIT = "soft_limit";
static const std::string CLIENT_BUFFER_LIMIT_SOFT_SECONDS = "soft_seconds";
//Memory units.
static const std::string KILOBYTES = "kb";
static const std::string MEGABYTES = "mb";
static const std::string GIGABYTES = "gb";
//Redis key command names.
static const std::string COMMAND_DEL = "DEL";
static const std::string COMMAND_DUMP = "DUMP";
static const std::string COMMAND_EXISTS = "EXISTS";
static const std::string COMMAND_EXPIRE = "EXPIRE";
static const std::string COMMAND_EXPIRE_AT = "EXPIREAT";
static const std::string COMMAND_KEYS = "KEYS";
static const std::string COMMAND_MIGRATE = "MIGRATE";
static const std::string COMMAND_MOVE = "MOVE";
static const std::string COMMAND_OBJECT = "OBJECT";
static const std::string COMMAND_PERSIST = "PERSIST";
static const std::string COMMAND_PEXIPRE = "PEXPIRE";
static const std::string COMMAND_PEXPIRE_AT = "PEXPIREAT";
static const std::string COMMAND_PTTL = "PTTL";
static const std::string COMMAND_RANDOMKEY = "RANDOMKEY";
static const std::string COMMAND_RENAME = "RENAME";
static const std::string COMMAND_RENAMENX = "RENAMENX";
static const std::string COMMAND_RESTORE = "RESTORE";
static const std::string COMMAND_SORT = "SORT";
static const std::string COMMAND_TTL = "TTL";
static const std::string COMMAND_TYPE = "TYPE";
static const std::string COMMAND_SCAN = "SCAN";
//Redis string command names.
static const std::string COMMAND_APPEND = "APPEND";
static const std::string COMMAND_BITCOUNT = "BITCOUT";
static const std::string COMMAND_BITOP = "BITOP";
static const std::string COMMAND_DECR = "DECR";
static const std::string COMMAND_DECR_BY = "DECRBY";
static const std::string COMMAND_GET = "GET";
static const std::string COMMAND_GET_BIT = "GETGIT";
static const std::string COMMAND_GET_RANGE = "GETRANGE";
static const std::string COMMAND_GET_SET = "GETSET";
static const std::string COMMAND_INCR = "INCR";
static const std::string COMMAND_INCR_BY = "INCRBY";
static const std::string COMMAND_INCR_BY_FLOAT = "INCRBYFLOAT";
static const std::string COMMAND_MGET = "MGET";
static const std::string COMMAND_MSET = "MSET";
static const std::string COMMAND_MSETNX = "MSETNX";
static const std::string COMMAND_PSETEX = "PSETEX";
static const std::string COMMAND_SET = "SET";
static const std::string COMMAND_SET_BIT = "SETBIT";
static const std::string COMMAND_SETEX = "SETEX";
static const std::string COMMAND_SET_RANGE = "SETRANGE";
static const std::string COMMAND_STRLEN = "STRLEN";
//Redis hash command names.
static const std::string COMMAND_HDEL = "HDEL";
static const std::string COMMAND_HEXISTS = "HEXISTS";
static const std::string COMMAND_HGET = "HGET";
static const std::string COMMAND_HGET_ALL = "HGETALL";
static const std::string COMMAND_HINCR_BY = "HINCRBY";
static const std::string COMMAND_HINCR_BY_FLOAT = "HINCRBYFLOAT";
static const std::string COMMAND_HKEYS = "HKEYS";
static const std::string COMMAND_HLEN = "HLEN";
static const std::string COMMAND_HMGET = "HMGET";
static const std::string COMMAND_HMSET = "HMSET";
static const std::string COMMAND_HSET = "HSET";
static const std::string COMMAND_HSETNX = "HSETNX";
static const std::string COMMAND_HVALS = "HVALS";
static const std::string COMMAND_HSCAN = "HSCAN";
//Redis list command names.
static const std::string COMMAND_BLPOP = "BLPOP";
static const std::string COMMAND_BRPOP = "BRPOP";
static const std::string COMMAND_BRPOPLPUSH = "BRPOPLPUSH";
static const std::string COMMAND_LINDEX = "LINDEX";
static const std::string COMMAND_LINSTER = "LINSTER";
static const std::string COMMAND_LLEN = "LLEN";
static const std::string COMMAND_LPOP = "LPOP";
static const std::string COMMAND_LPUSH = "LPUSH";
static const std::string COMMAND_LPUSHX = "LPUSHX";
static const std::string COMMAND_LRANGE = "LRANGE";
static const std::string COMMAND_LREM = "LREM";
static const std::string COMMAND_LSET = "LSET";
static const std::string COMMAND_LTRIM = "LTRIM";
static const std::string COMMAND_RPOP = "RPOP";
static const std::string COMMAND_RPOPLPUSH = "RPOPLPUSH";
static const std::string COMMAND_RPUSH = "RPUSH";
static const std::string COMMAND_RPUSHX = "RPUSHX";
//Redis set command names.
static const std::string COMMAND_SADD = "SADD";
static const std::string COMMAND_SCARD = "SCARD";
static const std::string COMMAND_SDIFF = "SDIFF";
static const std::string COMMAND_SDIFFSTORE = "SDIFFSTORE";
static const std::string COMMAND_SINTER = "SINTER";
static const std::string COMMAND_SINTERSORE = "SINTERSTORE";
static const std::string COMMAND_SISMEMEBER = "SISMEMBER";
static const std::string COMMAND_SMEMBERS = "SMEMBERS";
static const std::string COMMAND_SMOVE = "SMOVE";
static const std::string COMMAND_SPOP = "SPOP";
static const std::string COMMAND_SRANDMEMEBER = "SRANDMEMEBER";
static const std::string COMMAND_SREM = "SREM";
static const std::string COMMAND_SUNION = "SUNION";
static const std::string COMMAND_SUINIONSTORE = "SUNIONSTORE";
static const std::string COMMAND_SSCAN = "SSCAN";
//Redis sorted set command names.
static const std::string COMMAND_ZADD = "ZADD";
static const std::string COMMAND_ZCARD = "ZCARD";
static const std::string COMMAND_ZCOUNT = "ZCOUNT";
static const std::string COMMAND_ZINCR_BY = "ZINCRBY";
static const std::string COMMAND_ZINTERSTORE = "ZINTERSTORE";
static const std::string COMMAND_ZRANGE = "ZRANGE";
static const std::string COMMAND_ZRANGEBYSCORE = "ZRANGEBYSCORE";
static const std::string COMMAND_ZRANK = "ZRANK";
static const std::string COMMAND_ZREM = "ZREM";
static const std::string COMMAND_ZREMRANGEBYRANK = "ZREMRANGEBYRANK";
static const std::string COMMAND_ZREMRANGEBYSCORE = "ZREMRANGEBYSCORE";
static const std::string COMMAND_ZREVRANK = "ZREVERANK";
static const std::string COMMAND_ZSCORE = "ZSCORE";
static const std::string COMMAND_ZUNIONSTORE = "ZUNIONSTORE";
static const std::string COMMAND_ZSCAN = "ZSCAN";
//Redis pub/sub command names.
static const std::string COMMAND_PSUBSCRIBE = "PSUBSCRIBE";
static const std::string COMMAND_PUBSUB = "PUBSUB";
static const std::string COMMAND_PUBLISH = "PUBLISH";
static const std::string COMMAND_PUNSUBSCRIBE = "PUNSUBSCRIBE";
static const std::string COMMAND_SUBSCRIBE = "SUBSCRIBE";
static const std::string COMMAND_UNSUBSCRIBE = "UNSUBSCRIBE";
//Redis transaction command names.
static const std::string COMMAND_DISCARD = "DISCARD";
static const std::string COMMAND_EXEC = "EXEC";
static const std::string COMMAND_MULTI = "MULTI"; 
static const std::string COMMAND_UNWATCH = "UNWATCH";
static const std::string COMMAND_WATCH = "WATCH";
//Redis scripting command namees.
static const std::string COMMAND_EVAL = "EVAL";
static const std::string COMMAND_EVALSHA = "EVALSHA";
static const std::string COMMAND_SCRIPT_EXISTS = "SCRIPT EXISTS";
static const std::string COMMAND_SCRIPT_FLUSH = "SCRIPT FLUSH";
static const std::string COMMAND_SCRIPT_KILL = "SCRIPT KILL";
static const std::string COMMAND_SCRIPT_LOAD = "SCRIPT LOAD";
//Redis connection command names.
static const std::string COMMAND_AUTH = "AUTH";
static const std::string COMMAND_ECHO = "ECHO";
static const std::string COMMAND_PING = "PING";
static const std::string COMMAND_QUIT = "QUIT";
static const std::string COMMAND_SELECT = "SELECT";
//Redis server command names.
static const std::string COMMAND_BGREWRITEAOF = "BGREWRITEAOF";
static const std::string COMMAND_BGSAVE = "BGSAVE";
static const std::string COMMAND_CLIENT_KILL = "CLIENT KILL";
static const std::string COMMAND_CLIENT_LIST = "CLIENT LIST";
static const std::string COMMAND_CLIENT_GETNAME = "CLIENT GETNAME";
static const std::string COMMAND_CLIENT_SETNAME = "CLIENT SETNAME";
static const std::string COMMAND_CONFIG_GET = "CONFIG GET";
static const std::string COMMAND_CONFIG_REWRITE = "CONFIG REWRITE";
static const std::string COMMAND_CONFIG_SET = "CONFIG SET";
static const std::string COMMAND_CONFIG_RESETSTAT = "CONFIG RESETSTAT";
static const std::string COMMAND_DBSIZE = "DBSIZE";
static const std::string COMMAND_DEBUG_OBJECT = "DEBUG OBJECT";
static const std::string COMMAND_DEBUG_SEGFAULT = "DEBUG SEGFAULT";
static const std::string COMMAND_FLUSHALL = "FLUSHALL";
static const std::string COMMAND_FLUSHDB = "FLUSHDB";
static const std::string COMMAND_INFO = "INFO";
static const std::string COMMAND_LASTSAVE = "LASTSAVE";
static const std::string COMMAND_MONITOR = "MONITOR";
static const std::string COMMAND_SAVE = "SAVE";
static const std::string COMMAND_SHUTDOWN = "SHUTDOWN";
static const std::string COMMAND_SLAVEOF = "SLAVEOF";
static const std::string COMMAND_SLOWLOG = "SLOWLOG";
static const std::string COMMAND_SYNC = "SYNC";
static const std::string COMMAND_TIME = "TIME";
//Vector for config file parsing. I could probably do this better.
std::vector<std::string>get_config_key_vector()
{
    std::vector<std::string> config_keys;
    config_keys.push_back(INCLUDE_FILE);
    config_keys.push_back(DAEMONIZE);
    config_keys.push_back(PIDFILE);
    config_keys.push_back(PORT);
    config_keys.push_back(TCP_BACKLOG);
    config_keys.push_back(BIND_ADDR);
    config_keys.push_back(UNIX_SOCKET);
    config_keys.push_back(UNIX_SOCKET_PERMISSION);
    config_keys.push_back(TCP_KEEPALIVE);
    config_keys.push_back(LOG_LEVEL);
    config_keys.push_back(LOG_FILE);
    config_keys.push_back(SYSLOG);
    config_keys.push_back(SYSLOG_IDENT);
    config_keys.push_back(SYSLOG_FACILITY);
    config_keys.push_back(DATABASES);
    config_keys.push_back(SAVE);
    config_keys.push_back(STOP_WRITES_ON_BGSAVE_ERROR);
    config_keys.push_back(RDB_COMPRESSION);
    config_keys.push_back(RDB_CHECKSUM);
    config_keys.push_back(DB_FILENAME);
    config_keys.push_back(DB_DIR);
    config_keys.push_back(SLAVE_OF);
    config_keys.push_back(MASTER_AUTH);
    config_keys.push_back(SLAVE_SERVE_STALE_DATA);
    config_keys.push_back(SLAVE_READ_ONLY);
    config_keys.push_back(REPL_PING_SLAVE_PERIOD);
    config_keys.push_back(REPL_TIMEOUT);
    config_keys.push_back(REPL_DISABLE_TCP_NODELAY);
    config_keys.push_back(REPL_BACKLOG_SIZE);
    config_keys.push_back(REPL_BACKLOG_TTL);
    config_keys.push_back(SLAVE_PRIORITY);
    config_keys.push_back(MIN_SLAVES_TO_WRITE);
    config_keys.push_back(MIN_SLAVES_MAX_LAG);
    config_keys.push_back(REQUIRE_PASS);
    config_keys.push_back(RENAME_COMMAND);
    config_keys.push_back(MAX_CLIENTS);
    config_keys.push_back(MAX_MEMORY);
    config_keys.push_back(MAX_MEMORY_POLICY);
    config_keys.push_back(MAX_MEMORY_SAMPLES);
    config_keys.push_back(APPEND_ONLY);
    config_keys.push_back(APPEND_FILENAME);
    config_keys.push_back(APPEND_FSYNC);
    config_keys.push_back(NO_APPEND_FSYNC_ON_REWRITE);
    config_keys.push_back(AUTO_AOF_REWRITE_PERCENTAGE);
    config_keys.push_back(AUTO_AOF_REWRITE_MIN_SIZE);
    config_keys.push_back(LUA_TIME_LIMIT);
    config_keys.push_back(SLOWLOG_LOG_SLOWER_THAN);
    config_keys.push_back(SLOWLOG_MAX_LEN);
    config_keys.push_back(NOTIFY_KEYSPACE_EVENTS);
    config_keys.push_back(HASH_MAX_ZIP_LIST_ENTRIES);
    config_keys.push_back(HASH_MAX_ZIP_LIST_VALUE);
    config_keys.push_back(LIST_MAX_ZIP_LIST_ENTRIES);
    config_keys.push_back(LIST_MAX_ZIP_LIST_VALUE);
    config_keys.push_back(SET_MAX_INTSET_ENTRIES);
    config_keys.push_back(ZSET_MAX_ZIP_LIST_ENTRIES);
    config_keys.push_back(ZSET_MAX_ZIP_LIST_VALUE);
    config_keys.push_back(ACTIVE_REHASHING);
    config_keys.push_back(CLIENT_OUTPUT_BUFFER_LIMIT);
    config_keys.push_back(HZ);
    config_keys.push_back(AOF_REWRITE_INCREMENTAL_FSYNC);
    return config_keys;
}
}}//end of nova::redis
#endif /* CONSTANTS_H */
