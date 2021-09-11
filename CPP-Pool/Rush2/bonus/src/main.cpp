/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <thread>
#include <pthread.h>

#include "Object.hpp"
#include "Toy.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "IElf.hpp"
#include "PapaXmasElf.hpp"
#include "ConveyorBeltRand.hpp"
#include "TableRand.hpp"
#include "MagicalCarpet.hpp"

void playSound(Object *obj, sf::Music *packGift, sf::Music *giftpaperised)
{
    static bool packGiftp = false;
    static bool giftpaperisedp = false;
    if (obj->_name == "Box" && !packGiftp) {
        packGift->play();
        packGiftp = true;
    }
    if (obj->_name == "GiftPaper" && !giftpaperisedp) {
        giftpaperised->play();
        giftpaperisedp = true;
    }
    if (obj->_name != "GiftPaper" && obj->_name != "Box") {
        packGift->stop();
        packGiftp = false;
        giftpaperisedp = false;
        giftpaperised->stop();
    }
}

int Simulation(IElf *lf)
{
    srandom(42);
    Box obj;
    LittlePony p("UNICORN!");
    Teddy b("BEAR");
    std::cout << obj << std::endl;
    std::cout << p;
    std::cout << b;
    while (lf->wrap()) {
        std::cout << "+1 gift wrapped !!" << std::endl;
    }
    return 0;
}

sf::Sprite *carboard;
sf::Sprite *carboardClose;
sf::Sprite *elf;
sf::Sprite *littlepony;
sf::Sprite *teddy;
sf::Sprite *gitfPaper;

