
#include <time.h>

#include "arcade.hpp"
#include "snake.hpp"
#include "game.hpp"

#include <iostream>

extern "C" Snake* ctor()
{
    return new Snake;
}

extern "C" std::string getLibName()
{
    return (std::string("Snake"));
}

extern "C" int getLibType()
{
    return (1);
}

Snake::Snake()
{
    std::vector<IObject *> *objs = new std::vector<IObject *>;

    Square *border = new Square;
    Square *border2 = new Square;

    border->pos = Vec2i{0, 0};
    border->color = colors[1];
    border->size = Vec2i{-1, -1};

    border2->pos = Vec2i{1, 1};
    border2->color = colors[0];
    border2->size = Vec2i{-1, -1};

    _score = new Text("0");
    _score->pos = Vec2i {0, 0};
    _score->color = colors[15];

    _win = new Text("");
    _win->pos = Vec2i {0, 0};
    _win->color = colors[1];
    score = 0;

    objs->push_back(border);
    objs->push_back(border2);

    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    long ms = spec.tv_nsec / 1.0e6 + (spec.tv_sec * 1.0e3);

    this->objs = objs;
    this->_time = ms;
    this->_border = border;
    this->_border2 = border2;
    this->_name = "Nibbler";

    _stopped = false;
    _dir = 'R';
}

bool Snake::isWall(Vec2i pos) {
    int xStart = _border->pos.x;
    int xStop = _border->pos.x + _border->size.x - 1;
    int yStart = _border->pos.y;
    int yStop = _border->pos.y + _border->size.y - 1;
    if (pos.y == yStart || pos.y == yStop) {
        return true;
    }
    if (pos.x == xStart || pos.x == xStop) {
        return true;
    }
    return false;
}

bool Snake::isSnakeBody(Vec2i is) {
    std::vector<Vec2i> poss(_snakePosition.begin() + 1, _snakePosition.end());
    for (Vec2i pos : poss) {
        if (pos.x == is.x && pos.y == is.y)
            return true;
    }
    return false;
}

void Snake::moveSnake()
{
    Vec2i oldPos;
    Vec2i tmp;

    for (int i = 0; i < int(_snakePosition.size()); i++) {
        Vec2i posHead = Vec2i{0, 0};
        if (i == 0) {
            oldPos = _snakePosition[0];
            if (_dir == 'R')
                _snakePosition[0].x += 1;
            if (_dir == 'L')
                _snakePosition[0].x -= 1;
            if (_dir == 'U')
                _snakePosition[0].y -= 1;
            if (_dir == 'D')
                _snakePosition[0].y += 1;
            if (isWall(_snakePosition[0]) || isSnakeBody(_snakePosition[0])) {
                //std::cout << "Snake Game Over !" << std::endl;
                _win->text = "LOST";
                _stopped = true;
                flush = 1;
            }
            continue;
        }
        tmp = _snakePosition[i];
        _snakePosition[i] = oldPos;
        oldPos = tmp;
    }
}

std::vector<IObject *> *Snake::run(Vec2i vec)
{
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    long now = (spec.tv_nsec / 1.0e6) + (spec.tv_sec * 1.0e3);

    if (_border->size.x == -1 && _border->size.y == -1) {
        _windowSize = vec;
        _border->size = Vec2i{vec.x - 2, vec.y - 2};
        _border2->size = Vec2i{vec.x - 4, vec.y - 4};
        _snakePosition.push_back(Vec2i{_border->size.x / 2, _border->size.y / 2});
        _snakePosition.push_back(Vec2i{_border->size.x / 2 - 1, _border->size.y / 2});
        _snakePosition.push_back(Vec2i{_border->size.x / 2 - 2, _border->size.y / 2});
        _snakePosition.push_back(Vec2i{_border->size.x / 2 - 3, _border->size.y / 2});

        
        this->_score->pos = Vec2i {0, vec.y - 1};
        this->_win->pos = Vec2i {10, vec.y - 1};

    }

    if (now - _time < 75 || _stopped)
        return this->objs;
    _time = now;

    this->clear();

    this->moveSnake();

    std::vector<Vec2i>::iterator *toDelete = nullptr;
    for (std::vector<Vec2i>::iterator it = _foodPosition.begin(); it != _foodPosition.end(); ++it) {
        Vec2i pos = *it;
        if (pos.x == _snakePosition.front().x && pos.y == _snakePosition.front().y) {
            _snakeSize += 1;
            Vec2i queue = _snakePosition.back();
            if (_dir == 'R')
                queue.x -= 1;
            if (_dir == 'L')
                queue.x += 1;
            if (_dir == 'U')
                queue.y += 1;
            if (_dir == 'D')
                queue.y -= 1;
            _snakePosition.push_back(queue);
            toDelete = &it;
        }
    }

    if (toDelete) {
        _foodPosition.erase(*toDelete);
        score += 1;
    }

    this->objs->push_back(this->_border);
    this->objs->push_back(this->_border2);

    _score->text = std::to_string(score);
    this->objs->push_back(this->_score);
    this->objs->push_back(this->_win);

    for (Vec2i pos : _snakePosition) {
        Square *body = new Square;
        body->pos = pos;
        body->color = colors[4];
        body->size = Vec2i{1, 1};
        this->objs->push_back(body);
    }

    if (_foodPosition.size() < 1) {
        Vec2i pos = {rand()%((_windowSize.x / 2) - 4) + 1, rand()%((_windowSize.y / 2) - 4) + 1};
        _foodPosition.push_back(pos);
    }

    for (std::vector<Vec2i>::iterator it = _foodPosition.begin(); it != _foodPosition.end(); ++it) {
        Vec2i pos = *it;
        Square *body = new Square;
        body->pos = pos;
        body->color = colors[2];
        body->size = Vec2i{1, 1};
        this->objs->push_back(body);
    }

    return this->objs;
}

void Snake::clear()
{
//    for (IObject *obj : *this->objs)
//        delete obj;
    this->objs->clear();
}

void Snake::computeEvent(Event event)
{
    if (UP(event.type) && _dir != 'D') {
        _dir = 'U';
    } else if (DOWN(event.type) && _dir != 'U') {
        _dir = 'D';
    } else if (RIGHT(event.type) && _dir != 'L') {
        _dir = 'R';
    } else if (LEFT(event.type) && _dir != 'R') {
        _dir = 'L';
    }
}

int Snake::getScore()
{
    if (flush) {
        flush = 0;
        return score;
    }
    return -1;
}
