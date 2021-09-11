#include <iostream>
#include <string>
#include "ai.hpp"

Ai::Ai(std::string ip, int port, std::string team, bool nolog) : 
    ip(ip), port(port), team(team), nolog(nolog)
{
    timeLast = std::chrono::high_resolution_clock::now();
    srand(time(0));
    playerId = rand();
}

int Ai::connnect()
{
    sock = create_socket(ip, port);
    if (sock != -1) return 0;
    return 1;
}

int Ai::login()
{
    {
        std::string response = getResponse();
        if (response != "WELCOME") return 1;
    }
    {
        try {
            if (team.back() != '\n') team += "\n";
            dprintf(sock, "%s", team.c_str());
            std::string response = getResponse();
            if (response == "ko") return 1;
            clientMax = std::atoi(response.c_str());
            std::string world = getResponse();
            int divider = world.find(" ");
            worldSize = Vec2(
                std::atoi(world.c_str()),
                std::atoi(world.c_str() + divider)
            );
            map.resize(worldSize.x);
            for (int i = 0; i < worldSize.x; i++) map[i].resize(worldSize.y);
        } catch (...) {
            return 1;
        }
        return 0;
    }
}

std::string Ai::getResponse() {
    std::unique_lock<std::mutex> lk(responseMutex);
    responseVariable.wait(lk, [this] () {return responses.size() > 0;});
    std::string response = responses.back();
    responses.pop_back();
    lk.unlock();
    return response;
}

void Ai::startListening() {
    while (1) {
        if (shouldStopListening) return;
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(sock, &fds);
        select(sock + 1, &fds, NULL, NULL, NULL);

        char buffer[4096];
        memset(buffer, 0, 4096);
        std::string msgTot = "";
        
        while (1) {
            int size = read(sock, buffer, 4095);
            if (size == -1)
                exit(84);
            if (size == 0) {
                continue;
            }
            buffer[size] = 0;
            msgTot += buffer;
            if (buffer[size-1] == '\n')
                break;
        }

        std::string response(msgTot.c_str());
        boost::trim(response);

        std::vector<std::string> lines = split(response, "\n");
        for (std::size_t i = 0; i < lines.size(); ++i) {
            std::cout << "{" <<  lines[i] << "}" << std::endl;
            if (lines[i].find("message", 0) != std::string::npos) {
                // TODO MESSAGE RECEIVED
                continue;
            } else if (lines[i].find("eject:", 0) != std::string::npos) {
                // TODO EJECT RECEIVED
                continue;
            } else if (lines[i].find("Current level", 0) != std::string::npos) {
                level++;
                continue;
            }
            // ADD RESPONSE
            responseMutex.lock();
            responses.push_front(lines[i]);
            responseMutex.unlock();
            responseVariable.notify_one();
        }        
    }
}

void Ai::stopListening(std::thread t) {
    shouldStopListening = true;
    t.join();
}

void Ai::startNew()
{
    std::string command("./zappy_ai -h ");
    command += ip + " -p " + std::to_string(port) + " -n " + team + " > /dev/null";
    if (fork()) {
        //*this = Ai(ip, port, team, true);
        // system(command.c_str());
        // exit(0);
    }
}

int Ai::compute()
{
    level2();
    return 1;
}