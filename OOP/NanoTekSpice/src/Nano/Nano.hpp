/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** Nano
*/

#ifndef NANO_HPP_
#define NANO_HPP_

#include <map>
#include "Error.hpp"
#include "IComponent.hpp"
#include "Parser.hpp"
#include "ComponentFactory.hpp"

class Nano
{
    public:
        Nano(const std::string &filename);
        ~Nano();

        void createAllComponents(std::map<std::string, std::string> components);
        void createAllLinks(std::map<std::string, std::string> links);
        std::map<std::string, nts::IComponent *> getAllComponent();
        std::vector<std::string> mySplit(const std::string &origin, char delim);
    private:
        std::map<std::string, nts::IComponent *> _components;
};

#endif