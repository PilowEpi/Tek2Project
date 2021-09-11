/*
** EPITECH PROJECT, 2021
** YEP Zappy
** File description:
** Msg
*/

#ifndef YEP_MSG_HPP_
#define YEP_MSG_HPP_

#include "../Object.hpp"

class Msg : public Object2D
{
    public:
        Msg(std::string message, rl::Vec3 pos, std::shared_ptr<rl::Font> font, rl::Color color);

        void simulate() override;
        void handleEvent(std::string event) override {};
        void render(rl::Camera3d *cam) override;
        void changeMsg(std::string msg);
    private:
        std::string squeezeMsg(std::string origin, int squeezePercent);
        rl::Texture *_mTexture;
        rl::Vec3 _pos;
        
        std::string _msg;
        std::shared_ptr<rl::Font> _ft;
        int _ftSize;

        bool _isVisible;
        float _timer;
};

#endif
