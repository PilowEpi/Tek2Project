/*
** EPITECH PROJECT, 2021
** YEP Zappy
** File description:
** Info
*/

#ifndef INFO_HPP_
#define INFO_HPP_

#include "../Object.hpp"

class Trantor;

class Info : public Object2D
{
    public:
        Info(int scene,
            Zappy *m,
            std::shared_ptr<rl::Font> font,
            rl::Color bgColor = rl::Color(40, 40, 40, 125));

            void handleEvent(std::string event) override;
            void render(rl::Camera3d *cam) override;
    private:
        Zappy *_win;
        int _disabled;
        int _scene;
        std::shared_ptr<rl::Font> _font;
        rl::Rectangle _bg; // background of the Info object
        rl::Color _bgColor; //  color of the background
        Trantor *_p;
};

#endif