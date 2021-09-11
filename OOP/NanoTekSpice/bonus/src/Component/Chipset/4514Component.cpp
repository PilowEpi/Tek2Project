/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#include "4514Component.hpp"

C4514::C4514(const std::string &name)
        :AComponent(name, "4514",24)
{
    this->_pins[0] = new nts::APin(nts::IN);
    this->_pins[1] = new nts::APin(nts::IN);
    this->_pins[2] = new nts::APin(nts::IN);
    this->_pins[3] = new nts::APin(nts::OUT);
    this->_pins[4] = new nts::APin(nts::OUT);
    this->_pins[5] = new nts::APin(nts::OUT);
    this->_pins[6] = new nts::APin(nts::OUT);
    this->_pins[7] = new nts::APin(nts::OUT);
    this->_pins[8] = new nts::APin(nts::OUT);
    this->_pins[9] = new nts::APin(nts::OUT);
    this->_pins[10] = new nts::APin(nts::OUT);
    this->_pins[11] = new nts::APin(nts::OTHER);


    this->_pins[12] = new nts::APin(nts::OUT);
    this->_pins[13] = new nts::APin(nts::OUT);
    this->_pins[14] = new nts::APin(nts::OUT);
    this->_pins[15] = new nts::APin(nts::OUT);
    this->_pins[16] = new nts::APin(nts::OUT);
    this->_pins[17] = new nts::APin(nts::OUT);
    this->_pins[18] = new nts::APin(nts::OUT);
    this->_pins[19] = new nts::APin(nts::OUT);
    this->_pins[20] = new nts::APin(nts::IN);
    this->_pins[21] = new nts::APin(nts::IN);
    this->_pins[22] = new nts::APin(nts::IN);
    this->_pins[23] = new nts::APin(nts::OTHER);
}

void C4514::reset_decode()
{
    this->setPinValue(3, nts::FALSE);
    this->setPinValue(4, nts::FALSE);
    this->setPinValue(5, nts::FALSE);
    this->setPinValue(6, nts::FALSE);
    this->setPinValue(7, nts::FALSE);
    this->setPinValue(8, nts::FALSE);
    this->setPinValue(9, nts::FALSE);
    this->setPinValue(10, nts::FALSE);

    this->setPinValue(12, nts::FALSE);
    this->setPinValue(13, nts::FALSE);
    this->setPinValue(14, nts::FALSE);
    this->setPinValue(15, nts::FALSE);
    this->setPinValue(16, nts::FALSE);
    this->setPinValue(17, nts::FALSE);
    this->setPinValue(18, nts::FALSE);
    this->setPinValue(19, nts::FALSE);

    this->sendData(3, this->_links[13].second);
    this->sendData(4, this->_links[13].second);
    this->sendData(5, this->_links[13].second);
    this->sendData(6, this->_links[13].second);
    this->sendData(7, this->_links[13].second);
    this->sendData(8, this->_links[13].second);
    this->sendData(9, this->_links[13].second);
    this->sendData(10, this->_links[13].second);

    this->sendData(12, this->_links[13].second);
    this->sendData(13, this->_links[13].second);
    this->sendData(14, this->_links[13].second);
    this->sendData(15, this->_links[13].second);
    this->sendData(16, this->_links[13].second);
    this->sendData(17, this->_links[13].second);
    this->sendData(18, this->_links[13].second);
    this->sendData(19, this->_links[13].second);

}

