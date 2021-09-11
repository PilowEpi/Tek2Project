#include "display.hpp"

ASfmlModule::ASfmlModule(int width, int height) :
    width(width),
    height(height)
{
    _backGroundColor = sf::Color(40, 40, 40);
}

void ASfmlModule::display() {
    std::cerr << "module display not init" << std::endl;
    throw;
}

void ASfmlModule::mouse_over(int m_x, int m_y) {
    (void) m_x;
    (void) m_y;
}

void ASfmlModule::mouse_click(int m_x, int m_y) {
    (void) m_x;
    (void) m_y;
}

void ASfmlModule::setWindow(sf::RenderWindow *window, SfmlDisplay *disp) {
    _window = window;
    _sfml = disp;
}

SfmlModuleGraph::SfmlModuleGraph(int width, int height, std::deque<float *> &data, sf::Color *color, int mode) :
    ASfmlModule(width, height),
    _data(data),
    _color(color),
    _mode(mode)
{
}


//data is a deque of float * terminated by -1
//color is an array with a len >= to len(float *)
void SfmlModuleGraph::display() {
    int _x = x + 1;
    int _y = y + 1;
    int _width = width - 2;
    int _height = height - 2;
    {
        sf::RectangleShape rectangle(sf::Vector2f(_width, _height));
        rectangle.setFillColor(_backGroundColor);
        rectangle.setPosition(_x, _y);
        _window->draw(rectangle);
    }
    for (int i = ((int)_data.size() < _width ? _data.size() : _width)-1; i > 1; --i) {
        int val = (_width) - i;
        for (int j = 0; _data[i-1][j] != -1 && _data[i][j] != -1; j++){
            float offset[2] = {0, 0};
            if (_data[i][j] < 0 || _data[i-1][j] < 0)
                    break;
            for (int k = 0; k < 2; k++){
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(_x+val,   _y+_height-_data[i][j]  *_height+k + offset[0]), _color[j]),
                    sf::Vertex(sf::Vector2f(_x+val+1, _y+_height-_data[i-1][j]*_height+k + offset[1]), _color[j])
                };
                offset[0] += _data[i][j];
                offset[1] += _data[i-1][j];
                _window->draw(line, 2, sf::Lines);
            }
        }
    }
}

SfmlModuleText::SfmlModuleText(int width, int height, std::string &data, sf::Color color, std::string path) :
    ASfmlModule(width, height),
    _data(data),
    _color(color)
{
    if (!_font.loadFromFile(path)){
        std::cerr << "cannot load font" << std::endl;
        return;
    }
    int _height = height-2;
    _fontSize = _height-2;
    sf::Text text;
    text.setFont(_font);
    text.setString(_data);
    text.setCharacterSize(_fontSize);
    this->height = text.getGlobalBounds().height > height ? text.getGlobalBounds().height : height;
}

void SfmlModuleText::display() {
    int _x = x + 1;
    int _y = y + 1;
    int _width = width - 2;
    int _height = height - 2;
    {
        sf::RectangleShape rectangle(sf::Vector2f(_width, _height));
        rectangle.setFillColor(_backGroundColor);
        rectangle.setPosition(_x, _y);
        _window->draw(rectangle);
    }
    {
        sf::Text text;
        text.setFont(_font);
        text.setString(_data);
        text.setCharacterSize(_fontSize);
        text.setFillColor(_color);
        text.setPosition((int)(_x+_width/2-text.getGlobalBounds().width/2), (int)_y);
        _window->draw(text);
    }
}

SfmlModuleButton::SfmlModuleButton(int width, int height, std::string &data, void (*func)(SfmlModuleButton &)) :
    SfmlModuleText(width, height, data),
    _func(func),
    _data(data),
    _color(color)
{
    _backGroundColor_not_over = sf::Color(60, 60, 60);
    _backGroundColor_over = sf::Color(100, 100, 100);
}

void SfmlModuleButton::display() {
    SfmlModuleText::display();
    _backGroundColor = _backGroundColor_not_over;
}

void SfmlModuleButton::mouse_click(int m_x, int m_y) {
    (void)m_x;
    (void)m_y;
    _func(*this);
}

