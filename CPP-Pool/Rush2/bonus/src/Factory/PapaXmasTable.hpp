/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** PapaXmasTable
*/

#ifndef __PAPAXMASTABLE__
#define __PAPAXMASTABLE__

#include "ITable.hpp"

class PapaXmasTable : public ITable
{
public:
	PapaXmasTable();
	~PapaXmasTable();
	bool insert(Object *obj);
	Object *remove(int idx);
	std::string *getObjectsNames();
	size_t objectCount();
};

#endif
