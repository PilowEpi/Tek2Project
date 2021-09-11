/*
** EPITECH PROJECT, 2020
** CPOOL D16
** File description:
** CPOOL D16
*/


#ifndef EVENT_MANAGER_HPP_
#define EVENT_MANAGER_HPP_

#include <list>
#include <iostream>
#include <algorithm>

#include "Event.hpp"

class EventManager
{
    public:
        EventManager();
        ~EventManager();
        EventManager(const EventManager &other);
        EventManager &operator=(const EventManager &other);
        
        void addEvent(const Event &e);
        void removeEventsAt(unsigned int time);
        void dumpEvents() const;
        void dumpEventAt(unsigned int time) const;
        
        void addTime(unsigned int time);
        void addEventList(const std::list<Event> &events);
    private:
        unsigned int _time;
        std::list<Event> _events;
};

#endif