/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#include "LoggerComponent.hpp"

CLogger::CLogger(const std::string &name)
        :AComponent(name, "logger", 10)
{
    this->_pins[0] = new nts::APin(nts::IN); // 1
    this->_pins[1] = new nts::APin(nts::IN); // 2
    this->_pins[2] = new nts::APin(nts::IN); // 4
    this->_pins[3] = new nts::APin(nts::IN); // 8
    this->_pins[4] = new nts::APin(nts::IN); // 16
    this->_pins[5] = new nts::APin(nts::IN); // 32
    this->_pins[6] = new nts::APin(nts::IN); // 64
    this->_pins[7] = new nts::APin(nts::IN); // 128
    this->_pins[8] = new nts::APin(nts::IN); // Clock
    this->_pins[9] = new nts::APin(nts::IN); // inhibit
}

void CLogger::simulate(size_t tick)
{
    nts::LogicGate lg;
    int data[] = {1, 2, 4, 8, 16, 32, 64, 128};
    int value = 0;
    char result;
    std::fstream file;

    tick = tick;
    this->_isCompute = true;
    if ((this->getValuePin(8) == nts::FALSE && this->_last == nts::TRUE) || this->getValuePin(9) != nts::FALSE)
        return;
    
    for (int i = 0; i < 8; i++) {
        if (this->getValuePin(i) == nts::TRUE)
            value += data[i];
    }
    result = value;
    file.open("./log.bin", std::ios::app);
    if (!file) {
        return;
    }
    file << result;
    file.close();
}