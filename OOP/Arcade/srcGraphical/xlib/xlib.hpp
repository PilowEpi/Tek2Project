
#ifndef _XLIB_LIB_H
#define _XLIB_LIB_H

#include <X11/Xlib.h>
#include <X11/extensions/Xdbe.h>

#include "arcade.hpp"

#define PIXELSIZE 16

class Xlib : public ADisplayModule {
private:
    Display *display;
    Window window;
    long event_mask;
    XEvent event;
    GC gc;
    bool dbestate;
    XdbeBackBuffer _backbuffer;
    Visual *d_vis = NULL;
    XdbeBackBuffer d_backBuf;
    long _time;
    bool needToDraw;
public:
    ~Xlib() {};

    void init(int x, int y);
    void stop();
    
    void dbe();
    void setColor(Color color);
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
