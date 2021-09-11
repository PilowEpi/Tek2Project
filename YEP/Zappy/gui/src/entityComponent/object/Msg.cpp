/*
** EPITECH PROJECT, 2021
** YEP Zappy
** File description:
** Msg
*/

#include "../Object.hpp"
#include "../../Zappy.hpp"

Msg::Msg(std::string message, rl::Vec3 pos, std::shared_ptr<rl::Font> font, rl::Color color)
{
    _ft = std::make_shared<rl::Font>("gui/assets/minecraftia.ttf");
    _msg = squeezeMsg(message, 10);
    _pos = pos;
    _color = color;
    _ftSize = 2;
    _scene = 2;
    _mTexture = new rl::Texture(_msg, (*_ft), _ftSize, _color);
    _isVisible = true;
    _timer = 200;
}

void Msg::changeMsg(std::string msg)
{
    if (_mTexture != NULL)
        delete _mTexture;
    _msg = squeezeMsg(msg, 10);
    _mTexture = new rl::Texture(_msg, (*_ft), _ftSize, _color);
}

std::string Msg::squeezeMsg(std::string _origin, int squeezePercent)
{
    std::string newMsg("");
    int size = _origin.size();

    for (int i = 0; i < size; i++) {
        if (i % squeezePercent == 0)
            newMsg += '\n';
        newMsg += _origin[i];
    }
    return newMsg;
}

void Msg::simulate()
{
    if (_timer >= 0) {
        _timer -= 1;
        _color.a -= 1;
    } else {
        _color.a = 0;
        _isVisible = false;
    }
}

void Msg::render(rl::Camera3d *cam)
{
    if (!_isVisible)
        return;
    _mTexture->drawBillboard(*cam, _pos + rl::Vec3(0, 2, 0), 1, _color);
}
