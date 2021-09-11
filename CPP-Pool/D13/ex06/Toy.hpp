/*
** EPITECH PROJECT, 2020
** CPOOL D13
** File description:
** CPOOL D13
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <string>
#include "Picture.hpp"

class Toy :public Picture
{
    public:
    enum ToyType {
        BASIC_TOY,
        BUZZ,
        WOODY,
        ALIEN
    };

    Toy(ToyType type = BASIC_TOY, const std::string &name = "toy", const std::string &file = "");

    ToyType getType() const { return _type;};
    std::string getName() const { return _name;};
    std::string getAscii() const { return this->getData();};
    void setName(std::string const & name) { _name = name;};
    bool setAscii(std::string const &filename);
    void setType(ToyType type) { _type = type;};

    virtual bool speak(std::string const &statement);

    virtual bool speak_es(std::string const &statement);


    class Error 
    {
        public:
            enum ErrorType {
                UNKNOWN,
                PICTURE,
                SPEAK
            };

            Error(std::string const &whatValue = "", std::string const &whereValue = "", ErrorType typeValue = ErrorType::UNKNOWN)
                {this->_what = whatValue; this->_where = whereValue; this->type = typeValue;};

            void setWhat(std::string const &whatValue) { _what = whatValue;};
            void setWhere(std::string const &whereValue) { _where = whereValue;};
            void setType(ErrorType typeValue) { type = typeValue;};

            std::string what() const { return _what;};
            std::string where() const { return _where;};

            ErrorType type;
        private:
            std::string _where;
            std::string _what;
    };

    Error getLastError() const { return _error;};
    private:
        ToyType _type;
        std::string _name;
        Error _error;
};



std::ostream &operator<<(std::ostream &out, const Toy &toy);
Toy &operator<<(Toy &toy, const std::string &str);

#endif