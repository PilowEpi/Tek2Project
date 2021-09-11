/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** PapaXmasConveyorBelt
*/

#include "ITable.hpp"
#include "PapaXmasConveyorBelt.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"


PapaXmasConveyorBelt::PapaXmasConveyorBelt()
{
	this->obj = nullptr;
}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt()
{
	if (this->obj != nullptr)
		delete this->obj;
}

bool PapaXmasConveyorBelt::IN()
{
	static short selector = 0;

	if (this->obj) {
		std::cerr << "ERROR : PapaXmasConveyorBelt::IN : an object is already on the PapaXmasConveyorBelt!" << std::endl;
		return false;
	}
	selector++;
	if (selector % 2 == 0) {
		this->obj = new Box;
		selector = 0;
	} else
		this->obj = new GiftPaper;
	return true;
}

bool PapaXmasConveyorBelt::OUT()
{
	if (this->obj) {
		delete this->obj;
		this->obj = nullptr;
	} else {
		std::cerr << "ERROR: PapaXmasConveyorBelt : can't delete uninitialized object!" << std::endl;
		return false;
	}
	return true;
}

bool PapaXmasConveyorBelt::insert(Object *object)
{
	if (!object) {
		std::cerr << "ERROR : PapaXmasConveyorBelt::insert : can't insert a nullptr in PapaXmasConveyorBelt!" << std::endl;
		return false;
	}
	if (this->obj) {
		std::cerr << "ERROR : PapaXmasConveyorBelt::insert : an object is already on the PapaXmasConveyorBelt!" << std::endl;
		return false;
	}
	this->obj = object;
	return true;
}

Object *PapaXmasConveyorBelt::remove()
{
	Object *to_return;

	if (!this->obj) {
		std::cerr << "ERROR : PapaXmasConveyorBelt::remove : there is no object on the PapaXmasConveyorBelt!" << std::endl;
		return nullptr;
	}
	to_return = this->obj;
	this->obj = nullptr;
	return to_return;
}

bool PapaXmasConveyorBelt::isEmpty()
{
	if (this->obj)
		return false;
	return true;
}

IConveyorBelt *createConveyorBelt()
{
	IConveyorBelt *conveyor = new PapaXmasConveyorBelt;

	return conveyor;
}