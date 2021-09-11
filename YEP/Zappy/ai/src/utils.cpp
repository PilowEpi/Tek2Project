#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <string>
#include <cstring>
#include <ext/stdio_filebuf.h>
#include <thread>
#include <boost/algorithm/string/trim.hpp>

#include "utils.hpp"
#include "ai.hpp"

Object objectNameToEnum(std::string name)
{
    boost::trim(name);
    if (name == "player")   return Object::PLAYER;
    if (name == "food")     return Object::FOOD;
    if (name == "linemate") return Object::LINEMATE;
    if (name == "deraumere")return Object::DERAUMERE;
    if (name == "sibur")    return Object::SIBUR;
    if (name == "mendiane") return Object::MENDIANE;
    if (name == "phiras")   return Object::PHIRAS;
    if (name == "thystame") return Object::THYSTAME;
    throw std::invalid_argument(name);
}

std::string enumToObjectName(Object obj)
{
    if (obj == Object::PLAYER)      return "player";
    if (obj == Object::FOOD)        return "food";
    if (obj == Object::LINEMATE)    return "linemate";
    if (obj == Object::DERAUMERE)   return "deraumere";
    if (obj == Object::SIBUR)       return "sibur";
    if (obj == Object::MENDIANE)    return "mendiane";
    if (obj == Object::PHIRAS)      return "phiras";
    if (obj == Object::THYSTAME)    return "thystame";
    throw std::invalid_argument(std::to_string(int(obj)));
}

std::string makeMessage(Ai &ai, int type) {
    std::string msg = std::to_string(MAGIC) + "|" + std::to_string(ai.rollId++) + "|" + std::to_string(ai.playerId) + "|" + std::to_string(type) + "|";

    // player inventory
    for (int i = 1; i <= 7; i++) {
        msg += std::to_string(ai.inventory[(Object)i]) + "|";
    }

    // refferentiel id and cordinate
    msg += std::to_string(ai.mapId) + "|" + std::to_string(ai.simulate_position.x)   + "|" + std::to_string(ai.simulate_position.y) + "|" + std::to_string(ai.simulate_dir) + "|" + std::to_string(ai.level) + "|";

    // player map
    for (auto &line : ai.map) {
        for (auto &cell : line) {
            msg += std::to_string(cell.time) + "|";
            for (int i = 0; i <= 7; i++) {
                msg += std::to_string(cell.objects[(Object)i]) + "|";
            }
        }
    }
    return msg;
}

std::vector<std::string> split(const std::string &origin, std::string delim)
{
    std::size_t start = 0U;
    std::size_t end = origin.find(delim);
    std::vector<std::string> splited;

    while (end != std::string::npos) {
        std::string list_item(origin.substr(start, end - start));
        splited.push_back(list_item);

        start = end + 1;
        end = origin.find(delim, start);
    }
    std::string lstr = origin.substr(start, origin.size());
    splited.push_back(lstr);
    return splited;
}

Vec2 directionToDeltaVec(edir dir) {
    if (dir == NORTH)
        return Vec2(0, -1);
    else if (dir == SOUTH)
        return Vec2(0, 1);
    else if (dir == EAST)
        return Vec2(0, 1);
    return Vec2(0, -1);
}

edir DeltaVecToEdir(Vec2 vec) {
    if (vec.x > 0)
        return EAST;
    else if (vec.x < 0)
        return WEST;
    else if (vec.y > 0)
        return SOUTH;
    return NORTH;
}

