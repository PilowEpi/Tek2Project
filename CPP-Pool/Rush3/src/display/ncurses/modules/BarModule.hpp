/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** BarModule
*/

#ifndef BARMODULE_HPP_
#define BARMODULE_HPP_

#include "ANCursesModules.hpp"
#include "NCursesDrawer.hpp"

class BarModule : public ANCursesModules
{
    public:
        BarModule(int col, int row, AMonitorModule *module, int key, int index, int size);
        ~BarModule();
        void display() override;

    protected:
    private:
};

#endif /* !BARMODULE_HPP_ */
