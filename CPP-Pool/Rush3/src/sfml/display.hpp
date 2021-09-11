#ifndef _SFMLDISPLAY_H_
#define _SFMLDISPLAY_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <deque>
#include <list>

#include "IMonitorModule.hpp"
#include "AMonitorModule.hpp"
#include "AMonitorDisplay.hpp"

void sfmlLoop(std::list<AMonitorModule *> &modules);

class SfmlDisplay;
class sfmlModuleButton;

class ASfmlModule {
public:
    enum Type {
        TEXT,
        GRAPHIC,
        BAR
    };
    ASfmlModule(int width, int height);
    virtual void display();
    virtual void mouse_over(int m_x, int m_y);

    virtual void mouse_click(int m_x, int m_y);

    void setWindow(sf::RenderWindow *window, SfmlDisplay *disp);

    sf::Color _backGroundColor;
    sf::RenderWindow *_window;
    int width;
    int height;
    int color;
    bool _isDisplayed = true;
    SfmlDisplay *_sfml;
    int x = -1;
    int y = -1;
    std::string _id = "";
};

class SfmlModuleGraph : public ASfmlModule {
public:
    SfmlModuleGraph(int width, int height, std::deque<float *> &data, sf::Color *color, int mode = 0);

    void display() override;

    std::deque<float *> &_data;
    sf::Color *_color;
    int _mode;
};

class SfmlModuleText : public ASfmlModule {
public:
    SfmlModuleText(int width, int height, std::string &data, sf::Color color = {255, 255, 255}, std::string path = "src/sfml/font/font.TTF");
    void display() override;

    sf::Font _font;
    int _fontSize;
    std::string &_data;
    sf::Color _color;
};

class SfmlModuleButton : public SfmlModuleText {
public:
    SfmlModuleButton(int width, int height, std::string &data, void (*func)(SfmlModuleButton &));

    void display() override;

    void mouse_click(int m_x, int m_y) override;

    void mouse_over(int m_x, int m_y) override;

    sf::Color _backGroundColor_over;
    sf::Color _backGroundColor_not_over;
    void (*_func)(SfmlModuleButton &);
    sf::Font _font;
    int _fontSize;
    std::string &_data;
    sf::Color _color;
};

//data is a float array terminated with a -1;
//color is an array with the same len has data
class SfmlModuleBar : public ASfmlModule {
public:
    SfmlModuleBar(int width, int height, float *data, sf::Color *color);
    void display() override;

    float *_data;
    sf::Color *_color;
};

class SfmlDisplay : public AMonitorDisplay {
public:
    SfmlDisplay(int win_width = 400, int win_heigh = 100);

    ~SfmlDisplay();

    bool addModule(ASfmlModule *module);

    void main_loop(std::list<AMonitorModule *> modules) override;

    void reorganizeModules();

    bool display();

    void activateById(std::string id, bool status);

    std::deque<ASfmlModule *> getModules() { return _modules;}

    int _width;
    int _height;
    std::deque<ASfmlModule *> _modules;
    sf::RenderWindow *_window;
};

#endif
