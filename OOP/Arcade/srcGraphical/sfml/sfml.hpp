
#ifndef _SFML_LIB_H
#define _SFML_LIB_H

#include <SFML/Window.hpp>

#include "arcade.hpp"

#define PIXELSIZE 16

class SFML : public ADisplayModule {
private:
    sf::RenderWindow window;
    sf::Font _font;
public:
    ~SFML() {};

    void init(int x, int y);
    void stop();
    
    void drawSquare(Square *);
    void drawCircle(Circle *);
    void drawText(Text *);
    void drawLine(Line *);
    void drawPixel(int x, int y, Color color);
    void drawShape(IObject* obj);
    
    void refresh();

    // Event
    Event getEvent();

    Vec2f getSize() { return Vec2f(_x, _y); }

    const std::string getName() {return this->_name;};
    
    private:
        std::string _name;
        int _x;
        int _y;
};

#endif
