#include <string>
#include "common.h"
#include "connection.h"
#include "redis_constants.h"
#include "redis_response.h"
#include "redis_commands.h"
namespace nova { namespace redis {
class RedisClient
{
    private:
        bool _authed;
        bool _name_set;
        int _socket;
        std::string _port;
        std::string _host;
        std::string _client_name;
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
        redis_response _send_redis_message(std::string message)
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
            int multi_args = 0;
            int multi_len = 0;
            std::string tmp_byte = "";
            std::string tmp_multi = "";
            std::string tmp_multi_len = "";
            std::string multi_data = "";
            int retries = 0;
            std::string first_byte;
            std::string response = "";
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
                return redis_response(first_byte,
                                        response.substr(
                                            0, 
                                            response.length() - 2));
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
                return redis_response(MULTIPART_RESPONSE,
                                        multi_data);   
            }
            else
            {
                return redis_response(UNSUPPORTED_RESPONSE, "");
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
            return redis_response(CNOTHING_TO_DO_RESPONSE, "");
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
        RedisClient(std::string host, std::string port, std::string client_name)
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
        redis_response config_get(std::string name)
        {
            redis_response res = _send_redis_message(
                _commands.config_get(name));
            if (res.status != CMESSAGE_SENT_RESPONSE)
            {
                return res;
            }
            return _get_redis_response();
        }
        redis_response config_set(std::string name, std::string value)
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
}}//end nova::redis namespace
