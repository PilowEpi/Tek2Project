
#ifndef _IRRLICHT_LIB_H
#define _IRRLICHT_LIB_H

#include <irrlicht/irrlicht.h>
#include <iostream>
#include <fstream>
#include "arcade.hpp"

#define PIXELSIZE 16

class IrrlichtEventReceiver : public irr::IEventReceiver {
public:
    int lastKeyPressed = -1;

    enum type {
        KEYPRESS,
        WINDOWCLOSED
    };

    virtual bool OnEvent(const irr::SEvent &event) override {
        if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
            if (event.KeyInput.PressedDown) {
                lastKeyPressed = event.KeyInput.Key;
            }
        }

        return false;
    };

    IrrlichtEventReceiver() {}
};

class Irrlicht : public ADisplayModule {
private:
    IrrlichtEventReceiver eventReceiver;
    irr::IrrlichtDevice *device;
    irr::video::IVideoDriver *driver;
    irr::scene::ISceneManager *smgr;
    irr::gui::IGUIEnvironment *guienv;
    irr::gui::IGUIFont* font;
public:
    ~Irrlicht() {};

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
