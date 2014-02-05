#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
#include <unistd.h>
#include "connection.h"
#include "redis_constants.h"
using namespace std;
namespace redis
{
    struct redis_response
    {
        string status;
        string description;
        string data;
        redis_response(string _status, string _data)
        {
            status = _status;
            data = _data;
            if (_status == STRING_RESPONSE)
            {
                description = STRING_DESCRIPTION;
            }
            else if (_status == ERROR_RESPONSE)
            {
                description = ERROR_DESCRIPTION;
            }
            else if (_status == INTEGER_RESPONSE)
            {
                description = INTEGER_DESCRIPTION;
            }
            else if (_status == MULTIPART_RESPONSE)
            {
                description = MULTIPART_DESCRIPTION;
            }
            else if (_status == CERROR_RESPONSE)
            {
                description = CERROR_DESCRIPTION;
            }
            else if (_status == UNSUPPORTED_RESPONSE)
            {
                description = UNSUPPORTED_DESCRIPTION;
            }
            else if (_status == SERROR_RESPONSE)
            {
                description = SERROR_DESCRIPTION;
            }
            else if (_status == STIMEOUT_RESPONSE)
            {
                description = STIMEOUT_DESCRIPTION;
            }
            else if (_status ==CTIMEOUT_RESPONSE)
            {
                description = CTIMEOUT_DESCRIPTION;
            }
            else if (_status == CCONNECTED_RESPONSE)
            {
                description = CCONNECTED_DESCRIPTION;
            }
            else if (_status == CCONNECTION_ERR_RESPONSE)
            {
                description = CCONNECTION_ERR_DESCRIPTION;
            }
            else if (_status == CMESSAGE_SENT_RESPONSE)
            {
                description = CMESSAGE_SENT_DESCRIPTION;
            }
            else if (_status == CNOTHING_TO_DO_RESPONSE)
            {
                description = CNOTHING_TO_DO_DESCRIPTION;
            }
            else
            {
                status = "uknown";
                description = "Uknown status passed.";
            }
        }
    };
    string to_string(int number)
    {
        stringstream ss;
        ss << number;
        return ss.str();
    }
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
    class RedisClient
    {
        private:
            bool _authed;
            bool _name_set;
            int _socket;
            string _port;
            string _host;
            string _client_name;
            Commands _commands;
            redis_response _connect()
            {
                int retries = 0;
                while (retries <= MAX_RETRIES)
                {
                    _socket = get_socket(_host, _port);
                    if (_socket >= 0)
                    {
                        break;
                    }
                    ++retries;
                }
                if (_socket >= 0)
                {
                    return redis_response(CCONNECTED_RESPONSE, "");
                }
                return redis_response(CCONNECTION_ERR_RESPONSE, "");
            }
            redis_response _send_redis_message(string message)
            {
                int sres = 0;
                if (_socket < 0)
                {
                    redis_response res = _connect();
                    if (res.status != CCONNECTED_RESPONSE)
                    {
                        return res;
                    }
                }
                sres = send_message(_socket, message);
                if (sres == SOCK_ERROR)
                {
                    return redis_response(STIMEOUT_RESPONSE, "");
                }
                return redis_response(CMESSAGE_SENT_RESPONSE, "");
            }
            redis_response _get_redis_response()
            {
            /*
             * Determine the response type from the redis server and return
             * A struct containing the response type as a string,
             * a string of its data and a description of the response type.
             * This method accepts an integer to an active socket file
             * descriptor.
             */
                int retries = 0;
                string first_byte;
                string response = "";
                if (_socket < 0)
                {
                    return redis_response(STIMEOUT_DESCRIPTION, "");
                }
                while (true)
                {
                    if (retries == MAX_RETRIES)
                    {
                        return redis_response(CTIMEOUT_RESPONSE, "");
                    }
                    first_byte = get_response(_socket, FIRST_BYTE_READ);
                    if (first_byte.length() > 0)
                    {
                        break;
                    }
                    ++retries;
                }
                retries = 0;
                if (first_byte == STRING_RESPONSE ||
                    first_byte == ERROR_RESPONSE ||
                    first_byte == INTEGER_RESPONSE)
                {
                    while (true)
                    {                        
                        if (retries == MAX_RETRIES)
                        {
                           return redis_response(CTIMEOUT_RESPONSE, "");
                        }
                        response += get_response(_socket, READ_LEN);
                        if (response.length() == 0)
                        {
                            ++retries;
                            continue;
                        }
                        if (response.substr(response.length() - CRLF_LEN) ==
                           CRLF)
                        {
                            break;
                        }
                        ++retries;
                    }
                    if (response.substr(response.length() - CRLF_LEN) != CRLF)
                    {
                        return redis_response(SERROR_RESPONSE, "");
                    }
                    return redis_response(first_byte, response);
                }
                else if (first_byte == MULTIPART_RESPONSE)
                {
                    return redis_response(UNSUPPORTED_RESPONSE, response);
                }
                
            }
            redis_response _set_client()
            {
                if (!_name_set)
                {
                    redis_response res = _send_redis_message(
                        _commands.client_set_name(_client_name));
                    if (res.status != CMESSAGE_SENT_RESPONSE)
                    {
                        return res; 
                    }
                    res = _get_redis_response();
                    if (res.status == STRING_RESPONSE)
                    {
                        _name_set = true;
                    }
                    return res;
                }
                redis_response res = 
                    redis_response(CNOTHING_TO_DO_RESPONSE, "");
            }
            redis_response _auth()
            {
                if (_commands.password.length() > 0 && !_authed)
                {
                    redis_response res = _send_redis_message(_commands.auth());
                    if (res.status != CMESSAGE_SENT_RESPONSE)
                    {
                        return res;
                    }
                    res = _get_redis_response();
                    if (res.status == ERROR_RESPONSE)
                    {
                        _commands.find_password();
                        res = _send_redis_message(_commands.auth());
                        if (res.status != CMESSAGE_SENT_RESPONSE)
                        {
                            return res;
                        }
                        res = _get_redis_response();
                        if (res.status == STRING_RESPONSE)
                        {
                            _authed = true;
                        }
                    }
                    if (res.status == STRING_RESPONSE)
                    {
                        _authed = true;
                    }
                    return res;
                }
                _authed = true;
                return redis_response(CNOTHING_TO_DO_RESPONSE, "");
            }
            redis_response _reconnect()
            {
                close(_socket);
                _authed = false;
                _name_set = false;
                _socket = -1;
                redis_response res = _connect();
                if (res.status != CCONNECTED_RESPONSE)
                {
                    return res;
                }
                res = _auth();
                if (res.status != STRING_RESPONSE)
                {
                    return res;
                }
                res = _set_client();
                if (res.status != STRING_RESPONSE)
                {
                    return res;
                }
                return redis_response(CCONNECTED_RESPONSE, "");
            }
        public:
            RedisClient(string host, string port, string client_name)
            {
                _host = host;
                _port = port;
                _client_name = client_name;
                _authed = false;
                _name_set = false;
                _socket = -1;
                _connect();
                redis_response res = _auth();
                res = _set_client();
            }
            ~RedisClient()
            {
                close(_socket);
            }
            redis_response ping()
            {
                redis_response res = _send_redis_message(_commands.ping());
                if (res.status != CMESSAGE_SENT_RESPONSE)
                {
                    return res;
                }
                return _get_redis_response();
            }
            redis_response bgsave()
            {
                redis_response res = _send_redis_message(_commands.bgsave());
                if (res.status != CMESSAGE_SENT_RESPONSE)
                {
                    return res;
                }
                return _get_redis_response();
            }
            redis_response save()
            {
                redis_response res = _send_redis_message(_commands.save());
                if (res.status != CMESSAGE_SENT_RESPONSE)
                {
                    return res;
                }
                return _get_redis_response();
            }
            redis_response last_save()
            {
                redis_response res = _send_redis_message(
                    _commands.last_save());
                if (res.status != CMESSAGE_SENT_RESPONSE)
                {
                    return res;
                }
                return _get_redis_response();
            }
            redis_response config_get(string name)
            {
                redis_response res = _send_redis_message(
                    _commands.config_get(name));
                if (res.status != CMESSAGE_SENT_RESPONSE)
                {
                    return res;
                }
                return _get_redis_response();
            }
            redis_response config_set(string name, string value)
            {
                redis_response res = _send_redis_message(
                    _commands.config_set(name, value));
                if (res.status != CMESSAGE_SENT_RESPONSE)
                {
                    return res;
                }
                return _get_redis_response();
            }
            redis_response config_rewrite()
            {
                redis_response res = _send_redis_message(
                    _commands.config_rewrite());
                if (res.status != CMESSAGE_SENT_RESPONSE)
                {
                    return res;
                }
                return _get_redis_response();
            }



    };
}


