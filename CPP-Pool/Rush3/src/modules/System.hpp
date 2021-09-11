/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** SystemModule
*/

#ifndef SYSTEMMODULE_HPP_
#define SYSTEMMODULE_HPP_

#include <sys/utsname.h>
#include <string>

#include "IData.hpp"
#include "AMonitorModule.hpp"

class System : public AMonitorModule
{
    public:
        System();
        ~System();
        void refresh();

        std::string &getString();
        IData *getDataC();
        float getNumber();
    protected:
    private:
};

#endif /* !HOSTNAMEMODULE_HPP_ */
