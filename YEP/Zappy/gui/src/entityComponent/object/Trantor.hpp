/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Trantor
*/

#ifndef TRANTOR_HPP_
#define TRANTOR_HPP_

#include "../Object.hpp"

enum Rotation
{
    North   = 0,
    East    = 1,
    South   = 2,
    Weast   = 3,
};

class Trantor : public Object3D
{
    public:
        Trantor(rl::Vec2 coords, rl::Color color, Rotation _r, int lvl, int id, std::string teamName, std::shared_ptr<std::vector<std::shared_ptr<rl::Model>>> models, std::shared_ptr<std::vector<std::shared_ptr<rl::Texture>>> skins);
   
        void handleEvent(std::string event) override;
        void simulate() override;
        void render(rl::Camera3d *cam) override;

        enum Rtype {
            food        = 0,
            linemate    = 1,    // Melanite
            deraumere   = 2,    // Emeraude
            sibur       = 3,    // Rubis
            mendiane    = 4,    
            phiras      = 5,    // Saphir
            thystame    = 6,    // Amethyst
        };

        std::shared_ptr<std::vector<std::shared_ptr<rl::Model>>> _models;
        std::shared_ptr<std::vector<std::shared_ptr<rl::Texture>>> _skins;
        rl::Vec2 _coords;
        float _r;
        float _scale;
        int _id;
        int _frame;
        int _lvl;
        bool _death;
        rl::Color _color;
        std::string _teamName;
        std::unordered_map<Rtype, int> _ressources;
        rl::BoundingBox *getBoundingBox();
        std::vector<Msg *> _topMsg; // vecteur de la mort (ne peux pas etre delete cause : raylib )

        // Events
        void setPlayerPos(int x, int y, Rotation r);
        void setPlayerLvl(int lvl);
        void setPlayerInv(int *data);
        void forwardPlayer(int x, int y);
        void rotatePlayer(Rotation r);
        void addResource(int type);
        void delResource(int type);
        void setResource(int type, int q);
        void printDebug();
    private:
        float getRotation(Rotation r);
        void movePlayer(std::string line);
        void setPlayerLvl(std::string line);
};

#endif