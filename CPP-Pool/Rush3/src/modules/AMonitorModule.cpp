/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** IMonitorModule
*/

#include <string>

#include "AMonitorModule.hpp"

AMonitorModule::AMonitorModule(std::string label, std::string data)
	: label(label), data(new std::string(data))
{
}

AMonitorModule::~AMonitorModule()
{
	delete data;
}

void AMonitorModule::switchState()
{
	activated = !activated;
}

bool AMonitorModule::getState()
{
	return activated;
}

std::string &AMonitorModule::getData()
{
	return *data;
}

std::string &AMonitorModule::getLabel()
{
	return label;
}