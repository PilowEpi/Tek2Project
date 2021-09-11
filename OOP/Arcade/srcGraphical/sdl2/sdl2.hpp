
#ifndef _SDL2_LIB_H
#define _SDL2_LIB_H

#include "arcade.hpp"

#define PIXELSIZE 16

class SDL2 : public ADisplayModule {

public:
    ~SDL2() {};

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

    Vec2f getSize() { return Vec2f(_x / PIXELSIZE, _y / PIXELSIZE); }

    const std::string getName() {return this->_name;};
    
    private:
        std::string _name;
        int _x;
        int _y;
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        TTF_Font *_font;
};

#endif
