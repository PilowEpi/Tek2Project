/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** UsernameModule
*/

#ifndef RAMDATA_HPP_
#define RAMDATA_HPP_

#include <deque>
#include <string>

#include "IMonitorModule.hpp"
#include "Memory.hpp"
#include "IData.hpp"

class RamData : public IData
{
    public:
        RamData();
        ~RamData();
        void update(IMonitorModule *memory);
        std::string data();

    	// Percentage
    	std::deque<double> ram_percentage;
    	std::deque<double> swap_percentage;

    	// Raw
    	std::uint64_t ram_max;
    	std::deque<std::uint64_t> ram_raw;
    	std::uint64_t swap_max;
    	std::deque<std::uint64_t> swap_raw;
        float *ram_percentage_bar;
        float *swap_percentage_bar;
};

#endif /* !Ramdata */
