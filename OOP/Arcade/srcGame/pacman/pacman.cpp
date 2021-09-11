#include <stdlib.h>
#include <time.h>

#include <iostream>

#include "arcade.hpp"
#include "pacman.hpp"
#include "game.hpp"

extern "C" Pacman* ctor()
{
    return new Pacman;
}

extern "C" std::string getLibName()
{
    return (std::string("Pacman"));
}

extern "C" int getLibType()
{
    return (1);
}

Pacman::Pacman()
{
    std::vector<IObject *> *objs = new std::vector<IObject *>;
    Square *pacman = new Square;
    Square *red = new Square;
    Square *pink = new Square;
    Square *cyan = new Square;

    _name = "Pacman";
    srand(time(0));

    //Pacman
    pacman->pos = Vec2i{-3, -3};
    pacman->color = colors[11];
    pacman->size = Vec2i{3, 3};

    //Ghost
    red->pos = Vec2i{21, 15};
    red->color = colors[1];
    red->size = Vec2i{3, 3};

    pink->pos = Vec2i{23, 21};
    pink->color = colors[13];
    pink->size = Vec2i{3, 3};

    cyan->pos = Vec2i{26, 21};
    cyan->color = colors[14];
    cyan->size = Vec2i{3, 3};

    // _win = new Text("");
    // _win->pos = Vec2i {0, 0};
    // _win->color = colors[1];
// 
    // _scoreT = new Text("0");
    // _scoreT->pos = Vec2i {0, 0};
    // _scoreT->color = colors[15];

    this->_fantoms.push_back(red);
    this->_fantoms.push_back(pink);
    this->_fantoms.push_back(cyan);

    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    long ms = spec.tv_nsec / 1.0e6 + (spec.tv_sec * 1.0e3);

    this->objs = objs;
    this->_time = ms;
    this->_powerTime = 0;
    this->_state = 0;
    this->_pacman = pacman;
    this->_score = 0;
    this->_spawnTime = ms;
    this->_dir = Vec2i {0, 0};
}

Square *dup(Square *sq)
{
    Square *d = new Square;

    d->pos = sq->pos;
    d->color = sq->color;
    d->size = sq->size;
    return d;
}

std::vector<IObject *> *Pacman::run(Vec2i vec)
{
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    long now = (spec.tv_nsec / 1.0e6) + (spec.tv_sec * 1.0e3);

    if (_pacman->pos.x == -3 && _pacman->pos.y == -3)
        init(vec);
    
    if (now - _time < 75 || this->_state > 0)
        return this->objs;
    _time = now;
    if (_powerTime != 0 && (now - _powerTime) > 10000) {
        _powerTime = 0;
        _pacman->color = colors[11];
    }
    this->clear();

    this->objs->push_back(dup(_bg));
    this->stepPacman();

    if (isWon())
        this->_state = 2;

    this->pushMap();
    for (auto ghost : this->_fantoms) {
        stepGhost(ghost);
        this->objs->push_back(ghost);     
    }
    this->objs->push_back(_pacman);
    return this->objs;
}

bool Pacman::isWon()
{
    for (int i = 0; i < 15; i++) {
        for ( int j = 0; j < 15; j++) {
            if (dataMap[i][j] == '0') return false;
        }
    }
    return true;
}

void Pacman::clear()
{
    this->objs->clear();
}

void Pacman::init(Vec2i vec)
{
    this->createMap(vec);

    // this->_scoreT->pos = Vec2i {0, 0};
    // this->_win->pos = Vec2i {10, 0};

    Square *bg = new Square;

    bg->pos = Vec2i{0, 0};
    bg->color = colors[0];
    bg->size = Vec2i{vec.x, vec.y};
    _bg=bg;

    this->_pacman->pos = Vec2i {23, 27};
}

