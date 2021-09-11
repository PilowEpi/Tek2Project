
#include <stdlib.h>
#include <time.h>

#include "arcade.hpp"
#include "qix.hpp"
#include "game.hpp"

extern "C" Qix* ctor()
{
    return new Qix;
}

extern "C" std::string getLibName()
{
    return (std::string("Qix"));
}

extern "C" int getLibType()
{
    return (1);
}

Qix::Qix()
{
    std::vector<IObject *> *objs = new std::vector<IObject *>;
    
    Square *player = new Square;

    player->pos = Vec2i{-1, -1};
    player->color = colors[12];
    player->size = Vec2i{1, 1};

    Square *qix = new Square;

    qix->pos = Vec2i{-1, -1};
    qix->color = colors[1];
    qix->size = Vec2i{2, 2};

    _bg = new Square;
    _bg->pos = Vec2i{0, 0};
    _bg->color = colors[0];
    _bg->size = Vec2i{0, 0};

    _score = new Text("0");
    _score->pos = Vec2i {0, 0};
    _score->color = colors[15];

    _win = new Text("");
    _win->pos = Vec2i {0, 0};
    _win->color = colors[1];

    srand(time(0));

    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    long ms = spec.tv_nsec / 1.0e6 + (spec.tv_sec * 1.0e3);

    this->objs = objs;
    this->_time = ms;
    this->_name = "Qix";
    this->_start = spec.tv_sec;
    this->_igStart = 0;
    this->_state = 0;
    this->_player = player;
    this->_qix = qix;
    this->_dir = Vec2i {0, 0};
    this->score = 0;
}

