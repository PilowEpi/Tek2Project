/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#include "4008Component.hpp"

C4008::C4008(const std::string &name)
        :AComponent(name, "4008",16)
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
    this->_pins[9] = new nts::APin(nts::OUT);
    this->_pins[10] = new nts::APin(nts::OUT);
    this->_pins[11] = new nts::APin(nts::OUT);
    this->_pins[12] = new nts::APin(nts::OUT);
    this->_pins[13] = new nts::APin(nts::OUT);
    this->_pins[14] = new nts::APin(nts::IN);
    this->_pins[15] = new nts::APin(nts::OTHER);
}

void C4008::simulate(size_t tick)
{
    nts::LogicGate lg;
    nts::Tristate tri_xor = nts::UNDEFINED;
    nts::Tristate tri_and_one = nts::UNDEFINED;
    nts::Tristate tri_and_two = nts::UNDEFINED;

    tick = tick;
    if (this->_links.size() == 0)
        throw PinError("C4008 simulate: invalid link\n");


    // 1
    //Cin is false at the start
    tri_xor = lg.XORGate(this->getValuePin(6), this->getValuePin(5));
    tri_and_one = lg.ANDGate(this->getValuePin(6), this->getValuePin(5));;
    tri_and_two = lg.ANDGate(nts::FALSE, tri_xor);

    this->setPinValue(9, lg.XORGate(tri_xor, nts::FALSE));
    this->setPinValue(13, lg.ORGate(tri_and_two, tri_and_one));
    //Cin = Cout
    this->setPinValue(8, this->getValuePin(13));


    // 2
    //Cin is false at the start
    tri_xor = lg.XORGate(this->getValuePin(4), this->getValuePin(3));
    tri_and_one = lg.ANDGate(this->getValuePin(4), this->getValuePin(3));;
    tri_and_two = lg.ANDGate(this->getValuePin(8), tri_xor);

    this->setPinValue(10, lg.XORGate(tri_xor, this->getValuePin(8)));
    this->setPinValue(13, lg.ORGate(tri_and_two, tri_and_one));
    //Cin = Cout
    this->setPinValue(8, this->getValuePin(13));


    // 3
    //Cin is false at the start
    tri_xor = lg.XORGate(this->getValuePin(2), this->getValuePin(1));
    tri_and_one = lg.ANDGate(this->getValuePin(2), this->getValuePin(1));;
    tri_and_two = lg.ANDGate(this->getValuePin(8), tri_xor);

    this->setPinValue(11, lg.XORGate(tri_xor, this->getValuePin(8)));
    this->setPinValue(13, lg.ORGate(tri_and_two, tri_and_one));
    //Cin = Cout
    this->setPinValue(8, this->getValuePin(13));


    // 4
    //Cin is false at the start
    tri_xor = lg.XORGate(this->getValuePin(0), this->getValuePin(14));
    tri_and_one = lg.ANDGate(this->getValuePin(0), this->getValuePin(14));;
    tri_and_two = lg.ANDGate(this->getValuePin(8), tri_xor);

    this->setPinValue(12, lg.XORGate(tri_xor, this->getValuePin(8)));
    this->setPinValue(13, lg.ORGate(tri_and_two, tri_and_one));
    //Cin = Cout
    this->setPinValue(8, this->getValuePin(13));


    this->sendData(9, this->_links[9].second);
    this->sendData(10, this->_links[10].second);
    this->sendData(11, this->_links[11].second);
    this->sendData(12, this->_links[12].second);
    this->sendData(13, this->_links[13].second);

    this->_isCompute = true;
}