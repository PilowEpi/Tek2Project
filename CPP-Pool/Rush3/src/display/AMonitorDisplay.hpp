/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** AMonitorDisplay
*/

#ifndef AMONITORDISPLAY_HPP_
#define AMONITORDISPLAY_HPP_

#include "IMonitorDisplay.hpp"

class AMonitorDisplay : public IMonitorDisplay {
public:
    AMonitorDisplay();
    virtual ~AMonitorDisplay();
    virtual void main_loop(std::list<AMonitorModule *> modules) = 0;
    enum Type {
        Graph,
        Text
    };
protected:
private:
};

#endif /* !AMONITORDISPLAY_HPP_ */
