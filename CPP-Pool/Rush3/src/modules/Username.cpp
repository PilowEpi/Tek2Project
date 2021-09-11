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
#include "Username.hpp"

Username::Username() : AMonitorModule("Username", "")
{
}

Username::~Username()
{
}

void Username::refresh()
{
	char username[LOGIN_NAME_MAX];
    if (getlogin_r(username, LOGIN_NAME_MAX) == -1) {
    	throw std::runtime_error("Module failed to refresh");
    }
    *data = std::string(username);
}

std::string &Username::getString() {
    return *data;
}

IData *Username::getDataC() {
    throw std::runtime_error("Module doesn't have IData return value");
    return nullptr;
}

float Username::getNumber() {
    throw std::runtime_error("Module doesn't have Float return value");
    return 0.0;
}