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

		std::string *getObjectsNames();
		size_t objectCount();

		bool insert(Object *obj);
		Object *remove(int idx);
};

#endif
