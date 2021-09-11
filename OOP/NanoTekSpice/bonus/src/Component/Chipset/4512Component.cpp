/*
** EPITECH PROJECT, 2021
** 4512Component.cpp
** File description:
** nano
*/

#include "4512Component.hpp"

C4512::C4512(const std::string &name)
        :AComponent(name, "4512",16)
{
    this->_pins[0] = new nts::APin(nts::IN);
    this->_pins[1] = new nts::APin(nts::IN);
    this->_pins[2] = new nts::APin(nts::IN);
    this->_pins[3] = new nts::APin(nts::IN);
    this->_pins[4] = new nts::APin(nts::IN);
    this->_pins[5] = new nts::APin(nts::IN);
    this->_pins[6] = new nts::APin(nts::IN);
    this->_pins[7] = new nts::APin(nts::OTHER);

    this->_pins[8] = new nts::APin(nts::IN);
    this->_pins[9] = new nts::APin(nts::IN);
    this->_pins[10] = new nts::APin(nts::IN);
    this->_pins[11] = new nts::APin(nts::IN);
    this->_pins[12] = new nts::APin(nts::IN);
    this->_pins[13] = new nts::APin(nts::OUT);
    this->_pins[14] = new nts::APin(nts::IN);
    this->_pins[15] = new nts::APin(nts::OTHER);

}

void C4512::simulate(size_t tick)
{
    tick = tick;
    if (this->_links.size() == 0)
        throw PinError("C4512 simulate: invalid link\n");

    //OE pin -> true
    if (this->getValuePin(14)) {
        this->setPinValue(13, nts::UNDEFINED);
        this->sendData(13, this->_links[13].second);
        this->_isCompute = true;
        return;
    }

    //inhibit pin -> true
    if (this->getValuePin(9) && !this->getValuePin(14)) {
        this->setPinValue(13, nts::FALSE);
        this->sendData(13, this->_links[13].second);
        this->_isCompute = true;
        return;
    }

    //X0
    if (!this->getValuePin(10) && !this->getValuePin(11) && !this->getValuePin(12)) {
        this->setPinValue(13, this->getValuePin(0));
        this->sendData(13, this->_links[13].second);
        this->_isCompute = true;
        return;
    }

    //X1
    if (this->getValuePin(10) && !this->getValuePin(11) && !this->getValuePin(12)) {
        this->setPinValue(13, this->getValuePin(1));
        this->sendData(13, this->_links[13].second);
        this->_isCompute = true;
        return;
    }

    //X2
    if (!this->getValuePin(10) && this->getValuePin(11) && !this->getValuePin(12)) {
        this->setPinValue(13, this->getValuePin(2));
        this->sendData(13, this->_links[13].second);
        this->_isCompute = true;
        return;
    }

    //X3
    if (this->getValuePin(10) && this->getValuePin(11) && !this->getValuePin(12)) {
        this->setPinValue(13, this->getValuePin(3));
        this->sendData(13, this->_links[13].second);
        this->_isCompute = true;
        return;
    }

    //X4
    if (!this->getValuePin(10) && !this->getValuePin(11) && this->getValuePin(12)) {
        this->setPinValue(13, this->getValuePin(4));
        this->sendData(13, this->_links[13].second);
        this->_isCompute = true;
        return;
    }

    //X5
    if (this->getValuePin(10) && !this->getValuePin(11) && this->getValuePin(12)) {
        this->setPinValue(13, this->getValuePin(5));
        this->sendData(13, this->_links[13].second);
        this->_isCompute = true;
        return;
    }

    //X6
    if (!this->getValuePin(10) && this->getValuePin(11) && this->getValuePin(12)) {
        this->setPinValue(13, this->getValuePin(6));
        this->sendData(13, this->_links[13].second);
        this->_isCompute = true;
        return;
    }

    //X7
    if (this->getValuePin(10) && this->getValuePin(11) && this->getValuePin(12)) {
        this->setPinValue(13, this->getValuePin(8));
        this->sendData(13, this->_links[13].second);
        this->_isCompute = true;
        return;
    }
}