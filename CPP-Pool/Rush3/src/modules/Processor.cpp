/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** Processor
*/

#include <thread>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

#include "IData.hpp"
#include "Processor.hpp"
#include "ProcessorData.hpp"

Processor::Processor() : AMonitorModule("Processor" , "")
{
    this->nb_procs = std::thread::hardware_concurrency();
    computed_processor = new ProcessorData;
}

Processor::~Processor()
{
    delete computed_processor;
}

size_t GetIdleTime(const CPUData &e)
{
    return  e.data[S_IDLE] + e.data[S_IOWAIT];
}

size_t GetActiveTime(const CPUData &e)
{
    return  e.data[S_USER] + e.data[S_NICE] + e.data[S_SYSTEM] + e.data[S_IRQ] + e.data[S_SOFTIRQ] + e.data[S_STEAL] + e.data[S_GUEST] + e.data[S_GUEST_NICE];
}

size_t GetUserTime(const CPUData &e)
{
    return e.data[S_USER] + e.data[S_NICE] + e.data[S_GUEST] + e.data[S_GUEST_NICE];
}

size_t GetSysTime(const CPUData &e)
{
    return e.data[S_SYSTEM] + e.data[S_IRQ] + e.data[S_SOFTIRQ] + e.data[S_STEAL];
}

void GetProcessorData(std::deque<CPUData> &entries)
{
    std::ifstream proc_stat("/proc/stat");
    std::string line;
    CPUData entry;
    if (!proc_stat.is_open() || !proc_stat.good())
        throw std::runtime_error("Unable to open /proc/stat file !");
    while (std::getline(proc_stat, line))
        if (!line.compare(0, 3, "cpu")) {
            std::istringstream ss(line);
            entry.cpu = "";
            ss >> entry.cpu;
            for (int i = 0; i < 10; i++)
                ss >> entry.data[i];
            entries.push_back(entry);
        }
    proc_stat.close();
}

void Processor::refresh()
{
    std::deque<CPUData> nentry;
    std::deque<CPUData>::iterator itn;
    std::deque<CPUData>::iterator it;
    std::deque<std::array<float, 4>> data;
    std::array<float, 4> current;
    int x = 0;
    GetProcessorData(nentry);
    if (this->old_data.size()) {
        itn = nentry.begin();
        for (it = this->old_data.begin(); it != this->old_data.end() && itn != nentry.end(); ++it, ++itn) {
            current[0] = static_cast<float>(GetActiveTime(*itn) - GetActiveTime(*it)) / 100;
            current[1] = static_cast<float>(GetUserTime(*itn) - GetUserTime(*it)) / 100;
            current[2] = static_cast<float>(GetSysTime(*itn) - GetSysTime(*it)) / 100;
            current[3] = static_cast<float>(GetIdleTime(*itn) - GetIdleTime(*it)) / 100;
            if (!x) {
                current[0] /= this->nb_procs;
                current[1] /= this->nb_procs;
                current[2] /= this->nb_procs;
                current[3] /= this->nb_procs;
            }
            data.push_back(current);
            x++;
        }
        this->history.push_back(data);
        x = 0;
        this->old_data.pop_front();
        if (this->history.size() > 900)
            this->history.pop_front();
        this->computed_processor->update(this);
    }
    this->old_data = nentry;
}

unsigned int Processor::getNbProcs() const
{
    return (this->nb_procs);
}

const std::deque<std::deque<std::array<float, 4>>> &Processor::getProcessorData() const
{
    return (this->history);
}

std::string &Processor::getString() {
    throw std::runtime_error("Module doesn't have std::string return value");
    return *data;
}

IData *Processor::getDataC() {
    return computed_processor;
}

float Processor::getNumber() {
    throw std::runtime_error("Module doesn't have Float return value");
    return 0.0;
}