/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** MessageManager
*/

#ifndef YEP_MESSAGE_MANAGER
#define YEP_MESSAGE_MANAGER

#include <string>
#include <memory>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <ctype.h>
#include <err.h>
#include <unistd.h>

#include <string.h>
#include <assert.h>
#include <stdlib.h>

class Zappy;

class MessageManager
{
    public:
        MessageManager(int port, const std::string &machineName);
        ~MessageManager();

        void catchMessage();
        void handleMessage(Zappy *win);
        void callServer(const std::string &cmd);
        void retrieveInfo(int _maxId);
        void printMessages();

        std::vector<std::string *> _messages; // TO DO : make it shared ptr
    private:
        void createSocket();
        void readAndStock();
        void parse(char *buffer);
        int _port;
        std::string _machineName;
        
        int _socket;
        int _maxfd;
        fd_set _active;
        fd_set _read;
        struct timeval _tv;
};

#endif
