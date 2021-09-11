/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** IMonitorModule
*/

#include <ctime>
#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>

#include "IData.hpp"
#include "Time.hpp"

Time::Time() : AMonitorModule("Time", "")
{
}

Time::~Time()
{
}

void Time::refresh()
{
	time_t now = time(0);
	char* dt = ctime(&now);
	if (dt == NULL) {
		throw std::runtime_error("Module failed to reload");
	}
	std::ostringstream stream("");
	stream << "Local: " << dt;
	tm *gmtm = gmtime(&now);
	if (gmtm == NULL) {
		throw std::runtime_error("Module failed to reload");
	}
	dt = asctime(gmtm);
	if (dt == NULL) {
		throw std::runtime_error("Module failed to reload");
	}
	stream << std::string("UTC: ") << dt;
	*this->data = stream.str();
}

std::string &Time::getString() {
    return *data;
}

IData *Time::getDataC() {
    throw std::runtime_error("Module doesn't have IData return value");
    return nullptr;
}

float Time::getNumber() {
    throw std::runtime_error("Module doesn't have Float return value");
    return 0.0;
}