
#ifndef _SNAKE_GAME_H
#define _SNAKE_GAME_H

#include "arcade.hpp"
#include "game.hpp"

class Snake : public AGameModule {

public:
    ~Snake() {};
    Snake();

    std::vector<IObject *> *run(Vec2i vec);
    void computeEvent(Event event);

    const std::string getName() {return this->_name;};
    void moveSnake();
    bool isWall(Vec2i pos);
    bool isSnakeBody(Vec2i pos);
    int getScore();
private:
    void clear();

    Text *_score;
    Text *_win;
    int score;
    int flush = 0;

    std::string _name;
    std::vector<IObject *> *objs;

    Vec2i _windowSize;
    std::vector<Vec2i> _snakePosition;
    std::vector<Vec2i> _foodPosition;
    char _dir;

    int _snakeSize;
    Square *_border;
    Square *_border2;
    bool _stopped;
    long _time;
};

#endif
