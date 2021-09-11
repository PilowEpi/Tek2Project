#include "ai.hpp"
#include "level.hpp"

bool Ai::hasObjectToLevelUp()
{
    std::map<Object, int> objToLevelUp = LevelUpRequirement[level + 1];

    for (auto objreq : objToLevelUp) {
        if (objreq.first == PLAYER) continue;
        if (objreq.second > inventory[objreq.first]) {
            return false;
        }
    }
    return true;
}

std::map<Object, int> Ai::getMissingObjectToLevelUp()
{
    std::map<Object, int> objToLevelUp = LevelUpRequirement[level + 1];

    std::map<Object, int> mo;
    if (hasObjectToLevelUp()) return mo;
    for (auto objreq : objToLevelUp) {
        if (objreq.first == PLAYER) continue;
        if (objreq.second > inventory[objreq.first]) {
            mo[objreq.first] = objreq.second - inventory[objreq.first];
        }
    }
    return mo;
}

bool Ai::canLevelUp()
{
    if (map[position.x][position.y].objects[PLAYER] == (LevelUpRequirement[level + 1][PLAYER] - 1) && hasObjectToLevelUp()) {
        return true;
    }
    return false;
}

void Ai::goGetLevelUpItem()
{
    std::map<Object, int> missingObjects = getMissingObjectToLevelUp();
    for (auto &object : missingObjects) {
        for (int i = 0; i < object.second; i++) {
            if (!goTake(object.first)) {
                goWandering();
            }
            automaticWorkflow();
        }
    }    
}