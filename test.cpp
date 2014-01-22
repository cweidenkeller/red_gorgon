#include "connection.h"
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
    int sockfd;
    if ((sockfd = get_socket(argv[1], argv[2])) == -1)
    {
        perror("socket error.");
        return -1;
    }
    string message = "*3\r\n$3\r\nSET\r\n$3\r\nFOO\r\n$3\r\neee\r\n";
    send_message(sockfd, message);
    close(sockfd);
}
