/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "IComponent.hpp"
#include "Error.hpp"
#include "APin.hpp"
#include <vector>
#include <map>

namespace nts
{
    class AComponent : public nts::IComponent
    {
        public:
            // Ctor Dtor
            AComponent(const std::string &name, const std::string &type, size_t nbrPin);
            ~AComponent();
        
            // IComponent MF
            virtual void simulate(size_t tick) = 0;
            void dump();
            nts::Tristate compute(size_t pin);
            void setLink(size_t pin, nts::IComponent &other, size_t otherPin);

            // Creation
            void addLink(nts::IComponent *link, size_t start, size_t dest);

            // Data sended
            void sendData(size_t pin, nts::IComponent *link);
            void simulateBack(size_t pin);

            // Setter
            void setPinValue(size_t pin, nts::Tristate value);
            void setCompute(bool value);
            void setLast(nts::Tristate value);

            // Getter
            std::string getName() const { return _name;};
            std::map<size_t, nts::APin *> getPins() const { return _pins;};
            std::string getType() const { return _type;};
            bool getCompute() const { return _isCompute;};
            std::map<size_t, std::pair<size_t, nts::IComponent *>> getLinks() const { return _links;};

            // Getter Spec
            nts::Tristate getValuePin(size_t pin);
            nts::Tristate getSimplePin(size_t pin) {return this->_pins[pin]->getPinValue();};
            nts::PinType getPinType(size_t pin);
            nts::IComponent *getLink(size_t pin);

            // Type Print
            std::string getTypeFormated(nts::PinType type);
            std::string getValueFormated(nts::Tristate value);

            // Clock methods
            void makeInit() {_init = 0;};
            int _init;
        protected:
            nts::Tristate _last;
            std::string _name;
            std::string _type;
            size_t _nbrPin;
            bool _isCompute;
            
            // Liste de pin du Component
            std::map<size_t, nts::APin *> _pins;
            
            // Les links des pins
            std::map<size_t, std::pair<size_t, nts::IComponent *>> _links;

        private:
    };
};

#endif