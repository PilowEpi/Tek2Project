/*
** EPITECH PROJECT, 2020
** CPOOL D16
** File description:
** CPOOL D16
*/


#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <string>

class Event
{
    public:
        Event();
        Event(unsigned int time, const std::string &event);
        ~Event() {};
        Event(const Event &other);
        Event& operator=(const Event &other);

        unsigned int getTime() const { return time; };
        const std::string &getEvent() const { return event; };
        void setTime(unsigned int time) { this->time = time; };
        void setEvent(const std::string &event) { this->event = event; };

    private:
        unsigned int time;
        std::string event;
};

#endif