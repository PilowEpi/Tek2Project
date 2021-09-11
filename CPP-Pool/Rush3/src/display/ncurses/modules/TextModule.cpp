/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** TextModule
*/

#include "TextModule.hpp"

TextModule::TextModule(int col, int row, AMonitorModule *m, int key, int index, int size)
    : ANCursesModules(col, row, m, key, index, size)
{
}

TextModule::~TextModule()
{
}

void TextModule::display()
{
    NCursesDrawer d;
    std::string label = this->_module->getLabel();
    std::string to_print = this->_module->getString();
    std::ostringstream tmp("");
    std::ostringstream sstr("");
    int backn = 1;

    sstr << std::setw(COLS / 2 + label.length() / 2) << label <<  std::setw(COLS / 2 - label.length() / 2) << " " << std::endl;
    d.setColor(6);
    d.drawText(this->_col, this->_row, sstr.str().c_str());
    for (unsigned int x = 0; x < to_print.length(); x++) {
        if (to_print[x] == '\n') {
            sstr.clear();
            sstr.str("");
            sstr << std::setw(COLS / 2 + tmp.str().length() / 2) << tmp.str();
            d.setColor(0);
            d.drawText(this->_col + backn, this->_row, sstr.str().c_str());
            tmp.clear();
            tmp.str("");
            backn++;
        } else
            tmp << to_print[x];
    }
    if (tmp.str().length()) {
        sstr.clear();
        sstr.str("");
        sstr << std::setw(COLS / 2 + tmp.str().length() / 2) << tmp.str();
        d.setColor(0);
        d.drawText(this->_col + backn, this->_row, sstr.str().c_str());
    }
}