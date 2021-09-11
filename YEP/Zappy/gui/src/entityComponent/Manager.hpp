/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** Manager
*/

#ifndef ZAPPY_MANAGER_
#define ZAPPY_MANAGER_

#include "../Zappy.hpp"
#include "../raylib/rayLib.hpp"
#include <vector>
#include <iostream>
#include <memory>

class AObject;
class Zappy;

class Settings
{
    public:
        int _scene;
        rl::Vec2 _sizeMap;
        float _mVol;
        float _sVol;
        int _width;
        int _height;
        std::string _orientation;
};

class ComponentManager
{
    public:
        ComponentManager(Zappy *win);
        ~ComponentManager();

        void addComponent(std::shared_ptr<AObject> obj, int index);

        void addComponent(AObject *obj, int index);
        void clearComponents();
        int size() const { return _objs.size(); };

        void simulate();
        void renderAll();
        void handleEvent(std::string event);

        std::vector<std::vector<std::shared_ptr<AObject>>> _objs;
        Settings _settings;
        
        rl::Vec2 _currentMapSize = {0, 0};
        int _scene;
        uint _frame = 0;

        // Camera position

        rl::Camera3d *_cam;
        rl::Vec3 _set_pos;
        rl::Vec3 _set_target;
        void moveCamera(bool dynamic);
        void manageCamera();
        rl::Vec3 getPosition(std::string _dir);

        Zappy *_win;
    private:
    
};

#endif