void SfmlModuleButton::mouse_over(int m_x, int m_y) {
    (void) m_x; 
    (void) m_y;
    _backGroundColor = _backGroundColor_over;
}

//data is a float array terminated with a -1;
//color is an array with the same len has data
SfmlModuleBar::SfmlModuleBar(int width, int height, float *data, sf::Color *color) :
    ASfmlModule(width, height),
    _data(data),
    _color(color)
{
}

void SfmlModuleBar::display() {
    int _x = x + 1;
    int _y = y + 1;
    int _width = width - 2;
    int _height = height - 2;
    {
        sf::RectangleShape rectangle(sf::Vector2f(_width, _height));
        rectangle.setFillColor(_backGroundColor);
        rectangle.setPosition(_x, _y);
        _window->draw(rectangle);
    }
    int x = _x;
    for (int i = 0; _data[i] != -1; ++i) {
        sf::RectangleShape rectangle(sf::Vector2f((_width) *_data[i], _height));
        rectangle.setFillColor(_color[i]);
        rectangle.setPosition(_x, _y);
        _window->draw(rectangle);
        x += (_width) * _data[i];
    }
}

SfmlDisplay::SfmlDisplay(int win_width, int win_heigh) :
    _width(win_width),
    _height(win_heigh)
{
    _window = new sf::RenderWindow(sf::VideoMode(win_width, win_heigh), "my Top", sf::Style::Close);
    _window->setFramerateLimit(30);
}

SfmlDisplay::~SfmlDisplay() {
    delete _window;
}

bool SfmlDisplay::addModule(ASfmlModule *module) {
    module->setWindow(_window, this);

    if (module->x == -1 || module->y == -1){
        int x = 0;
        int y = 0;
        int height = 0;
        for (ASfmlModule *mod : _modules) {
            if (!mod->_isDisplayed)
                continue;
            if (y < mod->y) {
                y = mod->y;
                x = mod->x + mod->width;
                height = mod->height;
            } else if (y == mod->y){
                x = x > mod->x+mod->width ? x : mod->x+mod->width;
                height = height > mod->height ? height : mod->height;
            }
        }
        if (x+module->width > _width){
            y += height;
            x = 0;
        }
        module->x = x;
        module->y = y;
        if (module->_isDisplayed)
            _height = y + module->height;
    }
    _modules.push_back(module);
    return true;
}

void SfmlDisplay::reorganizeModules() {
    std::deque<ASfmlModule*> mods = _modules;
    _modules.clear();
    for (ASfmlModule *mod : mods) {
        mod->x = -1;
        mod->y = -1;
        addModule(mod);
    }
}

bool SfmlDisplay::display() {
    if (!_window->isOpen())
        return false;
    if ((int)_window->getSize().y != _height){
        _window->setSize(sf::Vector2u(_width, _height));
        display();
    }
    //pool event
    sf::Event event;
    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window->close();
        if (event.type == sf::Event::MouseButtonPressed) {
            for (ASfmlModule *mod : _modules){
                auto m = event.mouseButton;
                if (mod->x < m.x && m.x < mod->x + mod->width && mod->y < m.y && m.y < mod->y + mod->height)
                    mod->mouse_click(mod->x - m.x, mod->y - m.y);
            }
        }
        if (event.type == sf::Event::Resized) {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            _window->setView(sf::View(visibleArea));
        }
    }

    sf::Vector2i m = sf::Mouse::getPosition(*_window);
    for (ASfmlModule *mod : _modules){
        if (mod->x < m.x && m.x < mod->x + mod->width && mod->y < m.y && m.y < mod->y + mod->height) {
            mod->mouse_over(mod->x - m.x, mod->y - m.y);
        }
    }
    _window->clear();
    for (ASfmlModule *mod : _modules)
        if (mod->_isDisplayed)
            mod->display();
    _window->display();
    return true;
}

void SfmlDisplay::activateById(std::string id, bool status)
{
    for (ASfmlModule *mod : _modules)
        if (mod->_id == id){
            mod->_isDisplayed = status;
        }
}


void SfmlDisplay::main_loop(std::list<AMonitorModule *> modules)
{
    sfmlLoop(modules);
}
