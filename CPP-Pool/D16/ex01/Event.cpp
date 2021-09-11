/*
** EPITECH PROJECT, 2020
** CPOOL D16
** File description:
** CPOOL D16
*/

#include "Event.hpp"

Event::Event()
    : time(0), event("")
{}

Event::Event(unsigned int time, const std::string &event)
    : time(time), event(event)
{}

Event::Event(const Event &other)
    : time(other.time), event(other.event)
{}

Event &Event::operator=(const Event &other)
{
    this->time = other.time;
    this->event = other.event;
    return *this;
}