/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

void server(int *socks);
void sendToSantas(std::string &msg, int *socks);

#endif
