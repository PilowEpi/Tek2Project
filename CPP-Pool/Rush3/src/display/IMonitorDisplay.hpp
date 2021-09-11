/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include <list>
#include "AMonitorModule.hpp"

class IMonitorDisplay {
public:
    virtual ~IMonitorDisplay() {};
    virtual void main_loop(std::list<AMonitorModule *> modules) = 0;
};

#endif /* !IMONITORDISPLAY_HPP_ */