void Pacman::createMap(Vec2i vec)
{
    this->map.resize(vec.y, std::vector<int>(vec.x, 0));
    this->dataMap.resize(15, std::vector<char>(15, '0'));
    
    // BORDER Creation
    for (int i = 1; i < vec.x - 2; i++) {
        this->map[2][i] = WALL;
        this->map[vec.y - 2][i] = WALL;
    }
    for (int i = 3; i < vec.y - 2; i++) {
        this->map[i][1] = WALL;
        this->map[i][vec.x - 3] = WALL;
    }

    char array[16][16] = {
        "000000000000000",
        "011011010110110",
        "P0000101010000P",
        "011101010101110",
        "000000000000000",
        "111101121101111",
        "TEEE0122210EEET",
        "111101111101111",
        "000000000000000",
        "010101010101010",
        "P1010100010101P",
        "010001010100010",
        "010100010001010",
        "000101111101000",
        "110000000000011",
    };

    // Blocks Creation
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            dataMap[i][j] = array[i][j];
            switch (array[i][j]) {
                case '2':
                    this->createBlock(Seg((j * 3) + 2, (i * 3) + 3, 3, 3), SPAWN);
                    break;
                case '1':
                    this->createBlock(Seg((j * 3) + 2, (i * 3) + 3, 3, 3), WALL);
                    break;
                case '0':
                    this->createPow(Vec2i((j * 3) + 2, (i * 3) + 3), PACGUN);
                    break;
                case 'P':
                    this->createPow(Vec2i((j * 3) + 2, (i * 3) + 3), PACPOW);
                    break;
            }
        }
    }
}

void Pacman::createPow(Vec2i vec, Pacman::States type)
{
    if (type == PACGUN) {
        this->map[vec.y + 1][vec.x + 1] = PACGUN;
    } else if (type == PACPOW) {
        this->map[vec.y + 1][vec.x + 1] = PACPOW;
    }
}

void Pacman::createBlock(Seg seg, Pacman::States type)
{
    for (int j = seg.y; j < seg.y + seg.dy; j++)
        for (int i = seg.x; i < seg.x + seg.dx; i++)
            this->map[j][i] = type;
}

void Pacman::pushMap()
{
    for (int y = 0; y < (int) this->map.size(); y++) {
        for (int x = 0; x < (int) this->map[y].size(); x++) {
            if (this->map[y][x] == EMPTY)
                continue;

            Square *pt = new Square;

            pt->pos = Vec2i {x, y};
            pt->size = Vec2i {1, 1};

            switch (this->map[y][x]) {
            case WALL:
                pt->color = colors[4];
                break;
            case SPAWN:
                pt->color = colors[8];
                break;
            case PACPOW:
                pt->color = colors[2];
                break;
            case PACGUN:
                pt->color = colors[7];
                break;
            default :
                pt->color = colors[0];
            }
            
            this->objs->push_back(pt);
        }
    }
}

void Pacman::stepPacman()
{
    Square newPos;

    newPos.pos = Vec2i(_pacman->pos.x + _dir.x, _pacman->pos.y + _dir.y);
    newPos.size = _pacman->size;

    if (isWalkable(newPos))
        _pacman->pos = newPos.pos;
    if (isPac(*_pacman))
        deletePac(getCoords(newPos));
    if (isPower(*_pacman)) {
        deletePac(getCoords(newPos));
        startPower();
    }
    if (isTp(*_pacman))
        teleport();

}

void Pacman::startPower()
{
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    long now = (spec.tv_nsec / 1.0e6) + (spec.tv_sec * 1.0e3);

    this->_powerTime = now;
    _pacman->color = colors[3];
}

bool Pacman::needRepawn(Square *ghost)
{
    Vec2i pos = Vec2i(20, 21);

    for (int i = 0; i < 3; i++) {
        if (ghost->pos.x == (pos.x + (i * 3)) && ghost->pos.y == pos.y)
            return true;
    }
    return false;
}

void Pacman::stepGhost(Square *ghost)
{
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    long now = (spec.tv_nsec / 1.0e6) + (spec.tv_sec * 1.0e3);

    Vec2i dir = getDirToGoal(ghost->pos, _pacman->pos);
    Square newPos;
    
    if (needRepawn(ghost)) {
        if (now - _spawnTime > 3000) {
            ghost->pos = Vec2i(25, 15);
            _spawnTime = now;
        }
        return;
    }
    newPos.pos = Vec2i(ghost->pos.x + dir.x, ghost->pos.y + dir.y);
    newPos.size = ghost->size;

    if (!isWalkable(newPos)) {
        newPos.pos = randomWay(ghost->pos, newPos.pos);
    }
    ghost->pos = newPos.pos;

    if (ghost->pos.x == _pacman->pos.x && ghost->pos.y == _pacman->pos.y) {
        if (this->_powerTime != 0) {
            tpGhost(ghost);
        } else {
            this->_state = 1;
        }
    }
}

