/*
** EPITECH PROJECT, 2020
** CPOOL D06
** File description:
** CPOOL D06
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

#include "KoalaNurse.hpp"
#include "SickKoala.hpp"

KoalaNurse::KoalaNurse(int id)
{
    this->_id = id;
    this->_isWorking = false;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << this->_id << ": Finally some rest" << std::endl;
}

void KoalaNurse::giveDrug(std::string drugName, SickKoala *koala)
{
    koala->takeDrug(drugName);
}

std::string KoalaNurse::readReport(std::string fileName)
{
    std::fstream file;
    std::string check = fileName.substr(fileName.length() - 7, fileName.length());
    std::string error = "";
    std::string koalaName = "";
    std::string drugName = "";

    if (check != ".report")
        return (error);
    koalaName = fileName.substr(0, fileName.length() - 7);
    file.open(fileName);
    if (!file)
        return (error);
    getline(file, drugName);
    std::cout << "Nurse " << this->_id << ": Kreog! Mr. " << koalaName << " needs a " << drugName << "!" << std::endl;
    return (drugName);
}


void KoalaNurse::timeCheck()
{
    this->_isWorking = !this->_isWorking;
    if (this->_isWorking) {
        std::cout << "Nurse " << this->_id << ": Time to get to work!" << std::endl;
    } else {
        std::cout << "Nurse " << this->_id << ": Time to go home to my eucalyptus forest!" << std::endl;
    }
}

int KoalaNurse::getID()
{
    return (this->_id);
}