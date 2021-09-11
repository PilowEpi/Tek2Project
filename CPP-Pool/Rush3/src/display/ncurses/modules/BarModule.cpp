/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** BarModule
*/

#include <array>
#include "Processor.hpp"
#include "ProcessorData.hpp"
#include "BarModule.hpp"

BarModule::BarModule(int col, int row, AMonitorModule *m, int key, int index, int size)
    : ANCursesModules(col, row, m, key, index, size)
{

}

BarModule::~BarModule()
{
}

void BarModule::display()
{
    NCursesDrawer d;
    std::string label = this->_module->getLabel();
    std::ostringstream sstr("");
    int x = 1;

    sstr << std::setw(COLS / 2 + label.length() / 2) << label <<  std::setw(COLS / 2 - label.length() / 2) << " " << std::endl;
    d.setColor(6);
    d.drawText(this->_col, this->_row, sstr.str().c_str());
    if (dynamic_cast<Processor *>(this->_module)) {
            Processor *p = (Processor *)(this->_module);
            ProcessorData *pData = (ProcessorData *)p->getDataC();
            float **cores = pData->cores;
            float *cpu = cores[0];
            d.setColor(0);
            dprintf(2, "Values %f %f\n", cpu[1], cpu[2]);
            d.drawFullBar(this->_col + x, COLS / 2 - (COLS * 0.8) / 2, COLS * 0.75, std::string("CPU"), cpu[0], cpu[1]);

            for (int i = 1; cores[i]; i++) {
                if (i % 2) {
                    x++;
                    d.drawFullBar(this->_col + x, this->_row, COLS * 0.38, std::to_string(i), cores[i][0], cores[i][1]);
                } else  {
                    d.drawFullBar(this->_col + x, COLS / 2, COLS * 0.38, std::to_string(i), cores[i][0], cores[i][1]);
                }
            }
            return;
    }
    throw std::runtime_error("BarModule shouldn't be called out of Processor Module");
}
