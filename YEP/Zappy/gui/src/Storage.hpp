/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** Storage
*/

#ifndef ZAPPY_STORAGE_
#define ZAPPY_STORAGE_

#include "./raylib/rayLib.hpp"
#include "entityComponent/object/Trantor.hpp"
#include <memory>
#include <vector>
#include <string>
#include <unordered_map>


class Team
{
    public:
        Team(std::string name);

        std::string _name;
        rl::Color _teamColor;
    private:
};

class Storage
{
    public:
        Storage();

        void add(int id, std::shared_ptr<Trantor> p);
        void addEgg(int id, std::shared_ptr<Egg> egg);

        int _idMax;
        std::shared_ptr<std::vector<std::string>> _logs;
        std::vector<Team> _teams;
        std::shared_ptr<Map> _map;
        std::unordered_map<int, std::shared_ptr<Trantor>> _player;
        std::unordered_map<int, std::shared_ptr<Egg>> _egg;
    private:
};

#endif