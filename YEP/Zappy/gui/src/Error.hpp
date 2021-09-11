/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** Error
*/

#ifndef ERROR_ZAPPY_HPP_
#define ERROR_ZAPPY_HPP_

#include <string>
#include <exception>

class GuiError : public std::exception
{
    public:
        GuiError(std::string const &message, std::string const &component = "GuiError")
        : _message(message), _component(component) {};

        std::string const &getComponent() const noexcept { return _component;};
        const char *what() const noexcept {return _message.c_str();};
    private:
        std::string _message;
        std::string _component;
};


class NetworkError : public GuiError
{
    public:
        NetworkError(std::string const &message, std::string const &component = "Network Error")
        : GuiError(message, component) {};
};

#endif