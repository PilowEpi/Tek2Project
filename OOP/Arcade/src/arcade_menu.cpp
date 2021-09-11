/*
** EPITECH PROJECT, 2020
** OOP Arcade
** File description:
** main
*/

#include <dlfcn.h>
#include <err.h>
#include <stdio.h>

#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <filesystem>

#include "error.hpp"
#include "arcade.hpp"
#include "carcade.hpp"
#include "game.hpp"
#include "shared.hpp"

void setFill(Square *&sq, Square *from)
{
    sq = new Square;
    sq->pos = Vec2i{from->pos.x + 1, from->pos.y + 1};
    sq->size = Vec2i{from->size.x - 2, from->size.y - 2};
    sq->color = colors[1];
}

void createSquare(Square *&sq, Vec2i pos, int color, Vec2i size)
{
    sq = new Square;
    sq->pos = pos;
    sq->color = colors[color];
    sq->size = size;
}

void Arcade::Menu::initSquares()
{
    int boxSize = arcade->libs.size();
    int gXsize = 0;
    int lXsize = 0;

    if (int(arcade->games.size()) > boxSize)
        boxSize = arcade->games.size();

    for (const auto &lib : arcade->libs)
        if (int(lib.size()) > lXsize)
            lXsize = lib.size();

    for (const auto &game : arcade->games)
        if (int(game.size()) > gXsize)
            gXsize = game.size();

    boxSize = boxSize * 2 + 4 + (boxSize % 2 == 1 ? 1 : 0);

    if (lXsize > gXsize)
        gXsize = lXsize;

    gXsize += 4;

    int total = gXsize * 2 + 5;
    int lStart = (LIB_SIZE_X - total) / 2;
    int gStart = lStart + gXsize + 5;

    createSquare(libsSpot, Vec2i{lStart, 1}, 10, Vec2i{gXsize, boxSize});
    createSquare(gamesSpot, Vec2i{gStart, 1}, 11, Vec2i{gXsize, boxSize});
    createSquare(usernameSpot, Vec2i{lStart, boxSize + 2}, 12, Vec2i{10, 5});
    createSquare(boardSpot, Vec2i{gStart, boxSize + 2}, 7, Vec2i{gXsize, boxSize});
    createSquare(scoreBack, Vec2i{0, 0}, 0, Vec2i{LIB_SIZE_X, LIB_SIZE_Y});
    createSquare(scoreSpot, Vec2i
                 {
                     (LIB_SIZE_X - 13) / 2,
                     (LIB_SIZE_Y - 12) / 2
                 }, 10, Vec2i{13, 13});

    setFill(libsSpotFill, libsSpot);
    setFill(gamesSpotFill, gamesSpot);
    setFill(usernameSpotFill, usernameSpot);
    setFill(boardSpotFill, boardSpot);
    setFill(scoreFill, scoreSpot);

    score = 0;
}

void Arcade::Menu::initTexts()
{
    int i = 0;
    for (const auto &lib : arcade->libs) {
        Text *t = new Text(lib);
        Vec2i pos = libsSpotFill->pos;
        Vec2i size = libsSpot->size;

        t->pos = Vec2i {
            t->centerText(size.x) + pos.x + 1,
            i * 2 + pos.y + 1
        };
        t->color = colors[15];
        i++;

        texts.push_back(t);
    }

    i = 0;
    for (const auto &game : arcade->games) {
        Text *t = new Text(game);
        Vec2i pos = gamesSpotFill->pos;
        Vec2i size = gamesSpot->size;

        t->pos = Vec2i {
            t->centerText(size.x) + pos.x + 1,
            i * 2 + pos.y + 1
        };
        t->color = colors[15];
        i++;

        texts.push_back(t);
    }

    i = 0;
    for (const auto &game : arcade->games) {
        Text *t2 = new Text(std::string("Score ") + game);
        Vec2i pos = boardSpotFill->pos;
        Vec2i size = boardSpot->size;

        t2->pos = Vec2i {
            t2->centerText(size.x) + pos.x + 1,
            i * 2 + pos.y + 1
        };
        i++;
        t2->color = colors[15];
        texts.push_back(t2);
    }

    username = new Text("username");
    username->pos = Vec2i {usernameSpot->pos.x + 2, usernameSpot->pos.y + 2};
    username->color = colors[15];
    arcade->username = "username";
}

void Arcade::Menu::initCursor()
{
    cursor = new Line;

    cursor->pos = texts[0]->pos;
    cursor->color = colors[3];
    cursor->d = Vec2i {int(texts[0]->text.size() / 2), 0};
}

