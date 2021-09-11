#include <string>
#include <iostream>
#include <sstream>

#include "utils.hpp"
#include "friend.hpp"

Friend::Friend() {};
Friend::Friend(Vec2 MapSize, std::stringstream &ss, int id) {
    playerId = id;
    map.resize(MapSize.x);
    for (auto &vec : map)
        vec.resize(MapSize.y);
    update(ss);
}

int Friend::getNextNumber(std::stringstream &ss) {
    int val;
    char buf;
    ss >> val;
    ss >> buf; 
    return val;
}

void Friend::update(std::stringstream &ss) {
    // setInventory
    for (int i = 1; i <= 7; i++)
        inventory[(Object)i] = getNextNumber(ss);
    
    // refferentiel id and cordinate
    mapId = getNextNumber(ss);
    position.x = getNextNumber(ss);
    position.y = getNextNumber(ss);
    dir = (edir)getNextNumber(ss);

    level = getNextNumber(ss);

    std::cout << "update " << playerId << std::endl;

    // setMap
    for (auto &line : map) {
        for (auto &cell : line) {
            int time = getNextNumber(ss);
            std::vector<int> tmp_cell(8);
            for (int i = 0; i <= 7; i++){
                tmp_cell[i] = getNextNumber(ss);
                if (cell.time >= time) {
                    cell.time = time;
                    cell.objects[(Object)i] = tmp_cell[i];
                }
            }
        }
    }
    print_map(map);
}
