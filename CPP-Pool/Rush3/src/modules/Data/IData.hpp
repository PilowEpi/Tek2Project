/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** UsernameModule
*/

#ifndef IDATA_HPP_
#define IDATA_HPP_

#include "IMonitorModule.hpp"

class IData
{
    public:
        IData() {}
        virtual ~IData() {}
        virtual void update(IMonitorModule *module) = 0;
        virtual std::string data() = 0;
};

#endif /* !Ramdata */