void C4514::simulate(size_t tick)
{
    (void)tick;
    if (this->_links.empty())
        throw PinError("C4514 simulate: invalid link\n");

    //inhibit pin -> true
    if (this->getValuePin(22)) {
        reset_decode();
        this->_isCompute = true;
        return;
    }

    //  A=1 B=2 C=20 D=21
    //S0
    if (!this->getValuePin(1) && !this->getValuePin(2) && !this->getValuePin(20) && !this->getValuePin(21)) {
        reset_decode();

        this->setPinValue(10, nts::TRUE);
        this->sendData(10, this->_links[10].second);
        this->_isCompute = true;
        return;
    }
    //S1
    if (this->getValuePin(1) && !this->getValuePin(2) && !this->getValuePin(20) && !this->getValuePin(21)) {
        reset_decode();

        this->setPinValue(8, nts::TRUE);
        this->sendData(8, this->_links[8].second);
        this->_isCompute = true;
        return;
    }
    //S2
    if (!this->getValuePin(1) && this->getValuePin(2) && !this->getValuePin(20) && !this->getValuePin(21)) {
        reset_decode();

        this->setPinValue(9, nts::TRUE);
        this->sendData(9, this->_links[9].second);
        this->_isCompute = true;
        return;
    }
    //S3
    if (this->getValuePin(1) && this->getValuePin(2) && !this->getValuePin(20) && !this->getValuePin(21)) {
        reset_decode();

        this->setPinValue(7, nts::TRUE);
        this->sendData(7, this->_links[7].second);
        this->_isCompute = true;
        return;
    }

    //S4
    if (!this->getValuePin(1) && !this->getValuePin(2) && this->getValuePin(20) && !this->getValuePin(21)) {
        reset_decode();
        this->setPinValue(6, nts::TRUE);
        this->sendData(6, this->_links[6].second);
        this->_isCompute = true;
        return;
    }
    //S5
    if (this->getValuePin(1) && !this->getValuePin(2) && this->getValuePin(20) && !this->getValuePin(21)) {
        reset_decode();
        this->setPinValue(5, nts::TRUE);
        this->sendData(5, this->_links[5].second);
        this->_isCompute = true;
        return;
    }
    //S6
    if (!this->getValuePin(1) && this->getValuePin(2) && this->getValuePin(20) && !this->getValuePin(21)) {
        reset_decode();
        this->setPinValue(4, nts::TRUE);
        this->sendData(4, this->_links[4].second);
        this->_isCompute = true;
        return;
    }
    //S7
    if (this->getValuePin(1) && this->getValuePin(2) && this->getValuePin(20) && !this->getValuePin(21)) {
        reset_decode();
        this->setPinValue(3, nts::TRUE);
        this->sendData(3, this->_links[3].second);
        this->_isCompute = true;
        return;
    }

    //S8
    if (!this->getValuePin(1) && !this->getValuePin(2) && !this->getValuePin(20) && this->getValuePin(21)) {
        reset_decode();
        this->setPinValue(17, nts::TRUE);
        this->sendData(17, this->_links[17].second);
        this->_isCompute = true;
        return;
    }
    //S9
    if (this->getValuePin(1) && !this->getValuePin(2) && !this->getValuePin(20) && this->getValuePin(21)) {
        reset_decode();
        this->setPinValue(16, nts::TRUE);
        this->sendData(16, this->_links[16].second);
        this->_isCompute = true;
        return;
    }
    //S10
    if (!this->getValuePin(1) && this->getValuePin(2) && !this->getValuePin(20) && this->getValuePin(21)) {
        reset_decode();
        this->setPinValue(19, nts::TRUE);
        this->sendData(19, this->_links[19].second);
        this->_isCompute = true;
        return;
    }
    //S11
    if (this->getValuePin(1) && this->getValuePin(2) && !this->getValuePin(20) && this->getValuePin(21)) {
        reset_decode();
        this->setPinValue(18, nts::TRUE);
        this->sendData(18, this->_links[18].second);
        this->_isCompute = true;
        return;
    }

    //S12
    if (!this->getValuePin(1) && !this->getValuePin(2) && this->getValuePin(20) && this->getValuePin(21)) {
        reset_decode();
        this->setPinValue(13, nts::TRUE);
        this->sendData(13, this->_links[13].second);
        this->_isCompute = true;
        return;
    }
    //S13
    if (this->getValuePin(1) && !this->getValuePin(2) && this->getValuePin(20) && this->getValuePin(21)) {
        reset_decode();
        this->setPinValue(12, nts::TRUE);
        this->sendData(12, this->_links[12].second);
        this->_isCompute = true;
        return;
    }
    //S14
    if (!this->getValuePin(1) && this->getValuePin(2) && this->getValuePin(20) && this->getValuePin(21)) {
        reset_decode();
        this->setPinValue(15, nts::TRUE);
        this->sendData(15, this->_links[15].second);
        this->_isCompute = true;
        return;
    }
    //S15
    if (this->getValuePin(1) && this->getValuePin(2) && this->getValuePin(20) && this->getValuePin(21)) {
        reset_decode();
        this->setPinValue(14, nts::TRUE);
        this->sendData(14, this->_links[14].second);
        this->_isCompute = true;
        return;
    }
}