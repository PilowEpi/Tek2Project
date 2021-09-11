
#ifndef _QIX_GAME_H
#define _QIX_GAME_H

#include <deque>
#include <map>

#include "arcade.hpp"
#include "game.hpp"

class Qix : public AGameModule 
{

public:
    ~Qix() {};
    Qix();

    std::vector<IObject *> *run(Vec2i vec);
    void computeEvent(Event event);
    int getScore();

    const std::string getName() {return this->_name;};
    
private:
    enum States {
        IGNITED  = -1,
        EMPTY    =  0,
        BUILDING =  1,
        BORDER   =  2,
        FILLED   =  3  
    };
    
    std::string _name;
    std::vector<IObject *> *objs;
    std::vector<std::vector<int>> map;
    std::vector<std::vector<int>> _cpy;

    Text *_score;
    Text *_win;

    long _start;
    long _time;
    int _state;

    Vec2i _dir;

    int score;
    bool flushScore;

    Square *_player;
    Square *_qix;
    Square *_bg;

    std::vector<Square *> _sparks;
    std::vector<Vec2i> _sDirs;

    std::deque<Vec2i> _ignite;
    long _igStart;

    void clear();
    void init(Vec2i vec);

    void pushMap();
    
    bool isWalkable(Vec2i pos);
    bool isQix(Vec2i pos, Vec2i size);
    bool isSpark(Vec2i pos);

    void testFill();
    void doFill();

    bool recFill(int x, int y, int val);

    void stepPlayer();
    void stepQix();
    void stepSparks();

    void addSparkDir(std::vector<Vec2i> &, Vec2i &,
                     Vec2i &, int, int);
    bool hasIgnited();

    int isWon();
};

#endif
