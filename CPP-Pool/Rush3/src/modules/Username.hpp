/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** UsernameModule
*/

#ifndef USERNAMEMODULE_HPP_
#define USERNAMEMODULE_HPP_

#include <string>

#include "IData.hpp"
#include "AMonitorModule.hpp"

class Username : public AMonitorModule
{
    public:
        Username();
        ~Username();
        void refresh();

        std::string &getString();
        IData *getDataC();
        float getNumber();
    protected:
    private:
};

#endif /* !UsernameModule */
