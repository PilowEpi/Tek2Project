/*
** EPITECH PROJECT, 2021
** Core.cpp
** File description:
** coreShell.cpp
*/

#include "Core.hpp"

int Core::shell()
{
    simulate();
    this->_ticks = 0;
    this->refreshDisplay();
    if (isatty(0)) {
        this->ownShell();
    } else {
        this->ownShell();
    }
    return this->_exitValue;
}

void Core::setupPin()
{
    std::map<std::string, nts::IComponent *> _componentsMap = this->_nano->getAllComponent();

    for (auto &compo : _componentsMap) {
        auto *c = static_cast<nts::AComponent *> (compo.second);
        if (c->getType() == "input" || c->getType() == "clock") {
            this->_obj.push_back(c->getName());
        }
    }
}

int Core::myGetchar()
{
    struct termios old_termios;
    struct termios new_termios;
    int ch;

    tcgetattr(STDIN_FILENO, &old_termios);
    new_termios = old_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
    return (ch);
}

int Core::getArrow()
{
    int arrow = 0;

    if (getchar() != '[')
        return (-1);
    arrow = getchar();
    switch (arrow) {
        case 'A' :
            return this->historyArrow(5);
        case 'B' :
            return this->historyArrow(6);
        case 'C' :
            return this->rightArrow();
        case 'D' :
            return this->leftArrow();
        default :
            return (0);
    }
}

void cleanString(int len)
{
    for (int i = 0; i < len; i++)
        printf("\033[D");
    for (int i = 0; i < len; i++)
        printf(" ");
    for (int i = 0; i < len; i++)
        printf("\033[D");
}

int Core::historyArrow(int arrow)
{
    if (arrow == 5) {
        if (this->index == 0) return 9;
        this->index--;
    } else if (arrow == 6) {
        if (this->_history.size() == 0) return 8;
        if (this->index == this->_history.size() - 1) return 8;
        this->index++;
    }
    cleanString(this->_commands.size());
    this->_commands = this->_history[this->index];
    this->cursor = this->_commands.length();
    printf("%s", this->_commands.c_str());
    return (7);
}

void Core::tabulation()
{
    if (this->_obj.size() == 0)
        this->setupPin();
    if (this->_indexObj == this->_obj.size())
        this->_indexObj = 0;

    cleanString(this->_commands.size());
    this->_commands = this->_obj[this->_indexObj];
    this->cursor = this->_commands.length();
    printf("%s", this->_commands.c_str());
    this->_indexObj++;
}

int Core::leftArrow()
{
    if (this->cursor != 0) {
        this->cursor--;
        printf("\033[D");
    }
    return (4);
}

void Core::printnext(int spaces)
{
    int index = 0;
    int j = 0;

    for (int i = 0; this->_commands[index] != '\0' && i != this->cursor; i++)
        index++;
    for (; this->_commands[index] != '\0'; j++, index++)
        printf("%c", this->_commands[index]);
    for (int i = 0; i < spaces; i++, j++)
        printf(" ");
    for (; j != 0; j--)
        printf("\033[D");
}

int Core::rightArrow()
{
    if (this->cursor != this->_commands.length()) {
        this->cursor++;
        printf("\033[C");
        this->printnext(1);
    }
    return (3);
}

int Core::checkKey()
{
    if (this->c == '\n')
        return (-1);
    else if (this->c == '\t') {
        this->tabulation();
        return (10); 
    }
    if (this->c == 27)
        return (this->getArrow());
    
    return (1);
}

int Core::getCode()
{
    int code = 1;

    code = this->checkKey();
    if (this->cursor != 0 && this->c == 127) {
        printf("\033[D");
        printf(" ");
        printf("\033[D");
        this->_commands.erase(this->cursor - 1, 1);
        this->cursor--;
        this->printnext(1);
    } else if (code == 1 && this->c != 127) {
        this->_commands.insert(this->cursor, 1, this->c);
        this->printnext(0);
        this->cursor++;
    }
    return (code);
}

void Core::ownShell()
{
    int code = 0;

    this->_exitValue = 0;
    while (1) {
        printf("> ");
        do {
            this->c = myGetchar();
            if (this->c == 4 || this->c == -1)
                return;
            code = this->getCode();
            if (code == -1)
                continue;
            else if (code == 1)
                printf("%c", this->c);
        } while (this->c != '\n');
        printf("\n");
        if (commandExec(this->_commands) == 1) {
            break;
            this->index = this->_history.size();
        }
        this->reset();
    }
}

void Core::reset()
{
    if (this->_commands.length() != 0) {
        this->_history.push_back(this->_commands);
        this->index = this->_history.size();
    }
    this->_commands.clear();
    this->c = ' ';
    this->cursor = 0;
    this->_indexObj = 0;
}

void Core::ttyShell()
{
    std::string buffer;

    while (std::getline(std::cin, buffer)) {
        if (!buffer.empty()) {
            this->_exitValue = 0;
            if (commandExec(buffer) == 1)
                break;
        }
        std::cout << this->_prompt;
    }
}

void Core::printHistory()
{
    int i = 0;

    for (std::vector<std::string>::iterator it = this->_history.begin(); it != this->_history.end(); ++it, ++i) {
        printf("%d : %s\n", i, it->c_str());
    }
}

void Core::clearShell()
{
    printf("\x1B[2J\x1B[H");
}