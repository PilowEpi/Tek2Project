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

	protected:
		Object *obj;
};

IConveyorBelt *createConveyorBelt();

#endif