void Qix::init(Vec2i vec)
{
    this->map.resize(vec.y, std::vector<int>(vec.x, 0));
    for (int i = 0; i < vec.x; i++) {
        this->map[0][i] = BORDER;
        this->map[vec.y - 1][i] = BORDER;
    }
    for (int i = 0; i < vec.y; i++) {
        this->map[i][0] = BORDER;
        this->map[i][vec.x - 1] = BORDER;
    }

    for (int i = 0; i < 10; i++) {
        Square *spark = new Square;
        Vec2i dir;

        switch (rand() % 3) {
        case 0:
            spark->pos = Vec2i {0, rand() % (vec.y - 1)};
            dir = Vec2i {0, rand() % 2 == 0 ? -1 : 1};
            break;
        case 1:
            spark->pos = Vec2i {vec.x - 1, rand() % (vec.y - 1)};
            dir = Vec2i {0, rand() % 2 == 0 ? -1 : 1};
            break;
        case 2:
            spark->pos = Vec2i {rand() % (vec.x - 1), 0};
            dir = Vec2i {rand() % 2 == 0 ? -1 : 1, 0};
            break;
        }
        spark->color = colors[9];
        spark->size = Vec2i {1, 1};

        this->_sparks.push_back(spark);
        this->_sDirs.push_back(dir);
    }

    this->_score->pos = Vec2i {0, vec.y - 1};
    this->_win->pos = Vec2i {10, vec.y - 1};

    this->_bg->size = Vec2i {vec.x, vec.y - 1};

    this->_player->pos = Vec2i {vec.x / 2, vec.y - 1};
    this->_qix->pos = Vec2i {vec.x / 2, vec.y / 2};
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

int Qix::isWon()
{
    std::map<int, int> sizes;

    for (const std::vector<int> &x : map) {
        for (const int &y : x) {
            if (sizes.count(y) == 0)
                sizes[y] = 0;
            sizes[y] += 1;
        }
    }

    int total = 0;
    for (const auto &pair : sizes)
        total += pair.second;
    return ((100 * (sizes[FILLED] + sizes[BORDER])) / total);
}

std::vector<IObject *> *Qix::run(Vec2i vec)
{
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    long now = (spec.tv_nsec / 1.0e6) + (spec.tv_sec * 1.0e3);

    if (_player->pos.x == -1 && _player->pos.y == -1)
        init(vec);

    score = 1000 - (spec.tv_sec - _start) * 10;
    if (score < 100)
        score = 100;

    if (_state == 1)
        score = 50;

    score += isWon() * 5;

    if (_state == 1 || _state == 2) {
        flushScore = 1;
        if (_state == 1)
            _win->text = "LOST";
        if (_state == 2)
            _win->text = "WIN";
        _state = 3;

        this->objs->push_back(dupTxt(_win));
    }

    if (now - _time < 75 || _state > 0)
        return this->objs;
    _time = now;

    if (isWon() > 75)
        _state = 2;

    this->clear();

    stepPlayer();
    testFill();

    stepQix();
    stepSparks();

    this->objs->push_back(dup(_bg));
    pushMap();

    this->objs->push_back(dup(_player));

    for (Square *spark : _sparks)
        this->objs->push_back(dup(spark));

    this->objs->push_back(dup(_qix));

    _score->text = std::to_string(score);
    this->objs->push_back(dupTxt(_score));
    this->objs->push_back(dupTxt(_win));

    return this->objs;
}

void Qix::pushMap()
{
    for (int y = 0; y < (int) this->map.size(); y++) {
        for (int x = 0; x < (int) this->map[y].size(); x++) {
            if (this->map[y][x] == EMPTY)
                continue;

            Square *pt = new Square;

            pt->pos = Vec2i {x, y};
            pt->size = Vec2i {1, 1};

            switch (this->map[y][x]) {
            case BUILDING:
                pt->color = colors[15];
                break;
            case BORDER:
                pt->color = colors[7];
                break;
            case FILLED:
                pt->color = colors[10];
                break;
            case IGNITED:
                pt->color = colors[6];
                break;
            default :
                pt->color = colors[2];
            }
            
            this->objs->push_back(pt);
        }
    }
}

void Qix::clear()
{
    this->objs->clear();
}

void Qix::computeEvent(Event event)
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

bool Qix::isWalkable(Vec2i pos)
{
    if (pos.x < 0 || pos.y < 0 ||
        pos.x >= (int) this->map[0].size() ||
        pos.y >= (int) this->map.size())
        return false;
    
    if (this->map[pos.y][pos.x] > BORDER ||
        this->map[pos.y][pos.x] == BUILDING ||
        this->map[pos.y][pos.x] == IGNITED)
        return false;

    return true;
}

bool Qix::isSpark(Vec2i pos)
{
    if (pos.x < 0 || pos.y < 0 ||
        pos.x >= (int) this->map[0].size() ||
        pos.y >= (int) this->map.size())
        return false;
    
    if (this->map[pos.y][pos.x] != BORDER &&
        this->map[pos.y][pos.x] != BUILDING &&
        this->map[pos.y][pos.x] != IGNITED)
        return false;

    return true;
}

bool Qix::isQix(Vec2i pos, Vec2i size)
{
    for (int y = pos.y; y < size.y + pos.y; y++) {
        for (int x = pos.x; x < size.x + pos.x; x++) {

            if (x < 0 || y < 0 ||
                x >= (int) this->map[0].size() ||
                y >= (int) this->map.size())
                return false;
            
            if (this->map[y][x] > BUILDING ||
                this->map[y][x] == BORDER)
                return false;
        }
    }

    return true;
}

void Qix::stepPlayer()
{
    Vec2i pos = _player->pos;
    Vec2i newPos = Vec2i {pos.x + _dir.x, pos.y + _dir.y};

    if (isWalkable(newPos))
        _player->pos = newPos;

    if ((_dir.x != 0 || _dir.y != 0) &&
        this->map[pos.y][pos.x] == EMPTY)
        this->map[pos.y][pos.x] = BUILDING;

    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    long now = (spec.tv_nsec / 1.0e6) + (spec.tv_sec * 1.0e3) + 1;

    if (_dir.x == 0 && _dir.y == 0 &&
        now - _igStart > 700 && _igStart != 0) {

        if (_ignite.size() == 0) {
            this->_state = 1;
        } else {
            Vec2i ignited = _ignite.front();

            if (ignited.y == pos.y && ignited.x == pos.x)
                this->_state = 1;

            this->map[ignited.y][ignited.x] = IGNITED;
            _ignite.pop_front();
        }
    }

    if (_ignite.size() == 0)
        _igStart = now;

    _ignite.push_back(pos);
    _dir = Vec2i {0, 0};
}

void Qix::testFill()
{
    std::vector<std::vector<int>> cpy;

    int sizeX = this->map[0].size();
    int sizeY = this->map.size();

    cpy.resize(sizeY);
    for (int i = 0; i < sizeY; i++)
        cpy[i] = std::vector<int>(this->map[i]);

    this->_cpy = cpy;

    int cur = 6;
    for (int x = 0; x < sizeX; x++) {
        for (int y = 0; y < sizeY; y++) {
            if (recFill(x, y, cur))
                cur++;
        }
    }

    Vec2i pos = this->_player->pos;

    if (this->map[pos.y][pos.x] == BORDER)
        doFill();
}

void Qix::doFill()
{
    int size6 = 0;
    int size7 = 0;

    int sizeX = this->map[0].size();
    int sizeY = this->map.size();

    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            if (this->_cpy[y][x] == 6)
                size6++;
            if (this->_cpy[y][x] == 7)
                size7++;
        }
    }

    int minVal = 0;

    if (size6 < size7)
        minVal = 6;
    else
        minVal = 7;

    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            if (this->_cpy[y][x] == minVal)
                this->map[y][x] = FILLED;
            if (this->_cpy[y][x] == BUILDING ||
                this->_cpy[y][x] == IGNITED) // harden border
                this->map[y][x] = BORDER;
        }
    }

    _ignite.clear();
    _igStart = 0;
}

