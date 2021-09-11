/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** MagicalCarpet
*/

#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <thread>
#include <pthread.h>
#include "ITable.hpp"
#include "MagicalCarpet.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "LittlePony.hpp"
#include "Teddy.hpp"
#include "Server.hpp"

MagicalCarpet::MagicalCarpet()
{
	this->thrd = new std::thread(server, this->socket);
	while (this->socket[0] == 0) {
		sleep(1);
	}
	this->obj = nullptr;
}

MagicalCarpet::~MagicalCarpet()
{
	std::string str("END");
	sendToSantas(str, this->socket);
	if (this->obj != nullptr)
		delete this->obj;
}

bool MagicalCarpet::IN()
{
	short selector = random() % 4;

	if (this->obj) {
		std::cerr << "ERROR : MagicalCarpet::IN : an object is already on the MagicalCarpet!" << std::endl;
		return false;
	}
	switch (selector) {
		case 0:
			this->obj = new Box;
			break;
		case 1:
			this->obj = new GiftPaper;
			break;
		case 2:
			this->obj = new Teddy;
			break;
		case 3:
			this->obj = new LittlePony;
			break;
	}
	return true;
}

void MagicalCarpet::sendGift()
{
	std::string str("");
	std::string message = this->obj->serialize(str, 0);

	sendToSantas(message, this->socket);
	usleep(500);
}

bool MagicalCarpet::OUT()
{
	std::string str = "";

	if (this->obj) {
		std::cout << "e speex'n'XML" << std::endl;
		this->sendGift();
		delete this->obj;
		this->obj = nullptr;
	} else {
		std::cerr << "ERROR: MagicalCarpet : can't delete uninitialized object!" << std::endl;
		return false;
	}
	return true;
}

bool MagicalCarpet::insert(Object *object)
{
	if (!object) {
		std::cerr << "ERROR : MagicalCarpet::insert : can't insert a nullptr in MagicalCarpet!" << std::endl;
		return false;
	}
	if (this->obj) {
		std::cerr << "ERROR : MagicalCarpet::insert : an object is already on the MagicalCarpet!" << std::endl;
		return false;
	}
	this->obj = object;
	return true;
}

Object *MagicalCarpet::remove()
{
	Object *to_return;

	if (!this->obj) {
		std::cerr << "ERROR : MagicalCarpet::remove : there is no object on the MagicalCarpet!" << std::endl;
		return nullptr;
	}
	to_return = this->obj;
	this->obj = nullptr;
	return to_return;
}

bool MagicalCarpet::isEmpty()
{
	if (this->obj)
		return false;
	return true;
}
