/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** MemoryModule
*/

#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "Memory.hpp"
#include "MemoryModule.hpp"

MemoryModule::MemoryModule(int col, int row, AMonitorModule *module, int key, int index, int size)
    : ANCursesModules(col, row, module, key, index, size)
{
}

MemoryModule::~MemoryModule()
{
}

void MemoryModule::display()
{
    NCursesDrawer d;
    std::string label = this->_module->getLabel();
    Memory *process = (Memory *) this->_module;
    RamData *bla = (RamData *) process->getDataC();
    float *data = bla->ram_percentage_bar;
    float *data2 = bla->swap_percentage_bar;
    std::ostringstream sstr("");

    sstr << std::setw(COLS / 2 + label.length() / 2) << label <<  std::setw(COLS / 2 - label.length() / 2) << " " << std::endl;
    d.setColor(6);
    d.drawText(this->_col, this->_row, sstr.str().c_str());
    d.setColor(0);
    d.drawFullBar(this->_col + 1, COLS / 2 - (COLS * 0.8) / 2, COLS * 0.75, std::string("RAM"), data[0], 0);
    d.drawFullBar(this->_col + 2, COLS / 2 - (COLS * 0.8) / 2, COLS * 0.75, std::string("SWAP"), data2[0], 0);
}