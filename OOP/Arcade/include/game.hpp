/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <vector>

#include "arcade.hpp"
#include "shared.hpp"

#define LEFT(a) (a == 113 || a == 260)
#define UP(a) (a == 122 || a == 259)
#define DOWN(a) (a == 115 || a == 258)
#define RIGHT(a) (a == 100 || a == 261)
#define ESCAPE(a) (a == 27)
#define ENTER(a) (a == 13 || a == 10)

class IGameModule {
public:
    /**
     * @warning Do not remove
     */
    void *handle;

    /**
     * @brief Destructor of IGameModule
     */
    virtual ~IGameModule() = default;

    /**
     * @brief Function that been call every frame of the running time.
     * 
     * @return std::vector<IObject *> *list_of_Object
     */
    virtual std::vector<IObject *> *run(Vec2i vec) = 0;

    /**
     * @brief Function that been call to compute event in the running game.
     */
    virtual void computeEvent(Event event) = 0;

    /**
     * @brief Function that return the name of the game.
     * This function is used to khow the name for the menu.
     * 
     * @return std::string name_of_the_game
     */
    virtual const std::string getName() = 0;

    /**
     * @brief Function that return the current score.
     */
    virtual int getScore() = 0;
};

class AGameModule : public IGameModule {
public:
    /**
     * @brief Destructor of AGameModule
     */
    virtual ~AGameModule() {};
};

IGameModule *loadGame(const char *path);

#endif
