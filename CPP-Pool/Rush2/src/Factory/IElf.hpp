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

	protected:
		Object *lefthand;
		Object *righthand;
		ITable *table;
		IConveyorBelt *conveyor;
};

#endif