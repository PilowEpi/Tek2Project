/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** graphic
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

#include <string>

#include "arcade.hpp"
#include "game.hpp"

#define LIB_SIZE_X 50
#define LIB_SIZE_Y 50

class Arcade {
    class Menu {
    public:
        Menu(Arcade *arcade);
        ~Menu();

        void initSquares();
        void initTexts();
        void initCursor();

        void updateCursor();
        void handleEvent();
        void display();
        void draw();

        void setScore();
    private:
        Arcade *arcade;

        Square *libsSpot;
        Square *gamesSpot;
        Square *usernameSpot;
        Square *boardSpot;

        Square *libsSpotFill;
        Square *gamesSpotFill;
        Square *usernameSpotFill;
        Square *boardSpotFill;

        Text *username;

        Line *cursor;
        std::vector<Text *> texts;
        Event event;

        Square *scoreBack;
        Square *scoreSpot;
        Square *scoreFill;
        std::vector<Text *> scores;

        int run;
        int mode;
        int selected;
        int score;
    };

public:
    Arcade(char **av);

    void changeLib(bool );
    void changeGame(bool ); 
    IGameModule *loadGame(const char *path);
    IDisplayModule *loadGraph(const char *path);
    std::string getNameFromPath(std::string path);
    int getLibType(const char *path);
    void loadShared(std::string path);

    void saveScore(int newScore);

    void start();

    void handleEvent();
    void runGame();
private:
    std::vector<std::string> games;
    std::vector<std::string> gamePaths;

    std::vector<std::string> libs;
    std::vector<std::string> libsPaths;

    std::string currentLibName;
    std::string currentGameName;

    std::string username;

    IDisplayModule *currentLib;
    IGameModule *currentGame;
    
    int gameRun;
    Event ev;
};

#endif
