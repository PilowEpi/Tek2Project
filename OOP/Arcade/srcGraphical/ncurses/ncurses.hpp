
#ifndef _NCURSES_LIB_H
#define _NCURSES_LIB_H

#include <ncurses.h>
#include <vector>

#include "arcade.hpp"

class NCursesBuffPixel
{
    public:
        NCursesBuffPixel()
        : _cl(IDisplayModule::WHITE), _bg(IDisplayModule::BLACK), _c(' '){};
        ~NCursesBuffPixel() {};
        
        void setPixel(char pixel, IDisplayModule::color_t color, IDisplayModule::color_t bgColor);
        IDisplayModule::color_t _cl;
        IDisplayModule::color_t _bg;
        char _c;
    private:
};

class NCurses : public ADisplayModule
{
    public:
        ~NCurses() {};

        void init(int x, int y);
        void stop();

        void drawSquare(Square *);
        void drawText(Text *txt);
        void drawLine(Line *);
        void drawLineDx(int x_, int y_, int dx, int dy, IDisplayModule::color_t color);
        void drawPixel(int x, int y, IDisplayModule::color_t color);
        void drawShape(IObject* obj);

        IDisplayModule::color_t convertColor(const Color c);

        void refresh();

        // Event
        Event getEvent();

        Vec2f getSize() { return Vec2f(_x, _y); }

        const std::string getName() {return this->_name;};
    private:
        void initColor();
        std::string _name;
        int _x;
        int _y;
        bool _hasInit = false;

        // Buffer
        std::vector<std::vector<NCursesBuffPixel>> _buff;
};

#endif
