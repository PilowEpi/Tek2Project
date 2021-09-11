/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** Nano
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>
#include <exception>

class NanoError : public std::exception
{
    public:
        NanoError(std::string const &message, std::string const &component = "Error")
        : _message(message), _component(component) {};

        std::string const &getComponent() const noexcept { return _component;};
        const char *what() const noexcept {return _message.c_str();};
    private:
        std::string _message;
        std::string _component;
};

class FileError : public NanoError
{
    public:
        FileError(std::string const &message, std::string const &component = "File Reader")
        : NanoError(message, component) {};
};

class UnknownTypeError : public NanoError
{
    public:
        UnknownTypeError(std::string const &message, std::string const &component = "Component Type")
        : NanoError(message, component) {};
};

class UnknownNameError : public NanoError
{
    public:
        UnknownNameError(std::string const &message, std::string const &component = "Component Name")
        : NanoError(message, component) {};
};

class PinError : public NanoError
{
    public:
        PinError(std::string const &message, std::string const &component = "Pin Selection")
        : NanoError(message, component) {};
};

class ComponentError : public NanoError
{
    public:
        ComponentError(std::string const &message, std::string const &component = "Component Creation")
        : NanoError(message, component) {};

};

class ChipsetError : public NanoError
{
    public:
        ChipsetError(std::string const &message, std::string const &component = "Chipset Selection")
        : NanoError(message, component) {};
};

//error for the ctrl + C
class SigIntError : public std::exception
{
public:
    SigIntError();

private:
    std::string _message;
};
#endif