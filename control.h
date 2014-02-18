#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include "config.h"
#include "constants.h"
#include "common.h"
namespace nova { namespace redis {
class Control
{
    public:
        Control(std::string conf)
        {
            _config(conf);
        }
        int stop()
        {
            int pid;
            int status;
            if((status = system(REDIS_STOP.c_str())) == -1)
            {
                if((pid = _get_pid()) != -1)
                {
                    if (kill(pid, SIGNULL) == 0)
                    {
                        if(kill(pid, SIGTERM) == 0 ||
                           kill(pid, SIGKILL) == 0)
                        {
                            status = 0;
                        }
                    }
                    else
                    {
                        status = 0;
                    }
                }
            }
            if (status == 0)
            {
                unlink(_config.get_pidfile());
            }
            return status;

        }
        int start()
        {
            return system(REDIS_START.c_str());
        }
        int disable()
        {
            return system(REDIS_DISABLE.c_str());
        }
        int enable()
        {
            return system(REDIS_ENABLE.c_str());
        }

    private:
        Config _config;
        int _get_pid()
        {
            std::string line = "";
            std::string data = "";
            std::ifstream pfile(config.get_pidfile().c_str());
            if (!pfile.is_open())
            {
                return -1;
            }
            while (std::getline(pfile, line)
            {
                data += line;
            }
            pfile.close();
            if (data.length() <= 0)
            {
                return -1
            }
            return to_int(data);
        }
        
};
}}
