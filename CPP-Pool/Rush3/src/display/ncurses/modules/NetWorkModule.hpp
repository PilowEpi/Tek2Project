/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** NetWorkModule
*/

#ifndef NETWORKMODULE_HPP_
#define NETWORKMODULE_HPP_

#include "ANCursesModules.hpp"
#include "NCursesDrawer.hpp"

class NetWorkModule : public ANCursesModules {
    public:
        NetWorkModule(int col, int row, AMonitorModule *m, int key, int index, int size);
        ~NetWorkModule();
        void display() override;
};

#endif /* !NETWORKMODULE_HPP_ */