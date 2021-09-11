#include <thread>
#include <cstring>
#include <iostream>

//NetWork
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;
//~NetWork

#include "Server.hpp"

#define PORT 3630

static void init(void)
{
#ifdef WIN32
    WSADATA wsa;
    int err = WSAStartup(MAKEWORD(2, 2), &wsa);
    if (err < 0) {
        puts("WSAStartup failed !");
        exit(EXIT_FAILURE);
    }
#endif
}

void server(int *socks)
{
    init();
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == INVALID_SOCKET)
        herror("socket()");

    SOCKADDR_IN sin;
    std::memset(&sin, 0, sizeof(SOCKADDR_IN));

    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);

    int var = 1;
    setsockopt(sock,SOL_SOCKET, SO_REUSEADDR, &var, sizeof(int));

    if(bind(sock, (SOCKADDR *) &sin, sizeof sin) == SOCKET_ERROR)
        herror("bind()");
    std::cout << "BINDED" << std::endl;

    if(listen(sock, 64) == SOCKET_ERROR)
        perror("listen()");

    std::cout << "LISTEN" << std::endl;

    SOCKADDR_IN csin;
    SOCKET csock;
    std::memset(&csin, 0, sizeof(SOCKADDR_IN));
    std::memset(&csock, 0, sizeof(SOCKET));

    socklen_t sinsize = sizeof(csin);
    for (int i = 0; i < 65537-1; i++){
        std::cout << "WAITING" << std::endl;
        csock = accept(sock, (SOCKADDR *)&csin, &sinsize);
        if(csock == INVALID_SOCKET){
            perror("accept()");
            continue;
        }
        socks[i] = csock;
    }
    closesocket(sock);
}

void sendToSantas(std::string &msg, int *socks)
{
    std::cout << msg << std::endl;
    for (int i = 0; socks[i]; i++){
        if(send(socks[i], msg.c_str(), msg.size()+1, 0) < 0){
            herror("send()");
            continue;
        }
    }
}

/*int main()
{
    int socks[1024] = {0};
    std::thread t2(server, socks);
    sleep(10);
    std::string msg = "hello there";
    sendToSanta(msg, socks);
    for (int x = 0; socks[x]; x++)
        printf("%i ", socks[x]);
    exit(0);
}*/