void print_map(Ai &ai) {
    std::cout << "My " << "MAP" << std::endl;
    Vec2 pos(0, 0);
    Vec2 Dpos = directionToDeltaVec(ai.dir);
    Vec2 sDpos = directionToDeltaVec(ai.simulate_dir);
    for (auto &line : ai.map) {
        for (auto &cell : line) {
            std::cout << "|" << cell.objects[PLAYER] << " " << cell.objects[FOOD] << " " << cell.objects[LINEMATE];
        }
        std::cout << "|" << std::endl;
        pos.y = 0;
        for (auto &cell : line) {
            if (pos == ai.position)
                std::cout << "|" << cell.objects[DERAUMERE] << " " << "X" << " " << cell.objects[SIBUR];
            else if (pos == (ai.position+Dpos+ai.worldSize)%ai.worldSize)
                std::cout << "|" << cell.objects[DERAUMERE] << " " << "*" << " " << cell.objects[SIBUR];
            else if (pos == (ai.position+sDpos+ai.worldSize)%ai.worldSize)
                std::cout << "|" << cell.objects[DERAUMERE] << " " << "o" << " " << cell.objects[SIBUR];
            else
                std::cout << "|" << cell.objects[DERAUMERE] << " " << " " << " " << cell.objects[SIBUR];
            pos.y++;
        }
        std::cout << "|" << std::endl;
        for (auto &cell : line) {
            std::cout << "|" << cell.objects[MENDIANE] << " " << cell.objects[PHIRAS] << " " << cell.objects[THYSTAME];
        }
        std::cout << "|" << std::endl;
        for (auto &cell : line) {
            (void)cell;
            std::cout << "------";
        }
        std::cout << "-" << std::endl;
        pos.x++;
    }
}

void print_map(Friend &ai_friend) {
    std::cout << "My " << "MAP" << std::endl;
    Vec2 pos(0, 0);
    for (auto &line : ai_friend.map) {
        for (auto &cell : line) {
            std::cout << "|" << cell.objects[PLAYER] << " " << cell.objects[FOOD] << " " << cell.objects[LINEMATE];
        }
        std::cout << "|" << std::endl;
        pos.y = 0;
        for (auto &cell : line) {
            if (pos == ai_friend.position)
                std::cout << "|" << cell.objects[DERAUMERE] << " " << "X" << " " << cell.objects[SIBUR];
            else
                std::cout << "|" << cell.objects[DERAUMERE] << " " << " " << " " << cell.objects[SIBUR];
            pos.y++;
        }
        std::cout << "|" << std::endl;
        for (auto &cell : line) {
            std::cout << "|" << cell.objects[MENDIANE] << " " << cell.objects[PHIRAS] << " " << cell.objects[THYSTAME];
        }
        std::cout << "|" << std::endl;
        for (auto &cell : line) {
            (void)cell;
            std::cout << "------";
        }
        std::cout << "-" << std::endl;
        pos.x++;
    }
}

int create_socket(std::string ip, int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;

    if (sock < 0)
        return (-1);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr) < 0) {
        perror("inet_pton");
        return (-1);
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return (-1);
    }
    return (sock);
}

int sendall(int fd, const char *data, int size)
{
    while (size > 0){
        int sendedsize = write(fd, data, size);
        if (sendedsize < 0) {
            perror("sendall failed");
            return 0;
        }
        size -= sendedsize;
        data += sendedsize;
    }
    return 1;
}

int get_x(int id, int rot)
{
    int cur = 0;

    if (id == 0)
        return 0;

    for (int i = 1; i < 10; i ++) {
        for (int j = -i; j < i + 1; j++) {
            cur++;
            if (cur == id) {
                switch (rot) {
                case NORTH:
                    return j; 
                case EAST:
                    return i; 
                case SOUTH:
                    return -j; 
                case WEST:
                    return -i; 
                }
            }
        }
    }
    return 0;
}

int get_y(int id, int rot)
{
    int cur = 0;

    if (id == 0)
        return 0;

    for (int i = 1; i < 10; i ++) {
        for (int j = -i; j < i + 1; j++) {
            cur++;
            if (cur == id) {
                switch (rot) {
                case NORTH:
                    return -i;
                case EAST:
                    return j;
                case SOUTH:
                    return i;
                case WEST:
                    return -j;
                }
            }
        }
    }
    return 0;
}