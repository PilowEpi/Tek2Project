#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <climits>

#define MAGIC 2147483647

enum edir {
    NORTH = 0,
    WEST = 1,
    SOUTH = 2,
    EAST = 3,
};

enum Object {
    PLAYER = 0,
    FOOD = 1,
    LINEMATE = 2,
    DERAUMERE = 3,
    SIBUR = 4,
    MENDIANE = 5,
    PHIRAS = 6,
    THYSTAME = 7,
};

class Cell {
public:
    int time = INT_MAX/2;
    std::map<Object, int> objects;
};

typedef std::vector<std::vector<Cell>> Map;

class Vec2 {
public:
    Vec2() {}
    Vec2(int x, int y) : x(x), y(y) {}
    int x;
    int y;

    int &operator[](int i) {
        if (i == 0){
            return x;
        } else if (i == 1) {
            return y;
        }
        return x;
    }

    float pytagore() const {
        return std::pow((float)x*x+y*y, 0.5);
    }

    float dotProduct(const Vec2 &vec) const {
        return vec.x * this->y + this->x * vec.y;
    }

    float dotProductNorm(const Vec2 &vec) const {
        Vec2 v1 = *this / this->pytagore();
        Vec2 v2 = vec / vec.pytagore();

        return v1.x * v2.y + v2.x * v1.y;
    }

    Vec2 operator+(const Vec2 &other) const {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 operator-(const Vec2 &other) const {
        return Vec2(x - other.x, y - other.y);
    }

    Vec2 operator*(const Vec2 &other) const {
        return Vec2(x * other.x, y * other.y);
    }

    Vec2 operator/(const Vec2 &other) const {
        return Vec2(x / other.x, y / other.y);
    }

    Vec2 operator%(const Vec2 &other) const {
        return Vec2(x % other.x, y % other.y);
    }

    Vec2 &operator+=(const Vec2 &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2 &operator-=(const Vec2 &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2 &operator*=(const Vec2 &other) {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    Vec2 &operator/=(const Vec2 &other) {
        x /= other.x;
        y /= other.y;
        return *this;
    }

    Vec2 &operator%=(const Vec2 &other) {
        x /= other.x;
        y /= other.y;
        return *this;
    }

    Vec2 operator+(float val) const {
        return Vec2(x + val, y + val);
    }
    
    Vec2 operator-(float val) const {
        return Vec2(x - val, y - val);
    }

    Vec2 operator*(float val) const {
        return Vec2(x * val, y * val);
    }

    Vec2 operator/(float val) const {
        return Vec2(x / val, y / val);
    }

    Vec2 operator%(int val) const {
        return Vec2(x % val, y % val);
    }

    Vec2 &operator+=(float val) {
        x += val;
        y += val;
        return *this;
    }

    Vec2 &operator-=(float val) {
        x -= val;
        y -= val;
        return *this;
    }

    Vec2 &operator*=(float val) {
        x *= val;
        y *= val;
        return *this;
    }

    Vec2 &operator/=(float val) {
        x /= val;
        y /= val;
        return *this;
    }

    Vec2 &operator=(Vec2 val)
    {
        x = val.x;
        y = val.y;
        return *this;
    }

    bool operator==(const Vec2 &a) const {
        return x == a.x && y == a.y;
    }
};

#include "friend.hpp"
class Ai;
class Friend;

std::string makeMessage(Ai &ai, int type);
std::vector<std::string> split(const std::string &origin, std::string delim);
Vec2 directionToDeltaVec(edir dir);
edir DeltaVecToEdir(Vec2 vec);
int create_socket(std::string ip, int port);
void print_map(Friend &f);
void print_map(Ai &ai);
std::string enumToObjectName(Object o);
Object objectNameToEnum(std::string);
int sendall(int fd, const char *data, int size);

int get_x(int id, int rot);
int get_y(int id, int rot);