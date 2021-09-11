/*
** EPITECH PROJECT, 2020
** CPOOL D06
** File description:
** CPOOL D06
*/

#include <iostream>

#include "KoalaNurseList.hpp"
#include "KoalaNurse.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *nurse)
{
    this->_nurse = nurse;
    this->_next = NULL;
}

KoalaNurseList::~KoalaNurseList()
{
}

bool KoalaNurseList::isEnd()
{
    if (this->_next == NULL)
        return (true);
    return (false);
}

void KoalaNurseList::append(KoalaNurseList *node)
{
    KoalaNurseList *head = this;

    if (node == NULL)
        return;
    while (head->_next != NULL) {
        if (node->_nurse != nullptr &&
            head->_nurse != nullptr &&
            head->_nurse->_id == node->_nurse->_id)
            return;
        head = head->_next;
    }
    head->_next = node;
}

KoalaNurseList *KoalaNurseList::getFromID(int id)
{
    KoalaNurseList *head = this;

    while (head->_next != NULL) {
        if (head->_nurse != nullptr &&
            head->_nurse->_id == id)
            return (head);
        head = head->_next;
    }
    return (this);
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *node)
{
    KoalaNurseList *head = this;
    KoalaNurseList *prev = nullptr;

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

KoalaNurseList *searchFromID(KoalaNurseList *head, int id)
{
    while (head->_next != NULL) {
        if (head->_nurse != nullptr &&
            head->_nurse->_id == id)
            return (head);
        head = head->_next;
    }
    return (nullptr);
}

KoalaNurseList *KoalaNurseList::removeFromID(int id)
{
    KoalaNurseList *to_search = searchFromID(this, id);
    if (to_search != nullptr) {
        return (this->remove(to_search));
    } else {
        return (this);
    }
}

void KoalaNurseList::dump()
{
    KoalaNurseList *head = this;

    std::cout << "Nurses:";

    while (head != NULL) {
        if (head->_nurse == nullptr) {
            std::cout << " [nullptr]";
        } else {
            std::cout << " " << head->_nurse->_id;
        }
        if (head->_next != NULL) {
            std::cout << ",";
        }
        head = head->_next;
    }
    std::cout << "." << std::endl;
}