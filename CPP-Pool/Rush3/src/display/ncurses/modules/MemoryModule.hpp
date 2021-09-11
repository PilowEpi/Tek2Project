/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** MemoryModule
*/

#ifndef MEMORYMODULE_HPP_
#define MEMORYMODULE_HPP_

#include "ANCursesModules.hpp"
#include "NCursesDrawer.hpp"

class MemoryModule : public ANCursesModules {
    public:
        MemoryModule(int col, int row, AMonitorModule *module, int key, int index, int size);
        ~MemoryModule();
		void display() override;
};

#endif /* !MEMORYMODULE_HPP_ */
