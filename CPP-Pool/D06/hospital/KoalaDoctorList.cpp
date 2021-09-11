/*
** EPITECH PROJECT, 2020
** CPOOL D06
** File description:
** CPOOL D06
*/

#include <iostream>

#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *doctor)
{
    this->_doctor = doctor;
    this->_next = NULL;
}

KoalaDoctorList::~KoalaDoctorList()
{
}

bool KoalaDoctorList::isEnd()
{
    if (this->_next == NULL)
        return (true);
    return (false);
}

void KoalaDoctorList::append(KoalaDoctorList *node)
{
    KoalaDoctorList *head = this;

    if (node == NULL)
        return;
    while (head->_next != NULL) {
        if (node->_doctor != nullptr &&
            head->_doctor != nullptr &&
            head->_doctor->_name == node->_doctor->_name)
            return;
        head = head->_next;
    }
    head->_next = node;
}

KoalaDoctorList *KoalaDoctorList::getFromName(std::string name)
{
    KoalaDoctorList *head = this;

    while (head->_next != NULL) {
        if (head->_doctor != nullptr &&
            head->_doctor->_name == name)
            return (head);
        head = head->_next;
    }
    return (this);
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *node)
{
    KoalaDoctorList *head = this;
    KoalaDoctorList *prev = nullptr;

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

KoalaDoctorList *searchFromName(KoalaDoctorList *head, std::string name)
{
    while (head->_next != NULL) {
        if (head->_doctor != nullptr &&
            head->_doctor->_name == name)
            return (head);
        head = head->_next;
    }
    return (nullptr);
}

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string name)
{
    KoalaDoctorList *to_search = searchFromName(this, name);

    if (to_search != nullptr) {
        return (this->remove(to_search));
    } else {
        return (this);
    }
}

void KoalaDoctorList::dump()
{
    KoalaDoctorList *head = this;

    std::cout << "Doctors:";

    while (head != NULL) {
        if (head->_doctor == nullptr) {
            std::cout << " [nullptr]";
        } else {
            std::cout << " " << head->_doctor->_name;
        }
        if (head->_next != NULL) {
            std::cout << ",";
        }
        head = head->_next;
    }
    std::cout << "." << std::endl;
}