void Pacman::tpGhost(Square *ghost)
{
    if (ghost == _fantoms[0])
        ghost->pos = Vec2i(20, 21);
    if (ghost == _fantoms[1]) 
        ghost->pos = Vec2i(23, 21);
    if (ghost == _fantoms[2])
        ghost->pos = Vec2i(26, 21);
}

Vec2i Pacman::randomWay(Vec2i pos, Vec2i dir)
{
    Square newPos;

    newPos.size = Vec2i{3, 3};

    switch (rand() % 2) {
        case 0:
            newPos.pos = Vec2i(pos.x, dir.y);
            if (isWalkable(newPos))
                return newPos.pos;
        case 1:
            newPos.pos = Vec2i(dir.x, pos.y);
            if (isWalkable(newPos))
                return newPos.pos;
    }
    return (Vec2i(pos.x, pos.y));
}

Vec2i Pacman::findWay(Vec2i start, Vec2i dest)
{
    // TO DO
    return Vec2i(start.x, dest.y);
}

Vec2i Pacman::getDirToGoal(Vec2i current, Vec2i goal)
{
    Vec2i dir = Vec2i(0, 0);
    
    if (current.x > goal.x)
       dir.x = -1;
    else if (current.x < goal.x)
        dir.x = 1;
    else
        dir.x = 0;
    if (current.y > goal.y)
        dir.y = -1;
    else if (current.y < goal.y)
        dir.y = 1;
    else
        dir.y = 0;
    
    return dir;
}

bool Pacman::isWalkable(Square square)
{
    Vec2i pos(0,0);

    for (int i = 0; i < square.size.y; i++) {
        for (int j = 0; j < square.size.x; j++) {
            pos.x = square.pos.x + j;
            pos.y = square.pos.y + i;

            if (pos.x < 0 || pos.y < 0 ||
                pos.x >= (int) this->map[0].size() ||
                pos.y >= (int) this->map.size())
                return false;
            if (this->map[pos.y][pos.x] == WALL ||
                this->map[pos.y][pos.x] == SPAWN)
                return false;
        }
    }
    return true;
}

bool Pacman::isPac(Square sq)
{
    Vec2i pos = getCoords(sq);

    if (dataMap[pos.y][pos.x] == '0')
        return true;
    return false;
}

bool Pacman::isPower(Square sq)
{
    Vec2i pos = getCoords(sq);

    if (dataMap[pos.y][pos.x] == 'P')
        return true;
    return false;
}

bool Pacman::isTp(Square sq)
{
    Vec2i pos = getCoords(sq);

    if (dataMap[pos.y][pos.x] == 'T')
        return true;
    return false;
}

void Pacman::deletePac(Vec2i vec)
{
    dataMap[vec.y][vec.x] = ' ';
    _score += 100;
    refreshMap();
}

Vec2i Pacman::getCoords(Square sq)
{
    Vec2i pos;

    pos.x = (sq.pos.x - 2) / 3;
    pos.y = (sq.pos.y - 3) / 3;
    return pos;
}

void Pacman::refreshMap()
{
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            switch (dataMap[i][j]) {
                case '2':
                    this->createBlock(Seg((j * 3) + 2, (i * 3) + 3, 3, 3), SPAWN);
                    break;
                case '1':
                    this->createBlock(Seg((j * 3) + 2, (i * 3) + 3, 3, 3), WALL);
                    break;
                case '0':
                    this->createPow(Vec2i((j * 3) + 2, (i * 3) + 3), PACGUN);
                    break;
                case 'P':
                    this->createPow(Vec2i((j * 3) + 2, (i * 3) + 3), PACPOW);
                    break;
                default:
                    map[(i * 3) + 4][(j * 3) + 3] = EMPTY;
            }
        }
    }
}

void Pacman::computeEvent(Event event)
{
    if (UP(event.type))
        _dir = Vec2i {0, -1};
    else if (DOWN(event.type))
        _dir = Vec2i {0, 1};
    else if (RIGHT(event.type))
        _dir = Vec2i {1, 0};
    else if (LEFT(event.type))
        _dir = Vec2i {-1, 0};
}

void Pacman::teleport()
{
    if (_pacman->pos.x <= 3) {
        _pacman->pos.x = 41;
    } else {
        _pacman->pos.x = 4;
    }
}