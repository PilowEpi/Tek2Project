/*
** EPITECH PROJECT, 2021
** CoreCommands.cpp
** File description:
** CoreCommands.cpp
*/

#include "Core.hpp"
#include <exception>
#include <map>

SigIntError::SigIntError()
{
    this->_message = "ctrl + c pressed";
}

void Core::assign(const std::string &command)
{
    std::vector<std::string> vector = _nano->mySplit(command, '=');
    std::map<std::string, nts::IComponent *> mymap = this->_nano->getAllComponent();
    nts::AComponent *c;

    if (vector.size() == 2) {
        auto temp = mymap.find(vector[0]);
        if (temp == mymap.end()) {
            std::cout << "Invalid Command" << std::endl;
            return;
        }
        c = static_cast<nts::AComponent *> (temp->second);
        if (c == nullptr)
            std::cout << "Invalid Command" << std::endl;
        else if (c->getType() == "input" ||  c->getType() == "clock") {
            c->makeInit();
            if (vector[1] == "0")
                c->setPinValue(0, nts::FALSE);
            else if (vector[1] == "1")
                c->setPinValue(0, nts::TRUE);
            else if (vector[1] == "U")
                c->setPinValue(0, nts::UNDEFINED);
            else
                std::cout << "Invalid Command" << std::endl;
        }
        else {
            std::cout << "Invalid Component type" << std::endl;
        }
    }
    else
        std::cout << "Invalid Command" << std::endl;
}

void Core::refreshDisplay()
{
    std::map<std::string, nts::IComponent *> _componentsMap = this->_nano->getAllComponent();
    
    this->_buff.str("");
    this->_buff.clear();
    this->_buff << "tick: " << this->_ticks << std::endl;
    this->_buff << "input(s):" << std::endl;
    for (auto &compo : _componentsMap) {
        auto *c = static_cast<nts::AComponent *> (compo.second);
        if (c->getType() == "input" || c->getType() == "clock") {
            if (c->getSimplePin(0) == nts::TRUE)
                this->_buff << "  " << c->getName() << ": 1" << std::endl;
            if (c->getSimplePin(0) == nts::FALSE)
                this->_buff << "  " << c->getName() << ": 0" << std::endl;
            if (c->getSimplePin(0) == nts::UNDEFINED)
                this->_buff << "  " << c->getName() << ": U" << std::endl;
        }
    }

    this->_buff << "output(s):"<< std::endl;
    for (auto &compote : _componentsMap) {
        auto *c = static_cast<nts::AComponent *> (compote.second);
        if (c->getType() == "output") {
            if (c->getSimplePin(0) == nts::TRUE)
                this->_buff << "  " << c->getName() << ": 1" << std::endl;
            if (c->getSimplePin(0) == nts::FALSE)
                this->_buff << "  " << c->getName() << ": 0" << std::endl;
            if (c->getSimplePin(0) == nts::UNDEFINED)
                this->_buff << "  " << c->getName() << ": U" << std::endl;
        }
    }

}

void Core::display()
{
    std::cout << this->_buff.str();
}

void Core::simulate()
{
    std::map<std::string, nts::IComponent *> _componentsMap = this->_nano->getAllComponent();
    nts::AComponent *current;

    for (auto &component : _componentsMap) {
        current = static_cast<nts::AComponent *> (component.second);
        if (current->getType() == "output") {
            current->simulate(0);
            //break;
        }
    }
    for (auto &component : _componentsMap) {
        current = static_cast<nts::AComponent *> (component.second);
        current->setCompute(false);
    }
    this->_ticks++;
    this->refreshDisplay();
}

void Core::signal_sigint_handler(int signum)
{
    throw SigIntError();
}

void Core::loop()
{
    try {
        signal(SIGINT, this->signal_sigint_handler);
        while (true) {
            simulate();
            display();
            sleep(1);
        }
    } catch (SigIntError const & e) {
        std::cout << "loop : exit with CTRL + C" << std::endl;
    }
}

void Core::dump()
{
    std::map<std::string, nts::IComponent *> _componentsMap = this->_nano->getAllComponent();
    nts::AComponent *current;
    
    for (auto component : _componentsMap) {
        current = static_cast<nts::AComponent *> (component.second);
        current->dump();
    }
}