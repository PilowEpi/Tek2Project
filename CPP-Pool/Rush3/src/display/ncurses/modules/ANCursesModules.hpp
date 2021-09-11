/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** NcurseWindow
*/

#ifndef NCURSE_MOD_HPP_
#define NCURSE_MOD_HPP_

#include <sstream>
#include <iostream>
#include <iomanip>
#include <ncurses.h>
#include "AMonitorModule.hpp"
#include "Processor.hpp"

class ANCursesModules
{
	public:
		ANCursesModules(int col, int row, AMonitorModule *m, int key, int index, int size);
		virtual ~ANCursesModules();
		virtual void display() =  0;
		bool isEnabled() const;
		void setEnabled(bool b);
		char getKey() const;
        int getIndex() const;
        int getCol() const;
        int getSize() const;
		void setCoords(int col, int row);
		AMonitorModule *getModule() const;

	protected:
		WINDOW *_window;
		int _col;
        int _size;
		int _row;
		bool _isEnabled;
		AMonitorModule *_module;
		int _key;
        int _index;
        int original_col;
};

#endif