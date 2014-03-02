#include "constants.h"
#include <vector>
#include <string>
#include <iostream>
using namespace nova::redis;

int main()
{
    std::vector<std::string>config_keys(get_config_key_vector());
    std::cout << config_keys[0] << std::endl;
}
