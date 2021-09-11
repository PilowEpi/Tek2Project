/*
** EPITECH PROJECT, 2020
** CPOOL D16
** File description:
** CPOOL D16
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <stack>
#include <iostream>
#include <sstream>
#include <string>

class Parser
{
    public:
        Parser();
        void feed(const std::string&);
        int result() const { return _result;};
        void reset() { _result = 0; };
    private:
        int _result;
        std::stack<int> _operands;
};

#endif