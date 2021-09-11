/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** GuiFonctions
*/

#include "GuiFonctions.hpp"
#include <cstring>
#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <memory>

std::vector<std::string> split(const std::string &origin, char delim)
{
    std::vector<std::string> result;
    std::string line;
    std::istringstream stream(origin);
    
    while (getline(stream, line, delim))
        result.push_back(line);
    return (result);
}

void addToLog(std::string msg, Zappy *win)
{
    win->_stock->_logs->push_back(msg);
}

void GUI::doNothing(Zappy *win, const char *line)
{
    std::cout << "Command: " << line << " = Not Yet Implemented" << std::endl;
}

void GUI::createMap(Zappy *win, const char *line)
{
    std::vector<std::string> data = split(std::string(line), ' ');
    int x = 0;
    int y = 0;

    if (data.size() != 3)
        return;
    x = atoi(data[1].c_str());
    y = atoi(data[2].c_str());

    if (x < 0 || y < 0)
        return;
    std::cout << "Map Size requested : " << x << " " << y << std::endl;
    std::shared_ptr<Map> map = std::make_shared<Map>(rl::Vec2(x, y), win, 2);
    win->_stock->_map = map;
    win->_manager->addComponent(map, 2);
    win->_manager->_settings._sizeMap = rl::Vec2(x, y);
    data.clear();
}

void GUI::callEvent(Zappy *win, const char *line)
{
    //std::cout << "Call Event requested" << std::endl;
    std::string event(strdup(line));
    win->_manager->handleEvent(event); // Warning : peut etre long (need large test)
}

void GUI::storeTeams(Zappy *win, const char *line)
{
    std::vector<std::string> data = split(std::string(line), ' ');
    std::ostringstream log("");

    if (data.size() != 2)
        return;

    std::cout << "Teams created : " << data[1] << std::endl;
    log << "Team :" << data[1];
    addToLog(log.str().c_str(), win);
    win->_stock->_teams.push_back(Team(data[1]));
    data.clear();
}

void GUI::spawnTrantor(Zappy *win, const char *line)
{
    std::vector<std::string> data = split(std::string(line), ' ');
    std::ostringstream log("");

    if (data.size() != 7)
        return;
    int id = atoi(data[1].c_str());
    int x = atoi(data[2].c_str());
    int y = atoi(data[3].c_str());
    int rota = atoi(data[4].c_str());
    int level = atoi(data[5].c_str());
    rl::Color color;

    for (auto team : win->_stock->_teams)
        if (team._name == data[6])
            color = team._teamColor;

    log << "Trantor created : \n" << data[1] << " & team " << data[6];
    addToLog(log.str().c_str(), win);

    // std::cout << "Trantor created : " << data[1] << " & team " << data[6] << std::endl;
    // std::cout << "rota: " << rota << std::endl;
    // std::cout << "Pos : x : " << x << " y : " << y << std::endl << std::endl;

    std::shared_ptr<Trantor> p = std::make_shared<Trantor>(rl::Vec2(x, y), color, (Rotation)rota, level, id, data[6], win->_t._walking, win->_t._skins);
    win->_stock->add(id, p);
    win->_manager->addComponent(p, 2);
    win->_stock->_idMax = (win->_stock->_idMax < id) ? id : win->_stock->_idMax;
    data.clear();
    log.clear();
}

void GUI::explusion(Zappy *win, const char *line)
{
    std::vector<std::string> data = split(std::string(line), ' ');
    std::ostringstream log("");

    if (data.size() != 2)
        return;
    std::cout << "Trantor explusion " << data[1] << std::endl;
    log << "Trantor explusion \n id :" << data[1];
    addToLog(log.str().c_str(), win);
    win->_logs->callServer("ppo "+data[1]+"\n");
    data.clear();
}

void GUI::ppoCmd(Zappy *win, const char *line)
{
    std::vector<std::string> data = split(std::string(line), ' ');

    if (data.size() != 5)
        return;
    std::shared_ptr<Trantor> p = win->_stock->_player[atoi(data[1].c_str())];
    if (p == nullptr)
        return;
    p->setPlayerPos(atoi(data[2].c_str()), atoi(data[3].c_str()), (Rotation)atoi(data[4].c_str()));
}

void GUI::ppfCmd(Zappy *win, const char *line)
{
    std::vector<std::string> data = split(std::string(line), ' ');

    if (data.size() != 4)
        return;
    std::shared_ptr<Trantor> p = win->_stock->_player[atoi(data[1].c_str())];
    if (p == nullptr)
        return;
    p->forwardPlayer(atoi(data[2].c_str()), atoi(data[3].c_str()));
}

void GUI::ppCmd(Zappy *win, const char *line)
{
    std::vector<std::string> data = split(std::string(line), ' ');

    if (data.size() != 3)
        return;
    std::shared_ptr<Trantor> p = win->_stock->_player[atoi(data[1].c_str())];
    if (p == nullptr)
        return;
    p->rotatePlayer((Rotation)atoi(data[2].c_str()));
}

void GUI::pgtCmd(Zappy *win, const char *line)
{
    std::vector<std::string> data = split(std::string(line), ' ');

    if (data.size() != 3)
        return;
    std::shared_ptr<Trantor> p = win->_stock->_player[atoi(data[1].c_str())];
    std::shared_ptr<Map> map = win->_stock->_map;
    if (p == nullptr)
        return;
    p->addResource(atoi(data[2].c_str()));
    map->delSpecResource(p->_coords, atoi(data[2].c_str()));
}

