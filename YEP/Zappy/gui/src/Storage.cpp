/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** Storage
*/

#include "Storage.hpp"

// Storage Functions

Storage::Storage()
{
    _idMax = -1;
    _logs = std::make_shared<std::vector<std::string>>();
}

void Storage::add(int id, std::shared_ptr<Trantor> p)
{
    if (p == nullptr) {
        std::cerr << "NULLPTR" << std::endl;
        return;
    }
    _player[id] = p;
}

void Storage::addEgg(int id, std::shared_ptr<Egg> egg)
{
    if (egg == nullptr) {
        std::cerr << "NULLPTR" << std::endl;
        return;
    }
    _egg[id] = egg;    
}

// Team Functions

Team::Team(std::string teamName)
{
    _name = teamName;
    _teamColor = rl::Color(rand() % 255, rand() % 255, rand() % 255, 255);
}