void Arcade::Menu::updateCursor()
{
    if ((LEFT(event.type) && (mode == 1 || mode == 3)) ||
        (event.type == 260 && mode == 2)) {
        mode--;
        selected = 0;
    } else if ((RIGHT(event.type) && mode < 3) ||
        (event.type == 261 && mode == 2)) {
        mode++;
        selected = 0;
    }

    if (UP(event.type) && selected > 0) {
        selected--;

        if (mode == 2) {
            selected = 0;
            mode = 0;
        }
    } else if (DOWN(event.type)) {
        if (mode == 0 &&
            selected + 1 < int(arcade->libs.size())) {
            selected++;
        } else if (mode == 1 && selected + 1 < int(texts.size() - arcade->libs.size())) {
            selected++;
        } else if (mode == 3 && selected + 1 < int(texts.size() - arcade->libs.size())) {
            selected++;
        }
    }

    int i = selected;

    if (mode == 1)
        i += arcade->libs.size();

    if (mode == 3)
        i += arcade->libs.size() + arcade->games.size();

    if (i < int(texts.size())) {
        int size = texts[i]->text.size();

        cursor->pos = texts[i]->pos;
        cursor->d = Vec2i {size / 2 + size % 2, 0};
    }

    if (mode == 2) {
        cursor->d = Vec2i {0, 0};
        usernameSpotFill->color = colors[3];
    } else {
        usernameSpotFill->color = colors[1];
    }
}

void Arcade::Menu::setScore()
{
    std::string g_name;
    std::string g_score;

    int i = 0;
    Vec2i pos = scoreFill->pos;

    int idx = selected + arcade->libs.size();

    std::string game = texts[idx]->text;
    auto it = std::find(arcade->games.begin(), arcade->games.end(), game);
    int dist = it - arcade->games.begin();

    if (dist >= int(arcade->gamePaths.size()))
        return;
    
    std::string path = arcade->gamePaths[dist];

    scores.clear();

    int slash = path.rfind('/') + 1;

    if (slash > 0)
        path = path.substr(slash, path.length() - slash);
    std::ifstream save("scores_" + path + ".txt");

    if (save.fail())
        return;
    while (std::getline(save, g_name)) {
        std::getline(save, g_score);

        try {
            Text *t = new Text;
            int score = stoi(g_score); 

            t->text = g_name;

            while (t->text.length() != 12)
                t->text.push_back(' ');

            t->text += std::to_string(score);
            t->color = colors[15];
            t->pos = Vec2i {pos.x + 1, pos.y + i * 2 + 1};

            i++;
            scores.push_back(t);

        } catch (const std::invalid_argument &e) {
            continue;
        }
    }
}

void Arcade::Menu::handleEvent()
{
    while (event.type > 0) {
        if (ESCAPE(event.type) && score) {
            score = 0;
        } else if (ESCAPE(event.type)) {
            run = 0;
            break;
        }

        updateCursor();

        if (ENTER(event.type) && mode == 3) {
            score = 1;
            setScore();
        }

        if (ENTER(event.type) && mode == 1) {
            run = 0;
            cursor->color = colors[1];
            arcade->currentGameName = texts[selected + arcade->libs.size()]->text;
            break;
        }

        if (mode == 2) {
            if (isprint(event.type) &&
                username->text.length() < 12) {
                username->text.push_back(event.type);
                
            } else if (event.type == 127) {
                std::string txt = username->text;
                
                username->text = txt.substr(0, txt.size() - 1);
            }

            arcade->username = username->text;
        }

        if (ENTER(event.type) && mode == 0) {
            arcade->currentLib->stop();

            arcade->currentLib = arcade->loadGraph(arcade->libsPaths[selected].c_str());
            arcade->currentLib->init(LIB_SIZE_X, LIB_SIZE_Y);
        }
        event = arcade->currentLib->getEvent();
    }
}

Arcade::Menu::~Menu() {
    delete libsSpot;
    delete gamesSpot;
    delete usernameSpot;
    delete boardSpot;
    delete scoreBack;
    delete scoreSpot;

    delete libsSpotFill;
    delete gamesSpotFill;
    delete usernameSpotFill;
    delete boardSpotFill;
    delete scoreFill;

    delete cursor;

    for (Text *t : texts) {
        delete t;
    }
    delete username;
}

void Arcade::Menu::draw()
{
    if (score) {
        arcade->currentLib->drawShape(scoreBack);
        arcade->currentLib->drawShape(scoreSpot);
        arcade->currentLib->drawShape(scoreFill);

        for (const auto &text : scores)
            arcade->currentLib->drawShape(text);
    } else {
        arcade->currentLib->drawShape(gamesSpot);
        arcade->currentLib->drawShape(libsSpot);
        
        arcade->currentLib->drawShape(gamesSpotFill);
        arcade->currentLib->drawShape(libsSpotFill);
        
        arcade->currentLib->drawShape(usernameSpot);
        arcade->currentLib->drawShape(usernameSpotFill);
    
        arcade->currentLib->drawShape(boardSpot);
        arcade->currentLib->drawShape(boardSpotFill);
        
        arcade->currentLib->drawShape(cursor);
        arcade->currentLib->drawShape(username);
        
        for (const auto &text : texts)
            arcade->currentLib->drawShape(text);
    }

    arcade->currentLib->refresh();
}

void Arcade::Menu::display()
{
    while (run) {
        event = arcade->currentLib->getEvent();

        handleEvent();
        draw();
    }
}

Arcade::Menu::Menu(Arcade *arcade) : arcade(arcade), event(-1), run(1), mode(0), selected(0)
{
    this->initSquares();
    this->initTexts();
    this->initCursor();    
}
