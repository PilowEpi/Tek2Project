

#include <unistd.h>
#include <SFML/Graphics.hpp>

#include "arcade.hpp"
#include "sfml.hpp"

extern "C" SFML* ctor()
{
    return new SFML;
}

extern "C" std::string getLibName()
{
    return (std::string("SFML"));
}

extern "C" int getLibType()
{
    return (0);
}

void SFML::init(int x, int y)
{
    window.create(sf::VideoMode(x * PIXELSIZE, y * PIXELSIZE), "My window");

    _font.loadFromFile("fonts/Roboto-Black.ttf");
    _x = x;
    _y = y;
}

void SFML::stop()
{
    window.close();
}

void SFML::drawSquare(Square *shape) {
    sf::RectangleShape rect(sf::Vector2f{float(shape->size.x * PIXELSIZE), float(shape->size.y * PIXELSIZE)});
    rect.setFillColor(sf::Color{shape->color.r, shape->color.g, shape->color.b});
    rect.setPosition(sf::Vector2f{float(shape->pos.x * PIXELSIZE), float(shape->pos.y * PIXELSIZE)});
    window.draw(rect);
}

void SFML::drawCircle(Circle *) {}

void SFML::drawText(Text *shape) {
    sf::Text text(shape->text, _font, PIXELSIZE);
    text.setPosition(sf::Vector2f{float(shape->pos.x * 16), float(shape->pos.y * 16)});
    text.setFillColor(sf::Color(shape->color.r, shape->color.g, shape->color.b));
    window.draw(text);
}

void SFML::drawLine(Line *shape) {
    sf::RectangleShape line(sf::Vector2f{float(shape->d.x * PIXELSIZE), float(PIXELSIZE)});
    line.setPosition(sf::Vector2f{float(shape->pos.x * PIXELSIZE), float(shape->pos.y * PIXELSIZE)});
    line.setFillColor(sf::Color(shape->color.r, shape->color.g, shape->color.b));
    window.draw(line);
}

void SFML::drawPixel(int x, int y, Color color) {
    sf::RectangleShape rect(sf::Vector2f{float(PIXELSIZE), float(PIXELSIZE)});
    rect.setPosition(sf::Vector2f{float(x), float(y)});
    rect.setFillColor(sf::Color(color.r, color.g, color.b));
    window.draw(rect);
}

void SFML::drawShape(IObject *obj) {
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
    
void SFML::refresh() {
    window.display();
    window.clear();
}

    // Event
Event SFML::getEvent() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                    case sf::Keyboard::Key::A:
                        return Event(97);
                    case sf::Keyboard::Key::Z:
                        return Event(122);
                    case sf::Keyboard::Key::E:
                        return Event(101);
                    case sf::Keyboard::Key::R:
                        return Event(114);
                    case sf::Keyboard::Key::T:
                        return Event(116);
                    case sf::Keyboard::Key::Y:
                        return Event(121);
                    case sf::Keyboard::Key::U:
                        return Event(117);
                    case sf::Keyboard::Key::I:
                        return Event(105);
                    case sf::Keyboard::Key::O:
                        return Event(111);
                    case sf::Keyboard::Key::P:
                        return Event(112);
                    case sf::Keyboard::Key::Q:
                        return Event(113);
                    case sf::Keyboard::Key::S:
                        return Event(115);
                    case sf::Keyboard::Key::D:
                        return Event(100);
                    case sf::Keyboard::Key::F:
                        return Event(102);
                    case sf::Keyboard::Key::G:
                        return Event(103);
                    case sf::Keyboard::Key::H:
                        return Event(104);
                    case sf::Keyboard::Key::J:
                        return Event(106);
                    case sf::Keyboard::Key::K:
                        return Event(107);
                    case sf::Keyboard::Key::L:
                        return Event(108);
                    case sf::Keyboard::Key::M:
                        return Event(109);
                    case sf::Keyboard::Key::W:
                        return Event(119);
                    case sf::Keyboard::Key::X:
                        return Event(120);
                    case sf::Keyboard::Key::C:
                        return Event(99);
                    case sf::Keyboard::Key::V:
                        return Event(118);
                    case sf::Keyboard::Key::B:
                        return Event(98);
                    case sf::Keyboard::Key::N:
                        return Event(110);
                    case sf::Keyboard::Key::BackSpace:
                        return Event(127);
                    case sf::Keyboard::Key::Return:
                        return Event(13);
                    case sf::Keyboard::Key::Escape:
                        return Event(27);
                    case sf::Keyboard::Key::Up:
                        return Event(259);
                    case sf::Keyboard::Key::Left:
                        return Event(260);
                    case sf::Keyboard::Key::Down:
                        return Event(258);
                    case sf::Keyboard::Key::Right:
                        return Event(261);
                    case sf::Keyboard::Key::Space:
                        return Event(32);
                    default:
                        return Event(-1);
            }
        }
    }
    return Event(-1);
}
