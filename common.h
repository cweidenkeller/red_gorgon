#include <string>
using namespace std;
namespace redis
{
    string to_string(int number)
    {
        stringstream ss;
        ss << number;
        return ss.str();
    }
    int to_int(string number)
    {
        int num;
        istringstream(number) >> num;
        return num;
    }
}
