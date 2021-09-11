/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** UsernameModule
*/

#include <iostream>
#include <sstream>
#include <string>
#include <deque>
#include <array>

#include "IMonitorModule.hpp"
#include "Processor.hpp"
#include "ProcessorData.hpp"

ProcessorData::ProcessorData()
{
	cores = nullptr;
}

ProcessorData::~ProcessorData()
{
}

void ProcessorData::update(IMonitorModule *mod)
{
	Processor *processor = (Processor *) mod;
	history = processor->getProcessorData();
	nb_procs = processor->getNbProcs();
	
	if (!cores) {
		cores = new float*[nb_procs + 2];
		for (int i = 0; i < (int)nb_procs + 1; i++) {
			cores[i] = new float[3];
			cores[i][2] = -1;
		}
		cores[nb_procs + 1] = nullptr;
	}
	for (int i = 0; i < (int)nb_procs + 1; i++) {
		cores[i][0] = history.back()[i][1];
		cores[i][1] = history.back()[i][2];
	}
	float *newaverage = new float[3];
	newaverage[2] = -1;
	newaverage[0] = history.back()[0][1];
	newaverage[1] = history.back()[0][2];
	average_graph.push_front(newaverage);
}

std::string ProcessorData::data()
{
	std::ostringstream stream("");
	stream << "Core count: " << nb_procs << std::endl;
	return stream.str();
}

std::deque<float *> &ProcessorData::getAverage()
{
	return average_graph;
}