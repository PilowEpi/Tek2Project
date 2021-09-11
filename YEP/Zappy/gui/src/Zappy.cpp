/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** Zappy
*/

#include "Zappy.hpp"
#include <sstream>

Zappy::Zappy(int port, std::string machineName)
{
    std::cout << "Port : " << port << std::endl;
    std::cout << "Machine Name : " << machineName << std::endl;

    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    _win = new rl::Window(800, 600, "Zappy GUI");
    _win->changeFps(60);
    rl::Window::SetExitKey(-1);
    _stock = new Storage();
    preLoad();
    createUI();
    _logs = new MessageManager(port, machineName);
}

Zappy::~Zappy()
{
    delete _win;
    delete _manager;
    delete _logs;
}

void Zappy::startLoading()
{
    std::unique_ptr<rl::Texture> logo = std::make_unique<rl::Texture>("gui/assets/menus/noui.png");
    while (!_win->ShouldClose()) {
        _win->beginDrawing();
        _win->clearBackground(rl::Color(255, 255, 255, 255));
        logo->draw(0, 0, rl::Color(255, 255, 255, 255));
        _win->endDrawing();
        break;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Zappy::launch()
{
    callBaseMsg();
    while (!_win->ShouldClose() && !_ending) {
        _logs->catchMessage();
        _logs->handleMessage(this);
        _win->beginDrawing();
        ClearBackground(Color{255, 255, 255, 255});
        _win->clearBackground(rl::Color(255, 255, 255, 255));
        _manager->manageCamera();
        _manager->handleEvent("");
        _manager->simulate();
        _manager->renderAll();
        _win->endDrawing();
        _logs->retrieveInfo(_stock->_idMax);
    }
}

void Zappy::callBaseMsg()
{
    _logs->callServer(GUI_MAGIC);
    _logs->callServer("tna");
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    _logs->callServer("msz");
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    _logs->callServer("mct");
    _logs->catchMessage();
    _logs->handleMessage(this);
}

/*
0 = HOME
1 = OPTIONS
2 = MAP
*/
void Zappy::createUI()
{
    _manager->addComponent(std::make_shared<Btn>(rl::Vec2(1.0 / 2, 5.0 / 20), rl::Vec2(0.0, 0.0), "ZappyGui", 24, rl::Rectangle(0, 0, 400, 40), _t._click, 0, this, &(BF::playBtn), (void *)0, _t._btn, _t._ft), 0);
    _manager->addComponent(std::make_shared<Btn>(rl::Vec2(1.0 / 2, 5.0 / 20), rl::Vec2(0.0, 100.0), "Options", 24, rl::Rectangle(400, 0, 196, 40), _t._click, 0, this, &(BF::optBtn), (void *)0, _t._btn, _t._ft), 0);
    _manager->addComponent(std::make_shared<Btn>(rl::Vec2(1.0 / 2, 5.0 / 20), rl::Vec2(0.0, 200.0), "Quit ZappyGui", 24, rl::Rectangle(0, 0, 400, 40), _t._click, 0, this, &(BF::quitBtn), (void *)0, _t._btn, _t._ft), 0);
    _manager->addComponent(std::make_shared<Btn>(rl::Vec2(1.0 / 2, 5.0 / 20), rl::Vec2(0.0, 60.0), "Resolution: 800 x 600", 24, rl::Rectangle(0, 0, 400, 40), _t._click, 1, this, &(BF::resolutionBtn), (void *)0, _t._btn, _t._ft), 1);
    _manager->addComponent(std::make_shared<Btn>(rl::Vec2(1.0 / 2, 5.0 / 20), rl::Vec2(0.0, 200.0), "Back to Home", 24, rl::Rectangle(0, 0, 400, 40), _t._click, 1, this, &(BF::backToHome), (void *)0, _t._btn, _t._ft), 1);
    _manager->addComponent(std::make_shared<Btn>(rl::Vec2(1.0 / 2, 19.0 / 20), rl::Vec2(0.0, 0.0), "North", 24, rl::Rectangle(0, 0, 400, 40), _t._click, 2, this, &(BF::directionBtn), (void *)0, _t._btn, _t._ft), 2);
    _manager->addComponent(std::make_shared<Menu>(rl::Vec2(1.0, 0.0), rl::Vec2(-200.0, 0.0), this, 200, _t._ft, _stock->_logs), 2);
    _manager->addComponent(std::make_shared<Info>(2, this, _t._ft), 2);
    _manager->addComponent(std::make_shared<Help>(2, this, _t._ft), 2);
}

void Zappy::preLoad()
{
    _manager = new ComponentManager(this);
    rl::Sound::InitAudioDevice(); // Init audio

    _t._btn = std::make_shared<rl::Texture>("gui/assets/menus/btns.png");
    _t._ft = std::make_shared<rl::Font>("gui/assets/minecraftia.ttf");
    _t._ftbroad = std::make_shared<rl::Font>("gui/assets/minecraftia.ttf");
    _t._click = std::make_shared<rl::Sound>("gui/assets/musics/click.wav");
    _t._dirt = std::make_shared<rl::Model>("gui/assets/block/dirt.glb");
    _t._block = std::make_shared<rl::Texture>("gui/assets/block/iron.png");
    _t._food = std::make_shared<rl::Texture>("gui/assets/block/food.png");
    _t._egg = std::make_shared<rl::Texture>("gui/assets/block/egg.png");
    _t._walking = std::make_shared<std::vector<std::shared_ptr<rl::Model>>>();
    _t._skins = std::make_shared<std::vector<std::shared_ptr<rl::Texture>>>();

    std::ostringstream objPath("");

    for (int i = 1; i < 41; i++) {
        if (i < 10)
            objPath << "gui/assets/player/model/steve_0" << i << ".glb";
        else
            objPath << "gui/assets/player/model/steve_" << i << ".glb";
        _t._walking->push_back(std::make_shared<rl::Model>(objPath.str().c_str()));
        objPath.str("");
        objPath.clear();
    }

    for (int i = 1; i <= 8; i++) {
        objPath << "gui/assets/player/skin/skin_0" << i << ".png";
        std::cout << objPath.str() << std::endl;
        _t._skins->push_back(std::make_shared<rl::Texture>(objPath.str()));
        objPath.str("");
        objPath.clear();
    }
}
