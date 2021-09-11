/*
** EPITECH PROJECT, 2020
** CPOOL D16
** File description:
** CPOOL D16
*/

#ifndef DOMESTIC_KOALA_HPP_
#define DOMESTIC_KOALA_HPP_

#include <vector>
#include <string>
#include <iostream>
#include "KoalaAction.hpp"

class DomesticKoala
{
    public:
        using methodPointer_t = void (KoalaAction::*) (const std::string &);
        
        DomesticKoala(KoalaAction &);
        ~DomesticKoala();
        DomesticKoala(const DomesticKoala &other);
        DomesticKoala &operator=(const DomesticKoala &other); 

        const std::vector<methodPointer_t> *getActions() const; 

        void learnAction(unsigned char command, methodPointer_t action);
        void unlearnAction(unsigned char command);
        void doAction(unsigned char command, const std::string &parameter);

        void setKoalaAction(KoalaAction &action);
    private:
        DomesticKoala();

        KoalaAction 
        action;
        std::vector<methodPointer_t> vec;
};

#endif