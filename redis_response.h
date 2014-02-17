#include <string>
namespace nova { namespace redis {
struct redis_response
/* This struct is used to represent responses from the redis server.
    * It returns the status. A predefined set of responses can be found in
    * redis_constants.h.
    * A breif description of the response and the data if any the response
    * contained.
    */
{
    std::string status;
    std::string description;
    std::string data;
    redis_response(std::string _status, std::string _data)
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
}}//end nova::redis namespace.
