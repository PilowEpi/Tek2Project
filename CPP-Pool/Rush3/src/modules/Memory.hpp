/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** Memory
*/

class Memory;

#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include <deque>
#include <string>

#include "IData.hpp"
#include "RamData.hpp"
#include "AMonitorModule.hpp"

class Memory : public AMonitorModule
{
    public:
        Memory();
        ~Memory();
        void refresh();

        // Getter
        unsigned long getTotalram();
        std::deque<unsigned long> getAvailableram();

        unsigned long getTotalswap();
        std::deque<unsigned long> getFreeswap();

        std::deque<unsigned short> getProcs();

        std::string &getString();
        IData *getDataC();
        float getNumber();
    protected:
    private:
    	// RAM
    	unsigned long totalram;
    	std::deque<unsigned long> availableram; // Memory used by buffers
    	// SWAP
    	unsigned long totalswap;
    	std::deque<unsigned long> freeswap; // Swap space available
    	// PROCS
    	std::deque<unsigned short> procs; // Number of current processes

    	unsigned int mem_unit;

    	// Computed Values
    	RamData *computed_ram;
};

#endif /* !MEMORY_HPP_ */
