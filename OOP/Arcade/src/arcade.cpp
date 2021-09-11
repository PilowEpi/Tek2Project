
#include <dlfcn.h>

#include <map>
#include <utility>
#include <algorithm>
#include <iostream>
#include <fstream>

#include "arcade.hpp"
#include "carcade.hpp"
#include "game.hpp"
#include "shared.hpp"

void Arcade::changeLib(bool next)
{
    auto it = std::find(libs.begin(), libs.end(), currentLibName);
    if (next) {
        if (it == libs.end() - 1) {
            it = libs.begin();
        } else {
            it++;
        }
    } else {
        if (it == libs.begin()) {
            it = libs.end() - 1;
        } else {
            it--;
        }
    }
    currentLibName = (*it);

    it = std::find(libs.begin(), libs.end(), currentLibName);
    int dist = it - libs.begin();

    if (dist >= int(libsPaths.size()))
        return;
    std::string path = libsPaths[dist];
    
    currentLib->stop();
    currentLib = loadGraph(path.c_str());
    currentLib->init(LIB_SIZE_X, LIB_SIZE_Y);
}

void Arcade::changeGame(bool next)
{
    auto it = std::find(games.begin(), games.end(), currentGameName);
    if (next) {
        if (it == games.end() - 1) {
            it = games.begin();
        } else {
            it++;
        }
    } else {
        if (it == games.begin()) {
            it = games.end() - 1;
        } else {
            it--;
        }
    } 
    currentGameName = (*it);

    it = std::find(games.begin(), games.end(), currentGameName);
    int dist = it - games.begin();

    if (dist >= int(gamePaths.size()))
        return;
    std::string path = gamePaths[dist];
    
    currentGame = loadGame(path.c_str());
}

void Arcade::handleEvent()
{
    while (ev.type > 0) {
        if (ESCAPE(ev.type)) {
            gameRun = 0;
            break;
        }
        if (ev.type == 111) {
            this->changeLib(true);
        } else if (ev.type == 108) {
            this->changeLib(false);
        } else if (ev.type == 112) {
            this->changeGame(true);
        } else if (ev.type == 109) {
            this->changeGame(false);
        } else if (ev.type == 114) {
            auto it = std::find(games.begin(), games.end(), currentGameName);
            int dist = it - games.begin();

            if (dist >= int(gamePaths.size()))
                return;
            std::string path = gamePaths[dist];
            
            currentGame = loadGame(path.c_str());
        } else if (ev.type == 116) {
            
            Arcade::Menu menu(this);

            menu.display();
        }
        currentGame->computeEvent(ev);
        ev = currentLib->getEvent();
    }
}

void Arcade::runGame()
{
    gameRun = 1;

    while (gameRun) {
        ev = currentLib->getEvent();

        handleEvent();
        saveScore(currentGame->getScore());

        Vec2f sf = currentLib->getSize();
        Vec2i size = Vec2i{int(sf.x), int(sf.y)};

        std::vector<IObject *> *objs = currentGame->run(size);

        for (IObject *disp : (*objs))
            currentLib->drawShape(disp);
        currentLib->refresh();    
    }
}

void Arcade::saveScore(int newScore)
{
    if (newScore < 0)
        return;
    std::vector<std::pair<std::string, int>> scores;

    auto it = std::find(games.begin(), games.end(), currentGameName);
    int dist = it - games.begin();

    if (dist >= int(gamePaths.size()))
        return;
    
    std::string path = gamePaths[dist];
    int slash = path.rfind('/') + 1;

    if (slash > 0)
        path = path.substr(slash, path.length() - slash);
    std::string file = "scores_" + path + ".txt";

    std::fstream save(file, std::ios::in);
    std::string g_name;
    std::string g_score;

    while (std::getline(save, g_name)) {
        std::getline(save, g_score);

        try {
            scores.push_back(std::make_pair(g_name, stoi(g_score)));
        } catch (const std::invalid_argument &) {
            continue;
        }
    }
    save.close();

    int size = scores.size();
    if (size < 5) {
        scores.push_back(std::make_pair(username, newScore));
    } else {
        int i = 0;

        for (; i < size; i++) {
            if (newScore > scores[i].second)
                break;
        }
        if (i < size)
            scores[i] = std::make_pair(username, newScore);
    }

    auto lbd = [](std::pair<std::string, int> a, std::pair<std::string, int> b) {
        return a.second > b.second;};

    std::sort(scores.begin(), scores.end(), lbd);

    std::fstream out(file, std::ios::out | std::ios::trunc);
    for (const auto &pair : scores) {
        out << pair.first << std::endl;
        out << std::to_string(pair.second) << std::endl;
    }
    out.close();
}

void Arcade::start()
{
    currentLib->init(LIB_SIZE_X, LIB_SIZE_Y);

    Arcade::Menu menu(this);

    menu.display();
    
    if (currentGameName.empty()) {
        currentLib->stop();
        //void *handle = currentLib->handle;
        delete currentLib; // move dlclose in interface destructor ?
        //dlclose(handle);
        //return;
    }

    auto it = std::find(games.begin(), games.end(), currentGameName);
    int dist = it - games.begin();

    if (dist >= int(gamePaths.size()))
        return;
    std::string path = gamePaths[dist];
    
    currentGame = loadGame(path.c_str());

    runGame();

    currentLib->stop();

    exit(0);
}

