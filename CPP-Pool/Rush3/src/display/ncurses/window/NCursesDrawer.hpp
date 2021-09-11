/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** NCursesDrawer
*/

#ifndef NCURSESDRAWER_HPP_
#define NCURSESDRAWER_HPP_

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <ncurses.h>

class NCursesDrawer {
    // fond noir text blanc
    // setColor(BLEU, NOIR) <- TXT BLEU , FOND NOIR
    // drawText(col, row, std::string text);
    // drawChar(col, row, char c);
    public:
        NCursesDrawer();
        ~NCursesDrawer() {};
        
        void setColor(int color_id);

        void drawText(int col, int row, std::string text);
        void drawChar(int col, int row, char c);
        void drawBar(int col, int row, int size, float local, float system);
        void drawPercent(int col, int row, float percentage);
        void drawFullBar(int col, int row, int size, std::string label, float local, float system);
    private:
        int _color_id;
};

#endif /* !NCURSESDRAWER_HPP_ */