bool Qix::recFill(int x, int y, int val)
{
    if (this->_cpy[y][x] != 0)
        return false;
    this->_cpy[y][x] = val;

    recFill(x + 1, y, val);
    recFill(x - 1, y, val);
    recFill(x, y + 1, val);
    recFill(x, y - 1, val);
    return true;
}

void Qix::stepQix()
{
    Vec2i size = this->_qix->size;
    Vec2i qix = this->_qix->pos;
    Vec2i pos = this->_player->pos;

    if (rand() % 3 != 0) {
        Vec2i newQix = Vec2i {-1, -1};

        while (!isQix(newQix, size)) {
            newQix = Vec2i {
                qix.x + rand() % 5 - 2,
                qix.y + rand() % 5 - 2
            };
        }

        this->_qix->pos = newQix;
    }

    qix = _qix->pos;
    for (int y = qix.y; y < qix.y + size.y; y++) {
        for (int x = qix.x; x < qix.x + size.x; x++) {

            if ((x == pos.x && y == pos.y) ||
                this->map[y][x] == BUILDING ||
                this->map[y][x] == IGNITED)
                
                this->_state = 1;
            
        }
    }
}

void Qix::stepSparks()
{
    for (int i = 0; i < (int) _sparks.size(); i++) {
        Square *spark = _sparks[i];
        Vec2i dir = _sDirs[i];

        Vec2i pos = spark->pos;

        Vec2i player = _player->pos;

        std::vector<Vec2i> newDirs;

        addSparkDir(newDirs, pos, dir, -1, 0);
        addSparkDir(newDirs, pos, dir, 1, 0);
        addSparkDir(newDirs, pos, dir, 0, -1);
        addSparkDir(newDirs, pos, dir, 0, 1);

        if (newDirs.size() != 0)
            dir = newDirs[rand() % newDirs.size()];
        else
            dir = Vec2i {0, 0};

        if (rand() % 3 != 0) {
            Vec2i newPos = Vec2i {pos.x + dir.x, pos.y + dir.y};
            spark->pos = newPos;
            _sDirs[i] = dir;
        }
        
        if (spark->pos.x == player.x &&
            spark->pos.y == player.y)
            _state = 1;
    }
}

void Qix::addSparkDir(std::vector<Vec2i> &newDirs, Vec2i &pos,
                      Vec2i &dir, int dx, int dy)
{
    if ((-dx == dir.x && dx != 0) ||
        (-dy == dir.y && dy != 0))
        return;
    
    Vec2i newPos = Vec2i {pos.x + dx, pos.y + dy};

    if (isSpark(newPos))
        newDirs.push_back(Vec2i {dx, dy});
}

bool Qix::hasIgnited()
{
    for (int i = 0; i < (int) this->map.size(); i++)
        for (int j = 0; j < (int) this->map[0].size(); j++)
            if (this->map[i][j] == IGNITED)
                return true;
    return false;
}

int Qix::getScore()
{
    if (flushScore) {
        flushScore = 0;
        return score;
    }
    return -1;
}
