#include <string>
using namespace std;
namespace redis
{
    static const string DEFAULT_REDIS_CONFIG = "/etc/redis/redis.conf";
    static const string STRING_RESPONSE = "+";
    static const string STRING_DESCRIPTION = "String.";
    static const string ERROR_RESPONSE = "-";
    static const string ERROR_DESCRIPTION = "Error.";
    static const string INTEGER_RESPONSE = ":";
    static const string INTEGER_DESCRIPTION = "Integer.";
    static const string CERROR_RESPONSE = "cerror";
    static const string CERROR_DESCRIPTION = "Client error.";
    static const string UNSUPPORTED_RESPONSE = "unsupported";
    static const string UNSUPPORTED_DESCRIPTION = "Unsupported response type.";
    static const string SERROR_RESPONSE = "serror";
    static const string SERROR_DESCRIPTION = "Redis server error.";
    static const string STIMEOUT_RESPONSE = "stimeout";
    static const string STIMEOUT_DESCRIPTION = "Redis server timeout.";
    static const string CTIMEOUT_RESPONSE = "ctimeout";
    static const string CTIMEOUT_DESCRIPTION = "Redis client timed out.";
    static const string CCONNECTED_RESPONSE = "cconnected";
    static const string CCONNECTED_DESCRIPTION = "Redis client connected.";
    static const string CCONNECTION_ERR_RESPONSE = "sconnection_err";
    static const string CCONNECTION_ERR_DESCRIPTION = "Redis client unable "
                                                       "to connect.";
    static const string CMESSAGE_SENT_RESPONSE = "cmessage_sent";
    static const string CMESSAGE_SENT_DESCRIPTION = "Redis client"
                                                    "sent message.";
    static const string CNOTHING_TO_DO_RESPONSE  = "cnothing";
    static const string CNOTHING_TO_DO_DESCRIPTION = "No command sent "
                                                     "nothing to do.";
    static const string CRLF = "\r\n";
    static const int CRLF_LEN = 2;
    static const int SOCK_ERROR = -1;
    static const int MAX_RETRIES = 1;
    static const int FIRST_BYTE_READ = 1;
    static const int READ_LEN = 20;
    static const string AUTH_COMMAND = "*2\r\n$4\r\nAUTH\r\n";
    static const string PING_COMMAND = "*1\r\n$4\r\nPING\r\n";
    static const string BGSAVE_COMMAND = "*1\r\n$6\r\nBGSAVE\r\n";
    static const string SAVE_COMMAND  = "*1\r\n$4\r\nSAVE\r\n";
    static const string LAST_SAVE_COMMAND = "*1\r\n$8\r\nLASTSAVE\r\n";
    static const string CLIENT_SET_COMMAND = "*3\r\n$6\r\nCLIENT\r\n$7\r\n"
                                             "SETNAME\r\n";
    static const string CONFIG_SET_COMMAND = "*4\r\n$6\r\nCONFIG\r\n$3\r\n" 
                                             "SET\r\n";
    static const string CONFIG_GET_COMMAND = "*3\r\n$6\r\nCONFIG\r\n$3\r\n"
                                             "GET\r\n";
    static const string CONFIG_REWRITE_COMMAND = "*2\r\n$6\r\nCONFIG"
                                                "\r\n$7\r\nREWRITE\r\n";
    static const string DSIGN  = "$";
}
