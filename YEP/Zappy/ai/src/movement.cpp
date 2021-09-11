#include <iostream>

#include "ai.hpp"

void Ai::goToCell(Vec2 pos) {
    Vec2 posD = (pos - position + worldSize*1.5) % worldSize - worldSize*0.5;

    goToCellDelta(posD);
}

void Ai::goToCellDelta(Vec2 posD) {
    if (posD.pytagore() == 0)
        return;
    std::cout << "move D "<< posD.x << " " << posD.y << std::endl;
    Vec2 dirVec = directionToDeltaVec(dir);
    if (posD.x == 0 || posD.y == 0) {
        turn(DeltaVecToEdir(posD));
        goForward(abs(posD.x) + abs(posD.y));
    } else {
        if (dirVec.dotProductNorm(Vec2(posD.x, 0)) > 0){
            turn(DeltaVecToEdir(Vec2(posD.x, 0)));
            goForward(abs(posD.x));
            posD.x = 0;
            if (posD.y)
                goToCellDelta(posD);
        } else {
            turn(DeltaVecToEdir(Vec2(0, posD.y)));
            goForward(abs(posD.y));
            posD.y = 0;
            if (posD.x)
                goToCellDelta(posD);
        }
    }
}

void Ai::turn(edir d)
{
    if (simulate_dir == d) return;
    if (simulate_dir == NORTH && d == EAST) return Right();
    if (simulate_dir == NORTH && d == WEST) return Left();
    if (simulate_dir == NORTH && d == SOUTH) {
        Left();
        return Left();
    }
    if (simulate_dir == SOUTH && d == EAST) return Left();
    if (simulate_dir == SOUTH && d == WEST) return Right();
    if (simulate_dir == SOUTH && d == NORTH) {
        Right();
        return Right();
    }
    if (simulate_dir == EAST && d == NORTH) return Left();
    if (simulate_dir == EAST && d == SOUTH) return Right();
    if (simulate_dir == EAST && d == WEST) {
        Right();
        return Right();
    }
    if (simulate_dir == WEST && d == NORTH) return Right();
    if (simulate_dir == WEST && d == SOUTH) return Left();
    if (simulate_dir == WEST && d == EAST) {
        Left();
        return Left();
    }
}

/**
 * Go [distance] away : Cost 7 * distance
**/
void Ai::goForward(int distance)
{
    for (int i = 0; i < distance; i++) {
        Forward();
    }
}