/*
** EPITECH PROJECT, 2020
** CPOOL D13
** File description:
** CPOOL D13
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <iostream>
#include <string>
#include <fstream>

class Picture
{
    public:
        Picture(const std::string &file = "");
        Picture(const Picture &other);
        Picture &operator=(const Picture &other);


        bool getPictureFromFile(const std::string &file);

        std::string getData() const { return _data;};
        void setData(std::string const &str) {_data = str;};

    private:
        std::string _data;
};


#endif