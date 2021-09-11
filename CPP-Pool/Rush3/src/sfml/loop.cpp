#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <list>
#include <deque>
#include <array>
#include <unistd.h>

#include "display.hpp"

#include "IMonitorModule.hpp"

#include "Processor.hpp"
#include "ProcessorData.hpp"

#include "System.hpp"

#include "Username.hpp"
#include "Hostname.hpp"
#include "Uptime.hpp"
#include "Time.hpp"
#include "Networking.hpp"
#include "NetworkData.hpp"

void fonc_cpu(SfmlModuleButton &a)
{
    static bool val = false;
    a._sfml->activateById("CPU", val);
    a._sfml->reorganizeModules();
    val = !val;
}

void fonc_username(SfmlModuleButton &a)
{
    static bool val = false;
    a._sfml->activateById("Username", val);
    a._sfml->reorganizeModules();
    val = !val;
}

void fonc_system(SfmlModuleButton &a)
{
    static bool val = false;
    a._sfml->activateById("System", val);
    a._sfml->reorganizeModules();
    val = !val;
}

void fonc_hostname(SfmlModuleButton &a)
{
    static bool val = false;
    a._sfml->activateById("Hostname", val);
    a._sfml->reorganizeModules();
    val = !val;
}

void fonc_time(SfmlModuleButton &a)
{
    static bool val = false;
    a._sfml->activateById("Time", val);
    a._sfml->reorganizeModules();
    val = !val;
}

void fonc_uptime(SfmlModuleButton &a)
{
    static bool val = false;
    a._sfml->activateById("UpTime", val);
    a._sfml->reorganizeModules();
    val = !val;   
}

void fonc_mem(SfmlModuleButton &a)
{
    static bool val = false;
    a._sfml->activateById("MEM", val);
    a._sfml->reorganizeModules();
    val = !val;
}

void fonc_net(SfmlModuleButton &a)
{
    static bool val = false;
    a._sfml->activateById("NET", val);
    a._sfml->reorganizeModules();
    val = !val;   
}

