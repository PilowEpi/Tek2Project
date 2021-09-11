/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** ConveyorBeltRand
*/

#ifndef __CONVEYORBELTRAND__
#define __CONVEYORBELTRAND__

#include "Object.hpp"
#include "IConveyorBelt.hpp"

class ConveyorBeltRand : public IConveyorBelt
{
public:
	ConveyorBeltRand();
	~ConveyorBeltRand();
	bool IN();
	bool OUT();
	bool insert(Object *obj);
	Object *remove();
	bool isEmpty();
	Object *obj;
	int giftcounter = 0;
protected:
};

#endif