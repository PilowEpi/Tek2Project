/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** AComponent
*/

#include "AComponent.hpp"

nts::AComponent::AComponent(const std::string &name, const std::string &type, size_t nbrPin)
    : _name(name), _nbrPin(nbrPin), _type(type), _isCompute(false)
{
    this->_last = nts::UNDEFINED;
}

nts::AComponent::~AComponent()
{
    for (auto pin: this->_pins) {
        delete pin.second;
    }
}

nts::Tristate nts::AComponent::getValuePin(size_t pin)
{
    if (this->_nbrPin < pin)
        throw PinError("getValuePin: try to reach unvailable pin\n");
    if (this->getPinType(pin) == nts::OTHER)
        throw PinError("getValuePin: try to reach bad pin\n");
    this->simulateBack(pin);
    return (this->_pins[pin]->getPinValue());
}

nts::PinType nts::AComponent::getPinType(size_t pin)
{
    if (this->_nbrPin < pin)
        throw PinError("getPinType: try to reach unvailable type of pin\n");
    return (this->_pins[pin]->getPinType());
}

nts::IComponent *nts::AComponent::getLink(size_t pin)
{
    nts::IComponent *link = this->_links[pin].second;
    
    if (link == NULL)
        throw PinError("getLink: try to reach unvailable link\n");
    return (link);
}

void nts::AComponent::addLink(nts::IComponent *link, size_t start, size_t dest)
{
    auto linkVerif = this->_links.find(start);
    
    if (linkVerif != this->_links.end())
        throw FileError("addLink: link already set\n");
    if (link == NULL)
        throw ChipsetError("addLink: try to create a null link\n");
    if (start > this->_nbrPin - 1)
        throw FileError("addLink: try to create a invalid link\n");
    if (this->getPinType(start) == nts::OTHER)
        throw FileError("addLink: try to create a link to a bad pin\n");
    this->_links.insert({start, {dest, link}});
}

void nts::AComponent::setPinValue(size_t pin, nts::Tristate value)
{
    if (this->_pins.size() < pin)
        throw ChipsetError("setPinValue: try to set a unvailable pin\n");
    if (this->getPinType(pin) == nts::OTHER)
        throw ChipsetError("setPinValue: try to set a pin that's not a I/O pin\n");
    this->_pins[pin]->setPinValue(value);
}

std::string nts::AComponent::getTypeFormated(nts::PinType type)
{
    switch (type)
    {
    case nts::OTHER:
        return "Other";
    case nts::IN:
        return "In";
    case nts::OUT:
        return "Out";
    default:
        return "";
    }
}

std::string nts::AComponent::getValueFormated(nts::Tristate value)
{
    switch (value)
    {
    case nts::UNDEFINED:
        return "Undefined";
    case nts::TRUE:
        return "True";
    case nts::FALSE:
        return "False";
    default:
        return "";
    }
}

void nts::AComponent::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
    nts::AComponent *otherAC;

    otherAC = static_cast<nts::AComponent *>(&other);
    if (otherAC == NULL)
        throw FileError("setLink: Invalid Link\n");
    if ((otherAC->getPinType(otherPin) == nts::IN && this->getPinType(pin) == nts::OUT) || 
        (otherAC->getPinType(otherPin) == nts::OUT && this->getPinType(pin) == nts::IN)) {
            otherAC->addLink(this, otherPin, pin);
            this->addLink(&other, pin, otherPin);
    } else {
        throw FileError("setlink: try to set a bad link\n");
    }
}

nts::Tristate nts::AComponent::compute(std::size_t pin)
{
    return (this->getValuePin(pin));
}

void nts::AComponent::simulateBack(size_t pin)
{
    nts::AComponent *temp = static_cast<nts::AComponent *> (this->_links[pin].second);
    std::string name;
    
    if (temp == NULL)
        return;
    name = temp->getType();
    if (name != "output") {
        temp->simulate(this->_links[pin].first);
    }
}

void nts::AComponent::dump()
{
    std::cout << "-------- Chipset "<< this->_type << " : " << this->_name <<"--------" << std::endl;
    std::cout << "\tMy Adress : " << this << std::endl;
    std::cout << "\tNb Of Pin : " << this->_nbrPin << std::endl;
    std::cout << "\tPin Info :" << std::endl;
    for (unsigned int i = 0; i < this->_nbrPin; i++) {
        std::cout << "\t-> " << i << " : " << this->getValueFormated(this->_pins[i]->getPinValue())  << " : ";
        std::cout << this->getTypeFormated(this->_pins[i]->getPinType()) << std::endl;
    }
    std::cout << "\tLink Info :" << std::endl;
    for (auto link : this->_links)
        std::cout << "\t-> " << link.first << " >=> " << link.second.first << " : " << link.second.second << std::endl;
    std::cout << std::endl;
}

void nts::AComponent::setCompute(bool value)
{
    this->_isCompute = value;
}

void nts::AComponent::sendData(size_t pin, nts::IComponent *link)
{
    nts::AComponent *out = static_cast<nts::AComponent *>(this->_links[pin].second);

    if (out == NULL)
        return;
    out->setPinValue(this->_links[pin].first, this->_pins[pin]->getPinValue());
}

void nts::AComponent::setLast(nts::Tristate value)
{
    this->_last = value;
}