/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** Menu
*/

#include "../Object.hpp"
#include "../../Zappy.hpp"

Menu::Menu(rl::Vec2 pos, rl::Vec2 offset, Zappy *m, float size, std::shared_ptr<rl::Font> font, std::shared_ptr<std::vector<std::string>> txt, rl::Color c)
    : _move(size, 0.0),
      _rect(0.0, 0.0, 0.0, 0.0),
      _btn(0.0, 0.0, 0.0, 0.0)
{
    _pos = pos;
    _offset = offset;
    _zappy = m;
    _color = c;
    _size = size;
    _txt = txt;
    _deploy = false;
    _switch = 0;
    _font = font;
}

void Menu::simulate()
{
    if (_switch > 0) {
        _move.x += 4;
        if (_move.x >= _rect.width)
            _switch = 0;
    }
    if (_switch < 0) {
        _move.x -= 4;
        if (_move.x <= 0)
            _switch = 0;
    }
}

void Menu::handleEvent(std::string event)
{
    rl::Vec2 pos = rl::Mouse::GetMousePosition();

    if (_btn.checkCollision(pos) && rl::Mouse::IsMouseButtonReleased(::MouseButton::MOUSE_LEFT_BUTTON) && !_switch) {
        if (_deploy)
            _switch = 1;
        else
            _switch = -1;
        _deploy = !_deploy;
    }
}

void Menu::render(rl::Camera3d *cam)
{
    int index = 0;

    _rect.x = ((float)_zappy->_win->getScreenWidth()) * _pos.x + _offset.x + _move.x;
    _rect.y = ((float)_zappy->_win->getScreenHeight()) * _pos.y + _offset.y + _move.y;
    _rect.width = _size;
    _rect.height = ((float)_zappy->_win->getScreenHeight());
    _rect.draw(_color);
    _btn.width = 40.0;
    _btn.height = 40.0;
    _btn.x = _rect.x - _btn.width;
    _btn.draw(_deploy ? rl::Color(240, 40, 40, 140) : rl::Color(40, 240, 40, 140));
    _font->drawTextEx(_deploy ? ">" : "<", rl::Vec2(_btn.x + 15.0, 0.0), 40.0, 0.0, rl::Color(255,255,255,255));
    if (_deploy) {
        for (auto str : *_txt) {
            _font->drawTextEx(str, rl::Vec2(_rect.x, index * 30), 20, 0.0, rl::Color(230,230,230,230));
            for (auto c : str)
                c == '\n' ? index++ : 0;
            index++;
        }
    }
    if (index * 30 >= _rect.height)
        _txt->erase(_txt->begin());
}
