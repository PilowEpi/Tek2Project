/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** IMonitorModule
*/

class IMonitorModule;
class IData;

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include "IData.hpp"

class IMonitorModule {
    public:
        virtual ~IMonitorModule() {}
        virtual std::string &getString() = 0;
        virtual IData *getDataC() = 0;
        virtual float getNumber() = 0;
        virtual void refresh() = 0;
        virtual bool getState() = 0;
        virtual void switchState() = 0;
        virtual std::string &getLabel() = 0;
    protected:
    private:
};

#endif /* !IMONITORMODULE_HPP_ */


// Label
// Type Possible :
//      List / Deque
//      float
//      std::string