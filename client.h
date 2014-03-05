#include <string>
#include <iostream>
#include "common.h"
#include "connection.h"
#include "constants.h"
#include "response.h"
#include "commands.h"
#include "control.h"
#include "config.h"
#ifndef CLIENT_H
#define CLIENT_H
namespace nova { namespace redis {
class Client
    /*
     * This is the redis Client class it handles all communication
     * and process control of a redis instance.
     * This object is thread safe and handles closing
     * of any open file descriptors or sockets on deconstruction.
     */
{
    private:
        bool _authed;
        bool _name_set;
        int _socket;
        std::string _port;
        std::string _host;
        std::string _client_name;
        std::string _config_file;
        std::string _config_command;
        Commands*_commands;
        /*
         * Connects to the redis server using nova::redis::get_socket.
         * found
         */
        response _connect()
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
                return response(CCONNECTED_RESPONSE, "");
            }
            return response(CCONNECTION_ERR_RESPONSE, "");
        }
        response _send_redis_message(std::string message)
        {
            int sres = 0;
            if (_socket < 0)
            {
                response res = _connect();
                if (res.status != CCONNECTED_RESPONSE)
                {
                    return res;
                }
            }
            sres = send_message(_socket, message);
            if (sres == SOCK_ERROR)
            {
                return response(STIMEOUT_RESPONSE, "");
            }
            return response(CMESSAGE_SENT_RESPONSE, "");
        }
        response _get_redis_response()
        {
           /*
            * Determine the response type from the redis server and return
            * A struct containing the response type as a string,
            * a string of its data and a description of the response type.
            * This method accepts an integer to an active socket file
            * descriptor.
            */
            int multi_args = 0;
            int multi_len = 0;
            std::string tmp_byte = "";
            std::string tmp_multi = "";
            std::string tmp_multi_len = "";
            std::string multi_data = "";
            int retries = 0;
            std::string first_byte;
            std::string res = "";
            if (_socket < 0)
            {
                return response(STIMEOUT_DESCRIPTION, "");
            }
            while (true)
            {
                if (retries == MAX_RETRIES)
                {
                    return response(CTIMEOUT_RESPONSE, "");
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
                        return response(CTIMEOUT_RESPONSE, "");
                    }
                    res += get_response(_socket, READ_LEN);
                    if (res.length() == 0)
                    {
                        ++retries;
                        continue;
                    }
                    if (res.substr(res.length() - CRLF_LEN) == CRLF)
                    {
                        break;
                    }
                    ++retries;
                }
                if (res.substr(res.length() - CRLF_LEN) != CRLF)
                {
                    return response(SERROR_RESPONSE, "");
                }
                return response(first_byte,
                                    res.substr(0,
                                               res.length() - 2));
            }
            else if (first_byte == MULTIPART_RESPONSE)
            {
                while (true)
                {
                    tmp_byte = get_response(_socket, 1);
                    if (tmp_byte == "\r")
                    {
                        get_response(_socket, 2);
                        multi_args = to_int(tmp_multi);
                        tmp_byte = "";
                        break;
                    }
                    tmp_multi += tmp_byte;
                }
                while (multi_args != 0)
                {
                    tmp_multi_len = "";
                    while (true)
                    {
                        if (tmp_byte == "\r")
                        {
                            get_response(_socket, 1);
                            tmp_byte = "";
                            multi_len = to_int(tmp_multi_len);
                            break;
                        }
                        tmp_byte = get_response(_socket, 1);
                        tmp_multi_len += tmp_byte;
                    }
                    multi_data += get_response(_socket,
                                                multi_len);
                    if (multi_args != 1)
                    {
                        multi_data += " ";
                        get_response(_socket,
                                        3);
                    }
                    else
                    {
                        get_response(_socket, 2);
                    }
                    --multi_args;
                }
                return response(MULTIPART_RESPONSE,
                                        multi_data);
            }
            else
            {
                return response(UNSUPPORTED_RESPONSE, "");
            }
        }
        response _set_client()
        {
            if (!_name_set)
            {
                response res = _send_redis_message(
                    _commands->client_set_name(_client_name));
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
            return response(CNOTHING_TO_DO_RESPONSE, "");
        }
        response _auth()
        {
            if (_commands->password.length() > 0 && !_authed)
            {
                response res = _send_redis_message(_commands->auth());
                if (res.status != CMESSAGE_SENT_RESPONSE)
                {
                    return res;
                }
                res = _get_redis_response();
                if (res.status == ERROR_RESPONSE)
                {
                    res = _send_redis_message(_commands->auth());
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
            return response(CNOTHING_TO_DO_RESPONSE, "");
        }
        response _reconnect()
        {
            close(_socket);
            _authed = false;
            _name_set = false;
            _socket = -1;
            response res = _connect();
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
            return response(CCONNECTED_RESPONSE, "");
        }
        void _find_config_command()
        {
            for (int i=0; i < config->get_renamed_commands().size(); i++)
            {
                if (config->get_renamed_commands()[i][RENAMED_COMMAND] ==
                    COMMAND_CONFIG)
                {
                    _config_command =
                        config->get_renamed_commands()[i][NEW_COMMAND_NAME];
                }
            }
        }
    public:
        Control* control;
        Config* config;
        Client(std::string host, std::string port, std::string client_name,
               std::string config_file)
        {
            _host = host;
            _port = port;
            _config_command = COMMAND_CONFIG;
            _client_name = client_name;
            _config_file = config_file;
            config = new Config(config_file);
            _find_config_command();
            _commands = new Commands(config->get_require_pass(),
                                     _config_command);
            control = new Control(config->get_pidfile());
            _authed = false;
            _name_set = false;
            _socket = -1;
            _connect();
            response res = _auth();
            res = _set_client();
        }
        ~Client()
        {
            close(_socket);
        }
        response ping()
        {
            response res = _send_redis_message(_commands->ping());
            if (res.status != CMESSAGE_SENT_RESPONSE)
            {
                return res;
            }
            return _get_redis_response();
        }
        response bgsave()
        {
            response res = _send_redis_message(_commands->bgsave());
            if (res.status != CMESSAGE_SENT_RESPONSE)
            {
                return res;
            }
            return _get_redis_response();
        }
        response save()
        {
            response res = _send_redis_message(_commands->save());
            if (res.status != CMESSAGE_SENT_RESPONSE)
            {
                return res;
            }
            return _get_redis_response();
        }
        response last_save()
        {
            response res = _send_redis_message(
                _commands->last_save());
            if (res.status != CMESSAGE_SENT_RESPONSE)
            {
                return res;
            }
            return _get_redis_response();
        }
        response config_get(std::string name)
        {
            response res = _send_redis_message(
                _commands->config_get(name));
            if (res.status != CMESSAGE_SENT_RESPONSE)
            {
                return res;
            }
            return _get_redis_response();
        }
        response config_set(std::string name, std::string value)
        {
            response res = _send_redis_message(
                _commands->config_set(name, value));
            if (res.status != CMESSAGE_SENT_RESPONSE)
            {
                return res;
            }
            return _get_redis_response();
        }
        response config_rewrite()
        {
            response res = _send_redis_message(
                _commands->config_rewrite());
            if (res.status != CMESSAGE_SENT_RESPONSE)
            {
                return res;
            }
            return _get_redis_response();
        }
};
}}//end nova::redis namespace
#endif /* CLIENT_H */
