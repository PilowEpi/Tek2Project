/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** ANCursesModules
*/


#include "ANCursesModules.hpp"

ANCursesModules::ANCursesModules(int col, int row, AMonitorModule *m, int key, int index, int size)
{
    this->_col = col;
    this->_row = row;
    this->_isEnabled = true;
    this->_module = m;
    this->_key = key;
    this->_index = index;
    this->original_col = col;
    this->_size = size;
}

ANCursesModules::~ANCursesModules()
{
}

void ANCursesModules::setCoords(int col, int row)
{
    this->_col = col;
    this->_row = row;
}

bool ANCursesModules::isEnabled() const
{
    return (this->_isEnabled);
}

void ANCursesModules::setEnabled(bool b)
{
    this->_isEnabled = b;
}

char ANCursesModules::getKey() const
{
    return (this->_key);
}

AMonitorModule *ANCursesModules::getModule() const
{
    return (this->_module);
}

int ANCursesModules::getIndex() const
{
    return (this->_index);
}

int ANCursesModules::getCol() const
{
    return (this->original_col);
}

int ANCursesModules::getSize() const
{
    return (this->_size);
}
