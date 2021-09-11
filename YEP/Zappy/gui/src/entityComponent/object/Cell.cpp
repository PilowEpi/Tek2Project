/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** Cell
*/

#include "../Object.hpp"
#include "../../Zappy.hpp"


Cell::Cell(rl::Vec2 coord, std::shared_ptr<rl::Model> dirt, std::shared_ptr<rl::Texture> block, std::shared_ptr<rl::Texture> foodTxt)
{
    _coords = rl::Vec2(coord);
    _floor = dirt;
    _block = block;
    _food = foodTxt;
    _color = rl::Color(255, 255, 255, 255);
    _size = rl::Vec3(0.15f, 0.15f, 0.15f);
    
    // Init Ressources
    _ressources[food]       = 0;
    _ressources[linemate]   = 0;
    _ressources[deraumere]  = 0;
    _ressources[sibur]      = 0;
    _ressources[mendiane]   = 0;
    _ressources[phiras]     = 0;
    _ressources[thystame]   = 0;
}

Cell::~Cell()
{
    _ressources.clear();
}

void Cell::render(rl::Camera3d *cam)
{
    std::vector<rl::Color> color = {rl::Color(255, 255, 255, 255), rl::Color(0, 255, 255, 255),
                                rl::Color(0, 255, 0, 255), rl::Color(255, 0, 255, 255),
                                rl::Color(255, 0, 0, 255), rl::Color(255, 255, 0, 255)};
    float coords[] = {-0.6, -0.4, -0.2, 0, 0.2, 0.4};
    // Floor

    _floor->drawEx(rl::Vec3(_coords.x * 1.6, 0, _coords.y * 1.6),
                    rl::Vec3(0, 1, 0), 0,
                    rl::Vec3(0.8f, 0.8f, 0.8f), _color);
    // Food

    for (int i = 0; i < _ressources[food]; i++) {
        _food->drawTexture(rl::Vec3((_coords.x * 1.6) - 0.4, 0.9 + (i * 0.15), (_coords.y * 1.6) + 0.6),
                    _size, color[0]);
    }
    
    // Minerals

    for (int j = 1; j <= 7; j++) {
        for (int i = 0; i < _ressources[(Rtype)j]; i++) {
            _block->drawTexture(rl::Vec3((_coords.x * 1.6) - 0.4, 0.9 + (i * 0.15), (_coords.y * 1.6) + coords[j - 1]),
                        _size, color[j - 1]);
        }
    }

}

void Cell::addResources(int *data)
{
    for (int i = 0; i < 7; i++)
        _ressources[(Rtype)i] += data[i];
}

void Cell::setResources(int *data)
{
    for (int i = 0; i < 7; i++)
        _ressources[(Rtype)i] = data[i];
}

void Cell::printResources()
{
    for (int i = 0; i < 7; i++)
        std::cout << "rsc : " << i << " :" << _ressources[(Rtype)i] << std::endl;
}

void Cell::addResource(Rtype type)
{
    _ressources[type]++;
}

void Cell::delResource(Rtype type)
{
    _ressources[type]--;
}