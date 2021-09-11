/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Server
*/

#include <thread>
#include <cstring>
#include <iostream>
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
    SOCKADDR_IN sin;
    SOCKADDR_IN csin;
    SOCKET csock;
    int var = 1;
    socklen_t sinsize = sizeof(csin);
    
    if (sock == INVALID_SOCKET)
        herror("socket()");
    std::memset(&sin, 0, sizeof(SOCKADDR_IN));
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
    setsockopt(sock,SOL_SOCKET, SO_REUSEADDR, &var, sizeof(int));
    if (bind(sock, (SOCKADDR *) &sin, sizeof sin) == SOCKET_ERROR)
        herror("bind()");
    if (listen(sock, 64) == SOCKET_ERROR)
        perror("listen()");
    std::memset(&csin, 0, sizeof(SOCKADDR_IN));
    std::memset(&csock, 0, sizeof(SOCKET));
    for (int i = 0; i < 65537 - 1; i++) {
        csock = accept(sock, (SOCKADDR *)&csin, &sinsize);
        if (csock == INVALID_SOCKET) {
            perror("accept()");
            continue;
        }
        socks[i] = csock;
    }
    closesocket(sock);
}

void sendToSantas(std::string &msg, int *socks)
{
    for (int i = 0; socks[i]; i++) {
        if (send(socks[i], msg.c_str(), msg.size()+1, 0) < 0){
            herror("send()");
            continue;
        }
    }
}