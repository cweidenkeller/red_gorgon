namespace nova { namespace redis {
std::string to_string(int number)
{
    std::stringstream ss;
    ss << number;
    return ss.str();
}
int to_int(std::string number)
{
    int num;
    std::istringstream(number) >> num;
    return num;
}
}}//end nova::redis namespace.
