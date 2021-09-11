/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** IMonitorModule
*/

#include <chrono>
#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>

#include "IData.hpp"
#include "Uptime.hpp"

Uptime::Uptime() : AMonitorModule("Uptime", "")
{
}

Uptime::~Uptime()
{
}

void Uptime::refresh()
{
	std::chrono::milliseconds chrono(0u);
    double uptime_seconds;
    unsigned long long uptime = 0;
    if (std::ifstream("/proc/uptime", std::ios::in) >> uptime_seconds) {
        chrono = std::chrono::milliseconds(static_cast<unsigned long long>(uptime_seconds*1000.0));
    	uptime = chrono.count();
        up_time = (float) chrono.count();
    }
    else  {
    	throw std::runtime_error("Module failed to refresh");
    }
    int up_d = (int) uptime / 1000 / 60 / 60 / 24;
    uptime -= up_d * 1000 * 60 * 60 * 24;
    int up_h = (int) uptime / 1000 / 60 / 60;
    uptime -= up_h * 1000 * 60 * 60;
    int up_m = (int) uptime / 1000 / 60;
    uptime -= up_m * 1000 * 60;
    int up_s = (int) uptime / 1000;
    std::ostringstream stream("");
    stream << up_d << " day(s) " << up_h << " hours " << up_m << " minutes " << up_s << " seconds" << std::endl;
    *data = stream.str();
}

std::string &Uptime::getString() {
    return *data;
}

IData *Uptime::getDataC() {
    throw std::runtime_error("Module doesn't have IData return value");
    return nullptr;
}

float Uptime::getNumber() {
    return (float) up_time;
}