/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** UsernameModule
*/

#include <iostream>
#include <sstream>

#include "Memory.hpp"
#include "RamData.hpp"

RamData::RamData()
{
	ram_max = 0;
	swap_max = 0;
	ram_percentage_bar = new float[2];
	ram_percentage_bar[1] = -1;
	swap_percentage_bar = new float[2];
	swap_percentage_bar[1] = -1;
}

RamData::~RamData()
{
}

void RamData::update(IMonitorModule *mod)
{
	Memory *memory = (Memory *) mod;
	ram_max = memory->getTotalram();
	swap_max = memory->getTotalswap();
	ram_percentage.push_back(1 - (double) memory->getAvailableram().back() / ram_max);
	swap_percentage.push_back(1 - (double) memory->getFreeswap().back() / swap_max);
	ram_raw.push_back((ram_max - memory->getAvailableram().back()) * 1000);
	swap_raw.push_back((swap_max - memory->getFreeswap().back()) * 1000);
	ram_percentage_bar[0] = (float) ram_percentage.back();
	swap_percentage_bar[0] = (float) swap_percentage.back();
}

std::string RamData::data()
{
	std::ostringstream stream("");
	stream << "Raw Ram Max:" << ram_max << std::endl;
	stream << "Swap Max:" << swap_max << std::endl;
	stream << "Ram percentage:" << ram_percentage.back() << std::endl;
	stream << "Ram raw:" << ram_raw.back() << std::endl;
	stream << "Swap percentage:" << swap_percentage.back() << std::endl;
	stream << "Swap raw:" << swap_raw.back() << std::endl;
	return stream.str();
}