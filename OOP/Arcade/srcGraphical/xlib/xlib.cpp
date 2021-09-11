#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/Xdbe.h>
#include <unistd.h>
#include <iostream>

#include "arcade.hpp"
#include "xlib.hpp"

extern "C" Xlib* ctor()
{
    return new Xlib;
}

extern "C" std::string getLibName()
{
    return (std::string("Xlib"));
}

extern "C" int getLibType()
{
    return (0);
}

void Xlib::dbe()
{   
    int major, minor;
    if (XdbeQueryExtension(display, &major, &minor)) {
        dbestate = true;
        std::cerr << "Running with Xdbe (" << major << "." << minor << "), using double buffering !" << std::endl;
        int numScreens = 1;
        Drawable screens[] = { DefaultRootWindow(display) };
        XdbeScreenVisualInfo *info = XdbeGetVisualInfo(display, screens, &numScreens);
        if (!info || numScreens < 1 || info->count < 1) {
            dbestate = false;
            std::cerr << "Xdbe can't be supported !" << std::endl;
            return;
        }

        XVisualInfo xvisinfo_templ;
        xvisinfo_templ.visualid = info->visinfo[0].visual;
        xvisinfo_templ.screen = 0;
        xvisinfo_templ.depth = info->visinfo[0].depth;

        int matches;
        XVisualInfo *xvisinfo_match = XGetVisualInfo(display, VisualIDMask | VisualScreenMask | VisualDepthMask, &xvisinfo_templ, &matches);

        if (!xvisinfo_match || matches < 1) {
            dbestate = false;
            std::cerr << "Couldn't match a Visual with double buffering !" << std::endl;
            return;
        }

        d_vis = xvisinfo_match->visual;
    } else {
        dbestate = false;
        std::cerr << "DBE NOT AVAILABLE SCREEN WILL FLICKER" << std::endl;
    }
}

void Xlib::init(int x, int y)
{
    display = XOpenDisplay(0);

    dbe();

    window = XCreateWindow(display, DefaultRootWindow(display), 0, 0, x * PIXELSIZE, y * PIXELSIZE, 0, CopyFromParent, CopyFromParent, d_vis, 0, 0);

    d_backBuf = XdbeAllocateBackBufferName(display, window, XdbeBackground);

    int sc = DefaultScreen(display);
    gc = DefaultGC(display, sc);

    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    _time = spec.tv_nsec / 1.0e6 + (spec.tv_sec * 1.0e3);
    needToDraw = true;

    XMapWindow(display, window);
    XSelectInput(display, window, KeyPressMask);

    _x = x;
    _y = y;
}

void Xlib::setColor(Color color)
{
    unsigned long c = color.b + (color.g << 8) + (color.r << 16);
    XSetForeground(display, gc, c);
}

void Xlib::stop()
{
    XdbeDeallocateBackBufferName(display, d_backBuf);
    XUnmapWindow(display, window);
    XCloseDisplay(display);
}

void Xlib::drawSquare(Square *shape) {
    setColor(shape->color);
    XFillRectangle(display, window, gc, shape->pos.x * PIXELSIZE, shape->pos.y * PIXELSIZE, shape->size.x * PIXELSIZE, shape->size.y * PIXELSIZE);
}

void Xlib::drawCircle(Circle *) {}

void Xlib::drawText(Text *shape) {
    setColor(shape->color);
    XDrawString(display, window, gc, shape->pos.x * PIXELSIZE, shape->pos.y * PIXELSIZE, shape->text.c_str(), shape->text.size());
}

void Xlib::drawLine(Line *shape) {
    setColor(shape->color);
    XFillRectangle(display, window, gc, shape->pos.x * PIXELSIZE, (shape->pos.y - 1) * PIXELSIZE, shape->d.x * PIXELSIZE, PIXELSIZE);
}

void Xlib::drawPixel(int x, int y, Color color) {
    setColor(color);
    XFillRectangle(display, window, gc, x * PIXELSIZE, y * PIXELSIZE, PIXELSIZE, PIXELSIZE);
}

void Xlib::drawShape(IObject *obj) {
    Square *square = dynamic_cast<Square *>(obj);
    Line *line = dynamic_cast<Line *>(obj);
    Text *txt = dynamic_cast<Text *>(obj);

    if (!needToDraw)
        return;
    if (txt)
        this->drawText(txt);
    else if (square)
        this->drawSquare(square);
    else if (line)
        this->drawLine(line);
}
    
void Xlib::refresh() {
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    long now = (spec.tv_nsec / 1.0e6) + (spec.tv_sec * 1.0e3);

    // Optimization
    if (now - _time < (1000 / 30)) { // 120 = FPS
        needToDraw = false;
        return;
    }
    _time = now;
    needToDraw = true;
    XdbeSwapInfo swapInfo;
    swapInfo.swap_window = window;
    swapInfo.swap_action = XdbeBackground;

    // XdbeSwapBuffers returns true on success, we return 0 on success.
    if (!XdbeSwapBuffers(display, &swapInfo, 1)) {
        std::cerr << "Buffer swap failed !" << std::endl;
        return;
    }

    XFlush(display);
}

    // Event
Event Xlib::getEvent() {
    if (XCheckMaskEvent(display, KeyPressMask, &event)) {
        switch(event.xkey.keycode) {
                    case 24:
                        return Event(97);
                    case 25:
                        return Event(122);
                    case 26:
                        return Event(101);
                    case 27:
                        return Event(114);
                    case 28:
                        return Event(116);
                    case 29:
                        return Event(121);
                    case 30:
                        return Event(117);
                    case 31:
                        return Event(105);
                    case 32:
                        return Event(111);
                    case 33:
                        return Event(112);
                    case 38:
                        return Event(113);
                    case 39:
                        return Event(115);
                    case 40:
                        return Event(100);
                    case 41:
                        return Event(102);
                    case 42:
                        return Event(103);
                    case 43:
                        return Event(104);
                    case 44:
                        return Event(106);
                    case 45:
                        return Event(107);
                    case 46:
                        return Event(108);
                    case 47:
                        return Event(109);
                    case 52:
                        return Event(119);
                    case 53:
                        return Event(120);
                    case 54:
                        return Event(99);
                    case 55:
                        return Event(118);
                    case 56:
                        return Event(98);
                    case 57:
                        return Event(110);
                    case 22:
                        return Event(127);
                    case 36:
                        return Event(13);
                    case 9:
                        return Event(27);
                    case 111:
                        return Event(259);
                    case 113:
                        return Event(260);
                    case 116:
                        return Event(258);
                    case 114:
                        return Event(261);
                    case 65:
                        return Event(32);
                    default:
                        return Event(-1);
            }
    }
    return Event(-1);
}
