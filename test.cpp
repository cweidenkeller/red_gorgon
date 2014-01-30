#include "connection.h"
#include "redis.h"
#include <string>
#include <iostream>
using namespace std;
using namespace redis;
int main(int argc, char* argv[])
{
    string data;
    int sockfd;
    if ((sockfd = get_socket(argv[1], argv[2])) == -1)
    {
        perror("socket error.");
        return -1;
    }
    string message = "*3\r\n$3\r\nSET\r\n$3\r\nFOO\r\n$3\r\neee\r\n";
    send_message(sockfd, message);
    data = get_response(sockfd, 100);
    close(sockfd);
    cout << data << endl;
    Commands commands = Commands();
    cout << commands.ping();
    cout << commands.config_get("foo");
    cout << commands.config_set("fooasdf", "barasdfff");
}
