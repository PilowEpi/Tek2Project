#ifndef BORG_HPP_
#define BORG_HPP_

#include <string>
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Borg
{
    class Ship
        {
            public:
                // Ctor
                Ship();

                // Dtor
                ~Ship();

                // MF
                void setupCore(WarpSystem::Core *core);
                void checkCore();

                bool move(int warp, Destination d);
                bool move(int warp);
                bool move(Destination d);
                bool move();

                // Properties
            private:
                WarpSystem::Core *_core;
                int _side;
                short _maxWarp;
                Destination _location;
                Destination _home;
        };
}

#endif
