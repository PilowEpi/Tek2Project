/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** NetWorkModule
*/

#include "NetworkData.hpp"
#include "Networking.hpp"
#include "NetWorkModule.hpp"

NetWorkModule::NetWorkModule(int col, int row, AMonitorModule *m, int key, int index, int size)
    : ANCursesModules(col, row, m, key, index, size)
{
}

NetWorkModule::~NetWorkModule()
{
}

void NetWorkModule::display()
{
    NCursesDrawer d;
    std::string label = this->_module->getLabel();
    std::ostringstream sstr("");
    int backn = 1;

    sstr << std::setw(COLS / 2 + label.length() / 2) << label <<  std::setw(COLS / 2 - label.length() / 2) << " " << std::endl;
    d.setColor(6);
    d.drawText(this->_col, this->_row, sstr.str().c_str());
    if (dynamic_cast<Networking *>(this->_module)) {
        d.setColor(0);
        Networking *n = (Networking *)(this->_module);
        std::deque<std::deque<NetData>> dataset = n->getNetworkingData();
        std::deque<NetData> last = *(dataset.rbegin());
        sstr.clear();
        sstr.str("");
        sstr << "Device name " << "|" << std::setw(5) << "Down" << "|" << std::setw(5) << "Up";
        d.drawText(this->_col + backn, COLS / 2 - sstr.str().length() / 2, sstr.str().c_str());
        backn++;
        for (NetData nd : last) {
            sstr.clear();
            sstr.str("");
            sstr << std::setw(15) << nd.device << " | " << std::setw(5) << nd.rx << " " << nd.rx_unity << " | " << std::setw(5)<< nd.tx << " " << nd.tx_unity;
            d.drawText(this->_col + backn, COLS / 2 - sstr.str().length() / 2, sstr.str().c_str());
            backn++;
        }    
        return;
    }
    throw std::runtime_error("NetWorkModule shouldn't be called out of Network Module");
}