#include <vector>
#include <string>
#include <iostream>
#include "config.h"
using namespace nova::redis;
int main()
{
    std::string path = "/home/cweidenkeller/red_gorgon/test_redis.conf";
    Config conf(path);
    std::cout << conf.get_include_files().size() << std::endl;
    std::cout << conf.get_include_files()[0] << std::endl;
    std::cout << conf.get_include_files()[1] << std::endl;
    std::cout << conf.get_log_file() << std::endl;
    
}
