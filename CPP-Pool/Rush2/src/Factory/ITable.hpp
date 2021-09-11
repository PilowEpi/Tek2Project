/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** ITable
*/

#ifndef __ITABLE__
#define __ITABLE__

#include "Object.hpp"

class ITable
{
	public:
		virtual ~ITable() {}

		virtual std::string *getObjectsNames() = 0;
		virtual size_t objectCount() = 0;

		virtual bool insert(Object *obj) = 0;
		virtual Object *remove(int idx) = 0;

	protected:
		Object *objects[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		std::string* _names;
};

ITable *createTable();

#endif