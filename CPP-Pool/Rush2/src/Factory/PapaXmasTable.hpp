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

		size_t objectCount();
		std::string *getObjectsNames();
		
		bool insert(Object *obj);
		Object *remove(int idx);
};

#endif
