/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** IConveyorBelt
*/

#ifndef __ICONVEYORBELT__
#define __ICONVEYORBELT__

#include "Object.hpp"

class IConveyorBelt
{
public:
	virtual ~IConveyorBelt() {}
	virtual bool IN() = 0;
	virtual bool OUT() = 0;
	virtual bool insert(Object *obj) = 0;
	virtual Object *remove() = 0;
	virtual bool isEmpty() = 0;
	int x = 1920/1.5;
	int y = 1080/2 + 50;
	int dx = 1920/1.5;
	int dy = 1080/2;
	int sizeX = 200;
	int sizeY = 100;
	Object *obj = 0;
protected:
};

IConveyorBelt *createConveyorBelt();

#endif
