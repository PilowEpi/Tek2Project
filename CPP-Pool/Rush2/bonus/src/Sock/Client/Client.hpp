/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Client Sock
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#include <cstring>
#include <string>
#include <iostream>
#define PORT 3630
#include <string>

int initsock(const std::string hostname_string);
std::string rcvsock(int sock);

#endif
