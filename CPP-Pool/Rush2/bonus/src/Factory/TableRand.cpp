/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** TableRand
*/

#include <string>

#include "LittlePony.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "Object.hpp"
#include "TableRand.hpp"

TableRand::TableRand()
{
	_names = new std::string[10];
}

TableRand::~TableRand()
{
	for (size_t i = 0; i < 9; i++) {
		if (this->objects[i] != nullptr) {
			delete this->objects[i];
		}
	}
	if (_names) {
		delete []_names;
	}
}

size_t TableRand::objectCount()
{
	size_t objectCount = 0;
	for (size_t i = 0; i < 10; i++) {
		if (this->objects[i]) {
			objectCount++;
		}
	}
	return objectCount;
}

bool TableRand::insert(Object *obj)
{
	if (this->objectCount() >= 9) {
		std::cerr << "ERROR : TableRand: too many objects, table collapse !" << std::endl;
		return false;
	}
	for (size_t i = 0; i < 9; i++) {
		if (!this->objects[i]) {
			this->objects[i] = obj;
			return true;
		}
	}
	return false;
}

Object *TableRand::remove(int idx)
{
	if (idx < 0 || idx >= 9) {
		std::cerr << "ERROR : TableRand: index out of range" << std::endl;
	}
	if (this->objects[idx]) {
		Object *tmp = this->objects[idx];
		this->objects[idx] = nullptr;
		return tmp;
	} else {
		std::cerr << "ERROR : TableRand: no item at index " << idx << "!" << std::endl;
		return nullptr;
	}
}

std::string *TableRand::getObjectsNames()
{
	if (_names) {
		delete []_names;
	}
	_names = new std::string[10];
	for (size_t i = 0; i < 10; i++) {
		if (this->objects[i])
			_names[i] = this->objects[i]->getName();
		else
			_names[i] = "";
	}
	return _names;
}