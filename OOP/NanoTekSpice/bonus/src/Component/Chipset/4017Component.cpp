/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#include "4017Component.hpp"

C4017::C4017(const std::string &name)
        :AComponent(name, "4017",16)
{
    this->_pins[0] = new nts::APin(nts::OUT); // Q5
    this->_pins[1] = new nts::APin(nts::OUT); // Q1
    this->_pins[2] = new nts::APin(nts::OUT); // Q0
    this->_pins[3] = new nts::APin(nts::OUT); // Q2
    this->_pins[4] = new nts::APin(nts::OUT); // Q6
    this->_pins[5] = new nts::APin(nts::OUT); // Q7
    this->_pins[6] = new nts::APin(nts::OUT); // Q3
    this->_pins[7] = new nts::APin(nts::OTHER);

    this->_pins[8] = new nts::APin(nts::OUT); // Q8
    this->_pins[9] = new nts::APin(nts::OUT); // Q4
    this->_pins[10] = new nts::APin(nts::OUT); // Q9
    this->_pins[11] = new nts::APin(nts::OUT); // Q5-9
    this->_pins[12] = new nts::APin(nts::IN); // CP1 => inhibit
    this->_pins[13] = new nts::APin(nts::IN); // CP0 => Clock
    this->_pins[14] = new nts::APin(nts::IN); // MR => reset
    this->_pins[15] = new nts::APin(nts::OTHER);
}

size_t C4017::getIndexOfQ()
{
    for (int i = 0; i < 11; i++) {
        if (this->getPinType(i) == nts::OTHER)
            continue;
        if (this->getValuePin(i) == nts::TRUE)
            return (i);
    }
    return (99); // Q NULL
}

size_t getNextQ(size_t index)
{
    int key[] = {5, 1, 0, 2, 6, 7, 3, 88, 8, 4, 9};
    int value;

    if (index == 10)
        return (2);
    for (int i = 0; i < 11 ; i++) {
        if (index == i)
            value = key[i];
    }
    value++;
    for (int i = 0; i < 11 ; i++) {
        if (value == key[i])
            return i;
    }
    return (99); // Index NULL
} 

void C4017::simulate(size_t tick)
{
    nts::LogicGate lg;
    size_t index = this->getIndexOfQ();
    size_t next;
    
    if (this->_isCompute == true)
        return;
    this->_isCompute = true;

    // Reset/Init 4017
    if (this->getValuePin(14) == nts::TRUE || index == 99) {
        
        this->setPinValue(11, nts::TRUE); // Carry Out
        this->setPinValue(2, nts::TRUE);
        for (int i = 0; i < 11 ; i++) {
            if (this->getPinType(i) == nts::OTHER || i == 2)
                continue;
            this->setPinValue(i, nts::FALSE);
        }
    } 
    // Clock/Inhibit Check
    if ((this->getValuePin(13) == nts::TRUE && this->_last == nts::FALSE) || this->getValuePin(12) != nts::FALSE) {
        return;
    } else {
        // Counter +1
        next = getNextQ(index);
        this->setPinValue(index, nts::FALSE);
        this->setPinValue(next, nts::TRUE);
        if (next == 0)
            this->setPinValue(11, nts::FALSE); // Carry Out
        else if (next == 2)
            this->setPinValue(11, nts::TRUE); // Carry Out Reset
    }

    // SendData
    for (int i = 0; i < 15; i++) {
        if (this->getPinType(i) != nts::OUT)
            continue;
        this->sendData(i, this->_links[i].second);
    }
}