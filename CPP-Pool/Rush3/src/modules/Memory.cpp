/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** IMonitorModule
*/

#include <sys/sysinfo.h>
#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <fstream>

#include "IData.hpp"
#include "Memory.hpp"
#include "RamData.hpp"

Memory::Memory() : AMonitorModule("Memory", "")
{
	computed_ram = new RamData;
}

Memory::~Memory()
{
	delete computed_ram;
}

void Memory::refresh()
{
	std::string token;
	std::ifstream file("/proc/meminfo");
	unsigned long nbr;

	if (!file.good())
		throw std::runtime_error("Module can't be refreshed");

	while (file >> token) {
		if (token == "MemTotal:") {
			file >> totalram;
		} else if (token == "MemAvailable:") {
			file >> nbr;
			availableram.push_back(nbr);
		} else if (token == "SwapTotal:") {
			file >> totalswap;
		} else if (token == "SwapFree:") {
			file >> nbr;
			freeswap.push_back(nbr);
		}
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	file.close();

    // MemUnit
    if (availableram.size() > 900)
    	availableram.pop_front();
    if (freeswap.size() > 900)
    	freeswap.pop_front();
    if (procs.size() > 900)
    	procs.pop_front();
    computed_ram->update((IMonitorModule *) this);
    *data = computed_ram->data();
}

unsigned long Memory::getTotalram()
{
	return totalram;
}

std::deque<unsigned long> Memory::getAvailableram()
{
	return availableram;
}

unsigned long Memory::getTotalswap()
{
	return totalswap;
}

std::deque<unsigned long> Memory::getFreeswap()
{
	return freeswap;
}

std::deque<unsigned short> Memory::getProcs()
{
	return procs;
}

std::string &Memory::getString() {
	throw std::runtime_error("Module doesn't have Std::string return value");
	return *data;
}

IData *Memory::getDataC() {
	return computed_ram;
}

float Memory::getNumber() {
	throw std::runtime_error("Module doesn't have Float return value");
	return 0.0;
}