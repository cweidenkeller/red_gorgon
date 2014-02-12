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
            map<string, string> _slave_of;
            vector<map<string, string> _renamed_commands;
            vector<map<string, string> _client_output_buffer_limit;
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
            vector<string> get_bind_addrs()
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
            string get_db_dir()
            {
                return _get_string_value(DB_DIR);
            }
            map<string, string>get_slave_of()
            {
                return _slave_of;
            }
            string get_master_auth()
            {
                return _get_string_value(MASTER_AUTH);
            }
            bool get_slave_serve_stale_data()
            {
                return _get_bool_value(SLAVE_SERVE_STALE_DATA);
            }
            bool get_slave_read_only()
            {
                return _get_bool_value(SLAVE_READ_ONLY);
            }
            int get_repl_ping_slave_period()
            {
                return _get_int_value(REPL_PING_SALVE_PERIOD);
            }
            int get_repl_timeout()
            {
                return _get_int_value(REPL_TIMEOUT);
            }
            bool get_repl_disable_tcp_nodelay()
            {
                return _get_bool_value(REPL_DISABLE_TCP_NODELAY);
            }
            string get_repl_backlog_size()
            {
                return _get_string_value(REPL_BACKLOG_SIZE);
            }
            int get_repl_backlog_ttl()
            {
                return _get_int_value(REPL_BACKLOG_TTL);
            }
            int get_slave_priority()
            {
                return _get_int_value(SLAVE_PRIORITY);
            }
            int get_min_slaves_to_write()
            {
                return _get_int_value(MIN_SLAVES_TO_WRITE);
            }
            int get_min_slaves_max_lag()
            {
                return _get_int_value(MIN_SLAVES_MAX_LAG);
            }
            string get_require_pass()
            {
                return _get_string_value(REQUIRE_PASS);
            }
            vector<map<string, string>get_renamed_commands()
            {
                return _renamed_commands;
            }
            int get_max_client()
            {
                return _get_int_value(MAX_CLIENTS);
            }
            int get_max_memory()
            {
                return _get_int_value(MAX_MEMORY);
            }
            string get_max_memory_policy()
            {
                return _get_string_value(MAX_MEMORY_POLICY);
            }
            int get_max_memory_samples()
            {
                return _get_int_value(MAX_MEMORY_SAMPLES);
            }
            bool get_append_only()
            {
                return _get_bool_value(APPEND_ONLY);
            }
            string get_append_filename()
            {
                return _get_string_value(APPEND_FILENAME);
            }
            string get_append_fsync()
            {
                return _get_string_value(APPEND_FSYNC);
            }
            bool get_no_append_fsync_on_rewrite()
            {
                return _get_bool_value(NO_APPEND_FSYNC_ON_REWRITE);
            }
            int get_auto_aof_rewrite_percentage()
            {
                return _get_int_value(AUTO_AOF_REWRITE_PERCENTAGE);
            }
            string get_auto_aof_rewrite_min_size()
            {
                return _get_string_value(AUTO_AOF_REWRITE_MIN_SIZE);
            }
            int get_lua_time_limit()
            {
                return _get_int_value(LUA_TIME_LIMIT);
            }
            int get_slowlog_log_slower_than()
            {
                return _get_int_value(SLOWLOG_LOG_SLOWER_THAN);
            }
            int get_slowlog_max_len()
            {
                return _get_int_value(SLOWLOG_MAX_LEN);
            }
            string get_notify_keyspace_events()
            {
                return _get_string_value(NOTIFY_KEYSPACE_EVENTS);
            }
            int get_hash_max_zip_list_entries()
            {
                return _get_int_value(HASH_MAX_ZIP_LIST_ENTRIES);
            }
            int get_hash_max_zip_list_value()
            {
                return _get_int_value(HASH_MAX_ZIP_LIST_VALUE);
            }
            int get_list_max_zip_list_entries()
            {
                return _get_int_value(LIST_MAX_ZIP_LIST_ENTRIES);
            }
            int get_list_max_zip_list_value()
            {
                return _get_int_value(LIST_MAX_ZIP_LIST_VALUE);
            }
            int get_set_max_intset_entries()
            {
                return _get_int_value(SET_MAX_INTSET_ENTRIES);
            }
            int get_zset_max_zip_list_entries()
            {
                return _get_int_value(ZSET_MAX_ZIP_LIST_ENTRIES);
            }
            int get_zset_max_zip_list_value()
            {
                return _get_int_value(ZSET_MAX_ZIP_LIST_VALUE);
            }
            bool get_active_rehashing()
            {
                return _get_bool_value(ACTIVE_REHASHING);
            }
            vector<map<string,string> get_client_output_buffer_limit()
            {
                return _client_output_buffer_limit;
            }
            int get_hz()
            {
                return _get_string_value(HZ);
            }
            bool get_aof_rewrite_incremental_fsync()
            {
                return _get_bool_value(AOF_REWRITE_INCREMENTAL_FSYNC);
            }
    };
}