void sfmlLoop(std::list<AMonitorModule *> &modules)
{
    
    SfmlDisplay sfml(400, 800);
    
    sf::Color colors[] = {sf::Color::Green, sf::Color::Red};

    // Username    
    for (IMonitorModule *mod : modules) {
        if (dynamic_cast<Username *>(mod)) {
            std::string &button_str = mod->getLabel();
            SfmlModuleButton *font = new SfmlModuleButton(sfml._width, 25, button_str, fonc_username); 
            font->_id = "";
            sfml.addModule(font);

            std::string &Username_str = mod->getString();
            SfmlModuleText *fontud = new SfmlModuleText(sfml._width, 25, Username_str); 
            fontud->_id = "Username";
            sfml.addModule(fontud);
        }
    }

    // Hostname
    for (IMonitorModule *mod : modules) {
        if (dynamic_cast<Hostname *>(mod)) {
            std::string &button_str = mod->getLabel();
            SfmlModuleButton *font = new SfmlModuleButton(sfml._width, 25, button_str, fonc_hostname); 
            font->_id = "";
            sfml.addModule(font);


            std::string &Hostname_str = mod->getString();
            SfmlModuleText *fonthd = new SfmlModuleText(sfml._width, 25, Hostname_str); 
            fonthd->_id = "Hostname";
            sfml.addModule(fonthd);
        }
    }

    // System
    for (IMonitorModule *mod : modules) {
        if (dynamic_cast<System *>(mod)) {
            std::string &Systeml_str = mod->getLabel();
            SfmlModuleButton *font = new SfmlModuleButton(sfml._width, 25, Systeml_str, fonc_system); 
            font->_id = "";
            sfml.addModule(font);


            std::string &System_str = mod->getString();
            SfmlModuleText *fontsd = new SfmlModuleText(sfml._width, 17, System_str); 
            fontsd->_id = "System";
            sfml.addModule(fontsd);
        }
    }

    // CPU
    std::string CPU_str = "CPU";
    for (IMonitorModule *mod : modules) {
        if (dynamic_cast<Processor *>(mod)) {
            SfmlModuleButton *font = new SfmlModuleButton(50, 25, CPU_str, fonc_cpu); 
            font->_id = "";
            sfml.addModule(font);

            Processor *process = (Processor *) mod;
            ProcessorData *bla = (ProcessorData *) process->getDataC();
            float **cores = bla->cores;

            //display cpu bar
            float *data = cores[0];
            SfmlModuleBar *barmod = new SfmlModuleBar(350, 25, data, colors);
            barmod->_id = "CPU";
            sfml.addModule(barmod);

            //dislay thread bar
            for  (int i = 1; cores[i]; i++){
                std::string *thread_str = new std::string();
                *thread_str = std::to_string(i);
                SfmlModuleText *font = new SfmlModuleText(25, 25, *thread_str); 
                font->_id = "CPU";
                sfml.addModule(font);
                
                data = cores[i];
                SfmlModuleBar *barmod = new SfmlModuleBar(175, 25, data, colors);
                barmod->_id = "CPU";
                sfml.addModule(barmod);
            }

            //display proc graph
            std::deque<float *> &datafloat = bla->getAverage();
            SfmlModuleGraph *graphmod = new SfmlModuleGraph(sfml._width, 100, datafloat, colors);
            graphmod->_id = "CPU";
            sfml.addModule(graphmod);
        }
    }
    
    // Time
    for (IMonitorModule *mod : modules) {
        if (dynamic_cast<Time *>(mod)) {
            std::string &str = mod->getLabel();
            SfmlModuleButton *font = new SfmlModuleButton(sfml._width, 25, str, fonc_time); 
            font->_id = "";
            sfml.addModule(font);
            
            std::string &str2 = mod->getString();
            SfmlModuleText *mod = new SfmlModuleText(sfml._width, 17, str2); 
            mod->_id = "Time";
            sfml.addModule(mod);
        }
    }

    // UpTime
    for (IMonitorModule *mod : modules) {
        if (dynamic_cast<Uptime *>(mod)) {
            std::string &str = mod->getLabel();
            SfmlModuleButton *font = new SfmlModuleButton(sfml._width, 25, str, fonc_uptime); 
            font->_id = "";
            sfml.addModule(font);

            std::string &str2 = mod->getString();
            SfmlModuleText *fontsd = new SfmlModuleText(sfml._width, 17, str2); 
            fontsd->_id = "UpTime";
            sfml.addModule(fontsd);
        }
    }

    // Memory
    for (IMonitorModule *mod : modules) {
        if (dynamic_cast<Memory *>(mod)) {
            std::string &str = mod->getLabel();
            SfmlModuleButton *font = new SfmlModuleButton(sfml._width, 25, str, fonc_mem); 
            font->_id = "";
            sfml.addModule(font);

            std::string *str2 = new std::string("RAM");
            SfmlModuleText *font2 = new SfmlModuleText(50, 25, *str2); 
            font2->_id = "MEM";
            sfml.addModule(font2);

            Memory *process = (Memory *) mod;
            RamData *bla = (RamData *) process->getDataC();
            float *data = bla->ram_percentage_bar;
            SfmlModuleBar *barmod = new SfmlModuleBar(350, 25, data, colors);
            barmod->_id = "MEM";
            sfml.addModule(barmod);

            std::string *str3 = new std::string("SWAP");
            SfmlModuleText *font3 = new SfmlModuleText(50, 25, *str3); 
            font3->_id = "MEM";
            sfml.addModule(font3);

            float *data2 = bla->swap_percentage_bar;
            SfmlModuleBar *barmod2 = new SfmlModuleBar(350, 25, data2, colors);
            barmod2->_id = "MEM";
            sfml.addModule(barmod2);
        }
    }

    // Networking
    for (IMonitorModule *mod : modules) {
        if (dynamic_cast<Networking *>(mod)) {
            Networking *networki = (Networking *) mod;
            NetworkData *bla = (NetworkData *) networki->getDataC();

            std::string *str = new std::string("Networking");
            SfmlModuleButton *font = new SfmlModuleButton(sfml._width, 25, *str, fonc_net); 
            font->_id = "";
            sfml.addModule(font);

            std::string *input = new std::string("Receiving");
            SfmlModuleText *fontinput = new SfmlModuleText(sfml._width / 2, 25, *input); 
            fontinput->_id = "NET";
            sfml.addModule(fontinput);

            std::string *output = new std::string("Transmiting");
            SfmlModuleText *fontoutput = new SfmlModuleText(sfml._width / 2, 25, *output); 
            fontoutput->_id = "NET";
            sfml.addModule(fontoutput);

            //dislay thread bar
            std::map<std::string, std::deque<float *>> &inputDeq = bla->getInput();
            std::map<std::string, std::deque<float *>> &outputDeq = bla->getOutput();
            for (std::pair<std::string, std::deque<float *>> pair : inputDeq) {
                std::string *netTitle = new std::string();
                *netTitle = pair.first;
                SfmlModuleText *font = new SfmlModuleText(sfml._width, 25, *netTitle); 
                font->_id = "NET";
                sfml.addModule(font);
                
                std::deque<float *> &datainput = inputDeq[pair.first];
                SfmlModuleGraph *graphmod = new SfmlModuleGraph(200, 100, datainput, colors);
                graphmod->_id = "NET";
                sfml.addModule(graphmod);

                std::deque<float *> &dataoutput = outputDeq[pair.first];
                SfmlModuleGraph *graphmod2 = new SfmlModuleGraph(200, 100, dataoutput, colors);
                graphmod2->_id = "NET";
                sfml.addModule(graphmod2);
            }            
        }
    }

    int frame = 1;
    while (sfml._window->isOpen())
    {
        sfml.display();
        if (!(frame%30))
            for (AMonitorModule *m : modules)
                m->refresh(); // TRY CATCH RUNTIME_ERROR !!!
        frame++;
    }
}
