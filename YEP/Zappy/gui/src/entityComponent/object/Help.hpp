/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** Help
*/

#ifndef HELP_HPP_
#define HELP_HPP_

#include "../Object.hpp"

class Help : public Object2D
{
    public:
        Help(int scene, Zappy *m, 
        std::shared_ptr<rl::Font> font, 
        rl::Color bgColor = rl::Color(40, 40, 40, 125));

        void render(rl::Camera3d *cam) override;
    private:
        Zappy *_win;
        int _scene;
        std::shared_ptr<rl::Font> _font;
        rl::Rectangle _bg; // background of the Info object
        rl::Color _bgColor; //  color of the background
};

#endif