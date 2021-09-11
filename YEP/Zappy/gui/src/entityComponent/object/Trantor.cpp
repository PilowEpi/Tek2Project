/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Trantor
*/

#include "../Object.hpp"
#include "../../Zappy.hpp"
#include "../../messageManager/GuiFonctions.hpp"

Trantor::Trantor(rl::Vec2 coords, rl::Color color, Rotation rota, int lvl, int id, std::string teamName, std::shared_ptr<std::vector<std::shared_ptr<rl::Model>>> models, std::shared_ptr<std::vector<std::shared_ptr<rl::Texture>>> skins)
{
    _coords = rl::Vec2(coords);
    _lvl = lvl;
    _id = id;
    _toRemove = false;
    _teamName = teamName;
    _skins = skins;
    _models = models;
    _scale = 0.2f;
    _r = getRotation(rota);
    _frame = 1;
    _color = color;
    _death = false;

    // Init Ressources
    _ressources[food]       = 12;
    _ressources[linemate]   = 0;
    _ressources[deraumere]  = 0;
    _ressources[sibur]      = 0;
    _ressources[mendiane]   = 0;
    _ressources[phiras]     = 0;
    _ressources[thystame]   = 0;

    _boundingBox._bd.min = _pos + rl::Vec3{-0.25, 0.0, -0.25};
    _boundingBox._bd.max = _pos + rl::Vec3{0.25, 1, 0.25};
}

void Trantor::handleEvent(std::string event)
{
}

void Trantor::simulate()
{
    if (_death) {
        _boundingBox._bd.min = rl::Vec3();
        _boundingBox._bd.max = rl::Vec3();
        return;
    }
    _pos = rl::Vec3(_coords.y * 1.6, 0.9, _coords.x * 1.6);
    _boundingBox._bd.min = _pos + rl::Vec3{-0.25, 0.0, -0.25};
    _boundingBox._bd.max = _pos + rl::Vec3{0.25, 1, 0.25};

    for (auto msg : _topMsg)
        msg->simulate();
}

void Trantor::render(rl::Camera3d *cam)
{
    if (_death)
        return;
    if (_frame < 0 || _frame > 40)
        return;
    (*_models)[(int)_frame]->setMaterialTexture(0, (*_skins)[_lvl - 1]);
    (*_models)[(int)_frame]->drawEx(_pos, rl::Vec3(0, 1, 0), _r, rl::Vec3(_scale, _scale, _scale), _color);
    for (auto msg : _topMsg)
        msg->render(cam);
}

float Trantor::getRotation(Rotation r)
{
    switch (r) {
        case Rotation::North:
            return 180.0f;
        case Rotation::East:
            return -90.0f;
        case Rotation::South:
            return 0.0f;
        case Rotation::Weast:
            return 90.0f;
    }
    return 0.0f;
}

void Trantor::setPlayerInv(int *data)
{
    for (int i = 0; i < 7; i++) {
        //std::cout << "Set rc : " << i << " q :" << data[i] <<  std::endl;
        _ressources[(Rtype)i] = data[i];
    }
}

void Trantor::setPlayerPos(int x, int y, Rotation rota)
{
    _coords.x = x;
    _coords.y = y;
    _r = getRotation(rota);
}

void Trantor::setPlayerLvl(int lvl)
{
    _lvl = lvl;
}

rl::BoundingBox *Trantor::getBoundingBox()
{
    return &_boundingBox;
}

void Trantor::forwardPlayer(int x, int y)
{
    _coords.x = x;
    _coords.y = y;
}

void Trantor::rotatePlayer(Rotation r)
{
    _r = getRotation(r);
}

void Trantor::addResource(int type)
{
    _ressources[(Rtype)type]++;
    // std::cout << "Player take :" << type << std::endl;
    // printDebug();
}

void Trantor::delResource(int type)
{
    _ressources[(Rtype)type]--;
    // std::cout << "Player del :" << type << std::endl;
    // printDebug();
}

void Trantor::setResource(int type, int q)
{
    _ressources[(Rtype)type] = q;
    // std::cout << "Player set :" << type << " q:" << q << std::endl;
    // printDebug();
}

void Trantor::printDebug()
{
    std::cout << "==Trantor Debug Mode==" << std::endl;
    std::cout << "Id : " << _id << std::endl;
    std::cout << "Level : " << _lvl << std::endl;
    std::cout << "Team : " << _teamName << std::endl;
    std::cout << "Coords : x:" << _coords.x << ", y:" << _coords.y << std::endl;
    std::cout << "Ressources :" << std::endl;
    std::cout << "\tfood        :" << _ressources[(Rtype)0] << std::endl;
    std::cout << "\tlinemate    :" << _ressources[(Rtype)1] << std::endl;
    std::cout << "\tderaumere   :" << _ressources[(Rtype)2] << std::endl;
    std::cout << "\tsibur       :" << _ressources[(Rtype)3] << std::endl;
    std::cout << "\tmendiane    :" << _ressources[(Rtype)4] << std::endl;
    std::cout << "\tphiras      :" << _ressources[(Rtype)5] << std::endl;
    std::cout << "\tthystame    :" << _ressources[(Rtype)6] << std::endl;
}