#include <map>
#include <fsream>
namespace redis
{
    class RedisConfig
    {
        private:
            map<string, string>_options;
            vector<string> _include;
            vector<string> _bind_addrs;
            vector<map<string, string>> _save;
            string _get_string_value(string key)
            {
                if (options.count(key) > 0)
                {
                    return _options[key];
                }
                return NULL;
            }
            int _get_int_value(string key)
            {
                if (_options.count(key) > 0)
                {
                    return to_int(_options[key]);
                }
                return NULL;
            }
            bool _get_bool_value(string key)
            {
                if (_options.count(key) > 0)
                {
                    if (_options[key] == TYPE_TRUE)
                    {
                        return true;
                    }
                    if (_options[key] == TYPE_FALSE)
                    {
                        return false;
                    }
                }
                return NULL;
            }
        public:
            vector<string> get_include_files()
            {
                return _include;
            }
            bool get_daemonize()
            {
                return _get_bool_value(DAEMONIZE);
            }
            string get_pidfile()
            {
                return _get_string_value(PIDFILE);
            }
            int get_port()
            {
                return _get_int_value(PORT);
            }
            int get_tcp_backlog()
            {
                return _get_int_value(TCP_BACKLOG);
            }
            vectory<string> get_bind_addrs()
            {
                return _bind_addrs;
            }
            string get_unix_socket()
            {
                return _get_string_value(UNIX_SOCKET);
            }
            int get_unix_socket_permission()
            {
                return _get_int_value(UNIX_SOCKET_PERMISSION);
            }
            int get_tcp_keepalive()
            {
                return _get_int_value(TCP_KEEPALIVE);
            }
            string get_log_level()
            {
                return _get_string_value(LOG_LEVEL):
            }
            string get_log_file()
            {
                return _get_string_value(LOG_FILE);
            }
            bool get_syslog_enabled()
            {
                return _get_bool_value(SYSLOG);
            }
           string get_syslog_ident()
           {
               return _get_string_value(SYSLOG_IDENT);
           }
           string get_syslog_facility()
           {
               return _get_string_value(SYSLOG_FACILITY);
           }
           int get_databases()
           {
               return _get_int_value(DATABASES);
           }
           vector<map<string, string>> get_save_intervals()
           {
               return _save;
           }
           bool get_stop_writes_on_bgsave_error()
           {
               return _get_bool_value(STOP_WRITES_ON_BGSAVE_ERROR);
           }
           bool get_rdb_compression()
           {
               return _get_bool_value(RDB_COMPRESSION);
           }
           bool get_rdb_checksum()
           {
               return _get_bool_value(RDB_CHECKSUM);
           }
           string get_db_filename()
           {
               return _get_string_value(DB_FILENAME);
           }
           string get db_dir()
           {
               return _get_string_value(DB_DIR);
           }


    };
}