int main()
{
    sf::Texture cardbordT;
    cardbordT.loadFromFile("medias/cardboard.png");
    sf::Texture carboardCloseT;
    carboardCloseT.loadFromFile("medias/cardboard_close.png");
    sf::Texture elfT;
    elfT.loadFromFile("medias/elf.png");
    sf::Texture littleponyT;
    littleponyT.loadFromFile("medias/littlepony.png");
    sf::Texture teddyT;
    teddyT.loadFromFile("medias/teddy.png");
    sf::Texture gitfPaperT;
    gitfPaperT.loadFromFile("medias/giftpaper.png");
    sf::Music packGift;
    if (!packGift.openFromFile("medias/bookClose.ogg"))
        exit(0);
    sf::Music giftpaperised;
    if (!giftpaperised.openFromFile("medias/bookFlip2.ogg"))
        exit(0);
    carboard = new sf::Sprite;
    carboardClose = new sf::Sprite;
    elf = new sf::Sprite;
    littlepony = new sf::Sprite;
    teddy = new sf::Sprite;
    gitfPaper = new sf::Sprite;

    carboard->setTexture(cardbordT);
    carboardClose->setTexture(carboardCloseT);
    elf->setTexture(elfT);
    littlepony->setTexture(littleponyT);
    teddy->setTexture(teddyT);
    gitfPaper->setTexture(gitfPaperT);

    carboard->setScale(1 / (carboard->getLocalBounds().width / 40), 1 / (carboard->getLocalBounds().width / 40));
    carboardClose->setScale(1 / (carboardClose->getLocalBounds().width / 40), 1 / (carboardClose->getLocalBounds().width / 40));
    elf->setScale(1 / (elf->getLocalBounds().width / 80), 1 / (elf->getLocalBounds().width / 80));
    littlepony->setScale(1 / (littlepony->getLocalBounds().width / 40), 1 / (littlepony->getLocalBounds().width / 40));
    teddy->setScale(1 / (teddy->getLocalBounds().width / 40), 1 / (teddy->getLocalBounds().width / 40));
    gitfPaper->setScale(1 / (gitfPaper->getLocalBounds().width / 40), 1 / (gitfPaper->getLocalBounds().width / 40));

    sf::Sound sound;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Santa's factory");
    int frame = 0;
    //start sim
    IElf *lf = new PapaXmasElf;
    lf->setTable(new TableRand);
    lf->setConveyor(new ConveyorBeltRand);
	std::thread simthread(Simulation, lf);


    sf::CircleShape elf_cir(lf->sizeX);
    elf_cir.setFillColor(sf::Color(35, 142, 107));
    
    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setFillColor(sf::Color(249, 215, 28));

    
    sf::Texture texture;
    texture.loadFromFile("medias/background.jpg");
    sf::Sprite background;
    background.setTexture(texture);
    background.setScale(2, 2);

    sf::Texture texture2;
    texture2.loadFromFile("medias/conveyor.png");
    sf::Sprite conveyor;
    conveyor.setTexture(texture2);
    conveyor.setScale(1 / (conveyor.getLocalBounds().height / 80), 1 / (conveyor.getLocalBounds().height / 80));

    conveyor.setRotation(180.f);

    sf::Texture texture3;
    texture3.loadFromFile("medias/table.jpg");
    sf::Sprite table;
    table.setTexture(texture3);
    table.setScale(1 / (table.getLocalBounds().width / 200), 1 / (table.getLocalBounds().width / 200));

    sf::RectangleShape restart(sf::Vector2f(120, 60));
    restart.setPosition(1920 / 2 - 120 / 2, 1080 - 100);
    restart.setFillColor(sf::Color(21, 178, 211));

    window.setFramerateLimit(60);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (rectangle.getLocalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    delete lf;
                    exit(0);
                }
            }
        }
        window.clear();
        window.draw(background);
        window.draw(restart);

        //Draw elf
        elf->setPosition(lf->x-lf->sizeX/2, lf->y-lf->sizeY/2-50);
        window.draw(*elf);

        //Draw conveyor
        conveyor.setPosition(lf->conveyor->x-40+conveyor.getGlobalBounds().width*0.7, lf->conveyor->y + conveyor.getGlobalBounds().height*1.5-90);
        window.draw(conveyor);
    
        //Draw table
        table.setPosition(lf->table->x-110, lf->table->y-20);
        window.draw(table);

        //Draw Object on conveyor
        Object *obj = lf->conveyor->obj;
        if (obj){
            sf::Sprite *s = obj->_name == "Box" ? carboard : obj->_name == "GiftPaper" ? gitfPaper : obj->_name == "Rainbow Dash" ? littlepony : obj->_name == "Bear" ? teddy : carboard;
            s->setPosition(obj->dx-obj->sizeX/2, obj->dy-obj->sizeY/2);
            window.draw(*s);
            obj->dx = obj->dx*0.9 + obj->x*0.1; 
            obj->dy = obj->dy*0.9 + obj->y*0.1; 
        }

        //draw Object on Table
        for (int i = 0; i < 10; i++){
            Object *obj = lf->table->objects[i];
            if (obj){
                sf::Sprite *s = obj->_name == "Box" ? carboard : obj->_name == "GiftPaper" ? gitfPaper : obj->_name == "Rainbow Dash" ? littlepony : obj->_name == "Bear" ? teddy : carboard;
                //sf::Sprite *s = obj->sprite;
                int pos = lf->table->sizeX/10*(i-5);
                s->setPosition(obj->dx-obj->sizeX/2+pos, obj->dy-obj->sizeY/2);
                window.draw(*s);
                obj->dx = obj->dx*0.9 + obj->x*0.1; 
                obj->dy = obj->dy*0.9 + obj->y*0.1; 
            }
        }
        
        //Draw Object in hands
            //left
        obj = lf->lefthand;
        if (obj){
            sf::Sprite *s = obj->_name == "Box" ? carboard : obj->_name == "GiftPaper" ? gitfPaper : obj->_name == "Rainbow Dash" ? littlepony : obj->_name == "Bear" ? teddy : carboard;
            playSound(obj, &packGift, &giftpaperised);
            s->setPosition(obj->dx-obj->sizeX/2, obj->dy-obj->sizeY/2);
            window.draw(*s);
            obj->dx = obj->dx*0.9 + obj->x*0.1; 
            obj->dy = obj->dy*0.9 + obj->y*0.1; 
        }
            //right
        obj = lf->righthand;
        if (obj){
            sf::Sprite *s = obj->_name == "Box" ? carboard : obj->_name == "GiftPaper" ? gitfPaper : obj->_name == "Rainbow Dash" ? littlepony : obj->_name == "Bear" ? teddy : carboard;
            playSound(obj, &packGift, &giftpaperised);
            s->setPosition(obj->dx-obj->sizeX/2, obj->dy-obj->sizeY/2);
            window.draw(*s);
            obj->dx = obj->dx*0.9 + obj->x*0.1; 
            obj->dy = obj->dy*0.9 + obj->y*0.1; 
        }


        window.display();
        frame++;
    }
}
