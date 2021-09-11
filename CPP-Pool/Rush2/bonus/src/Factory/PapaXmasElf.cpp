/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** PapaXmasElf
*/

#include <SFML/Graphics.hpp>
#include <unistd.h>

#include "PapaXmasElf.hpp"

extern sf::Sprite *elf;

PapaXmasElf::PapaXmasElf()
{
	this->table = createTable();
	this->conveyor = createConveyorBelt();
	this->lefthand = nullptr;
	this->righthand = nullptr;
	sprite = elf;
}

PapaXmasElf::~PapaXmasElf()
{
	delete (this->table);
	delete (this->conveyor);
	if (this->lefthand)
		delete (this->lefthand);
	if (this->righthand)
		delete (this->righthand);
}

bool PapaXmasElf::put(IConveyorBelt *conveyor, Object *obj)
{
	if (!conveyor) {
		std::cerr << "ERROR :PapaXmasElf: The elf doesn't have a conveyor!" << std::endl;
		throw ;
	}
	if (conveyor->insert(obj)) {
		obj->x = this->conveyor->x;
		obj->y = this->conveyor->y;
		usleep(500000);

		return true;
	}
	return false;
}

Object *PapaXmasElf::take(IConveyorBelt *conveyor)
{
	Object *obj = conveyor->remove();
	if (obj) {
		obj->isTaken();
		obj->x = this->x;
		obj->y = this->y;
		usleep(500000);

	}
	return obj;
}

bool PapaXmasElf::put(ITable *tb, Object *obj)
{
	if (!tb) {
		std::cerr << "ERROR :PapaXmasElf: The elf doesn't have a table!" << std::endl;
		throw ;
	}
	if (tb->insert(obj)) {
		obj->x = this->table->x;
		obj->y = this->table->y;
		usleep(500000);

		return true;
	}
	return false;
}

Object *PapaXmasElf::take(ITable *table, int idx)
{
	Object *obj = table->remove(idx);
	if (obj) {
		obj->isTaken();
		obj->x = this->x;
		obj->y = this->y;
		usleep(500000);

	}
	return obj;
}

std::string* PapaXmasElf::look()
{
	return this->table->getObjectsNames();
}

bool PapaXmasElf::putSomewhere(Object *obj)
{
	if (this->conveyor->isEmpty()) {
		this->put(this->conveyor, obj);
		return true;
	}
	return this->put(this->table, obj);
}

bool PapaXmasElf::emptyHand()
{
	if (this->lefthand && this->putSomewhere(this->lefthand)) {
		usleep(500000);
		this->lefthand = 0;
	}
	if (this->righthand && this->putSomewhere(this->righthand)) {
		usleep(500000);
		this->righthand = 0;
	}
	if (!this->lefthand && !this->righthand)
		return true;
	return false;
}

bool PapaXmasElf::takeToy()
{
	std::string *names = this->look();
	for (int i = 0; i < 9; i++) {
		if (names[i] == "Rainbow Dash" || names[i] == "Bear") {
			this->lefthand = this->take(this->table, i);
			usleep(500000);
			return true;
		}
	}
	if (this->conveyor->isEmpty()) {
		this->conveyor->IN();
		usleep(500000);
	}
	while (this->table) {
		Object *obj = this->take(this->conveyor);
		usleep(500000);
		if (obj->getType() == Object::TOY) {
			this->lefthand = obj;
			return true;
		} else {
			if (!this->put(this->table, obj)) {
				delete obj;
				return false;
			}
			usleep(500000);
			this->conveyor->IN();
			usleep(500000);
		}
	}
	return false;
}

bool PapaXmasElf::takeBox()
{
	std::string *names = this->look();
	for (int i = 0; i < 9; i++) {
		if (names[i] == "Box") {
			this->righthand = this->take(this->table, i);
			usleep(500000);
			return true;
		}
	}
	if (this->conveyor->isEmpty())
		this->conveyor->IN();
	while (this->table) {
		Object *obj = this->take(this->conveyor);
		usleep(500000);
		if (obj->getName() == "Box") {
			this->righthand = obj;
			return true;
		} else {
			if (!this->put(this->table, obj)) {
				delete obj;
				return false;
			}
			usleep(500000);
			this->conveyor->IN();
			usleep(500000);
		}
	}
	return false;
}

bool PapaXmasElf::takeGiftPaper()
{
	std::string *names = this->look();
	for (int i = 0; i < 9; i++) {
		if (names[i] == "GiftPaper") {
			this->lefthand = this->take(this->table, i);
			usleep(500000);
			return true;
		}
	}
	if (this->conveyor->isEmpty()) {
		this->conveyor->IN();
		usleep(500000);
	}
	while (this->table) {
		Object *obj = this->take(this->conveyor);
		usleep(500000);
		if (obj->getName() == "GiftPaper") {
			this->lefthand = obj;
			return true;
		} else {
			if (!this->put(this->table, obj)) {
				delete obj;
				return false;
			}
			usleep(500000);
			this->conveyor->IN();
			usleep(500000);
		}
	}
	return false;
}

bool PapaXmasElf::wrap()
{
	if (!this->emptyHand() || !this->takeToy() || !this->takeBox()) {
		std::cout << "o'pa ere's somin' wron' in da box!" << std::endl;
		return false;
	}
	this->righthand->openMe();
	usleep(200000);
	this->righthand->wrapMeThat(this->lefthand);
	usleep(200000);
	this->righthand->closeMe();
	usleep(200000);
	this->lefthand = 0;
	if (!this->takeGiftPaper()) {
		std::cout << "o'pa ere's somin' wron' in da box!" << std::endl;
		return false;
	}
	usleep(200000);
	this->lefthand->wrapMeThat(this->righthand);
	this->righthand = 0;
	if (!this->conveyor->isEmpty()) {
		this->righthand = this->take(this->conveyor);
		usleep(500000);
	}
	this->put(this->conveyor, this->lefthand);
	usleep(500000);
	this->lefthand = 0;
	this->conveyor->OUT();
	usleep(500000);
	return true;
}

void PapaXmasElf::setTable(ITable *table)
{
	if (this->table) {
		delete this->table;
	}
	this->table = table;
}

void PapaXmasElf::setConveyor(IConveyorBelt *conveyor)
{
	if (this->conveyor) {
		delete this->conveyor;
	}
	this->conveyor = conveyor;
}