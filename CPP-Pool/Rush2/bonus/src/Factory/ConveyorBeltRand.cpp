/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** ConveyorBeltRand
*/

#include <fstream>
#include <iostream>
#include <string>

#include "ITable.hpp"
#include "ConveyorBeltRand.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "LittlePony.hpp"
#include "Teddy.hpp"

ConveyorBeltRand::ConveyorBeltRand()
{
	this->obj = nullptr;
}

ConveyorBeltRand::~ConveyorBeltRand()
{
	if (this->obj != nullptr)
		delete this->obj;
}

bool ConveyorBeltRand::IN()
{
	short selector = random() % 4;

	if (this->obj) {
		std::cerr << "ERROR : ConveyorBeltRand::IN : an object is already on the ConveyorBeltRand!" << std::endl;
		return false;
	}
	switch (selector) {
		case 0:
			this->obj = new Box;
			break;
		case 1:
			this->obj = new GiftPaper;
			break;
		case 2:
			this->obj = new Teddy;
			break;
		case 3:
			this->obj = new LittlePony;
			break;
	}
	return true;
}

bool ConveyorBeltRand::OUT()
{
	std::string str = "";
	if (this->obj) {
		std::cout << "e speex'n'XML" << std::endl;
		std::string filename = "gift" + std::to_string(giftcounter++) + ".xml";
		std::ofstream file(filename);
		file << this->obj->serialize(str, 0);
		file.close();
		delete this->obj;
		this->obj = nullptr;
	} else {
		std::cerr << "ERROR: ConveyorBeltRand : can't delete uninitialized object!" << std::endl;
		return false;
	}
	return true;
}

bool ConveyorBeltRand::insert(Object *object)
{
	if (!object) {
		std::cerr << "ERROR : ConveyorBeltRand::insert : can't insert a nullptr in ConveyorBeltRand!" << std::endl;
		return false;
	}
	if (this->obj) {
		std::cerr << "ERROR : ConveyorBeltRand::insert : an object is already on the ConveyorBeltRand!" << std::endl;
		return false;
	}
	this->obj = object;
	return true;
}

Object *ConveyorBeltRand::remove()
{
	if (!this->obj) {
		std::cerr << "ERROR : ConveyorBeltRand::remove : there is no object on the ConveyorBeltRand!" << std::endl;
		return nullptr;
	}
	Object *to_return = this->obj;
	this->obj = nullptr;
	return to_return;
}

bool ConveyorBeltRand::isEmpty()
{
	if (this->obj)
		return false;
	return true;
}
