/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"

ComponentFactory::ComponentFactory()
{
    this->_cFunctor = {{"input", [&](std::string name) {return this->createInput(name);}},
                        {"output", [&](std::string name) {return this->createOutput(name);}},
                        {"true", [&](std::string name) {return this->createTrue(name);}},
                        {"false", [&](std::string name) {return this->createFalse(name);}},
                        {"clock", [&](std::string name) {return this->createClock(name);}},
                        {"4001", [&](std::string name) {return new C4001(name);}},
                        {"4011", [&](std::string name) {return new C4011(name);}},
                        {"4030", [&](std::string name) {return new C4030(name);}},
                        {"4069", [&](std::string name) {return new C4069(name);}},
                        {"4071", [&](std::string name) {return new C4071(name);}},
                        {"4008", [&](std::string name) {return new C4008(name);}},
                        {"4013", [&](std::string name) {return new C4013(name);}},
                        {"4017", [&](std::string name) {return new C4017(name);}},
                        {"4040", [&](std::string name) {return new C4040(name);}},
                        {"logger", [&](std::string name) {return new CLogger(name);}},
                        {"4512", [&](std::string name) {return new C4512(name);}},
                        {"4081", [&](std::string name) {return this->create4081(name);}}};
}

nts::IComponent *ComponentFactory::createComponent(const std::string type, const std::string name)
{
    if (this->_cFunctor[type] == NULL)
        throw FileError("createComponent : invalid type of component : " + type + "\n");
    return (this->_cFunctor[type](name));
}

nts::IComponent *ComponentFactory::createInput(const std::string name)
{
    return (new InputComponent(name));
}

nts::IComponent *ComponentFactory::createOutput(const std::string name)
{
    return (new OutputComponent(name));
}

nts::IComponent *ComponentFactory::createTrue(const std::string name)
{
    return (new TrueComponent(name));
}

nts::IComponent *ComponentFactory::createFalse(const std::string name)
{
    return (new FalseComponent(name));
}

nts::IComponent *ComponentFactory::createClock(const std::string name)
{
    return (new ClockComponent(name));
}

nts::IComponent *ComponentFactory::create4081(const std::string name)
{
    return (new C4081(name));
}

nts::IComponent *ComponentFactory::create4001(const std::string name)
{
    return (new C4001(name));
}

nts::IComponent *ComponentFactory::create4011(const std::string name)
{
    return (new C4011(name));
}

nts::IComponent *ComponentFactory::create4030(const std::string name)
{
    return (new C4030(name));
}

nts::IComponent *ComponentFactory::create4069(const std::string name)
{
    return (new C4069(name));
}

nts::IComponent *ComponentFactory::create4071(const std::string name)
{
    return (new C4071(name));
}

nts::IComponent *ComponentFactory::create4512(const std::string name)
{
    return (new C4512(name));
}

nts::IComponent *ComponentFactory::create4008(const std::string name)
{
    return (new C4008(name));
}