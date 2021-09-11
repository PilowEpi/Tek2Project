/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** TextModule
*/

#ifndef TEXTMODULE_HPP_
#define TEXTMODULE_HPP_

#include "ANCursesModules.hpp"
#include "NCursesDrawer.hpp"

class TextModule : public ANCursesModules {
    public:
        TextModule(int col, int row, AMonitorModule *module, int key, int index, int size);
        ~TextModule();
		void display() override;
};

#endif /* !TEXTMODULE_HPP_ */
