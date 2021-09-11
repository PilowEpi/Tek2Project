
#ifndef _QIX_GAME_H
#define _QIX_GAME_H

#include <deque>
#include <map>

#include "arcade.hpp"
#include "game.hpp"

class Centipede : public AGameModule 
{

public:
    ~Centipede() {};
    Centipede();

    std::vector<IObject *> *run(Vec2i vec);
    void computeEvent(Event event);
    int getScore();

    const std::string getName() {return this->_name;};
    
private:
    struct Mob {
        Mob(int size = 8, int dir = 1, Vec2i at = {6, 1});
        ~Mob();

        std::vector<Square *> parts;
        std::vector<int> dirs;
        int speed;
        int counter;
    };
    
    std::string _name;
    std::vector<IObject *> *objs;
    std::vector<std::vector<int>> map;

    std::vector<Mob *> centipedes;

    Text *_score;
    Text *_win;

    int cCounter = 0;

    long _time;
    long _btime;
    int _state;

    bool fire = 0;

    Vec2i _dir;

    int score;
    bool flushScore;

    Square *_player;
    Square *_bullet;
    Square *_bg;

    std::vector<Square *> _centipede;
    std::vector<Vec2i> _sDirs;

    void clear();
    void init(Vec2i vec);

    void pushMap();

    void stepPlayer();
    void stepCentipede();
    Vec2i moveCenti(Vec2i, int &);

    void processBullet();

    void deletePart(Mob *, Square *);
};

#endif
