/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** ComponentFactory
*/

#ifndef COMPONENT_FACTORY_HPP_
#define COMPONENT_FACTORY_HPP_

#include <map>
#include <string>
#include <functional>
#include "Error.hpp"

// Component

#include "Input.hpp"
#include "Output.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Clock.hpp"
#include "4081Component.hpp"
#include "4001Component.hpp"
#include "4011Component.hpp"
#include "4030Component.hpp"
#include "4069Component.hpp"
#include "4071Component.hpp"
#include "4008Component.hpp"
#include "4013Component.hpp"
#include "4017Component.hpp"
#include "4512Component.hpp"
#include "4040Component.hpp"
#include "LoggerComponent.hpp"

class ComponentFactory
{
    public:
        ComponentFactory();
        ~ComponentFactory() {};

        nts::IComponent *createComponent(const std::string type, const std::string name);
        nts::IComponent *createInput(const std::string name);
        nts::IComponent *createOutput(const std::string name);
        nts::IComponent *createTrue(const std::string name);
        nts::IComponent *createFalse(const std::string name);
        nts::IComponent *createClock(const std::string name);
        nts::IComponent *create4081(const std::string name);
        nts::IComponent *create4001(const std::string name);
        nts::IComponent *create4011(const std::string name);
        nts::IComponent *create4030(const std::string name);
        nts::IComponent *create4069(const std::string name);
        nts::IComponent *create4071(const std::string name);
        nts::IComponent *create4008(const std::string name);
        nts::IComponent *create4512(const std::string name);
    private:
        std::map<std::string, std::function<nts::IComponent *(std::string)>> _cFunctor;
};

#endif