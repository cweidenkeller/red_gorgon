#include <string>
#include "client.h"
#include "constants.h"
namespace nova { namespace redis {
class RedisMessageHandler
{
        Client* _client;
        void _prepare()
        {
            _client->control->install("redis-server");
        }
        void _restart()
        {
            _client->control->stop();
            _client->control->start();
        }
        void _start_db()
        {
            _client->control->start();
        }
        void _remove_overrides()
        {
            a;
        }
        void _reset_configuration()
        {
            a;
        }
        void _stop_db()
        {
            _client->control->stop();
        }
        void _update_overrides()
        {
            a;
        }
        void _mount_volume()
        {
            a;
        }
        void _unmount_volume()
        {
            a;
        }
        void _resize_fs()
        {
            a;
        }
        void _apply_overrides()
        {
            a;
        }
        void _change_passwords()
        {
            _client->set_config(MASTER_AUTH, "password");
        }
    public:
        RedisMessageHandler()
        {
           _client = new Client(SOCKET_NAME, 
                                REDIS_PORT,
                                AGENT_NAME,
                                DEFAULT_REDIS_CONFIG);

        }
        void handle_message(std::string message)
        {
            if (message == "prepare")
            {
                _prepare();
            }
            else if (message == "restart")
            {
                _restart();
            }
            else if (message == "start_db_with_conf_changes")
            {
                _start_db();
            }
            else if (message == "remove_overrides")
            {
                _remove_overrides();
            }
            else if (message == "reset_configuration")
            {
                _reset_configuration();
            }
            else if (message == "stop_db")
            {
                _stop_db();
            }
            else if (message == "update_overrides")
            {
                _update_overrides();
            }
            else if (message == "mount_volume")
            {
                _mount_volume();
            }
            else if (message == "unmount_volume")
            {
                _unmount_volume();
            }
            else if (message == "resize_fs")
            {
                _resize_fs();
            }
            else if (message == "apply_overrides")
            {
                _apply_overrides();
            }
            else if (message == "change_passwords")
            {
                _change_passwords();
            }
        }
};
}}// end namespace nova::redis
