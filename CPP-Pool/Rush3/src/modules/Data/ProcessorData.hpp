/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** UsernameModule
*/

#ifndef PROCESSORDATA_HPP_
#define PROCESSORDATA_HPP_

#include <deque>
#include <string>

#include "Memory.hpp"
#include "IData.hpp"

class ProcessorData : public IData
{
    public:
        ProcessorData();
        ~ProcessorData();
        void update(IMonitorModule *memory);
        std::string data();
        std::deque<float *> &getAverage();

        unsigned int nb_procs;
    	std::deque<std::deque<std::array<float, 4>>> history;
        float **cores;
        std::deque<float *> average_graph;
};

#endif /* !Ramdata */
