/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** Main
*/

#include "Zappy.hpp"
#include "Error.hpp"

int printUsage(void)
{
    std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tmachine is the name of the machine; localhost by default" << std::endl;
    return (1);
}

int startZappy(int port, std::string machine)
{
    try {
        Zappy zappy(port, machine);
        zappy.launch();
    } catch (GuiError &e) {
        std::cerr << e.getComponent() << " : " << e.what() << std::endl;
        return (84);
    } catch (...) {
        return (84);
    }
    return (0);
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

int handleArgs(int ac, char **argv)
{
    int port = -1;
    std::string name("");

    for (int i = 1; i < ac; i++) {
        if (!std::strcmp(argv[i], "-p")) {
            port = getPort(&i, ac, argv);
            continue;
        }
        if (!std::strcmp(argv[i], "-h")) {
            getMachineName(&i, ac, argv, name);
            continue;
        }
    }
    if (port == -1 || port == 0)
        return (84);
    if (name.size() == 0)
        name = "localhost";
    return (startZappy(port, name));
}

int main(int ac, char **argv)
{
    srand(time(0));
    if (ac == 2 && std::strcmp(argv[1], "-h")) 
        return (printUsage());
    return (handleArgs(ac, argv));
}