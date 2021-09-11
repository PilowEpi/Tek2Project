/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#include "4069Component.hpp"

C4069::C4069(const std::string &name)
        :AComponent(name, "4069",14)
{
    this->_pins[0] = new nts::APin(nts::IN);
    this->_pins[1] = new nts::APin(nts::OUT);
    this->_pins[2] = new nts::APin(nts::IN);
    this->_pins[3] = new nts::APin(nts::OUT);
    this->_pins[4] = new nts::APin(nts::IN);
    this->_pins[5] = new nts::APin(nts::OUT);
    this->_pins[6] = new nts::APin(nts::OTHER);

    this->_pins[7] = new nts::APin(nts::OUT);
    this->_pins[8] = new nts::APin(nts::IN);
    this->_pins[9] = new nts::APin(nts::OUT);
    this->_pins[10] = new nts::APin(nts::IN);
    this->_pins[11] = new nts::APin(nts::OUT);
    this->_pins[12] = new nts::APin(nts::IN);
    this->_pins[13] = new nts::APin(nts::OTHER);
}

void C4069::simulate(size_t tick)
{
    nts::LogicGate lg;

    tick = tick;
    if (this->_links.size() == 0)
        throw PinError("C4069 simulate: invalid link\n");
    if (tick == 1)
        this->setPinValue(1, lg.NOTGate(this->getValuePin(0)));
    if (tick == 3)
        this->setPinValue(3, lg.NOTGate(this->getValuePin(2)));
    if (tick == 5)
        this->setPinValue(5, lg.NOTGate(this->getValuePin(4)));
    if (tick == 7)
        this->setPinValue(7, lg.NOTGate(this->getValuePin(8)));
    if (tick == 9)
        this->setPinValue(9, lg.NOTGate(this->getValuePin(10)));
    if (tick == 11)
        this->setPinValue(11, lg.NOTGate(this->getValuePin(12)));
    
    this->sendData(1, this->_links[1].second);
    this->sendData(3, this->_links[3].second);
    this->sendData(5, this->_links[5].second);
    this->sendData(7, this->_links[7].second);
    this->sendData(9, this->_links[9].second);
    this->sendData(11, this->_links[11].second);

    this->_isCompute = true;
}