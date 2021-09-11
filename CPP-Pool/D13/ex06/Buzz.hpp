/*
** EPITECH PROJECT, 2020
** CPOOL D13
** File description:
** CPOOL D13
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy
{
    public:
        explicit Buzz(const std::string &name, const std::string &ascii = "buzz.txt");
        bool speak(const std::string &statement) final;
        bool speak_es(const std::string &statement) final;
    private:
};

std::ostream &operator<<(std::ostream &out, const Buzz &toy);

Buzz &operator<<(Buzz &toy, const std::string &str);


#endif