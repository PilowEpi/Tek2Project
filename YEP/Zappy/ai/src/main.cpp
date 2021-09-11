
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <string>
#include <cstring>
#include <ext/stdio_filebuf.h>
#include <thread>

#include "utils.hpp"
#include "ai.hpp"

void print_help() {
    std::cout << "USAGE: ./zappy_ai -p port -n name -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tname\tis the name of the team" << std::endl;
    std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
    exit(0);
}

int isNum(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i]))
            return (0);
    }
    return (1);
}

int getPort(int *ptr, int ac, char **argv)
{
    if (*ptr == ac || (*ptr) + 1 == ac)
        exit(84);
    if (!isNum(argv[(*ptr) + 1]))
        exit(84);
    return (std::atoi(argv[(*ptr) + 1]));
}

void getMachineName(int *ptr, int ac, char **argv, std::string &name)
{
    if (*ptr == ac || (*ptr) + 1 == ac)
        exit(84);
    else if (name != "")
        exit(84);
    name = std::string(argv[(*ptr) + 1]);
}

void getTeamName(int *ptr, int ac, char **argv, std::string &name)
{
    if (*ptr == ac || (*ptr) + 1 == ac)
        exit(84);
    else if (name != "")
        exit(84);
    name = std::string(argv[(*ptr) + 1]);
}

void zappy(std::string ip, int port, std::string team)
{
    std::cout << "zappy_ai : ip : " << ip << " port : " << port << std::endl;
    Ai ai(ip, port, team);

    ai.connnect();
    
    std::thread thread(&Ai::startListening, &ai);

    ai.login();

    while (ai.compute()) {
        
    }
    //ai.stopListening(thread);
}

int handleArgs(int ac, char **argv)
{
    int port = -1;
    std::string name("");
    std::string team("");

    for (int i = 1; i < ac; i++) {
        if (!std::strcmp(argv[i], "-p")) {
            port = getPort(&i, ac, argv);
            continue;
        }
        if (!std::strcmp(argv[i], "-h")) {
            getMachineName(&i, ac, argv, name);
            continue;
        }
        if (!std::strcmp(argv[i], "-n")) {
            getTeamName(&i, ac, argv, team);
        }
    }
    if (port == -1 || port == 0)
        return (84);
    if (name.size() == 0)
        name = "localhost";
    zappy(name, port, team);
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && std::string(av[1]) == "--help")
        print_help();
    return handleArgs(ac, av);
} 