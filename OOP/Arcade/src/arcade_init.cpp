/*
** EPITECH PROJECT, 2020
** OOP Arcade
** File description:
** main
*/

#include <dlfcn.h>
#include <err.h>

#include <vector>
#include <map>
#include <algorithm>
#include <filesystem>

#include "error.hpp"
#include "carcade.hpp"
#include "game.hpp"
#include "shared.hpp"

namespace fs = std::filesystem;

IGameModule *Arcade::loadGame(const char *path)
{
    void *handle = dlopen(path, RTLD_LAZY);

    if (!handle)
        throw LibraryError(dlerror());

    IGameModule *(*load)(void) = (IGameModule *(*)(void)) dlsym(handle, "ctor");

    char *error = dlerror();
    if (error)
        throw LibraryError(path);

    IGameModule *res = load();

    if (!res)
        throw LibraryError(std::string(path)+" returned nullptr\n");

    res->handle = handle;
    
    return res;
}

IDisplayModule *Arcade::loadGraph(const char *path)
{
    void *handle = dlopen(path, RTLD_LAZY);
    char *error = dlerror();

    if (!handle)
        throw LibraryError(error);

    ADisplayModule *(*load)(void) = (ADisplayModule *(*)(void)) dlsym(handle, "ctor");

    error = dlerror();
    if (error)
        throw LibraryError(path);

    ADisplayModule *res = load();

    if (!res)
        throw LibraryError(std::string(path)+" returned nullptr\n");

    res->handle = handle;

    return res;
}

std::string Arcade::getNameFromPath(std::string path)
{
    void *handle = dlopen(path.c_str(), RTLD_LAZY);

    if (!handle)
        throw LibraryError(dlerror());

    std::string (*getName)(void) = (std::string (*)(void)) dlsym(handle, "getLibName");

    char *error = dlerror();
    if (error)
        throw LibraryError(error);

    return getName();
}

int Arcade::getLibType(const char *path)
{
    void *handle = dlopen(path, RTLD_LAZY);

    if (!handle)
        throw LibraryError(dlerror());

    int (*getType)(void) = (int (*)(void)) dlsym(handle, "getLibType");

    char *error = dlerror();
    if (error)
        throw LibraryError(error);

    return getType();
}

void Arcade::loadShared(std::string path)
{
    int libType = getLibType(path.c_str());
    std::string name = getNameFromPath(path);

    switch (libType) {
    case 1: //IModule::type_m::GAME:
        games.push_back(name);
        gamePaths.push_back(path);
        break;
    case 0: //IModule::type_m::GRAPHIC:
        libs.push_back(name);
        libsPaths.push_back(path);
        break;
    default:
        throw LibraryError(path+" : lib type unrecognized\n");
    }
}

Arcade::Arcade(char **argv) : currentGameName(""), ev(-1)
{
    std::string path = "./lib";

    dlerror();
    if (this->getLibType(argv[1]) != 0) //IModule::type_m::GRAPHIC)
        throw LibraryError(" could not load "+std::string(argv[1])+" as graphic library\n");
    for (const auto &entry : fs::directory_iterator(path)) {
        this->loadShared(entry.path());
    }
    currentLibName = argv[1];
    currentLib = loadGraph(currentLibName.c_str());
}
