/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** Nano
*/

#include "Nano.hpp"
#include "Core.hpp"

Nano::Nano(const std::string &filename)
{
    Parser fileParser(filename);

    this->createAllComponents(fileParser.getComponent());
    this->createAllLinks(fileParser.getLinks());
}

Nano::~Nano()
{
    for (auto &component : this->_components) {
        delete component.second;
    }
}

void Nano::createAllComponents(std::map<std::string, std::string> components)
{
    ComponentFactory f;
    nts::IComponent *currentComponent = NULL;

    for (auto component : components) {
        currentComponent = f.createComponent(component.second, component.first);
        this->_components[component.first] = currentComponent;
    }
}

std::map<std::string, nts::IComponent *> Nano::getAllComponent()
{
    return this->_components;
}

std::vector<std::string> Nano::mySplit(const std::string &origin, char delim)
{
    std::vector<std::string> result;
    std::string line;
    std::istringstream stream(origin);
    
    while (getline(stream, line, delim))
        result.push_back(line);
    return (result);
}

void Nano::createAllLinks(std::map<std::string, std::string> links)
{
    std::vector<std::string> start;
    std::vector<std::string> end;
    nts::IComponent *component;
    int firstPin;
    int secondPin;

    for (auto link : links) {
        start = mySplit(link.first, ':');
        end = mySplit(link.second, ':');

        if (start.size() != 2 || end.size() != 2)
            throw FileError("createAllLinks: Invalid links\n");
        try {
            firstPin = std::stoi(start[1]) - 1;
            secondPin = std::stoi(end[1]) - 1;
        } catch (const std::exception &) {
            throw FileError("createAllLinks: Invalid pin (need a number but got : \""+start[1]+"\" and \""+end[1]+"\"\n");
        }
        if (firstPin < 0 || secondPin < 0)
            throw FileError("createAllLinks: Invalid pin (negative pin)\n");
        component = this->_components[start[0]];
        if (component == nullptr)
            throw FileError("createAllLinks: Invalid name of links (\""+start[0]+"\")\n");
        component->setLink(firstPin, *this->_components[end[0]], secondPin);
    }

    // for (auto comp : this->_components)
        // comp.second->dump();
}