/*
** EPITECH PROJECT, 2020
** CPOOL D13
** File description:
** CPOOL D13
*/

#include "Picture.hpp"

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::fstream fileData;
    std::string line;
    
    this->_data = "";
    if (file == "")
        return true;
    fileData.open(file, std::ios::in);
    if (!fileData) {
        this->_data = "ERROR";
        return false;
    }
    while (getline(fileData, line)) {
        this->_data += line;
        this->_data += "\n";
    }
    fileData.close();
    return true;
}

Picture::Picture(const Picture &other)
{
    this->_data = other.getData();
}

Picture &Picture::operator=(const Picture &other)
{
    this->_data = other.getData();
    return *this;
}