#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Client.hpp"

static void init(void)
{
#ifdef WIN32
    WSADATA wsa;
    int err = WSAStartup(MAKEWORD(2, 2), &wsa);
    if(err < 0) {
        puts("WSAStartup failed !");
        exit(EXIT_FAILURE);
    }
#endif
}

int initsock(const std::string hostname_string)
{
    init();
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == INVALID_SOCKET)
        herror("socket()");

    struct hostent *hostinfo = NULL;
    SOCKADDR_IN sin;
    std::memset(&sin, 0, sizeof(SOCKADDR_IN));

    const char *hostname = hostname_string.c_str();

    hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL){
        std::cerr << "Unknown host " << hostname << std::endl;
        exit(0);
    }

    sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr;
    sin.sin_port = htons(PORT);
    sin.sin_family = AF_INET;

    if(connect(sock,(SOCKADDR *) &sin, sizeof(SOCKADDR)) == SOCKET_ERROR) {
        herror("connect()");
        exit(0);
    }
    return sock;
}

std::string rcvsock(int sock)
{
    char c = 1;
    std::string result = "";
    while (1){
        if((recv(sock, &c, 1, 0)) < 0) {
            herror("recv()");
            exit(0);
        }
        if (!c)
            break;
        result += c;
    }
    return result;
}

/*int main()
{
    int fd = initsock();
    std::cout << rcvsock(fd) << std::endl;
}*/
