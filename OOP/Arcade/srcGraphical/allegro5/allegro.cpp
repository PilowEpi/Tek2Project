
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <unistd.h>

#include "arcade.hpp"
#include "allegro.hpp"

extern "C" Allegro* ctor()
{
    return new Allegro;
}

extern "C" std::string getLibName()
{
    return (std::string("Allegro"));
}

extern "C" int getLibType()
{
    return (0);
}

void Allegro::init(int x, int y)
{
    _x = x;
    _y = y;
    al_init();
    al_install_keyboard();
    window = al_create_display(x * PIXELSIZE, y * PIXELSIZE);
    font = al_create_builtin_font();
    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_init_primitives_addon();
}

void Allegro::stop()
{
    al_destroy_font(font);
    al_destroy_display(window);
    al_destroy_event_queue(queue);
}

void Allegro::drawSquare(Square *shape) {
    ALLEGRO_COLOR color = {float(shape->color.r / 255.0f), float(shape->color.g / 255.0f), float(shape->color.b / 255.0f), 1.0};
    al_draw_filled_rectangle(shape->pos.x * PIXELSIZE, shape->pos.y * PIXELSIZE, (shape->pos.x + shape->size.x) * PIXELSIZE, (shape->pos.y + shape->size.y) * PIXELSIZE, color);
}

void Allegro::drawCircle(Circle *) {}

void Allegro::drawText(Text *shape) {
    ALLEGRO_COLOR color = {float(shape->color.r / 255.0f), float(shape->color.g / 255.0f), float(shape->color.b / 255.0f), 1.0};
    al_draw_text(font, color, shape->pos.x * PIXELSIZE, shape->pos.y * PIXELSIZE, 0, shape->text.c_str());
}

void Allegro::drawLine(Line *shape) {
    ALLEGRO_COLOR color = {float(shape->color.r / 255.0f), float(shape->color.g / 255.0f), float(shape->color.b / 255.0f), 1.0};
    al_draw_filled_rectangle(shape->pos.x * PIXELSIZE, shape->pos.y * PIXELSIZE, (shape->pos.x + shape->d.x) * PIXELSIZE, (shape->pos.y + shape->d.y + 1) * PIXELSIZE, color);
}

void Allegro::drawPixel(int x, int y, Color color) {
    ALLEGRO_COLOR alcolor = {float(color.r / 255.0f), float(color.g / 255.0f), float(color.b / 255.0f), 1.0};
    al_draw_filled_rectangle(x * PIXELSIZE, y * PIXELSIZE, x * (PIXELSIZE + 1), y * (PIXELSIZE + 1), alcolor);
}

void Allegro::drawShape(IObject *obj) {
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
    
void Allegro::refresh() {
    al_flip_display();
    al_clear_to_color(al_map_rgb(0, 0, 0));
}

    // Event
Event Allegro::getEvent() {
    ALLEGRO_EVENT event;
    if (al_get_next_event(queue, &event)) {
        switch (event.type) {
            case ALLEGRO_EVENT_KEY_DOWN:
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_A:
                        return Event(97);
                    case ALLEGRO_KEY_Z:
                        return Event(122);
                    case ALLEGRO_KEY_E:
                        return Event(101);
                    case ALLEGRO_KEY_R:
                        return Event(114);
                    case ALLEGRO_KEY_T:
                        return Event(116);
                    case ALLEGRO_KEY_Y:
                        return Event(121);
                    case ALLEGRO_KEY_U:
                        return Event(117);
                    case ALLEGRO_KEY_I:
                        return Event(105);
                    case ALLEGRO_KEY_O:
                        return Event(111);
                    case ALLEGRO_KEY_P:
                        return Event(112);
                    case ALLEGRO_KEY_Q:
                        return Event(113);
                    case ALLEGRO_KEY_S:
                        return Event(115);
                    case ALLEGRO_KEY_D:
                        return Event(100);
                    case ALLEGRO_KEY_F:
                        return Event(102);
                    case ALLEGRO_KEY_G:
                        return Event(103);
                    case ALLEGRO_KEY_H:
                        return Event(104);
                    case ALLEGRO_KEY_J:
                        return Event(106);
                    case ALLEGRO_KEY_K:
                        return Event(107);
                    case ALLEGRO_KEY_L:
                        return Event(108);
                    case ALLEGRO_KEY_M:
                        return Event(109);
                    case ALLEGRO_KEY_W:
                        return Event(119);
                    case ALLEGRO_KEY_X:
                        return Event(120);
                    case ALLEGRO_KEY_C:
                        return Event(99);
                    case ALLEGRO_KEY_V:
                        return Event(118);
                    case ALLEGRO_KEY_B:
                        return Event(98);
                    case ALLEGRO_KEY_N:
                        return Event(110);
                    case ALLEGRO_KEY_BACKSPACE:
                        return Event(127);
                    case ALLEGRO_KEY_ENTER:
                        return Event(13);
                    case ALLEGRO_KEY_ESCAPE:
                        return Event(27);
                    case ALLEGRO_KEY_UP:
                        return Event(259);
                    case ALLEGRO_KEY_LEFT:
                        return Event(260);
                    case ALLEGRO_KEY_DOWN:
                        return Event(258);
                    case ALLEGRO_KEY_RIGHT:
                        return Event(261);
                    case ALLEGRO_KEY_SPACE:
                        return Event(32);
                    default:
                        return Event(-1);
                }
                return Event(event.keyboard.keycode);
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                return Event(27);
        }
    }
    return Event(-1);
}

/*
case 58:
                    return Event(13);
                case sf::Keyboard::Key::Escape:
                    return Event(27);
                case sf::Keyboard::Key::O:
                    return Event(111);
                case sf::Keyboard::Key::L:
                    return Event(108);
                case sf::Keyboard::Key::P:
                    return Event(112);
                case sf::Keyboard::Key::M:
                    return Event(109);
*/