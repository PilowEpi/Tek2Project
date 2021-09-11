/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** IMonitorModule
*/

#ifndef AMONITORMODULE_HPP_
#define AMONITORMODULE_HPP_

#include <string>

#include "IData.hpp"
#include "IMonitorModule.hpp"

class AMonitorModule : public IMonitorModule
{
    public:
        virtual ~AMonitorModule();
        virtual void refresh() = 0;
        virtual std::string &getString() = 0;
        virtual IData *getDataC() = 0;
        virtual float getNumber() = 0;
        bool getState();
        void switchState();
        std::string &getData();
        std::string &getLabel();
    protected:
        AMonitorModule(std::string label, std::string data);
        bool activated;
        std::string label;
        std::string *data;
    private:
};

#endif /* !AMONITORMODULE_HPP_ */
