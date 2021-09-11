
#include <irrlicht/irrlicht.h>
#include <unistd.h>

#include "arcade.hpp"
#include "irrlicht.hpp"

extern "C" Irrlicht* ctor()
{
    return new Irrlicht;
}

extern "C" std::string getLibName()
{
    return (std::string("Irrlicht"));
}

extern "C" int getLibType()
{
    return (0);
}

void Irrlicht::init(int x, int y)
{
    _x = x;
    _y = y;
    eventReceiver = IrrlichtEventReceiver();
    device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(x * PIXELSIZE, y * PIXELSIZE), 16, false, false, false, &eventReceiver);
    device->setWindowCaption(L"Irrlicht Window");
    driver = device->getVideoDriver();
    font = device->getGUIEnvironment()->getBuiltInFont();
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();
    device->run();
    driver->beginScene(true, true, irr::video::SColor(255, 0, 0, 0));
}

void Irrlicht::stop()
{  
    device->drop();
}

void Irrlicht::drawSquare(Square *shape) {
    irr::video::SColor color(255, shape->color.r, shape->color.g, shape->color.b);
    irr::core::recti pos(shape->pos.x * PIXELSIZE, shape->pos.y * PIXELSIZE, (shape->pos.x + shape->size.x) * PIXELSIZE, (shape->pos.y + shape->size.y) * PIXELSIZE);
    driver->draw2DRectangle(color, pos);
}

void Irrlicht::drawCircle(Circle *) {}

void Irrlicht::drawText(Text *shape) {
    irr::video::SColor color(255, shape->color.r, shape->color.g, shape->color.b);
    irr::core::recti pos(shape->pos.x * PIXELSIZE, shape->pos.y * PIXELSIZE, 0, 0);
    font->draw(shape->text.c_str(), pos, color);
}

void Irrlicht::drawLine(Line *shape) {
    irr::video::SColor color(255, shape->color.r, shape->color.g, shape->color.b);
    irr::core::recti pos(shape->pos.x * PIXELSIZE, shape->pos.y * PIXELSIZE, (shape->pos.x + shape->d.x) * PIXELSIZE, (shape->pos.y + shape->d.y + 1) * PIXELSIZE);
    driver->draw2DRectangle(color, pos);
}

void Irrlicht::drawPixel(int x, int y, Color color) {
    irr::video::SColor ircolor(255, color.r, color.g, color.b);
    irr::core::recti pos(x * PIXELSIZE, y * PIXELSIZE, (x + 1) * PIXELSIZE, (y + 1) * PIXELSIZE);
    driver->draw2DRectangle(ircolor, pos);
}

void Irrlicht::drawShape(IObject *obj) {
    Square *square = dynamic_cast<Square *>(obj);
    Line *line = dynamic_cast<Line *>(obj);
    Text *txt = dynamic_cast<Text *>(obj);

    if (txt)
        this->drawText(txt);
    else if (square)
        this->drawSquare(square);
    else if (line)
        this->drawLine(line);
}
    
void Irrlicht::refresh() {
    driver->endScene();
    device->run();
    driver->beginScene(true, true, irr::video::SColor(0, 0, 0, 1));
}

    // Event
Event Irrlicht::getEvent() {
    if (eventReceiver.lastKeyPressed == -1)
        return Event(-1);
    int key = eventReceiver.lastKeyPressed;
    eventReceiver.lastKeyPressed = -1;
    std::cout << "Key pressed : " << key << std::endl;
    switch (key) {
                    case irr::KEY_KEY_A:
                        return Event(97);
                    case irr::KEY_KEY_Z:
                        return Event(122);
                    case irr::KEY_KEY_E:
                        return Event(101);
                    case irr::KEY_KEY_R:
                        return Event(114);
                    case irr::KEY_KEY_T:
                        return Event(116);
                    case irr::KEY_KEY_Y:
                        return Event(121);
                    case irr::KEY_KEY_U:
                        return Event(117);
                    case irr::KEY_KEY_I:
                        return Event(105);
                    case irr::KEY_KEY_O:
                        return Event(111);
                    case irr::KEY_KEY_P:
                        return Event(112);
                    case irr::KEY_KEY_Q:
                        return Event(113);
                    case irr::KEY_KEY_S:
                        return Event(115);
                    case irr::KEY_KEY_D:
                        return Event(100);
                    case irr::KEY_KEY_F:
                        return Event(102);
                    case irr::KEY_KEY_G:
                        return Event(103);
                    case irr::KEY_KEY_H:
                        return Event(104);
                    case irr::KEY_KEY_J:
                        return Event(106);
                    case irr::KEY_KEY_K:
                        return Event(107);
                    case irr::KEY_KEY_L:
                        return Event(108);
                    case irr::KEY_KEY_M:
                        return Event(109);
                    case irr::KEY_KEY_W:
                        return Event(119);
                    case irr::KEY_KEY_X:
                        return Event(120);
                    case irr::KEY_KEY_C:
                        return Event(99);
                    case irr::KEY_KEY_V:
                        return Event(118);
                    case irr::KEY_KEY_B:
                        return Event(98);
                    case irr::KEY_KEY_N:
                        return Event(110);
                    case irr::KEY_BACK:
                        return Event(127);
                    case irr::KEY_RETURN:
                        return Event(13);
                    case irr::KEY_ESCAPE:
                        return Event(27);
                    case irr::KEY_UP:
                        return Event(259);
                    case irr::KEY_LEFT:
                        return Event(260);
                    case irr::KEY_DOWN:
                        return Event(258);
                    case irr::KEY_RIGHT:
                        return Event(261);
                    case irr::KEY_SPACE:
                        return Event(32);
                    default:
                        return Event(-1);
    }
    return Event(key);
}
