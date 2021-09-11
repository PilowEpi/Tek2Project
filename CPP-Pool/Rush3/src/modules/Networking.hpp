/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** Networking
*/

#ifndef NETDATA
#define NETDATA

typedef struct NetData_s
{
	std::string device;
    std::string rx_unity;
    std::string tx_unity;
	float rx;
    float tx;
} NetData;

#endif

#ifndef NETWORKING_HPP_
#define NETWORKING_HPP_

#include <string>
#include <deque>
#include <map>

#include "NetworkData.hpp"
#include "AMonitorModule.hpp"

class NetworkData;

typedef struct FileNetData_s {
    char name[64];
    unsigned long int rx_bytes;
    unsigned long int rx_packets;
    unsigned long int rx_errors;
    unsigned long int rx_dropped;
    unsigned long int rx_fifo_errors;
    unsigned long int frame;
    unsigned long int rx_compressed;
    unsigned long int multicast;
    unsigned long int tx_bytes;
    unsigned long int tx_packets;
    unsigned long int tx_errors;
    unsigned long int tx_dropped;
    unsigned long int tx_fifo_errors;
    unsigned long int collisions;
    unsigned long int tx_carrier_errors;
    unsigned long int tx_compressed;
} FileNetData;

class Networking : public AMonitorModule
{
    public:
        Networking();
        ~Networking();
        void refresh();
        unsigned int getAdaptatorsNb() const;
        const std::deque<std::deque<NetData>> &getNetworkingData() const;
        std::string &getString();
        IData *getDataC();
        float getNumber();
    private:
        void setAValue(float &value, long unsigned int hislong, std::string &unit);
        void setAdaptatorNb(unsigned int nb);
        void FillDataList(std::deque<NetData> &dump_data);
    	unsigned int adaptator;
        std::deque<std::deque<NetData>> history;
        std::map<std::string, unsigned long int> previous_r;
        std::map<std::string, unsigned long int> previous_t;
        NetworkData *computed_data;

        // History :
        //  List -> 900 iteration
        //      List -> Each Network device
        //          Net data stuct containing :
        //              - device name (std::string device)
        //              - Receiving bytes (float rx)
        //              - Transmiting bytes (float tx)
        //              - Receinving unit (std::sting rx_unity)
        //              - Transmiting unit; (std::string tx_unity)
};

#endif /* !NETWORKING_HPP_ */
