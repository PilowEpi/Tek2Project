
#ifndef _ALLEGRO_LIB_H
#define _ALLEGRO_LIB_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include "arcade.hpp"

#define PIXELSIZE 16

class Allegro : public ADisplayModule {
private:
    ALLEGRO_DISPLAY *window;
    ALLEGRO_FONT *font;
    ALLEGRO_EVENT_QUEUE *queue;
public:
    ~Allegro() {};

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
