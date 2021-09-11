/*
** EPITECH PROJECT, 2020
** CPOOL D16
** File description:
** CPOOL D16
*/

#include "EventManager.hpp"

EventManager::EventManager()
{
    this->_time = 0;
}

EventManager::~EventManager()
{
    this->_events.clear();
}

EventManager::EventManager(const EventManager &other)
    : _events(other._events), _time(other._time)
{
}

EventManager &EventManager::operator=(const EventManager &other)
{
    this->_events = other._events;
    this->_time = other._time;
    return *this;
}

void EventManager::addEvent(const Event &event)
{
    if (event.getTime() < _time)
        return;
    _events.push_back(event);
    _events.sort([](Event &a, Event &b) { return a.getTime() < b.getTime(); });
}

void EventManager::removeEventsAt(unsigned int time)
{
    _events.remove_if([time](Event &e){ return e.getTime() == time; });
}

void EventManager::dumpEvents() const
{
    for (Event event : _events) {
        std::cout << event.getTime() << ": " << event.getEvent() << std::endl;
    }
}

void EventManager::dumpEventAt(unsigned int time) const
{
    for (Event event : _events) {
        if (event.getTime() == time) {
            std::cout << event.getTime() << ": " << event.getEvent() << std::endl;
        }
    }
}

void EventManager::addTime(unsigned int time)
{
    unsigned int oldTime = this->_time;
    this->_time += time;

    for (Event event : _events) {
        if (event.getTime() > oldTime && event.getTime() <= this->_time) {
            std::cout << event.getEvent() << std::endl;
        }
    }
    _events.remove_if([time = _time](Event &e){ return e.getTime() <= time; });
}

void EventManager::addEventList(const std::list<Event> &events)
{
    for (Event event : events) {
        if (event.getTime() < _time)
            continue;
        _events.push_back(event);
    }
    _events.sort([](Event &a, Event &b) { return a.getTime() < b.getTime(); });
}