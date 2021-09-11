/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** Egg
*/

#ifndef YEP_EGG_HPP_
#define YEP_EGG_HPP_

#include "../Object.hpp"

class Egg : public Object3D
{
    public:
        Egg(rl::Vec2 coord, std::shared_ptr<rl::Texture> egg, rl::Color color, int id);

        void render(rl::Camera3d *cam) override;
        void simulate() override;
        void handleEvent(std::string event) override;

        std::shared_ptr<rl::Texture> _egg;
        rl::Vec2 _coords;
        rl::Color _color;
        rl::Vec3 _size;
        bool _destroyed;
        int _id;
    private:
};

#endif