/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** UsernameModule
*/

#ifndef NETWORKDATA_HPP_
#define NETWORKDATA_HPP_

#include <deque>
#include <string>

#include "Networking.hpp"
#include "IData.hpp"

class NetworkData : public IData
{
    public:
        NetworkData();
        ~NetworkData();
        void update(IMonitorModule *memory);
        std::string data();
        std::map<std::string, std::deque<float *>> &getOutput();
        std::map<std::string, std::deque<float *>> &getInput();

        unsigned int adaptatorcount;
        std::deque<std::deque<NetData>> computed_net;
        std::map<std::string, std::deque<float *>> input;
        std::map<std::string, std::deque<float *>> output;
        std::map<std::string, float> inputMax;
        std::map<std::string, float> outputMax;

        std::map<std::string, float> units;
};

#endif /* !Ramdata */
