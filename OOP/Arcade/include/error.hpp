/*
** EPITECH PROJECT, 2020
** OOP Arcade
** File description:
** error.hpp
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>
#include <exception>

/**
 * @brief Class ArcadeError
 * 
 * The main class for every error / exception thrown by the arcade project.
 * 
 */
class ArcadeError : public std::exception
{
    public:
        ArcadeError(std::string const &message, std::string const &component = "Error")
        : _message(message), _component(component) {};

        /**
         * @brief Function that returns the error message.
         */
        std::string const &getComponent() const noexcept { return _component;};

        /**
         * 
         */
        const char *what() const noexcept {return _message.c_str();};
    private:
        std::string _message;
        std::string _component;
};

class LibraryError : public ArcadeError
{
    public:
        LibraryError(std::string const &message, std::string const &component = "Lib Error :")
        : ArcadeError(message, component) {};
};

class GameError : public ArcadeError
{
    public:
        GameError(std::string const &message, std::string const &component = "Game Error :")
        : ArcadeError(message, component) {};
};

class GraphicError : public ArcadeError
{
    public:
        GraphicError(std::string const &message, std::string const &component = "Graphic Error :")
        : ArcadeError(message, component) {};
};

#endif