void GUI::pdrCmd(Zappy *win, const char *line)
{
    std::vector<std::string> data = split(std::string(line), ' ');

    if (data.size() != 3)
        return;
    std::shared_ptr<Trantor> p = win->_stock->_player[atoi(data[1].c_str())];
    std::shared_ptr<Map> map = win->_stock->_map;
    if (p == nullptr)
        return;
    p->delResource(atoi(data[2].c_str()));
    map->addSpecResource(p->_coords, atoi(data[2].c_str()));
}

void GUI::pbcCmd(Zappy *win, const char *line)
{
    std::ostringstream log("");

    if (strlen(line) > 30) {
        std::string s = "pbc " + atoi(&line[4]);
        s += " Broadcast!";
        pbcCmd(win, s.c_str());
        return;
    }
    std::vector<std::string> data = split(std::string(line), ' ');
    log << "Trantor broadcast \n id :" << data[1];
    addToLog(log.str().c_str(), win);
    //std::cout << "Broadcast From Player : " << data[1] << std::endl;
    std::shared_ptr<Trantor> p = win->_stock->_player[atoi(data[1].c_str())];
    Msg *msg = new Msg(&line[data[0].size() + data[1].size() + 2], p->_pos, win->_t._ftbroad, p->_color);
    p->_topMsg.push_back(msg);
}

void GUI::plvCmd(Zappy *win, const char *line)
{
    std::ostringstream log("");
    std::vector<std::string> data = split(std::string(line), ' ');

    if (data.size() != 3)
        return;
    std::shared_ptr<Trantor> p = win->_stock->_player[atoi(data[1].c_str())];
    p->setPlayerLvl(atoi(data[2].c_str()));
    log << "Trantor lvl up !";
    addToLog(log.str().c_str(), win);
    data.clear();
}

void GUI::pinCmd(Zappy *win, const char *line)
{
    std::vector<std::string> data = split(std::string(line), ' ');

    if (data.size() != 11)
        return;
    std::shared_ptr<Trantor> p = win->_stock->_player[atoi(data[1].c_str())];

    int rc[] = {atoi(data[4].c_str()),
                atoi(data[5].c_str()),
                atoi(data[6].c_str()),
                atoi(data[7].c_str()),
                atoi(data[8].c_str()),
                atoi(data[9].c_str()),
                atoi(data[10].c_str())};
    //std::cout << "Pin : [" << line << "]" << std::endl;
    p->setPlayerInv(rc);
    data.clear();
}

void GUI::picCmd(Zappy *win, const char *line)
{
    std::vector<std::string> data = split(std::string(line), ' ');
    std::shared_ptr<Trantor> p = win->_stock->_player[atoi(data[4].c_str())];
    std::string m("Incant  ");

    m += "lvl : " + data[3];

    Msg *msg = new Msg(m, p->_pos, win->_t._ftbroad, p->_color);
    p->_topMsg.push_back(msg);
}

void GUI::pieCmd(Zappy *win, const char *line)
{
    // TODO: implement smth (animation ? particle ?)
}

// Egg functions

void GUI::enwCmd(Zappy *win, const char *line)
{
    std::vector<std::string> data = split(std::string(line), ' ');

    if (data.size() != 5)
        return;
    std::cout << "New Egg: " << data[1] << std::endl;
    std::shared_ptr<Trantor> p = win->_stock->_player[atoi(data[2].c_str())];
    int x = atoi(data[3].c_str());
    int y = atoi(data[4].c_str());
    std::shared_ptr<Egg> newEgg = std::make_shared<Egg>(rl::Vec2(x, y), win->_t._egg, p->_color, atoi(data[1].c_str()));
    win->_stock->addEgg(atoi(data[1].c_str()), newEgg);
    win->_manager->addComponent(newEgg, 2);
    data.clear();
}

void GUI::ehtCmd(Zappy *win, const char *line)
{
    // TODO: implement smth (animation ? particle ?)
}

void GUI::eboCmd(Zappy *win, const char *line)
{
    // TODO : implement spawn Trantor
}

void GUI::ediCmd(Zappy *win, const char *line)
{
    std::vector<std::string> data = split(std::string(line), ' ');

    if (data.size() != 2)
        return;
    std::shared_ptr<Egg> newEgg = win->_stock->_egg[atoi(data[1].c_str())];
    newEgg->_destroyed = true;
}

void GUI::pdiCmd(Zappy *win, const char *line)
{
    std::vector<std::string> data = split(std::string(line), ' ');
    std::ostringstream log("");

    if (data.size() != 2)
        return;
    log << "Trantor dies\n id :" << data[1];
    addToLog(log.str().c_str(), win);
    std::cout << log.str() << std::endl;
    std::shared_ptr<Trantor> p = win->_stock->_player[atoi(data[1].c_str())];
    p->_death = true;
}

void GUI::prrCmd(Zappy *win, const char *line)
{
    std::vector<std::string> data = split(std::string(line), ' ');

    if (data.size() != 3)
        return;
    std::shared_ptr<Trantor> p = win->_stock->_player[atoi(data[1].c_str())];
    p->setResource(0, atoi(data[2].c_str()));
}

void GUI::victoryScene(Zappy *win, const char *line)
{
    std::vector<std::string> data = split(std::string(line), ' ');
    std::ostringstream log("");

    if (data.size() != 2)
        return;
    log << "! VICTORY !\n winner :" << data[1];
    addToLog(log.str().c_str(), win);
}