/*
** EPITECH PROJECT, 2020
** CPOOL D15
** File description:
** CPOOL D15
*/

#ifndef EX05_HPP_
#define EX05_HPP_

#include <exception>
#include <string>
#include <iostream>

template <class T>
class array
{
    public:
        array()
        {
            _array = 0;
            _length = 0;
        }

        array(unsigned int i)
        {
            _array = new T[i];
            for (size_t j = 0; j < i; j++)
                _array[j] = 0;
            _length = i;
        };

        array(const array &other)
        {
            _length = other._length;
            _array = new T[other._length];

            for (size_t i = 0; i < _length; i++) {
                _array[i] = other._array[i];
            }
        }

        ~array()
        {
            delete [] _array;
        }

        array &operator=(const array &other)
        {
            delete [] _array;
            _length = other._length;
            _array = new T[other._length];

            for (size_t i = 0; i < _length; i++) {
                _array[i] = other._array[i];
            }
            return (*this);
        }

        T &operator[](unsigned int i)
        {
            size_t new_size = i + 1;
            T *new_array = 0;

            if (i >= _length) {
                new_array = new T[new_size];
                for (size_t i = 0; i < _length; i++)
                    new_array[i] = _array[i];
                for (size_t j = _length ; j < new_size; j++)
                    new_array[j] = 0;
                _length = new_size;
                delete [] _array;
                _array = new_array;
            }
            return _array[i];
        }

        T &operator[](unsigned int i) const
        {
            if (i >= _length)
                throw std::exception();
            return _array[i];
        }
        
        size_t size() const
        {
            return _length;
        }

        template <typename U>
        array<U> convertTo(U (*func) (const T&elem))
        {
            array <U>new_array(_length);

            for (size_t i = 0; i < _length; i++)
                new_array[i] = (*func) (_array[i]);
            return (new_array);
        }

        void dump() const
        {
            //std::cout << true << std::endl;
            std::cout << "[";
            for (size_t i = 0; i < _length; i++) {
                if (i + 1 == _length) {
                    if (std::is_same<T, bool>::value)
                        std::cout << ((_array[i]) ? "true" : "false");
                    else
                        std::cout << _array[i];
                } else {
                    if (std::is_same<T, bool>::value)
                        std::cout << ((_array[i]) ? "true, " : "false, ");
                    else
                        std::cout << _array[i] << ", ";
                }
            }
            std::cout << "]" << std::endl;
        };

    private:
        T *_array;
        size_t _length;
};

#endif