/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** Map
*/

#include "../Object.hpp"
#include "../../Zappy.hpp"
#include "../../messageManager/GuiFonctions.hpp"

Map::Map(rl::Vec2 size, Zappy *win, int scene)
    : _content(size.y)
{
    std::shared_ptr<rl::Model> floor = win->_t._dirt;
    std::shared_ptr<rl::Texture> block = win->_t._block;
    std::shared_ptr<rl::Texture> food = win->_t._food;
 
    _scene = scene;
    _mapsize = rl::Vec2(size);
    _win = win;
    for (int i = 0; i < _mapsize.y; i++) {
        for (int j = 0; j < _mapsize.x; j++) {
            _content[i].push_back(std::make_shared<Cell>(rl::Vec2(i,j), floor, block, food));
        }
    }
}

void Map::simulate()
{

}

void Map::render(rl::Camera3d *cam)
{
    for (int i = 0; i < _mapsize.y; i++) {
        for (int j = 0; j < _mapsize.x; j++) {
            _content[i][j]->render(cam);
        }
    }
}

void Map::handleEvent(std::string event)
{
    if (event.size() == 0)
        return;
    std::vector<std::string> buf;
    if (std::strncmp(event.c_str(), "bct", 3))
        return;
    buf = split(event, ' ');
    
    int y = atoi(buf[2].c_str());
    int x = atoi(buf[1].c_str());
    int data[] = {atoi(buf[3].c_str()),
                atoi(buf[4].c_str()),
                atoi(buf[5].c_str()),
                atoi(buf[6].c_str()),
                atoi(buf[7].c_str()),
                atoi(buf[8].c_str()),
                atoi(buf[9].c_str())};

    _content[y][x]->setResources(data);
    buf.clear();
}

void Map::addSpecResource(rl::Vec2 coord, int type)
{
    _content[coord.y][coord.x]->addResource((Cell::Rtype) type);
}

void Map::delSpecResource(rl::Vec2 coord, int type)
{
    _content[coord.y][coord.x]->delResource((Cell::Rtype) type);
}