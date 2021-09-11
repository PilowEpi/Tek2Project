/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Santa
*/

#ifndef SANTA_HPP_
#define SANTA_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include "Object.hpp"

class Santa {
    public:
        Santa();
        ~Santa();

        void watchGift(const std::string &gift);
        bool takeGift();
        void putdownGift();
        const std::string &whatsWatched() const;
        const std::ifstream &getGift() const;

        bool validateXml();
        void unpackIt();
        void generateObj(std::vector<std::string> &v);
        const std::string *getToyName();
        void setContent(const std::string &c) {this->content = c;};
    protected:
        std::string watching;
        std::ifstream inHands;
        Object *obj;
        std::string content;
        size_t _size;
};

#endif /* !SANTA_HPP_ */
