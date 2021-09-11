
#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>
#include <exception>

class CommunicationError : public std::exception
{
    public:
        CommunicationError(std::string const &message,
                std::string const &component = "CommunicationDevice")
                : _message(message), _component(component) {};

        std::string const &getComponent() const noexcept { return _component;};
        const char *what() const noexcept {return _message.c_str();};
    private:
        std::string _message;
        std::string _component;
};

#endif