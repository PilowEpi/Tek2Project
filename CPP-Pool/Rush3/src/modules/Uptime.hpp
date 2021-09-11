/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** UsernameModule
*/

#ifndef UPTIME_HPP_
#define UPTIME_HPP_

#include <string>

#include "IData.hpp"
#include "AMonitorModule.hpp"

class Uptime : public AMonitorModule
{
    public:
        Uptime();
        ~Uptime();
        void refresh();

        std::string &getString();
        IData *getDataC();
        float getNumber();
    protected:
    	float up_time;
    private:
};

#endif /* !UsernameModule */
