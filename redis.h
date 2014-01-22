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
    class RedisClient
    {
        private:
        int port;
        string host;
        Commands commands;
        MessageBuilder builder;
    };
    class Commands
    {
        private:
            string ping;
            string config_set;
            string config_get;
            string config_rewrite;
            string config_command;
            string bgsave;
            string save;
            string last_save;
            string client_set_name;
            string redis_conf;
            void set_commands()
            {
                ping = "*1\r\n$4\r\nPING\r\n";
                bgsave = "*1\r\n$6\r\nBGSAVE\r\n";
                save = "*1\r\n$4\r\nSAVE\r\n";
                last_save = "*2\r\n$4\r\nLAST\r\n$4\r\nSAVE\r\n";
                client_set_name = "*3\r\n$6\r\nCLIENT\r\n$7\r\nSETNAME\r\n";
                config_command = find_config_command();
                if(config_command)
                {
                    string formatted_config;
                    formatted_config = "\r\n$" + 
                        to_string(config_command.length()) +
                        "\r\n" + config_command + "\r\n";
                    config_set = "*4" + formatted_config + "$3\r\nSET\r\n";
                    config_get = "*3" + formatted_config + "$3\r\nGET\r\n";
                    config_rewrite = "*2" + formatted_config +
                        "$7\r\nREWRITE\r\n";
                }
                else
                {
                    config_set = "*4\r\n$6\r\nCONFIG\r\n$3\r\nSET\r\n";
                    config_get = "*3\r\n$6\r\nCONFIG\r\n$3\r\nGET\r\n";
                    config_rewrite = "*2\r\n$6\r\nCONFIG\r\n$7\r\nREWRITE\r\n";
                }
            }
            string find_config_command()
            {
                return "config_command";
            }
        public:
            Commands()
            {
                redis_conf = "/etc/redis/redis.conf";
                set_commands();
            }
            Commands(string path)
            {
                redis_conf = path;
                set_commands();
            }
            string ping()
            {
                return ping;
            }
            string config_set(string key, string value)
            {
                key = "$" + to_string(key.length()) + "\r\n" + key + "\r\n";
                value = "$" + to_string(value.length()) +
                    "\r\n" + value + "\r\n";
                return config_set + key + value;
            }
            string config_get(string key)
            {
                key = "$" + to_string(key.length()) + "\r\n" + key + "\r\n";
                return config_get + key;
            }
            string config_rewrite()
            {
                return config_rewrite;
            }
            string bgsave()
            {
                return bgsave;
            }
            string save()
            {
                return save;
            }
            string last_save()
            {
                return last_save;
            }
            string client_set_name()
            {
                return client_set_name;
            }
    };
}
