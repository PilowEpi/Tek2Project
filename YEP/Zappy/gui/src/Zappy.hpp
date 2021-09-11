/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** Zappy
*/

#ifndef _ZAPPY_HPP
#define _ZAPPY_HPP

#include <vector>
#include <iostream>
#include <cstring>
#include <memory>
#include <thread>
#include <chrono>
#include <err.h>
#include <fstream>

#include "entityComponent/Manager.hpp"
#include "BtnFuncs.hpp"
#include "ZappyGui.hpp"
#include "messageManager/MessageManager.hpp"
#include "Storage.hpp"
#include "Error.hpp"

#define GUI_MAGIC ("ZAPPY_GUI")

class ComponentManager;

class allTexture
{
    public:
        std::shared_ptr<rl::Texture> _btn; // Btn texture
        std::shared_ptr<rl::Font> _ft; // Minecraft font
        std::shared_ptr<rl::Font> _ftbroad; // Minecraft font
        std::shared_ptr<rl::Sound> _click;
        std::shared_ptr<rl::Model> _dirt; // dirt Model
        std::shared_ptr<rl::Texture> _block; // iron block
        std::shared_ptr<rl::Texture> _egg; // egg block
        std::shared_ptr<std::vector<std::shared_ptr<rl::Model>>> _walking; // Walking Animation
        std::shared_ptr<std::vector<std::shared_ptr<rl::Texture>>> _skins; // Walking Animation
        std::shared_ptr<rl::Texture> _food; // food block
        rl::Mesh _cube_mesh = {1, 1, 1};
};

class Zappy
{
    public:
        Zappy(int port, std::string machineName);
        ~Zappy();
                
        void launch();

        rl::Window *_win;
        Storage *_stock;
        ComponentManager *_manager;
        MessageManager *_logs;
        allTexture _t;
        bool _ending = false;
    private:
        void startLoading();
        void createUI();
        void preLoad();
        void callBaseMsg();
};

#endif