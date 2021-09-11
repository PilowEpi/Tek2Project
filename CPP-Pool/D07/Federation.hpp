#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <string>
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Federation
{
    // Ctor

    // Dtor

    // Namespace
    namespace Starfleet
    {
        class Captain
        {
            public:
                // Ctor
                    Captain(std::string name);
                // Dtor
                    ~Captain();
                // MF
                    std::string getName();
                    int getAge();
                    void setAge(int age);
                // Properties
            private:
                std::string _name;
                int  _age;

        };

        class Ensign
        {
            public:
                // Ctor
                    explicit Ensign(std::string name);
                // Dtor
                    ~Ensign();
                // MF

                // Properties
            private:
                std::string _name;
        };

        class Ship
        {
            public:
                // Ctor
                Ship(int length, int width, std::string name, short maxWarp);

                // Dtor
                ~Ship();

                // MF
                void setupCore(WarpSystem::Core *core);
                void checkCore();
                void promote(Captain *captain);

                bool move(int warp, Destination d);
                bool move(int warp);
                bool move(Destination d);
                bool move();

                // Properties
            private:
                Starfleet::Captain *_captain;
                WarpSystem::Core *_core;
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                Destination _location;
                Destination _home;
        };
    };
    class Ship
    {
        public:
            Ship(int length, int width, std::string name);
            ~Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
        private:
            WarpSystem::Core *_core;
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            Destination _location;
            Destination _home;
    };
};

#endif