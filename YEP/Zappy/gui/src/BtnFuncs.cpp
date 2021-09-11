/*
** EPITECH PROJECT, 2021
** YEP Zappy
** File description:
** BtnFuncs
*/

#include "BtnFuncs.hpp"

void BF::setMusic(Zappy *win, Slider *s, void *data)
{
    float vol = s->_cpos.x * 1.0534;

    (void)data;
    win->_manager->_settings._mVol = vol;
    s->_text = std::string(std::string("Musics: ") + std::to_string((int)(vol * 100)) + "%");
}

void BF::setSound(Zappy *win, Slider *s, void *data)
{
    float vol = s->_cpos.x * 1.0534;

    (void)data;
    win->_manager->_settings._sVol = vol;
    s->_text = std::string(std::string("Sounds: ") + std::to_string((int)(vol * 100)) + "%");
}

void BF::resolutionBtn(Zappy *win, Btn *b, void *data)
{
    const int widths[] = {800, 1280, 1600, 1920};
    const int heights[] = {600, 720, 900, 1080};
    const std::string texts[] = {" 800 x 600", " 1280 x 720", " 1600 x 900", " 1920 x 1080"};
    int cur = win->_win->getScreenWidth();
    int x = 0;

    (void)data;
    for (auto w : widths) {
        if (w == cur)
            break;
        x++;
    }
    x = (x + 1) % 4;
    win->_win->setWindowSize(widths[x], heights[x]);
    win->_manager->_settings._width = widths[x];
    win->_manager->_settings._height = heights[x];
    b->_text = std::string("Resolution:") + texts[x];
}

void BF::directionBtn(Zappy *win, Btn *b, void *data)
{
    const std::string texts[] = {"North", "Weast", "South", "East"};
    std::string cur = win->_manager->_settings._orientation;
    int x = 0;
    
    (void)data;
    for (auto dir : texts) {
        if (dir == cur)
            break;
        x++;
    }
    x = (x + 1) % 4;
    win->_manager->_settings._orientation = texts[x];
    b->_text = texts[x];
}

void BF::switchScene(Zappy *win, int scene)
{
    win->_manager->_settings._scene = scene;
}

void BF::quitBtn(Zappy *win, Btn *b, void *data)
{
    (void)b;
    (void)data;
    win->_ending = true;
}

void BF::playBtn(Zappy *win, Btn *b, void *data)
{
    (void)data; 
    (void)b;
    switchScene(win, 2);
    
    win->_manager->manageCamera();
}

void BF::backToHome(Zappy *win, Btn *b, void *data)
{
    (void)data; 
    (void)b;
    switchScene(win, 0);
}

void BF::optBtn(Zappy *win, Btn *b, void *data)
{
    (void)b;
    (void)data;
    switchScene(win, 1);
}

