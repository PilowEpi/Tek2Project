#pragma once

static std::map<int, std::map<Object, int>> LevelUpRequirement = {
    {
        {
            2,
            {
                {PLAYER, 1},
                {LINEMATE, 1},
                {DERAUMERE, 0},
                {SIBUR, 0},
                {MENDIANE, 0},
                {PHIRAS, 0},
                {THYSTAME, 0},
            }
        },
        {
            3,
            {
                {PLAYER, 2},
                {LINEMATE, 1},
                {DERAUMERE, 1},
                {SIBUR, 1},
                {MENDIANE, 0},
                {PHIRAS, 0},
                {THYSTAME, 0},
            }
        },
        {
            4,
            {
                {PLAYER, 2},
                {LINEMATE, 2},
                {DERAUMERE, 0},
                {SIBUR, 1},
                {MENDIANE, 0},
                {PHIRAS, 2},
                {THYSTAME, 0},
            }
        },
        {
            5,
            {
                {PLAYER, 4},
                {LINEMATE, 1},
                {DERAUMERE, 1},
                {SIBUR, 2},
                {MENDIANE, 0},
                {PHIRAS, 1},
                {THYSTAME, 0},
            }
        },
        {
            6,
            {
                {PLAYER, 4},
                {LINEMATE, 1},
                {DERAUMERE, 2},
                {SIBUR, 1},
                {MENDIANE, 3},
                {PHIRAS, 0},
                {THYSTAME, 0},
            }
        },
        {
            7,
            {
                {PLAYER, 6},
                {LINEMATE, 1},
                {DERAUMERE, 2},
                {SIBUR, 3},
                {MENDIANE, 0},
                {PHIRAS, 1},
                {THYSTAME, 0},
            }
        },
        {
            8,
            {
                {PLAYER, 6},
                {LINEMATE, 2},
                {DERAUMERE, 2},
                {SIBUR, 2},
                {MENDIANE, 2},
                {PHIRAS, 2},
                {THYSTAME, 1},
            }
        }
    }
};