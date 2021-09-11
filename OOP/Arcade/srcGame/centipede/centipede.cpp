
#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <iostream>

#include "arcade.hpp"
#include "centipede.hpp"
#include "game.hpp"

extern "C" Centipede* ctor()
{
    return new Centipede;
}

extern "C" std::string getLibName()
{
    return (std::string("Centipede"));
}

extern "C" int getLibType()
{
    return (1);
}

Centipede::Centipede()
{
    std::vector<IObject *> *objs = new std::vector<IObject *>;

    _player = new Square;
    _player->pos = Vec2i {-1, -1};
    _player->color = colors[11];
    _player->size = Vec2i {1, 1};

    _bullet = new Square;
    _bullet->pos = Vec2i {0, 0};
    _bullet->color = colors[0];
    _bullet->size = Vec2i {1, 1};

    _score = new Text("0");
    _score->pos = Vec2i {0, 0};
    _score->color = colors[15];

    _win = new Text("");
    _win->pos = Vec2i {0, 0};
    _win->color = colors[1];

    _bg = new Square;
    _bg->pos = Vec2i{0, 0};
    _bg->color = colors[0];
    _bg->size = Vec2i{0, 0};

    centipedes.push_back(new Mob);
    
    srand(time(0));

    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    long ms = spec.tv_nsec / 1.0e6 + (spec.tv_sec * 1.0e3);

    this->objs = objs;
    this->_time = ms;
    this->_btime = ms;
    this->_name = "Centipede";
    this->score = 0;
    this->flushScore = 0;
    this->_dir = Vec2i {0, 0};
    this->_state = 0;
}

Square *dup(Square *sq)
{
    Square *d = new Square;

    d->pos = sq->pos;
    d->color = sq->color;
    d->size = sq->size;
    return d;
}

Text *dupTxt(Text *sq)
{
    Text *d = new Text;

    d->pos = sq->pos;
    d->color = sq->color;
    d->text = sq->text;
    return d;
}

Centipede::Mob::Mob(int size, int dir, Vec2i at)
{
    for (int i = 0; i < size; i++) {
        Square *part = new Square;
        part->color = colors[13];
        part->size = Vec2i {1, 2};
        part->pos = Vec2i {2 * i + at.x, at.y};

        this->parts.push_back(part);
        this->dirs.push_back(dir);
    }

    this->speed = ((size + 3) * 3) / 2l;
    this->counter = speed;
}

Centipede::Mob::~Mob()
{
    for (std::size_t i = 0; i < parts.size(); i++)
        delete parts[i];
}

void Centipede::init(Vec2i vec)
{
    this->map.resize(vec.y, std::vector<int>(vec.x, 0));

    for (int y = 4; y < (vec.y * 70) / 100; y += 3) {
        for (int x = 0; x < vec.x; x++) {
            if (rand() % 150 < 5) {
                this->map[y][x] = 5;
                this->map[y + 1][x] = 5;
            }
        }
    }

    this->_score->pos = Vec2i {0, vec.y - 1};
    this->_win->pos = Vec2i {10, vec.y - 1};
    this->_player->pos = Vec2i {vec.x / 2, vec.y - 2};
    this->_bg->size = Vec2i {vec.x, vec.y - 1};
    this->_state = 0;
    this->centipedes.clear();
    this->centipedes.push_back(new Mob);
}

std::vector<IObject *> *Centipede::run(Vec2i vec)
{
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    long now = (spec.tv_nsec / 1.0e6) + (spec.tv_sec * 1.0e3);

    if (_player->pos.x == -1 && _player->pos.y == -1)
        init(vec);

    if (_state == 4)
        init(vec);
    
    if (_state > 0) {
        flushScore = 1;
        if (_state == 1)
            _win->text = "LOST";
        if (_state == 2)
            _win->text = "WIN";
        _state += 2;

        this->objs->push_back(dupTxt(_win));
    }

    static int counter = 0;

    if (now - _time < 10 || _state > 0)
        return this->objs;
    _time = now;

    counter++;
    counter %= 6;

    if (now - _btime > 15000) {
        centipedes.push_back(new Mob);
        _btime = now;
    }


    processBullet();
        
    this->clear();
    stepCentipede();

    if (counter == 0)
        stepPlayer();

    this->objs->push_back(dup(_bg));
    pushMap();

    for (Centipede::Mob *centi : centipedes)
        for (Square *sq : centi->parts)
            this->objs->push_back(dup(sq));

    _score->text = std::to_string(score);

    this->objs->push_back(dup(_bullet));
    this->objs->push_back(dup(_player));
    this->objs->push_back(dupTxt(_score));
    this->objs->push_back(dupTxt(_win));

    return this->objs;
}

void Centipede::pushMap()
{
    for (int y = 0; y < (int) this->map.size(); y++) {
        for (int x = 0; x < (int) this->map[y].size(); x++) {
            if (this->map[y][x] == 0)
                continue;

            Square *pt = new Square;

            pt->pos = Vec2i {x, y};
            pt->size = Vec2i {1, 1};

            switch (this->map[y][x]) {
            case 5:
                pt->color = colors[9];
                break;
            case 4:
                pt->color = colors[1];
                break;
            case 3:
                pt->color = colors[10];
                break;
            case 2:
                pt->color = colors[6];
                break;
            case 1:
                pt->color = colors[5];
                break;
            }
            
            this->objs->push_back(pt);
        }
    }
}

