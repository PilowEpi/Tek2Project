/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** graphic
*/

#ifndef GRAPHIC_HPP_
#define GRAPHIC_HPP_

#include "shared.hpp"
#include "string"
#include "error.hpp"

/**
 * @brief Segment Object
 * 
 * ### Exemple
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
 * Seg segment = new segment(10, 10, 5, 5);
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
class Seg {
    public:
        Seg(float x, float y, float dx, float dy) : x(x), y(y), dx(dx), dy(dy) {}
        float x, y;
        float dx, dy;
};


/**
 * 
 * 
 */
class IEvent {
    public:
        IEvent() {};
};

class Event : public IEvent {
public:
    Event(int type) : type(type) {};
    int type;
};

const Color colors[16] = {
    {0, 0, 0},
    {128, 0, 0},
    {0, 128, 0},
    {128, 128, 0},
    {0, 0, 128},
    {128, 0, 128},
    {0, 128, 128},
    {128, 128, 128},
    
    {0 + 127, 0 + 127, 0 + 127},
    {128 + 127, 0 + 127, 0 + 127},
    {0 + 127, 128 + 127, 0 + 127},
    {128 + 127, 128 + 127, 0 + 127},
    {0 + 127, 0 + 127, 128 + 127},
    {128 + 127, 0 + 127, 128 + 127},
    {0 + 127, 128 + 127, 128 + 127},
    {128 + 127, 128 + 127, 128 + 127}
};


/**
 * @brief Class IDisplayModule
 * 
 * The main class with all diferent function for the Core Module.
 * 
 */
class IDisplayModule : public IModule {
    public:
        /**
         * @brief Every Color Code for graphical.
         */
        typedef enum {
            BLACK = 0,
            RED = 1, 
            GREEN = 2,
            BROWN = 3,
            BLUE = 4,
            MAGENTA = 5,
            CYAN = 6,
            WHITE = 7, // light

            BRIGHT_BLACK = 8, // Gray
            BRIGHT_RED = 9,
            BRIGHT_GREEN = 10,
            BRIGHT_BROWN = 11,
            BRIGHT_BLUE = 12,
            BRIGHT_MAGENTA = 13,
            BRIGHT_CYAN = 14, // Yellow
            BRIGHT_WHITE = 15
        } color_t;
        
        /**
         * @brief Destructor for the IDisplayModule
         */
        virtual ~IDisplayModule() = default;
        
        /**
         * @brief Funtion that init all for the graphic library.
         * 
         * @param[in] x 
         * @param[in] y
         */
        virtual void init(int x, int y) = 0;

        /**
         * @brief Function that stop the graphic library.
         */
        virtual void stop() = 0;

        /**
         * @brief Function that print a IObject.
         * 
         * @param[in] obj Object to print
         */
        virtual void drawShape(IObject *obj) = 0;
 
        /**
         * @brief Function that clear the current screen.
         */
        virtual void clearScreen() = 0;

        /**
         * @brief Function that refresh the current screen.
         */
        virtual void refresh() = 0;

        /**
         *  @brief Function that return the current event (actually a keybind event see Event Class).
         * 
         *  @return Event obj
         */    
        virtual Event getEvent() = 0;

        /**
         * @brief Function that return the name of the lib.
         * This function is used for the menu display.
         * 
         * @return std::string name
         */
        virtual const std::string getName() = 0;

        /**
         * @brief Function that return the size of the screen.
         * 
         * @return Vec2f size
         */
        virtual Vec2f getSize() = 0;

};


/**
 * @brief Class ADisplayModule
 * 
 * Abstract class of IDisplayModule.
 * 
 */
class ADisplayModule : public IDisplayModule {
    public:
        /**
         *  @warning DO NOT REMOVE
         */
        void *handle;
        /**
         * @brief Destructor of ADisplayModule
         */
        virtual ~ADisplayModule() {};
        virtual IModule::type_m getType() override {return IModule::type_m::GRAPHIC;};
        virtual void clearScreen() {};
};

#include <map>

void menu(const char *current,
          std::map<std::string, std::string> &games,
          std::map<std::string, std::string> &libs);

IDisplayModule *loadGraph(const char *path);

#endif
