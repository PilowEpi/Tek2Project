/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** Processor
*/

#ifndef PROCESSOR_HPP_
#define PROCESSOR_HPP_

#include <string>
#include <deque>

#include "IData.hpp"
#include "ProcessorData.hpp"
#include "AMonitorModule.hpp"

enum PROC_STATES {
    S_USER,
    S_NICE,
    S_SYSTEM,
    S_IDLE,
    S_IOWAIT,
    S_IRQ,
    S_SOFTIRQ,
    S_STEAL,
    S_GUEST,
    S_GUEST_NICE
};

typedef struct CPUData
{
	std::string cpu;
	size_t data[10];
} CPUData;

class Processor : public AMonitorModule
{
    public:
        Processor();
        ~Processor();
        void refresh();
        unsigned int getNbProcs() const;
        const std::deque<std::deque<std::array<float, 4>>> &getProcessorData() const;

        std::string &getString();
        IData *getDataC();
        float getNumber();
    protected:
    	
    private:
    	unsigned int nb_procs;
        std::deque<CPUData> old_data;
        std::deque<std::deque<std::array<float, 4>>> history;
        ProcessorData *computed_processor;

        // History :
        // List -> 900 iteration
        //      List -> of n cores (0 will always be average)
        //          index 0 Active time (User + Sys = Active)
        //          index 1 User time
        //          index 2 Sys time
        //          index 3 Idle time (Active + Idle = 100%)
};

#endif /* !UsernameModule */
