/*
** EPITECH PROJECT, 2020
** CPOOL D06
** File description:
** CPOOL D06
*/

#include <iostream>

#include "SickKoalaList.hpp"
#include "SickKoala.hpp"

SickKoalaList::SickKoalaList(SickKoala *koala)
{
    this->_koala = koala;
    this->_next = NULL;   
}

SickKoalaList::~SickKoalaList()
{
}

bool SickKoalaList::isEnd()
{
    if (this->_next == NULL)
        return (true);
    return (false);
}

void SickKoalaList::append(SickKoalaList *node)
{
    SickKoalaList *head = this;

    if (node == NULL)
        return;
    while (head->_next != NULL) {
        if (node->_koala != nullptr &&
            head->_koala != nullptr &&
            head->_koala->_name == node->_koala->_name)
            return;
        head = head->_next;
    }
    head->_next = node;
}

SickKoalaList *SickKoalaList::getFromName(std::string name)
{
    SickKoalaList *head = this;

    while (head->_next != NULL) {
        if (head->_koala != nullptr &&
            head->_koala->_name == name)
            return (head);
        head = head->_next;
    }
    return (this);
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *node)
{
    SickKoalaList *head = this;
    SickKoalaList *prev = nullptr;

    if (head == node) {
        return (this->_next);
    }
    while (head->_next != NULL) {
        if (head == node && prev != nullptr) {
            prev->_next = head->_next;
            return (this);
        } else if (head == node && prev == nullptr) {
            return (this->_next);
        }
        prev = head;
        head = head->_next;
    }
    return (this);
}

SickKoalaList *searchFromName(SickKoalaList *head, std::string name)
{
    while (head->_next != NULL) {
        if (head->_koala != nullptr &&
            head->_koala->_name == name)
            return (head);
        head = head->_next;
    }
    return (nullptr);
}

SickKoalaList *SickKoalaList::removeFromName(std::string name)
{
    SickKoalaList *to_search = searchFromName(this, name);

    if (to_search != nullptr) {
        return (this->remove(to_search));
    } else {
        return (this);
    }
}

SickKoala *SickKoalaList::getContent()
{
    return (this->_koala);
}

SickKoalaList *SickKoalaList::getNext()
{
    return (this->_next);
}

void SickKoalaList::dump()
{
    SickKoalaList *head = this;

    std::cout << "Patients:";

    while (head != NULL) {
        if (head->_koala == nullptr) {
            std::cout << " [nullptr]";
        } else {
            std::cout << " " << head->_koala->_name;
        }
        if (head->_next != NULL) {
            std::cout << ",";
        }
        head = head->_next;
    }
    std::cout << "." << std::endl;
}