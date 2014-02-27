#include <string>
#include <sstream>
#include "common.cc"
#ifndef COMMON_H
#define COMMON_H
namespace nova { namespace redis {
std::string to_string(int number);
int to_int(std::string number);
}}//end nova::redis namespace.
#endif /* COMMON_H */
