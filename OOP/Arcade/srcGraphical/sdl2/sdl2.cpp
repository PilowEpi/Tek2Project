
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "arcade.hpp"
#include "sdl2.hpp"

extern "C" SDL2* ctor()
{
    return new SDL2;
}

extern "C" std::string getLibName()
{
    return (std::string("SDL2"));
}

extern "C" int getLibType()
{
    return (0);
}

void SDL2::init(int x, int y)
{
    x *= PIXELSIZE;
    y *= PIXELSIZE;
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Error while initilizing SDL2 : " << SDL_GetError() << std::endl;
        return;
    }

    _window = SDL_CreateWindow(
        "SDL2 Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        x, y,
        0
    );

    int w;
    int h;
    SDL_GetWindowSize(_window, &w, &h);
    std::cout << "Window width: " << w << ", height : " << h << std::endl;
    std::cout << "Original Size : " << x / PIXELSIZE << "/" << y / PIXELSIZE << std::endl;

    if(!_window) {
        std::cerr << "Error while initilizing SDL2 window : " << SDL_GetError() << std::endl;
        return;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    if(!_window) {
        std::cerr << "Error while initilizing SDL2 renderer : " << SDL_GetError() << std::endl;
        return;
    }

    this->_x = x;
    this->_y = y;


    if (TTF_Init() < 0) {
        std::cerr << "Error whil initilizing SDL2_ttf : " << TTF_GetError() << std::endl;
        return;
    }

    _font = TTF_OpenFont("fonts/Roboto-Black.ttf", PIXELSIZE);
}

void SDL2::stop() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    TTF_CloseFont(_font);
    SDL_Quit();
    TTF_Quit();
}

void SDL2::drawSquare(Square *shape) {
    SDL_Rect rect = {shape->pos.x * PIXELSIZE, shape->pos.y * PIXELSIZE, shape->size.x * PIXELSIZE, shape->size.y * PIXELSIZE};
    SDL_SetRenderDrawColor(_renderer, shape->color.r, shape->color.g, shape->color.b, 1);
    SDL_RenderFillRect(_renderer, &rect);
}

void SDL2::drawCircle(Circle *) {}

void SDL2::drawText(Text *shape) {
    SDL_Color color = {shape->color.r, shape->color.g, shape->color.b, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(_font, shape->text.c_str(), color);
    if (!surface)
        return;
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
    if (!texture)
        return;
    SDL_Rect possize = {shape->pos.x * PIXELSIZE, shape->pos.y * PIXELSIZE, surface->w, surface->h};
    SDL_RenderCopy(_renderer, texture, NULL, &possize);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void SDL2::drawLine(Line *shape) {
    SDL_SetRenderDrawColor(_renderer, shape->color.r, shape->color.g, shape->color.b, 1);
    int width = shape->d.x * PIXELSIZE;
    int height = PIXELSIZE;
    SDL_Rect rect = {shape->pos.x * PIXELSIZE, shape->pos.y * PIXELSIZE, shape->pos.x + width, shape->pos.y + height};
    SDL_RenderFillRect(_renderer, &rect);
}

void SDL2::drawPixel(int x, int y, Color c) {
    SDL_SetRenderDrawColor(_renderer, c.r, c.g, c.b, 1);
    SDL_RenderDrawPoint(_renderer, x, y);
}

void SDL2::drawShape(IObject *obj) {
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
    
void SDL2::refresh() {
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 1);
    SDL_RenderPresent(_renderer);
    SDL_RenderClear(_renderer);
}

    // Event
Event SDL2::getEvent() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return (Event(27));
        }
        if (event.type == SDL_KEYDOWN) {
            switch(event.key.keysym.scancode) {
                    case SDL_SCANCODE_A:
                        return Event(97);
                    case SDL_SCANCODE_Z:
                        return Event(122);
                    case SDL_SCANCODE_E:
                        return Event(101);
                    case SDL_SCANCODE_R:
                        return Event(114);
                    case SDL_SCANCODE_T:
                        return Event(116);
                    case SDL_SCANCODE_Y:
                        return Event(121);
                    case SDL_SCANCODE_U:
                        return Event(117);
                    case SDL_SCANCODE_I:
                        return Event(105);
                    case SDL_SCANCODE_O:
                        return Event(111);
                    case SDL_SCANCODE_P:
                        return Event(112);
                    case SDL_SCANCODE_Q:
                        return Event(113);
                    case SDL_SCANCODE_S:
                        return Event(115);
                    case SDL_SCANCODE_D:
                        return Event(100);
                    case SDL_SCANCODE_F:
                        return Event(102);
                    case SDL_SCANCODE_G:
                        return Event(103);
                    case SDL_SCANCODE_H:
                        return Event(104);
                    case SDL_SCANCODE_J:
                        return Event(106);
                    case SDL_SCANCODE_K:
                        return Event(107);
                    case SDL_SCANCODE_L:
                        return Event(108);
                    case SDL_SCANCODE_M:
                        return Event(109);
                    case SDL_SCANCODE_W:
                        return Event(119);
                    case SDL_SCANCODE_X:
                        return Event(120);
                    case SDL_SCANCODE_C:
                        return Event(99);
                    case SDL_SCANCODE_V:
                        return Event(118);
                    case SDL_SCANCODE_B:
                        return Event(98);
                    case SDL_SCANCODE_N:
                        return Event(110);
                    case SDL_SCANCODE_BACKSPACE:
                        return Event(127);
                    case SDL_SCANCODE_RETURN:
                        return Event(13);
                    case SDL_SCANCODE_ESCAPE:
                        return Event(27);
                    case SDL_SCANCODE_UP:
                        return Event(259);
                    case SDL_SCANCODE_LEFT:
                        return Event(260);
                    case SDL_SCANCODE_DOWN:
                        return Event(258);
                    case SDL_SCANCODE_RIGHT:
                        return Event(261);
                    case SDL_SCANCODE_SPACE:
                        return Event(32);
                    default:
                        return Event(-1);
            }
        }
        return Event(-1);
    }
    return Event(-1);
}
