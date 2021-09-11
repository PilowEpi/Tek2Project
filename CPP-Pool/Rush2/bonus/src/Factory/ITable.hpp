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
	virtual bool insert(Object *obj) = 0;
	virtual Object *remove(int idx) = 0;
	virtual std::string *getObjectsNames() = 0;
	virtual size_t objectCount() = 0;
	int x = 1920/2;
	int y = 1080/2.5;
	int dx = 1920/2;
	int dy = 1080/2.5;
	int sizeX = 150;
	int sizeY = 75;
	Object *objects[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	std::string* _names = 0;
protected:
};

ITable *createTable();

#endif
