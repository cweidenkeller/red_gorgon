#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>
#include "connection.cc"
namespace nova { namespace redis {

    int get_socket(std::string host, std::string port);
    int send_message(int sockfd, std::string message);
    std::string get_response(int sockfd, int read_bytes);
}}//nova::redis
