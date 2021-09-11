
#ifndef SIMPLE_PTR_HPP_
#define SIMPLE_PTR_HPP_

#include "BaseComponent.hpp"

class SimplePtr
{
    public:
        explicit SimplePtr(BaseComponent *rawPtr) : _rawPtr(rawPtr) {};
        ~SimplePtr() {
            if (_rawPtr != nullptr)
                delete _rawPtr;
        };
        BaseComponent *get() const { return _rawPtr;};

    private:
        // Make the class non copyable
        SimplePtr(SimplePtr const &);
        SimplePtr &operator=(SimplePtr const &);

        BaseComponent *_rawPtr;
};

#endif // SIMPLE_PTR_HPP_
