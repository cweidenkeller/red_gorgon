#include <iostream>
#include <string>
#include "control.h"
using namespace nova::redis;
int main()
{
    int res;
    Control control = Control("/var/lib/redis/redis-server.pid");
    res = control.stop();
    std::cout << res << std::endl;
    res = control.start();
    std::cout << res << std::endl;
    res = control.disable();
    std::cout << res << std::endl;
    res = control.enable();
    std::cout << res << std::endl;
}
