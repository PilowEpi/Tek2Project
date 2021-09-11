/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** IElf
*/

#ifndef IELF_HPP
#define IELF_HPP

#include "IConveyorBelt.hpp"
#include "ITable.hpp"

class IElf
{
public:
	virtual ~IElf() {}
	virtual bool put(IConveyorBelt *conveyor, Object *obj) = 0;
	virtual Object *take(IConveyorBelt *conveyor) = 0;
	virtual bool put(ITable *table, Object *obj) = 0;
	virtual Object *take(ITable *table, int idx) = 0;
	virtual std::string* look() = 0;
	virtual bool wrap() = 0;
	virtual void setTable(ITable *table) = 0;
	virtual void setConveyor(IConveyorBelt *conveyor) = 0;
	int x = 1920/2;
	int y = 1080/2+50;
	int dx = 1920/2;
	int dy = 1080/2;
	int sizeX = 50;
	int sizeY = 50;
	Object *lefthand = 0;
	Object *righthand = 0;
	ITable *table = 0;
	IConveyorBelt *conveyor = 0;
	sf::Sprite *sprite;
protected:
};

#endif