void Centipede::clear()
{
    for (IObject *obj : (*this->objs))
        delete obj;
    this->objs->clear();
}

void Centipede::computeEvent(Event event)
{
    if ((UP(event.type) && _dir.y == 1) ||
        (DOWN(event.type) && _dir.y == -1) ||
        (RIGHT(event.type) && _dir.x == -1) ||
        (LEFT(event.type) && _dir.x == 1)) {

        _dir = Vec2i {0, 0};
        return;
    }

    if (UP(event.type))
        _dir = Vec2i {0, -1};
    else if (DOWN(event.type))
        _dir = Vec2i {0, 1};
    else if (RIGHT(event.type))
        _dir = Vec2i {1, 0};
    else if (LEFT(event.type))
        _dir = Vec2i {-1, 0};

    if (event.type == 32)
        fire = 1;
}

void Centipede::stepPlayer()
{
    Vec2i pos = _player->pos;
    Vec2i newPos = Vec2i {pos.x + _dir.x, pos.y + _dir.y};

    if (newPos.x + 1 < int(map.size()) &&
        newPos.y + 1 < int(map[0].size()) &&
        newPos.y >= int(map[0].size() * 80) / 100 &&
        newPos.x >= 0 && newPos.y >= 0)
        _player->pos = newPos;

    for (int i = 0; i < int(centipedes.size()); i++) {        
        Centipede::Mob *centi = centipedes[i];
        int partsNb = centi->parts.size();

        for (int j = 0; j < partsNb; j ++) {
            Square *sq = centi->parts[j];
            
            if (sq->pos.x == _player->pos.x &&
                (sq->pos.y == _player->pos.y ||
                 sq->pos.y + 1 == _player->pos.y))
                _state = 1;
            
        }
    }

    if (fire) {
        fire = 0;

        _bullet->color = colors[1];
        _bullet->pos = Vec2i {newPos.x, newPos.y - 1};
    }
}

void Centipede::deletePart(Centipede::Mob *centi, Square *sq)
{
    auto del = std::remove(centi->parts.begin(), centi->parts.end(), sq);
    centi->parts.erase(del, centi->parts.end());
    
    if (centi->parts.size() == 0) {
        auto del2 = std::remove(centipedes.begin(), centipedes.end(), centi);
        centipedes.erase(del2, centipedes.end());
        
        score += 50;

        cCounter++;

        if (cCounter > 20)
            _state = 2;
    }
}

void Centipede::processBullet()
{
    if (_bullet->color.r != colors[1].r ||
        _bullet->color.g != colors[1].g ||
        _bullet->color.b != colors[1].b)
        return;

    if (_bullet->pos.y > 0)
        _bullet->pos = Vec2i {_bullet->pos.x, _bullet->pos.y - 1};
    else
        _bullet->color = colors[0];

    Vec2i pos = _bullet->pos;

    for (int i = 0; i < int(centipedes.size()); i++) {        
        Centipede::Mob *centi = centipedes[i];
        int partsNb = centi->parts.size();

        for (int j = 0; j < partsNb; j ++) {
            Square *sq = centi->parts[j];
            Vec2i loc = sq->pos;
            
            if ((loc.y == pos.y ||
                 loc.y + 1 == pos.y) &&
                loc.x == pos.x) {

                deletePart(centi, sq);
                
                i = centipedes.size();
                j = partsNb;

                score += 20;

                _bullet->color = colors[0];
                _bullet->pos = Vec2i {_bullet->pos.x, 0};

                this->map[loc.y][loc.x] = 5;
                this->map[loc.y + 1][loc.x] = 5;
            }
        }
    }

    pos = _bullet->pos;

    if (this->map[pos.y][pos.x] != 0) {
        _bullet->color = colors[0];
        _bullet->pos = Vec2i {_bullet->pos.x, 0};

        this->map[pos.y][pos.x] -= 1;
        this->map[pos.y - 1][pos.x] -= 1;

        this->score += 5;
    }
}

Vec2i Centipede::moveCenti(Vec2i pos, int &dir)
{
    Vec2i withDir = Vec2i {pos.x + dir, pos.y};;

    if (withDir.x >= int(this->map[0].size()) ||
        withDir.x < 0 ||
        this->map[withDir.y][withDir.x] != 0) {

        dir *= -1;
        withDir = Vec2i {pos.x, pos.y + 3};
        
        return withDir;
    }
    
    return withDir;
}

void Centipede::stepCentipede()
{
    for (Centipede::Mob *centi : centipedes) {
        centi->counter -= 1;

        if (centi->counter > 0)
            continue;

        centi->counter = centi->speed;

        for (int i = 0; i < int(centi->parts.size()); i++) {
            Vec2i newPos = moveCenti(centi->parts[i]->pos, centi->dirs[i]);

            if (newPos.y + 2 > int(this->map.size())) {
                deletePart(centi, centi->parts[i]);
            } else {
                centi->parts[i]->pos = newPos;
            }
        }
    }
}

int Centipede::getScore()
{
    if (flushScore) {
        flushScore = 0;
        return score;
    }
    return -1;
}
