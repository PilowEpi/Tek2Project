#include <iostream>

#include "ai.hpp"

/**
 * Look Around : Cost 56
**/
void Ai::lookAround()
{
    Look();
    Left();
    Look();
    Left();
    Look();
    Left();
    Look();
    Left();
    automaticWorkflow();
}

void Ai::goWandering()
{
    int x = rand() % worldSize.x;
    int y = rand() % worldSize.y;

    goToCell(Vec2{x, y});
    lookAround();
    automaticWorkflow();
}

void Ai::goGetFood()
{
    while (inventory[FOOD] < 8) {
        std::cout << "HAS " << inventory[FOOD] << " FOOD" << std::endl;
        goWandering();
        lookAround();
        while (goTake(FOOD)) {
            automaticWorkflow();
        }
    }
}

bool Ai::goTake(Object o)
{
    Vec2 closest = closestObject(o);
    if (closest.x != -1 && closest.y != -1) {
        std::cout << "Closest " << enumToObjectName(o) << " : x" << closest.x << " , y" << closest.y << std::endl;
        goToCell(closest);
        Take(o);
//        Look();
        return 1;
    }
    return 0;
}

Vec2 Ai::closestObject(Object o)
{
    int minDist = -1;
    Vec2 closest(-1, -1);
    for (int i = 0; i < worldSize.x; i++) {
        for (int y = 0; y < worldSize.y; y++) {
            if (map[i][y].objects[o] > 0) {
                int xdist = std::abs(i - position.x);
                if (xdist > worldSize.x / 2) xdist = std::abs((xdist - worldSize.x)) + 1;
                int ydist = std::abs(y - position.y);
                if (ydist > worldSize.y / 2) ydist = std::abs((ydist - worldSize.y)) + 1;
                if ((xdist + ydist) < minDist || minDist == -1) {
                    minDist = xdist + ydist;
                    closest = Vec2{i, y};
                }
            }
        }
    }
    return closest;
}

void Ai::level2()
{
    if (level != 1) return;
    Vec2 pos = closestObject(LINEMATE);
    if (pos.x == -1 || pos.y == -1) {
        lookAround();
        pos = closestObject(LINEMATE);
        while (pos.x == -1 || pos.y == -1) {
            goWandering();
            pos = closestObject(LINEMATE);
        }
        return level2();
    }
    goToCell(pos);
    automaticWorkflow();
    Incantation();
    Inventory();
    automaticWorkflow();
    if (level != 2) {
        lookAround();
        level2();
    }
}