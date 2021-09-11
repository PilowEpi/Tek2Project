#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include <string>
#include "Parts.hpp"

class KoalaBot
{
    public:
        //Ctor
        KoalaBot(std::string serial = "Bob-01");

        // MF
        void setParts(Arms &arms);
        void setParts(Legs &legs);
        void setParts(Head &head);

        void swapParts(Arms &arms);
        void swapParts(Legs &legs);
        void swapParts(Head &head);

        void informations () const;
        bool status () const;
    private:
        std::string _serial;
        Arms _arms;
        Legs _legs;
        Head _head;
};

#endif