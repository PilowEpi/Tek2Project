/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#include "4040Component.hpp"

C4040::C4040(const std::string &name)
        :AComponent(name, "4040",16)
{
    this->_pins[0] = new nts::APin(nts::OUT); // Q12
    this->_pins[1] = new nts::APin(nts::OUT); // Q6
    this->_pins[2] = new nts::APin(nts::OUT); // Q5
    this->_pins[3] = new nts::APin(nts::OUT); // Q7
    this->_pins[4] = new nts::APin(nts::OUT); // Q4
    this->_pins[5] = new nts::APin(nts::OUT); // Q3
    this->_pins[6] = new nts::APin(nts::OUT); // Q2
    this->_pins[7] = new nts::APin(nts::OTHER); // Vss

    this->_pins[8] = new nts::APin(nts::OUT); // Q1
    this->_pins[9] = new nts::APin(nts::IN); // Clock
    this->_pins[10] = new nts::APin(nts::IN); // Reset
    this->_pins[11] = new nts::APin(nts::OUT); // Q9
    this->_pins[12] = new nts::APin(nts::OUT); // Q8
    this->_pins[13] = new nts::APin(nts::OUT); // Q10
    this->_pins[14] = new nts::APin(nts::OUT); // Q11
    this->_pins[15] = new nts::APin(nts::OTHER); // Vdd

    this->_counter = 0;
}

void C4040::addOneBinary()
{
    int result = this->_counter;

    for (int i = 0; result > 0; i++) {
        this->_binary[i] = result % 2;
        result = result / 2;
    }
    /* Debug
    std::cout << "[ ";
    for (int i = 0; i < 12; i++) {
        std::cout << this->_binary[i] << ", ";
    }
    std::cout << "]";
    std::cout << std::endl;
    */
}

void C4040::setAllValues()
{
    int key[] = {8, 6, 5, 4, 2, 1, 3, 12, 11, 13, 14, 0};
    nts::Tristate temp;

    for (int i = 0; i < 12; i++) {
        temp = (this->_binary[i] == 1) ? nts::TRUE : nts::FALSE;
        this->setPinValue(key[i], temp);
    }
}

void C4040::simulate(size_t tick)
{
    if (this->_isCompute == true)
        return;
    // Compute
    this->_isCompute = true;
    
    // Reset
    if (this->getValuePin(10) == nts::FALSE || this->_counter == 0) {
        for (size_t i = 0; i < 15; i++) {
            if (this->getPinType(i) == nts::OUT)
                this->setPinValue(i, nts::FALSE);
        }
        this->_counter = 1;
        for (size_t i = 0; i < 12; i++)
            this->_binary[i] = 0;

        // SendData TODO : Faire en une seule ligne :)
        for (int i = 0; i < 15; i++) {
            if (this->getPinType(i) != nts::OUT)
                continue;
            this->sendData(i, this->_links[i].second);
        }
        return;
    }
    if (this->getValuePin(9) == nts::FALSE && this->_last == nts::TRUE) {
        this->addOneBinary();
        this->_counter++;
    }
    this->setAllValues();
    // SendData TODO : Faire en une seule ligne :)
    for (int i = 0; i < 15; i++) {
        if (this->getPinType(i) != nts::OUT)
            continue;
        this->sendData(i, this->_links[i].second);
    }
}