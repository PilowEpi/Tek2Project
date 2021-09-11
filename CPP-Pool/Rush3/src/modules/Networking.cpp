/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** Networking
*/

#include <cstdio>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <fstream>

#include "NetworkData.hpp"
#include "Networking.hpp"

Networking::Networking() : AMonitorModule("Networking", "")
{
    this->adaptator = 0;
    computed_data = new NetworkData;
}

Networking::~Networking()
{
    delete computed_data;
}

void Networking::setAdaptatorNb(unsigned int nb)
{
    this->adaptator = nb;
}

void NclearStr(const std::string &input, std::string &output)
{
	output.clear();
	std::unique_copy (input.begin(), input.end(), std::back_insert_iterator<std::string>(output), [](char a,char b){ return isspace(a) && isspace(b);});  
}

void Networking::setAValue(float &value, long unsigned int hislong, std::string &unit)
{
    float tmp;
    int depth = 0;
    std::string units[] = {"octet", "Ko", "Mo", "Go", "To", "Po", "Eo", "Zo", "Yo"};

    tmp = static_cast<float>(hislong);
        while (tmp > 1000) {
            tmp /= 1000;
            depth++;
        }
    value = tmp;
    unit = units[depth];
}

void Networking::FillDataList(std::deque<NetData> &dump_data)
{
    std::fstream dataset;
    std::string line;
    std::string cline;
    FileNetData entry;
    NetData current;
    int x = 0;

    dataset.open("/proc/net/dev", std::ios::in);
    if (!dataset.is_open() || !dataset.good())
        throw std::runtime_error("Unable to open /proc/net/dev file !");
    while (std::getline(dataset, line)) {
        if (x < 2) {
            x++;
            continue;
        }
        NclearStr(line, cline);
        sscanf(cline.c_str(), "%s %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu",
            entry.name,
            &entry.rx_bytes,
            &entry.rx_packets,
            &entry.rx_errors,
            &entry.rx_dropped,
            &entry.rx_fifo_errors,
            &entry.frame,
            &entry.rx_compressed,
            &entry.multicast,
            &entry.tx_bytes,
            &entry.tx_packets,
            &entry.tx_errors,
            &entry.tx_dropped,
            &entry.tx_fifo_errors,
            &entry.collisions,
            &entry.tx_carrier_errors,
            &entry.tx_compressed);
        current.device = std::string(entry.name);
        if (this->previous_r.find(entry.name) != this->previous_r.end() && this->previous_t.find(entry.name) != this->previous_t.end()) {
            this->setAValue(current.rx, entry.rx_bytes - this->previous_r[entry.name], current.rx_unity);
            this->setAValue(current.tx, entry.tx_bytes - this->previous_t[entry.name], current.tx_unity);
            this->previous_r[entry.name] = entry.rx_bytes;
            this->previous_t[entry.name] = entry.tx_bytes;
        } else {
            this->previous_r.insert(std::pair<std::string, unsigned long int>(entry.name, entry.rx_bytes));
            this->previous_t.insert(std::pair<std::string, unsigned long int>(entry.name, entry.tx_bytes));
            this->setAValue(current.rx, entry.rx_bytes - entry.rx_bytes, current.rx_unity);
            this->setAValue(current.tx, entry.tx_bytes - entry.tx_bytes, current.tx_unity);
        }
        dump_data.push_back(current);
        x++;
    }
    this->setAdaptatorNb(x - 2);
    dataset.close();
}

void Networking::refresh()
{
    std::deque<NetData> dump_data;

    this->FillDataList(dump_data);
    this->history.push_back(dump_data);
    if (this->history.size() > 900)
        this->history.pop_front();
    this->computed_data->update(this);
}

unsigned int Networking::getAdaptatorsNb() const
{
    return (this->adaptator);
}

const std::deque<std::deque<NetData>> &Networking::getNetworkingData() const
{
    return (this->history);
}

std::string &Networking::getString() {
	throw std::runtime_error("Module doesn't have Std::string return value");
	return *data;
}

IData *Networking::getDataC() {
	return computed_data;
}

float Networking::getNumber() {
	throw std::runtime_error("Module doesn't have Float return value");
	return 0.0;
}