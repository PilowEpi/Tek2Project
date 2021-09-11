/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "../Object.hpp"

class Menu : public Object2D {
    public:
        Menu(rl::Vec2 pos, rl::Vec2 offset, Zappy *m, float size, std::shared_ptr<rl::Font> f, std::shared_ptr<std::vector<std::string>> txt, rl::Color c = rl::Color(40, 40, 40, 125));

        void simulate() override;
        void handleEvent(std::string event) override;
        void render(rl::Camera3d *cam) override;
    private:
        rl::Vec2 _pos;
        rl::Vec2 _offset;
        rl::Rectangle _rect;
        rl::Rectangle _btn;
        Zappy *_zappy;
        std::shared_ptr<rl::Font> _font;
        std::shared_ptr<std::vector<std::string>> _txt;
        rl::Color _color;
        rl::Vec2 _move;
        float _size;
        short _switch;
        bool _deploy;
};

#endif /* !MENU_HPP_ */
