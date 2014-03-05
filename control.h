#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include "constants.h"
#include "common.h"
#ifndef CONTROL_H
#define CONTROL_H
namespace nova { namespace redis {
class Control
{
    public:
        Control(std::string pid_file)
        {
            _pid_file = pid_file;
        }
        int stop()
        {
            int pid;
            int status;
            if((status = system(REDIS_STOP.c_str())) == -1)
            {
                if((pid = _get_pid()) != -1)
                {
                    if (kill(pid, 0) == 0)
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
                unlink(_pid_file.c_str());
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
        int install(std::string pkg_name)
        {
            return system((INSTALL_PKG + pkg_name).c_str());
        }
        int uninstall(std::string pkg_name)
        {
            return system((UNINSTALL_PKG + pkg_name).c_str());
        }
        int get_pid()
        {
            std::string line = "";
            std::string data = "";
            std::ifstream pfile(_pid_file.c_str());
            if (!pfile.is_open())
            {
                return -1;
            }
            while (std::getline(pfile, line))
            {
                data += line;
            }
            pfile.close();
            if (data.length() <= 0)
            {
                return -1;
            }
            return to_int(data);
        }
    private:
        std::string _pid_file;
        int _get_pid()
        {
            std::string line = "";
            std::string data = "";
            std::ifstream pfile(_pid_file.c_str());
            if (!pfile.is_open())
            {
                return -1;
            }
            while (std::getline(pfile, line))
            {
                data += line;
            }
            pfile.close();
            if (data.length() <= 0)
            {
                return -1;
            }
            return to_int(data);
        }
};
}}
#endif /* CONTROL_H */
