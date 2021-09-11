/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "../Object.hpp"
#include <memory>
#include <unordered_map>

class Cell
{
    public:
        Cell(rl::Vec2 coord, std::shared_ptr<rl::Model> dirt, std::shared_ptr<rl::Texture> block, std::shared_ptr<rl::Texture> food);
        ~Cell();

        enum Rtype {
            food        = 0,
            linemate    = 1,
            deraumere   = 2,
            sibur       = 3,
            mendiane    = 4,
            phiras      = 5,
            thystame    = 6,
        };

        void render(rl::Camera3d *cam);
        void addResource(Rtype type);
        void delResource(Rtype type);

        void addResources(int *data);
        void setResources(int *data);
        void printResources();
        
        rl::Vec2 _coords;
        rl::Color _color;
        rl::Vec3 _size;
        std::unordered_map<Rtype, int> _ressources;
        std::shared_ptr<rl::Model> _floor;
        std::shared_ptr<rl::Texture> _food;
        std::shared_ptr<rl::Texture> _block;
    private:
};

class Map : public Object3D
{
    public:
        Map(rl::Vec2 size, Zappy *win, int scene);
        ~Map() {};

        void handleEvent(std::string event) override;
        void simulate() override;
        void render(rl::Camera3d *cam) override;

        void addSpecResource(rl::Vec2 coord, int type);
        void delSpecResource(rl::Vec2 coord, int type);

        rl::Vec2 _mapsize;
        Zappy *_win;
        std::vector<std::vector<std::shared_ptr<Cell>>> _content;
    private:
};

#endif