/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** IMonitorModule
*/

#include <unistd.h>
#include <limits.h>
#include <string>
#include <stdexcept>

#include "IData.hpp"
#include "Hostname.hpp"

Hostname::Hostname() : AMonitorModule("Hostname", "")
{
}

Hostname::~Hostname()
{
}

void Hostname::refresh()
{
	char hostname[HOST_NAME_MAX];
    if (gethostname(hostname, HOST_NAME_MAX) == -1) {
    	throw std::runtime_error("Module failed to refresh");
    }
    *data = std::string(hostname);
}

std::string &Hostname::getString() {
	return *data;
}

IData *Hostname::getDataC() {
	throw std::runtime_error("Module doesn't have IData object return value");
	return nullptr;
}

float Hostname::getNumber() {
	throw std::runtime_error("Module doesn't have Float return value");
	return 0.0;
}