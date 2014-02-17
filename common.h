#include <string>
#include <sstream>
#include "common.cc"
namespace nova { namespace redis {
std::string to_string(int number);
int to_int(std::string number);
}}//end nova::redis namespace.
