#include <string>
#ifndef COMMANDS_H
#define COMMANDS_H
namespace nova { namespace redis {
class Commands
{
    private:
        std::string _config_set;
        std::string _config_get;
        std::string _config_rewrite;
        std::string _config_command;
        void set_commands()
        {
            if(_config_command.length() >= 1)
            {
                std::string formatted_config;
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
        std::string password;
        Commands(std::string _password, std::string config_command)
        {
            password = _password;
            _config_command = config_command;
            set_commands();
        }
        std::string auth()
        {
            if (password.length() <= 0)
            {
                return "";
            }
            return AUTH_COMMAND + DSIGN + to_string(password.length()) +
                    CRLF + password + CRLF;
        }
        std::string ping()
        {
            return PING_COMMAND;
        }
        std::string config_set(std::string key, std::string value)
        {
            key = DSIGN + to_string(key.length()) + CRLF + key + CRLF;
            value = DSIGN + to_string(value.length()) +
                CRLF + value + CRLF;
            return _config_set + key + value;
        }
        std::string config_get(std::string key)
        {
            key = DSIGN + to_string(key.length()) + CRLF + key + CRLF;
            return _config_get + key;
        }
        std::string config_rewrite()
        {
            return _config_rewrite;
        }
        std::string bgsave()
        {
            return BGSAVE_COMMAND;
        }
        std::string save()
        {
            return SAVE_COMMAND;
        }
        std::string last_save()
        {
            return LAST_SAVE_COMMAND;
        }
        std::string client_set_name(std::string client_name)
        {
            return CLIENT_SET_COMMAND + DSIGN +
                    to_string(client_name.length()) +
                    CRLF + client_name + CRLF;
        }
};
}}//end nova::redis namespace
#endif /* COMMANDS_H */
