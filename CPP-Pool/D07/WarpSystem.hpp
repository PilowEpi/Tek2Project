#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

#include <string>

namespace WarpSystem
{
    class QuantumReactor
    {
        // Ctor
        public:
            QuantumReactor();
        // Dtor

        // Members function
            bool isStable();
            void setStability(bool stability);
        // Properties
        private:
            bool _stability;

    };

    class Core
    {
        public:
            // Ctor
            Core(QuantumReactor *reactor);

            // Dtor
            
            // MF
            void setupCore(QuantumReactor *reactor);
            QuantumReactor *checkReactor(void);
        private:
            QuantumReactor *_coreReactor;
    };
};

#endif