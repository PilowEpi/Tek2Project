
#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input,
                                         std::ostream &output)
   try : _api(input, output) {

   } catch (const std::exception& e) {
        std::string error;
        error.assign(e.what());
        error = "Error: " + error;
        throw CommunicationError(error);
};

CommunicationDevice::~CommunicationDevice()
{
}

void
CommunicationDevice::startMission(std::string const &missionName,
                                  std::string *users,
                                  size_t nbUsers)
{
    std:: string error;

    try {
        for (size_t i = 0; i < nbUsers; ++i)
            _api.addUser(users[i]);

        _api.startMission(missionName);
    } catch (std::logic_error &e) {
        error.assign(e.what());
        error = "LogicError: " + error;
        throw CommunicationError(error);
    } catch (std::runtime_error &e ) {
        error.assign(e.what());
        error = "RuntimeError: " + error;
        throw CommunicationError(error);
    } catch (std::exception &e) {
        error.assign(e.what());
        error = "Error: " + error;
        throw CommunicationError(error);
    }
}

void
CommunicationDevice::send(std::string const &user,
                          std::string const &message) const
{
    try {
        _api.sendMessage(user, message);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void
CommunicationDevice::receive(std::string const &user,
                             std::string &message) const
{
    try {
        _api.receiveMessage(user, message);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "INVALID MESSAGE" << std::endl;
    }
}
