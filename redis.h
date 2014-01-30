#include "connection.h"
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;
namespace redis
{
    string to_string(int number)
    {
        stringstream ss;
        ss << number;
        return ss.str();
    }
    class Commands
    {
        private:
            string _ping;
            string _config_set;
            string _config_get;
            string _config_rewrite;
            string _config_command;
            string _bgsave;
            string _save;
            string _last_save;
            string _client_set_name;
            string _redis_conf;
            void set_commands()
            {
                _ping = "*1\r\n$4\r\nPING\r\n";
                _bgsave = "*1\r\n$6\r\nBGSAVE\r\n";
                _save = "*1\r\n$4\r\nSAVE\r\n";
                _last_save = "*2\r\n$4\r\nLAST\r\n$4\r\nSAVE\r\n";
                _client_set_name = "*3\r\n$6\r\nCLIENT\r\n$7\r\nSETNAME\r\n";
                _config_command = find_config_command();
		if(_config_command.length() >= 1)
                {
                    string formatted_config;
                    formatted_config = "\r\n$" + 
                                       to_string(_config_command.length()) +
                                       "\r\n" + _config_command + "\r\n";
                    _config_set = "*4" + formatted_config + "$3\r\nSET\r\n";
                    _config_get = "*3" + formatted_config + "$3\r\nGET\r\n";
                    _config_rewrite = "*2" + formatted_config + 
                                      "$7\r\nREWRITE\r\n";
                }
                else
                {
                    _config_set = "*4\r\n$6\r\nCONFIG\r\n$3\r\nSET\r\n";
                    _config_get = "*3\r\n$6\r\nCONFIG\r\n$3\r\nGET\r\n";
                    _config_rewrite = "*2\r\n$6\r\nCONFIG\r\n" 
                                      "$7\r\nREWRITE\r\n";
                }
            }
            string find_config_command()
            {
                return "config_command";
            }
            string find_password()
            {
                return "password";
            }
        public:
            Commands()
            {
                _redis_conf = "/etc/redis/redis.conf";
                set_commands();
            }
            Commands(string path)
            {
                _redis_conf = path;
                set_commands();
            }
            string ping()
            {
                return _ping;
            }
            string config_set(string key, string value)
            {
                key = "$" + to_string(key.length()) + "\r\n" + key + "\r\n";
                value = "$" + to_string(value.length()) +
                    "\r\n" + value + "\r\n";
                return _config_set + key + value;
            }
            string config_get(string key)
            {
                key = "$" + to_string(key.length()) + "\r\n" + key + "\r\n";
                return _config_get + key;
            }
            string config_rewrite()
            {
                return _config_rewrite;
            }
            string bgsave()
            {
                return _bgsave;
            }
            string save()
            {
                return _save;
            }
            string last_save()
            {
                return _last_save;
            }
            string client_set_name(string client_name)
            {
                return _client_set_name + "$" +
                       to_string(client_name.length()) +
                       "\r\n" + client_name + "\r\n";
            }
    };
    class RedisClient
    {
        private:
            int socket;
            string _port;
            string _host;
            string _client_name;
            Commands commands;
            int set_client(int sockfd)
            {
                int res;
                if (send_message(sockfd,
                    commands.client_set_name(_client_name)) == -1)
                {
                    return -1;
                }
                if (
            }
        public:
            RedisClient(string host, string port, string client_name)
            {
                _host = host;
                _port = port;
                _client_name = client_name;
            }
            int ping()
            {
                int res;
                int sockfd;
                if ((sockfd = get_socket(_host, _port)) == -1)
                {
                    return -1;
                }
            }

    };
}

