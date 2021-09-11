/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#include "4013Component.hpp"
#include <string>

C4013::C4013(const std::string &name)
        :AComponent(name, "4013",14)
{
    this->_pins[0] = new nts::APin(nts::OUT);
    this->_pins[1] = new nts::APin(nts::OUT);
    this->_pins[2] = new nts::APin(nts::IN);
    this->_pins[3] = new nts::APin(nts::IN);
    this->_pins[4] = new nts::APin(nts::IN);
    this->_pins[5] = new nts::APin(nts::IN);
    this->_pins[6] = new nts::APin(nts::OTHER);

    this->_pins[7] = new nts::APin(nts::IN);
    this->_pins[8] = new nts::APin(nts::IN);
    this->_pins[9] = new nts::APin(nts::IN);
    this->_pins[10] = new nts::APin(nts::IN);
    this->_pins[11] = new nts::APin(nts::OUT);
    this->_pins[12] = new nts::APin(nts::OUT);
    this->_pins[13] = new nts::APin(nts::OTHER);
}

void C4013::simulate(size_t tick)
{
    nts::LogicGate lg;
    std::pair<nts::Tristate, nts::Tristate> flipOne;
    std::pair<nts::Tristate, nts::Tristate> flipTwo;
    nts::Tristate dataOne[6] = {this->getValuePin(2), this->getValuePin(4),  this->getValuePin(3),
                            this->getValuePin(5), this->getValuePin(0), this->getValuePin(1)};
    nts::Tristate dataTwo[6] = {this->getValuePin(10), this->getValuePin(8),  this->getValuePin(9),
                            this->getValuePin(7), this->getValuePin(12), this->getValuePin(11)};

    tick = tick;
    if (this->_links.size() == 0)
        throw PinError("C4013 simulate: invalid link\n");

    flipOne = lg.flipFlop(dataOne);
    flipTwo = lg.flipFlop(dataTwo);


    this->setPinValue(0, flipOne.first);
    this->setPinValue(1, flipOne.second);
    this->setPinValue(12, flipTwo.first);
    this->setPinValue(11, flipTwo.second);

    this->sendData(0, this->_links[0].second);
    this->sendData(1, this->_links[1].second);
    this->sendData(12, this->_links[12].second);
    this->sendData(11, this->_links[11].second);

    this->_isCompute = true;
}