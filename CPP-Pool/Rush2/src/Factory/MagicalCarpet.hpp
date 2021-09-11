/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** MagicalCarpet
*/

#ifndef __MAGICALCARPER__
#define __MAGICALCARPER__

#include <thread>
#include <pthread.h>
#include "Object.hpp"
#include "IConveyorBelt.hpp"

class MagicalCarpet : public IConveyorBelt
{
	public:
		MagicalCarpet();
		~MagicalCarpet();

		bool IN();
		bool OUT();
		bool insert(Object *obj);
		Object *remove();
		bool isEmpty();
		void sendGift();

	protected:
		Object *obj;
		int giftcounter = 0;
		int socket[65537] = {0};
		std::thread *thrd;
};

#endif
