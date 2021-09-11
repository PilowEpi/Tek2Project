/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** SystemModule
*/

#ifndef TIMEMODULE_HPP_
#define TIMEMODULE_HPP_

#include <ctime>
#include <string>

#include "IData.hpp"
#include "AMonitorModule.hpp"

class Time : public AMonitorModule
{
    public:
        Time();
        ~Time();
        void refresh();

        std::string &getString();
        IData *getDataC();
        float getNumber();
    protected:
    	float up_time;
    private:
};

#endif /* !HOSTNAMEMODULE_HPP_ */
