#include <cstdlib>
#include <iostream>
#include "EventManager.hpp"

static std::list<Event> createTodoList()
{
    std::list<Event> todo;

    todo.push_front(Event(19, "The vengeance of the Koala"));
    todo.push_front(Event(20, "The return of the vengeance  of the Koala"));
    todo.push_front(Event(21, "The come back of the vengeance  of the Koala"));
    todo.push_front(Event(22, "The sequel to the vengeance."));
    todo.push_front(Event(9, "What the hell do you mean 'this morning' ?!"));
    todo.push_front(Event(1, "No, no, you're pushing it now ..."));

    return  todo;
}

static void populateEvents(EventManager &em)
{
    em.addEvent(Event(10, "Eat"));
    em.addEvent(Event(12, "Finish the exercises"));
    em.addEvent(Event(12, "Understand the  thing"));
    em.addEvent(Event(15, "Set the rights"));
    em.addEvent(Event(8, "Ask what the hell a const_iterator is"));
    em.addEvent(Event(11, "Wash my hands so that my keyboard doesn't smell likekebab"));
}

int main()
{
    EventManager em;

    populateEvents(em);
    em.dumpEvents ();
    std::cout  << "=====" << std::endl;

    em.removeEventsAt (12);
    em.dumpEvents ();
    std::cout  << "=====" << std::endl;

    em.addTime (10);
    std::cout  << "=====" << std::endl;

    em.dumpEvents ();
    std::cout  << "=====" << std::endl;

    std::list<Event> a = createTodoList ();
    em.addEventList(a);
    em.dumpEvents ();
    std::cout  << "=====" << std::endl;

    em.dumpEventAt (15);
    std::cout  << "=====" << std::endl;

    em.addTime (14);
    return  0;
}