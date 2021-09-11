/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** Help
*/

#include "../Object.hpp"
#include "../../Zappy.hpp"
#include <iostream>
#include <sstream>

Help::Help(int scene, Zappy *m, std::shared_ptr<rl::Font> font, rl::Color bgColor)
    : _bg(0, 0, 125, 200),
    _bgColor(bgColor)
{
    _scene = scene;
    _win = m;
    _font = font;
}

void Help::render(rl::Camera3d *cam)
{
    int index = 0;
    std::vector<rl::Color> color = {rl::Color(255, 140, 0, 255),rl::Color(255, 255, 255, 255), rl::Color(0, 255, 255, 255),
                                rl::Color(0, 255, 0, 255), rl::Color(255, 0, 255, 255),
                                rl::Color(255, 0, 0, 255), rl::Color(255, 255, 0, 255)};
    std::vector<std::string> rcName = {"food", "linemate", "deraumere", "sibur",
                                        "mendiane", "phiras", "thystame"};

    _bg.y = _win->_win->getScreenHeight() - _bg.height;
    rl::Rectangle square(100, _bg.y, 20, 20);
    _bg.draw(_bgColor);
    for (auto rc : rcName) {
        _font->drawTextEx(rc, rl::Vec2(_bg.x, (index * 30) + _bg.y), 20, 0.0, rl::Color(230,230,230,230));
        square.draw(color[index]);
        square.y = ((index + 1) * 30) + _bg.y;
        index++;
    }
}