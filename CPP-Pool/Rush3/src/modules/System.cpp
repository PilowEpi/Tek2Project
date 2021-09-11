/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** IMonitorModule
*/

#include <sys/utsname.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>

#include "IData.hpp"
#include "System.hpp"

System::System() : AMonitorModule("System informations", "")
{
}

System::~System()
{
}

void System::refresh()
{
	struct utsname uts;
    if (uname(&uts) == -1) {
    	throw std::runtime_error("Module failed to refresh");
    }
    std::ostringstream stream;
    stream << "System name: " << uts.sysname << std::endl;
	stream << "Kernel version: " << uts.release << std::endl;
    stream << "OS Version: " << uts.version << std::endl;
	stream << "Architecture: " << uts.machine << std::endl;
	*data = stream.str();
}

std::string &System::getString() {
    return *data;
}

IData *System::getDataC() {
    throw std::runtime_error("Module doesn't have IData return value");
    return nullptr;
}

float System::getNumber() {
    throw std::runtime_error("Module doesn't have Float return value");
    return 0.0;
}