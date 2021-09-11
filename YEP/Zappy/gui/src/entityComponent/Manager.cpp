/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** Manager
*/

#include "Manager.hpp"
#include <map>

ComponentManager::ComponentManager(Zappy *win) :
    _objs(7)
{
    _cam = new rl::Camera3d(rl::Vec3(15.0f, 10.0f, 15.0f),
                            rl::Vec3(0.0f, 0.0f, 0.0f),
                            rl::Vec3(0.0f, 1.0f, 0.0f),
                            45.0f, 0);
    _settings._scene = 0;
    _settings._sizeMap = rl::Vec2(0, 0);
    _settings._mVol = 1.0;
    _settings._sVol = 1.0;
    _settings._orientation = "North";
    _set_pos = {0, 0, 0};
    _set_target = {0, 0, 0};
    _scene = 0;
    _win = win;
}

ComponentManager::~ComponentManager()
{
    delete _cam;
    this->clearComponents();
}

void ComponentManager::addComponent(std::shared_ptr<AObject> obj, int index)
{
    obj->_manager = this;
    _objs[index].push_back(obj);
}

void ComponentManager::clearComponents()
{
    _objs[_settings._scene].clear();
}

void ComponentManager::simulate()
{
    /* Crash with tentor
    // remove designated objects
    for (int i = 0; i < _objs[_settings._scene].size(); i++) {
        auto obj = _objs[_scene][i];
        // clear object
        if (obj->_toRemove) {
            _objs[_scene].erase(_objs[_settings._scene].begin()+i);
            i--;
        }
    } */

    for (auto obj : _objs[_settings._scene])
        obj->simulate();
    _frame++;
}

void ComponentManager::renderAll()
{
    _cam->beginMode();
    for (auto obj : _objs[_settings._scene])
        if (Object3D *obj2 = dynamic_cast<Object3D *>(obj.get()))
            obj->render(_cam);
    _cam->endMode();
    for (auto obj : _objs[_settings._scene])
        if (Object2D *obj2 = dynamic_cast<Object2D *>(obj.get()))
            obj->render(_cam);
}

void ComponentManager::handleEvent(std::string event)
{
    for (auto obj: _objs[2]) {
        obj->handleEvent(event);
    }
    if (_settings._scene == 2)
        return;
    for (auto obj: _objs[_settings._scene]) {
        obj->handleEvent(event);
    }
}

void ComponentManager::manageCamera()
{
    if (_settings._scene == 2) {
        int x = _settings._sizeMap.x + 1;
        int y = _settings._sizeMap.y + 1;
        _set_target = rl::Vec3(x / 2, 0.9, y / 2);
        _set_pos = _set_target + getPosition(_settings._orientation);
    } else {
        _set_pos = rl::Vec3(1.0f, 1.0f, 1.0f);
        _set_target = rl::Vec3(4.0f, 1.5f, 1.0f);
    }
    moveCamera(true);
}

void ComponentManager::moveCamera(bool dynamic)
{
    if (dynamic) {
        static rl::Vec3 v_pos(0, 0, 0);
        static rl::Vec3 v_target(0, 0, 0);
        rl::Vec3 pos = _cam->getPosition();
        rl::Vec3 target = _cam->getTarget();

        v_pos    += (_set_pos    - v_pos    * 50 - pos   ) * 0.001;
        v_target += (_set_target - v_target * 50 - target) * 0.001;

        _cam->setTarget( target + v_target);
        _cam->moveCamera(pos    + v_pos);

    } else {
        _cam->setTarget(_set_target);
        _cam->moveCamera(_set_pos);
    }
}

rl::Vec3 ComponentManager::getPosition(std::string _dir)
{
    std::map<std::string, rl::Vec3> position;
    int x = _settings._sizeMap.x + 1;
    int y = _settings._sizeMap.y + 1;

    position["North"] = rl::Vec3(0, y, (x + y) * -1);
    position["South"] = rl::Vec3(0, y, (x + y));
    position["East"] = rl::Vec3((x + y), y, 0);
    position["Weast"] = rl::Vec3((x + y) * -1, y, 0);
    return position[_dir];
}