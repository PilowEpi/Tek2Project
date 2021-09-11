/*
** EPITECH PROJECT, 2020
** CPOOL D13
** File description:
** CPOOL D13
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <string>
#include "Picture.hpp"

class Toy :public Picture
{
    public:
    enum ToyType {
        BASIC_TOY,
        ALIEN
    };

    Toy(ToyType type = BASIC_TOY, const std::string &name = "toy", const std::string &file = "");
    
    Toy(const Toy &other);
    Toy &operator=(const Toy &other);

    ToyType getType() const { return _type;};
    std::string getName() const { return _name;};
    std::string getAscii() const { return this->getData();};
    void setName(std::string const & name) { _name = name;};
    bool setAscii(std::string const &filename);
    private:
        ToyType _type;
        std::string _name;
};

#endif