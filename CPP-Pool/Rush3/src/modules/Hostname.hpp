/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** HostnameModule
*/

#ifndef HOSTNAMEMODULE_HPP_
#define HOSTNAMEMODULE_HPP_

#include <string>

#include "IData.hpp"
#include "AMonitorModule.hpp"

class Hostname : public AMonitorModule
{
    public:
        Hostname();
        ~Hostname();
        void refresh();
        std::string &getString();
        IData *getDataC();
        float getNumber();
    protected:
    private:
};

#endif /* !HOSTNAMEMODULE_HPP_ */
