/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** Object
*/

#ifndef ZAPPY_OBJECT_
#define ZAPPY_OBJECT_

#include <string.h>
#include <vector>

#include "../raylib/rayLib.hpp"

class Zappy;
class ComponentManager;

class IObject
{
    public:
        virtual ~IObject() = default;
        virtual void handleEvent(std::string event) = 0;
        virtual void move(rl::Vec3 newPos) = 0;
        virtual void simulate() = 0;
        virtual void render(rl::Camera3d *cam) = 0;
    private:
};

class AObject : public IObject
{
    public:
        virtual ~AObject();
        virtual void handleEvent(std::string event) = 0;
        virtual void move(rl::Vec3 newPos)
        {
            _pos +=  newPos;
            _boundingBox._bd.min = rl::Vec3(_boundingBox._bd.min) + newPos;
            _boundingBox._bd.max = rl::Vec3(_boundingBox._bd.max) + newPos;
        }

        virtual void simulate() = 0;
        virtual void render(rl::Camera3d *cam) = 0;
        virtual float &operator[](int i) {return _pos[i];}

        rl::Vec3 boudingBoxCenter();
        rl::Vec3 _pos = {0, 0, 0};
        int _scene = 0;
        bool _toRemove = false;
        bool _isSolid = false;
        rl::BoundingBox _boundingBox;
        ComponentManager *_manager = 0;
        rl::Color _color = {255, 255, 255, 255};
    private:
};

class Object2D : public AObject
{
public:
    void handleEvent(std::string event) override {};
    void move(rl::Vec3 newPos) override { (void)newPos; };
    void simulate() override {};
    void render(rl::Camera3d *cam) override { (void)cam; };

};

class Object3D : public AObject
{
public:
};

#include "object/Btn.hpp"
#include "object/Slider.hpp"
#include "object/Map.hpp"
#include "object/Msg.hpp"
#include "object/Trantor.hpp"
#include "object/Menu.hpp"
#include "object/Info.hpp"
#include "object/Egg.hpp"
#include "object/Help.hpp"

#endif