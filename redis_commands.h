using namespace std;
namespace redis
{
    class Commands
    {
        private:
            string _config_set;
            string _config_get;
            string _config_rewrite;
            string _config_command;
            string _redis_conf;
            void set_commands()
            {
                _config_command = find_config_command();
                password = find_password();
                if(_config_command.length() >= 1)
                {
                    string formatted_config;
                    formatted_config = CRLF + DSIGN +
                                       to_string(_config_command.length()) +
                                       CRLF + _config_command + CRLF;
                    _config_set = "*4" + formatted_config + "$3\r\nSET\r\n";
                    _config_get = "*3" + formatted_config + "$3\r\nGET\r\n";
                    _config_rewrite = "*2" + formatted_config +
                                      "$7\r\nREWRITE\r\n";
                }
                else
                {
                    _config_set = CONFIG_SET_COMMAND;
                    _config_get = CONFIG_GET_COMMAND;
                    _config_rewrite = CONFIG_REWRITE_COMMAND;
                }
            }
        public:
            string password;
            Commands()
            {
                _redis_conf = DEFAULT_REDIS_CONFIG;
                set_commands();
            }
            Commands(string path)
            {
                _redis_conf = path;
                set_commands();
            }
            string find_password()
            {
                password = "password";
                return password;
            }
            string find_config_command()
            {
                return "";
            }
            string auth()
            {
                if (password.length() <= 0)
                {
                    return "";
                }
                return AUTH_COMMAND + DSIGN + to_string(password.length()) +
                       CRLF + password + CRLF;
            }
            string ping()
            {
                return PING_COMMAND;
            }
            string config_set(string key, string value)
            {
                key = DSIGN + to_string(key.length()) + CRLF + key + CRLF;
                value = DSIGN + to_string(value.length()) +
                    CRLF + value + CRLF;
                return _config_set + key + value;
            }
            string config_get(string key)
            {
                key = DSIGN + to_string(key.length()) + CRLF + key + CRLF;
                return _config_get + key;
            }
            string config_rewrite()
            {
                return _config_rewrite;
            }
            string bgsave()
            {
                return BGSAVE_COMMAND;
            }
            string save()
            {
                return SAVE_COMMAND;
            }
            string last_save()
            {
                return LAST_SAVE_COMMAND;
            }
            string client_set_name(string client_name)
            {
                return CLIENT_SET_COMMAND + DSIGN +
                       to_string(client_name.length()) +
                       CRLF + client_name + CRLF;
            }
    };
}
