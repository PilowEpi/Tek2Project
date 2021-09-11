/*
** EPITECH PROJECT, 2020
** CPOOL D16
** File description:
** CPOOL D16
*/

#ifndef BF_TRANSLATOR_HPP_
#define BF_TRANSLATOR_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <map>

class BF_Translator
{
    public:
        BF_Translator();
        int translate(const std::string in, const std::string out);
    private:
        std::map<char, std::string> translator;
        std::string result;
};

#endif