/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** TableRand
*/

#ifndef __TABLERAND__
#define __TABLERAND__

#include "ITable.hpp"

class TableRand : public ITable
{
public:
	TableRand();
	~TableRand();
	bool insert(Object *obj);
	Object *remove(int idx);
	std::string *getObjectsNames();
	size_t objectCount();
};

#endif
