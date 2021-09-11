/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#include "4030Component.hpp"

C4030::C4030(const std::string &name)
        :AComponent(name, "4030",14)
{
    this->_pins[0] = new nts::APin(nts::IN);
    this->_pins[1] = new nts::APin(nts::IN);
    this->_pins[2] = new nts::APin(nts::OUT);
    this->_pins[3] = new nts::APin(nts::OUT);
    this->_pins[4] = new nts::APin(nts::IN);
    this->_pins[5] = new nts::APin(nts::IN);
    this->_pins[6] = new nts::APin(nts::OTHER);

    this->_pins[7] = new nts::APin(nts::IN);
    this->_pins[8] = new nts::APin(nts::IN);
    this->_pins[9] = new nts::APin(nts::OUT);
    this->_pins[10] = new nts::APin(nts::OUT);
    this->_pins[11] = new nts::APin(nts::IN);
    this->_pins[12] = new nts::APin(nts::IN);
    this->_pins[13] = new nts::APin(nts::OTHER);
}

void C4030::simulate(size_t tick)
{
    nts::LogicGate lg;

    tick = tick;
    if (this->_links.size() == 0)
        throw PinError("C4030 simulate: invalid link\n");
    if (tick == 2) {
        this->setPinValue(2, lg.XORGate(this->getValuePin(0), this->getValuePin(1)));
    }
    if (tick == 3) {
        this->setPinValue(3, lg.XORGate(this->getValuePin(4), this->getValuePin(5)));
    }
    if (tick == 9) {
        this->setPinValue(9, lg.XORGate(this->getValuePin(8), this->getValuePin(7)));
    }
    if (tick == 10) {
        this->setPinValue(10, lg.XORGate(this->getValuePin(11), this->getValuePin(12)));
    }

    this->sendData(2, this->_links[2].second);
    this->sendData(3, this->_links[3].second);
    this->sendData(9, this->_links[9].second);
    this->sendData(10, this->_links[10].second);

    this->_isCompute = true;
}