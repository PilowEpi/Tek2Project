/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#include "2716Component.hpp"

C2716::C2716(const std::string &name)
        :AComponent(name, "2716",24)
{
    this->_pins[0] = new nts::APin(nts::IN);
    this->_pins[1] = new nts::APin(nts::IN);
    this->_pins[2] = new nts::APin(nts::IN);
    this->_pins[3] = new nts::APin(nts::IN);
    this->_pins[4] = new nts::APin(nts::IN);
    this->_pins[5] = new nts::APin(nts::IN);
    this->_pins[6] = new nts::APin(nts::IN);
    this->_pins[7] = new nts::APin(nts::IN);

    this->_pins[8] = new nts::APin(nts::OUT);
    this->_pins[9] = new nts::APin(nts::OUT);
    this->_pins[10] = new nts::APin(nts::OUT);
    this->_pins[11] = new nts::APin(nts::OTHER);
    this->_pins[12] = new nts::APin(nts::OUT);
    this->_pins[13] = new nts::APin(nts::OUT);
    this->_pins[14] = new nts::APin(nts::OUT);
    this->_pins[15] = new nts::APin(nts::OUT);
    this->_pins[16] = new nts::APin(nts::OUT);

    this->_pins[17] = new nts::APin(nts::IN);
    this->_pins[18] = new nts::APin(nts::IN);
    this->_pins[19] = new nts::APin(nts::IN);

    this->_pins[20] = new nts::APin(nts::OTHER);
    this->_pins[21] = new nts::APin(nts::IN);
    this->_pins[22] = new nts::APin(nts::IN);
    this->_pins[23] = new nts::APin(nts::OTHER);
}
