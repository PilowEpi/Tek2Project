
#ifndef _PACMAN_GAME_H
#define _PACMAN_GAME_H

#include <deque>

#include "arcade.hpp"
#include "game.hpp"

class Pacman : public AGameModule 
{

public:
    ~Pacman() {};
    Pacman();

    std::vector<IObject *> *run(Vec2i vec);
    void computeEvent(Event event);

    const std::string getName() {return this->_name;};
private:
    enum States
    {
        EMPTY =     0,
        WALL =      1,
        SPAWN =     2,
        PACGUN =    3,
        PACPOW =    4,
    };
    std::string _name;

    long _time;
    int _score;
    int _state;

    Square *_border;
    Square *_bg;
    Square *_pacman;
    std::vector<Square *> _fantoms;

    std::vector<std::vector<char>> dataMap;
    std::vector<std::vector<int>> map;
    std::vector<IObject *> *objs;

    Vec2i _dir;

    void init(Vec2i vec);
    void clear();
    int getScore() { return _score;};
    void pushMap();

    // Map Creation

    void createMap(Vec2i vec);
    void createBlock(Seg segment, Pacman::States type);
    void createPow(Vec2i vec, Pacman::States type);

    // Mouvement

    void stepPacman();
    void stepGhost(Square *ghost);
    bool isWalkable(Square square);

    // Ghost IA

    Vec2i getDirToGoal(Vec2i current, Vec2i goal);
    Vec2i randomWay(Vec2i pos, Vec2i currDir);
    Vec2i findWay(Vec2i start, Vec2i dest);


    // Delete Pacgun

    bool isPac(Square sq);
    void deletePac(Vec2i vec);
    Vec2i getCoords(Square sq);
    void refreshMap();

    // Power Up

    long _powerTime;
    bool isPower(Square sq);
    void startPower();
    void tpGhost(Square *ghost);

    // Teleport
    void teleport();
    bool isTp(Square sq);

    // Repawn ghost
    long _spawnTime;
    bool needRepawn(Square *ghost);

    // Win / Lose
    bool isWon();
};

#endif