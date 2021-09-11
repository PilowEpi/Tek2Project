/*
** EPITECH PROJECT, 2021
** YEP Zappy
** File description:
** Info
*/

#include "../Object.hpp"
#include "../../Zappy.hpp"
#include <iostream>
#include <sstream>

Info::Info(int scene, Zappy *m, std::shared_ptr<rl::Font> font, rl::Color bgColor)
    : _bg(0, 0, 0, 0),
    _bgColor(bgColor)
{
    _scene = scene;
    _win = m;
    _disabled = true;
    _font = font;
}

void Info::handleEvent(std::string event)
{
    rl::Vec2 pos = rl::Mouse::GetMousePosition();
    Trantor *p = 0;

    if (!rl::Mouse::IsMouseButtonReleased(::MouseButton::MOUSE_LEFT_BUTTON))
        return;
    _disabled = true;
    rl::Ray ray(pos, *(_win->_manager->_cam));
    bool step = false;
    for (auto obj : _win->_manager->_objs[2]) {
        if (p = dynamic_cast<Trantor *>(obj.get())) {
            if (ray.checkColissionBox(p->getBoundingBox())) {
                _p = p;
                step = true;
                break;
            }
        }
    }
    if (!step)
        return;
    _disabled = false;
}

void Info::render(rl::Camera3d *cam)
{
    rl::Rectangle border(10, 10, 66, 66);
    rl::Rectangle square(10, 80, 15, 15);
    rl::Rectangle head(8, 8, 8, 8);
    std::ostringstream ss;
    std::vector<rl::Color> color = {rl::Color(255, 255, 0, 255), rl::Color(255, 0, 0, 255),
                                rl::Color(255, 0, 255, 255), rl::Color(0, 255, 0, 255),
                                rl::Color(0, 255, 255, 255), rl::Color(255, 255, 255, 255),
                                rl::Color(255, 140, 0, 255)};
    int x = 0;

    if (_disabled)
        return;
    if (_p->_death)
        return;
    _win->_logs->callServer("pin " + _p->_id);
    ss.str("");
    _bg.x = 0;
    _bg.y = 0;
    _bg.width = 250;
    _bg.height = 125;
    _bg.draw(_bgColor);
    border.draw(rl::Color(255,255,255,255));
    ((*_p->_skins)[_p->_lvl - 1])->drawTiled(head, rl::Rectangle(11, 11, 64, 64), rl::Vec2(0, 0), 0.0, 8.0, _p->_color);
    ss << _p->_teamName << " (" << _p->_id << ")" << std::endl;
    _font->drawTextEx(ss.str(), rl::Vec2(80, 25), 24, 0.0, rl::Color(255, 255, 255, 255));
    ss.str("");
    ss << "Level : " << _p->_lvl << std::endl;
    _font->drawTextEx(ss.str(), rl::Vec2(80, 45), 24, 0.0, rl::Color(255, 255, 255, 255));
    for (const auto &entry : _p->_ressources) {
        square.draw(color[x]);
        _font->drawTextEx(std::to_string(entry.second), rl::Vec2(square.x + 17, square.y - 5), 24, 0.0, rl::Color(255, 255, 255, 255));
        if (x % 2) {
            square.x += 58;
            square.y -= 20;
        } else
            square.y += 20;
        x++;
    }
}