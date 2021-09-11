#pragma once
#include <map>

#include "utils.hpp"

class Friend {
public:
    Friend() {};
    Friend(Vec2 MapSize, std::stringstream &ss, int id);

    int getNextNumber(std::stringstream &ss);

    void update(std::stringstream &ss);

    int level;
    Vec2 position;
    std::map<Object, int> inventory;
    int mapId;
    int playerId;
    enum edir dir;
    Map map;
    int status;
    Vec2 m_dir;
};