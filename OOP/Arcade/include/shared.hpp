/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** shared
*/

#ifndef SHARED_HPP_
#define SHARED_HPP_

#include <string>

/**
 * @brief Color Class
 * 
 * ### Exemple
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
 * Color c = new Color(255, 255, 255);
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
class Color {
public:
    Color() {};
    Color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}
    unsigned char r, g, b;
};

/**
 * @brief IVec2 Class
 * 
 * Interface for Vec2 class
 */
class IVec2 {
public:
    virtual ~IVec2() = default;
};

/**
 *  @brief Vec2 Class
 * 
 *  Class for vector creation
 * 
 *  @param x (int, float)
 *  @param y (int, float)
 * 
 * ### Exemple
 * 
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
 * // Create a int vector
 * Vec2i size = new Vec2i(3, 4);
 * 
 * std::cout << size.x << " " << size.y << std::endl;
 * 
 * // Create a float vector
 * Vec2f size = new Vec2i(3.3, 4.2);
 * 
 * std::cout << size.x << " " << size.y << std::endl;
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 * ### Output
 * 
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
 * 3 4
 * 3.3 4.2
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 */
template <typename T>
class Vec2 : public IVec2 {
public:
    Vec2() {};
    /**
     * @brief Constructor for Vec2
     */
    Vec2(T x, T y) : x(x), y(y) {};
    T x, y;
};

#define Vec2f Vec2<float>
#define Vec2i Vec2<int>

/**
 * @brief IObject Class
 * 
 * Interface for Object class
 */
class IObject {
public:
    virtual ~IObject() = default;
};

/**
 * @brief Object Class
 * 
 * Class for object creation; This class is used to create
 * every object for the game. Can be used to create objects.
 * 
 * @param pos Vec2i (x, y)
 * @param color Color of the Object
 * 
 */
class Object : public IObject {
public:
    Vec2i pos;
    Color color;
};


/**
 * @brief Square Class
 * 
 * Class to create a square.
 * 
 * @param size Vec2i (Size of square)
 * @param angle Angle of the Square
 */
class Square : public Object {
    public:
        Vec2i size;
        float angle;
};


/**
 * @brief Texture Class
 * 
 * Class to set a texture to a square.
 * 
 * @param path Path to the texture
 */
class Texture : public Square {
    public:
        std::string path;
};


/**
 * @brief Text Class
 * 
 * Class to create a text.
 * 
 * @param text Text object (ex : "toto")
 */
class Text : public Square {
    public:
        /**
         * @brief Constructor of an Empty Text Object.
         */
        Text() : text("") {};

        /**
         * @brief Constructor of Text Object.
         */
        Text(std::string text) : text(text) {};
        std::string text;

        /**
         * @brief Get the center of the text.
         */
        template <typename T>
        T centerText(T x) {return (x - text.length()) / 2;};
};

/**
 * @brief Circle Class
 * 
 *  Class to create a circle.
 * 
 * @param r radius of the circle
 */
class Circle : public Object {
    public:
        float r;
};

/**
 * @brief Line Class
 * 
 *  Class to create a Line object.
 * 
 * @param d Vec2i (vector of the line)
 */
class Line : public Object {
    public:
        Vec2i d;
};


/**
 * @brief Module Class
 * 
 * used to create a Module object (A graphical library or a game library).
 */
class IModule {
    public:
        /**
         * @brief Enum type module.
         * Value :
         *      UNDEFINED(0),
         *      GRAPHIC(1),
         *      GAME(2)
         */
        typedef enum {
            UNDEFINED = 0,
            GRAPHIC = 1,
            GAME = 2
        } type_m;

        /**
         * @brief Return the type of the module.
         */
        virtual type_m getType() = 0;
};

#endif
