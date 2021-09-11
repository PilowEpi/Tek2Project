/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** PapaXmasConveyorBelt
*/

#ifndef __PAPAXMASCONVEYORBELT__
#define __PAPAXMASCONVEYORBELT__

#include "Object.hpp"
#include "IConveyorBelt.hpp"

class PapaXmasConveyorBelt : public IConveyorBelt
{
	public:
		PapaXmasConveyorBelt();
		~PapaXmasConveyorBelt();

		bool IN();
		bool OUT();
		bool insert(Object *obj);
		Object *remove();
		bool isEmpty();

	protected:
		Object *obj;
};

#endif