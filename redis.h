#include<string>
#include<fstream>
#include<iostream>
using namespace std;
class RedisClient
{

    private:
       int port;
       string host;
       Commands commands;

}

class Commands
{
    private:
        string ping = "PING";
        string config_set = "CONFIG SET";
        string config_get = "CONFIG GET";
        string config_rewrite = "CONFIG REWRITE";
        string config_command = "";
        string bgsave = "BGSAVE";
        string save = "SAVE";
        string last_save = "LAST SAVE";
        string client_set_name = "CLIENT SETNAME"
        string redis_conf = "/etc/redis/redis.conf";
        void set_config_commands()
        {            
            config_command = find_config_command();
            if(config_command)
            {
                config_set = config_command + " SET";
                config_get = config_command + " GET";
                config_rewrite = config_command + " REWRITE";
            }
        }
        string find_config_command()
        {
        }
    public:
        void Commands()
        {
            set_config_command();  
        }
        void Commands(string path)
        {
            redis_conf = path;
            find_config_command();
        }
        string ping()
        {
            return ping;
        }
        string config_set()
        {
            return config_set;
        }
        string config_get()
        {
            return config_get;
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
}
