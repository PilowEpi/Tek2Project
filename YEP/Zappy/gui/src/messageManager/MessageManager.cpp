/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** MessageManager
*/

#include "MessageManager.hpp"
#include "GuiFonctions.hpp"
#include <sstream>
#include <cstring>

MessageManager::MessageManager(int port, const std::string &machineName)
    : _port(port), _machineName(machineName)
{
    _tv.tv_sec = 0;
    _tv.tv_usec = 0;
    createSocket();
    FD_ZERO(&_active);
    FD_SET(_socket, &_active);
    FD_SET(0, &_active);
    _maxfd = _socket + 1;
}

MessageManager::~MessageManager()
{
    shutdown(_socket, SHUT_RDWR);
    close(_socket);
}

void MessageManager::createSocket()
{
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    _socket = socket(AF_INET, SOCK_STREAM, 0);
    if (_socket < 0)
        throw NetworkError("socket error");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(_port);
    char *test = strdup(_machineName.c_str());
    if (inet_pton(AF_INET, test, &server_addr.sin_addr) < 0)
        throw NetworkError("adress error");
    if (connect(_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        throw NetworkError("connect error");
    std::cout << " Socket connected successfully " << _socket << std::endl;
}

void MessageManager::catchMessage()
{
    _read = _active;
    if (select(_maxfd, &_read, NULL, NULL, &_tv) < 0)
        throw NetworkError("select error");
    if (FD_ISSET(_socket, &_read)) {
        readAndStock();
        FD_CLR(_socket, &_read);
    }
}

void MessageManager::readAndStock()
{
    char buf[1024] = {0};
    ssize_t nbytes;

    nbytes = read(_socket, buf, 1024);
    if (nbytes < 0)
        throw NetworkError("read client fail");
    else if (nbytes == 0)
        throw NetworkError("read client fail");
    else
        parse(buf);
}

void MessageManager::parse(char *buf)
{
    std::string temp("");

    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == '\n') {
            _messages.push_back(new std::string(temp));
            temp = "";
            i++;
        }
        temp += buf[i];
    }
}

void MessageManager::callServer(const std::string &cmd)
{
    dprintf(_socket, "%s\n", cmd.c_str());
}

void MessageManager::printMessages()
{
    int index = 0;

    std::cout << "MessageManager: " << std::endl;
    for (auto msg : _messages) {
        std::cout << "[" << index << "] :" << msg->c_str() << std::endl;
        index++;
    }
    std::cout << std::endl << std::endl;
}

void MessageManager::handleMessage(Zappy *win)
{
    const char cmd[][4] = {"msz", "bct", "tna", "pnw", "ppo", "plv", "pin", "pex",
                        "pbc", "pic", "pie", "pfk", "pdr", "pgt", "pdi", "enw",
                        "eht", "ebo", "edi", "sgt", "prr", "seg", "smg",
                        "ppf", "ppr", "ppl"};

    void (*fct[]) (Zappy *win, const char *data) =
    //    msz           bct                tna            pnw
    {GUI::createMap, GUI::callEvent, GUI::storeTeams, GUI::spawnTrantor,
    //    ppo           plv        pin            pex
    GUI::ppoCmd, GUI::plvCmd, GUI::pinCmd, GUI::explusion,
    //    pbc           pic         pie            pfk
    GUI::pbcCmd, GUI::picCmd, GUI::pieCmd, GUI::doNothing,
    //    pdr           pgt                pdi
    GUI::pdrCmd, GUI::pgtCmd, GUI::pdiCmd,
    //    enw           eht      ebo            edi
    GUI::enwCmd, GUI::ehtCmd, GUI::eboCmd, GUI::ediCmd,
    //    sgt           ppr                seg            smg
    GUI::doNothing, GUI::prrCmd, GUI::victoryScene, GUI::doNothing,
    //    ppf       ppr         ppl
    GUI::ppfCmd, GUI::ppCmd, GUI::ppCmd};

    for (auto msg : _messages) {
        for (int i = 0; i < 26; i++) {
            if (!std::strncmp(msg->c_str(), cmd[i], 3))
                fct[i](win, msg->c_str());
        }
    }
    _messages.clear();
}

void MessageManager::retrieveInfo(int maxId)
{
}