/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** PapaXmasElf
*/

#ifndef PAPAXMASELF_HPP
#define PAPAXMASELF_HPP

#include <string>

#include "IElf.hpp"

class PapaXmasElf : public IElf
{
public:
	PapaXmasElf();
	~PapaXmasElf();
	bool put(IConveyorBelt *conveyor, Object *obj);
	Object *take(IConveyorBelt *conveyor);
	bool put(ITable *table, Object *obj);
	Object *take(ITable *table, int idx);
	std::string* look();
	bool wrap();
	bool putSomewhere(Object *obj);
	bool emptyHand();
	bool takeToy();
	bool takeBox();
	bool takeGiftPaper();
	void setTable(ITable *table);
	void setConveyor(IConveyorBelt *conveyor);
};

#endif