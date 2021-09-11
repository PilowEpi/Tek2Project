/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** GuiFonctions
*/

#ifndef YEP_GUIFONCTIONS_
#define YEP_GUIFONCTIONS_

#include <string>
#include <iostream>
#include "../Zappy.hpp"

class Zappy;

std::vector<std::string> split(const std::string &origin, char delim);
void addToLog(std::string msg, Zappy *win);

namespace GUI
{
    void createMap(Zappy *win, const char *line);
    void callEvent(Zappy *win, const char *line);
    void storeTeams(Zappy *win, const char *line);
    void spawnTrantor(Zappy *win, const char *line);
    void explusion(Zappy *win, const char *line);
    void doNothing(Zappy *win, const char *line);
    void ppoCmd(Zappy *win, const char *line);
    void ppfCmd(Zappy *win, const char *line);
    void ppCmd(Zappy *win, const char *line);
    void pgtCmd(Zappy *win, const char *line);
    void pdrCmd(Zappy *win, const char *line);
    void pbcCmd(Zappy *win, const char *line);
    void plvCmd(Zappy *win, const char *line);
    void pinCmd(Zappy *win, const char *line);
    void picCmd(Zappy *win, const char *line);
    void pieCmd(Zappy *win, const char *line);
    void pdiCmd(Zappy *win, const char *line);
    void prrCmd(Zappy *win, const char *line);
    void victoryScene(Zappy *win, const char *line);
    // Egg functions
    void enwCmd(Zappy *win, const char *line);
    void ehtCmd(Zappy *win, const char *line);
    void eboCmd(Zappy *win, const char *line);
    void ediCmd(Zappy *win, const char *line);
}

#endif /* YEP_GUIFONCT */