#include <memory>
#include <unistd.h>
#include <cstring>
#include <boost/algorithm/string/trim.hpp>

#include "ai.hpp"
#include "utils.hpp"

#define IS_CMD(cmd, name) (cmd.find(name, 0) != std::string::npos)

void Ai::setResponses()
{
    if (oldCommands.empty())
        return;
    int responseC = 0;
    for (auto ocb = oldCommands.begin(); ocb != oldCommands.end(); ocb++, responseC++) {
        std::string response = getResponse();
        if (response.empty()) {
            continue;
        }
        answers.push_back({*ocb, response});
    }
    for (int i = 0; i < responseC; i++)
        oldCommands.pop_front();
}

void Ai::sendCommands()
{
    int commandSended = 0;
    for (auto cb = commands.begin(); cb != commands.end(); cb++, commandSended++) {
        if (commandSended == 10) break;
        sendall(sock, cb->c_str(), cb->size());
        oldCommands.push_back(*cb);
    }
    for (int i = 0; i < commandSended; i++)
        commands.pop_front();
}

void Ai::automaticWorkflow()
{
    if (commands.empty()) return;
    while (!commands.empty()) {
        auto timeNow = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(timeNow - timeLast);
        // addTimeToMap
        for (auto &line : map)
            for (auto &cell : line)
                cell.time += time_span.count()*1e6;
        timeLast = timeNow;
        sendCommands();
    }
    setResponses();
    traductAnswers();
}



/**
 * Méthode pas testé
**/
/*
ReceivedMesssage Ai::loadMessage(std::string message)
{
        ReceivedMesssage newmessage;
        newmessage.position = sposition;
        Vec2 directionVec2 = sposition;
        std::string strdirection = message.substr(8, 9);
        int direction = std::atoi(strdirection.c_str());
        std::cout << "broadcast dir " << direction << std::endl;
        print_map();
        for (int i = 0; i != responses.size(); i++) {
            auto cmd = oldCommands[i];
            auto res = responses[i];
            if (IS_CMD(cmd, "Left\n")) {
                if (res == "ko") continue;
                if (dir == NORTH) {
                    dir = WEST;
                } else if (dir == WEST) {
                    dir = SOUTH;
                } else if (dir == SOUTH) {
                    dir = EAST;
                } else if (dir == EAST) {
                    dir = NORTH;
                } else {
                    throw std::runtime_error("Invalid direction");
                }
            }
            if (IS_CMD(cmd, "Right\n")) {
                if (res == "ko") continue;
                if (dir == NORTH) {
                    dir = EAST;
                } else if (dir == EAST) {
                    dir = SOUTH;
                } else if (dir == SOUTH) {
                    dir = WEST;
                } else if (dir == WEST) {
                    dir = NORTH;
                } else {
                    throw std::runtime_error("Invalid direction");
                }
            }
        }
        switch (direction) {
            case 0:
                directionVec2 = sposition;
                break;
            case 1:
                if (dir == NORTH) {
                    directionVec2.y -= 1;
                } else if (dir == SOUTH) {
                    directionVec2.y += 1;
                } else if (dir == EAST) {
                    directionVec2.x += 1;
                } else if (dir == WEST) {
                    directionVec2.x -= 1;
                }
                break;
            case 2:
                if (dir == NORTH) {
                    directionVec2.y -= 1;
                    directionVec2.x -= 1;
                } else if (dir == SOUTH) {
                    directionVec2.y += 1;
                    directionVec2.x += 1;
                } else if (dir == EAST) {
                    directionVec2.x += 1;
                    directionVec2.y -= 1;
                } else if (dir == WEST) {
                    directionVec2.x -= 1;
                    directionVec2.y += 1;
                }
                break;
            case 3:
                if (dir == NORTH) {
                    directionVec2.x -= 1;
                } else if (dir == SOUTH) {
                    directionVec2.x += 1;
                } else if (dir == EAST) {
                    directionVec2.y += 1;
                } else if (dir == WEST) {
                    directionVec2.y -= 1;
                }
                break;
            case 4:
                if (dir == NORTH) {
                    directionVec2.y += 1;
                    directionVec2.x -= 1;
                } else if (dir == SOUTH) {
                    directionVec2.y -= 1;
                    directionVec2.x += 1;
                } else if (dir == EAST) {
                    directionVec2.x -= 1;
                    directionVec2.y -= 1;
                } else if (dir == WEST) {
                    directionVec2.x += 1;
                    directionVec2.y += 1;
                }
                break;
            case 5:
                if (dir == NORTH) {
                    directionVec2.y += 1;
                } else if (dir == SOUTH) {
                    directionVec2.y -= 1;
                } else if (dir == EAST) {
                    directionVec2.x -= 1;
                } else if (dir == WEST) {
                    directionVec2.x += 1;
                }
                break;
            case 6:
                if (dir == NORTH) {
                    directionVec2.y += 1;
                    directionVec2.x += 1;
                } else if (dir == SOUTH) {
                    directionVec2.y -= 1;
                    directionVec2.x -= 1;
                } else if (dir == EAST) {
                    directionVec2.x -= 1;
                    directionVec2.y += 1;
                } else if (dir == WEST) {
                    directionVec2.x += 1;
                    directionVec2.y -= 1;
                }
                break;
            case 7:
                if (dir == NORTH) {
                    directionVec2.x += 1;
                } else if (dir == SOUTH) {
                    directionVec2.x -= 1;
                } else if (dir == EAST) {
                    directionVec2.y += 1;
                } else if (dir == WEST) {
                    directionVec2.y -= 1;
                }
                break;
            case 8:
                if (dir == NORTH) {
                    directionVec2.y -= 1;
                    directionVec2.x += 1;
                } else if (dir == SOUTH) {
                    directionVec2.y += 1;
                    directionVec2.x -= 1;
                } else if (dir == EAST) {
                    directionVec2.x += 1;
                    directionVec2.y += 1;
                } else if (dir == WEST) {
                    directionVec2.x -= 1;
                    directionVec2.y -= 1;
                }
                break;
            default:
                throw std::logic_error("Invalid case direction");
        }
        if (directionVec2.x < 0) directionVec2.x = worldSize.x + directionVec2.x;
        if (directionVec2.x >= worldSize.x) directionVec2.x = directionVec2.x % worldSize.x;
        if (directionVec2.y < 0) directionVec2.y = worldSize.y + directionVec2.y;
        if (directionVec2.y >= worldSize.y) directionVec2.y = directionVec2.y % worldSize.y;
        std::cout << "MyPos : x" << sposition.x << " y" << sposition.y << std::endl;
        std::cout << "MyDir : " << dir << std::endl;
        std::cout << "DirPos : x" << directionVec2.x << " y" << directionVec2.y << std::endl;
        std::cout << "For case : " << direction << std::endl;
        newmessage.direction = directionVec2;
        newmessage.message = message.substr(11, message.size());
        return newmessage;
}
*/

/**
 *  NORTH   = UP    = -y = map[c.x][c.y - 1]
 *  EAST    = RIGHT = +x = map[c.x + 1][c.y]
 *  if (c.x >= worldSize.x -> 0) || c.x - 1 == -1 -> c.x == worldSize.x - 1
**/            
void Ai::traductAnswers()
{
    for (auto it = answers.begin(); it != answers.end(); it++) {
        std::string command = it->first;
        std::string answer  = it->second;
        if (IS_CMD(command, "Forward\n")) {
            if (answer == "ko") continue;
            if (dir == NORTH) {
                position.y -= 1;
            } else if (dir == EAST) {
               position.x += 1;
            } else if (dir == SOUTH) {
                 position.y += 1;
            } else if (dir == WEST) {
                 position.x -= 1;
            } else {
                throw std::runtime_error("Invalid direction");
            }
            if (position.x < 0) {
                   position.x = worldSize.x - 1;
            } else if (position.x == worldSize.x) {
                   position.x = 0;
            }
            if (position.y < 0) {
                position.y = worldSize.y - 1;
            } else if (position.y == worldSize.y) {
                position.y = 0;
            }
        }
        if (IS_CMD(command, "Left\n")) {
            if (answer == "ko") continue;
            if (dir == NORTH) {
                dir = WEST;
            } else if (dir == WEST) {
                dir = SOUTH;
            } else if (dir == SOUTH) {
                dir = EAST;
            } else if (dir == EAST) {
                dir = NORTH;
            } else {
                throw std::runtime_error("Invalid direction");
            }
        }
        if (IS_CMD(command, "Right\n")) {
            if (answer == "ko") continue;
            if (dir == NORTH) {
                dir = EAST;
            } else if (dir == EAST) {
                dir = SOUTH;
            } else if (dir == SOUTH) {
                dir = WEST;
            } else if (dir == WEST) {
                dir = NORTH;
            } else {
                throw std::runtime_error("Invalid direction");
            }
        }
        if (IS_CMD(command, "Look\n")) {
            std::string caseList = answer.substr(1, answer.size() - 2);
            boost::trim(caseList);

            std::vector<std::string> splitedCaseList = split(caseList, ",");
            for (std::size_t i = 0; i < splitedCaseList.size(); i++) {
                std::string str = splitedCaseList[i];
                boost::trim(str);
                std::vector<std::string> items = split(str, " ");
                int xdif = get_x(i, (int) dir);
                int ydif = get_y(i, (int) dir);
                int x = position.x + xdif;
                int y = position.y + ydif;
                if (x < 0) x = worldSize.x + x;
                if (x >= worldSize.x) x = x % worldSize.x;
                if (y < 0) y = worldSize.y + y;
                if (y >= worldSize.y) y = y % worldSize.y;
                map[x][y].objects.clear();
                for (std::size_t z = 0; z < items.size(); z++) {
                    std::string item = items[z];
                    if (item.empty()) continue;
                    Object o = objectNameToEnum(item);
                    map[x][y].objects[o]++;
                    map[x][y].time = 0;
                }
            }
            map[position.x][position.y].objects[PLAYER]--;
        }
        if (IS_CMD(command, "Inventory\n")) {
            std::string inventoryString = answer.substr(1, answer.size() -1);
            boost::trim(inventoryString);
            std::vector<std::string> inventoryList = split(inventoryString, ",");
            for (std::size_t i = 0; i < inventoryList.size(); i++) {
                std::string item_with_count = inventoryList[i];
                boost::trim(item_with_count);
                if (item_with_count.empty()) continue;
                int delim = item_with_count.find(" ");
                Object o = objectNameToEnum(item_with_count.substr(0, delim));
                inventory[o] = std::atoi(item_with_count.substr(delim, item_with_count.size()).c_str());
            }
        }
        if (IS_CMD(command, "Connect_nbr\n")) {
            if (std::atoi(answer.c_str()) > 0) {
                // TODO fork.
            }
        }
        if (IS_CMD(command, "Fork\n")) {
            // TODO determine what todo
        }
        if (IS_CMD(command, "Eject\n")) {
            // Server fault ! Do nothing
        }
        if (IS_CMD(command, "Take")) {
            Object o = objectNameToEnum(command.substr(5, command.size() - 1));
            if (answer == "ko") {
                map[position.x][position.y].objects[o] = 0;
                continue;
            }
            inventory[o]++;
            map[position.x][position.y].objects[o]--;
        }
        if (IS_CMD(command, "Set")) {
            Object o = objectNameToEnum(command.substr(4, command.size() - 1));
            if (answer == "ko") {
                inventory[o] = 0;
                continue;
            }
            inventory[o]--;
            map[position.x][position.y].objects[o]++;
        }
        if (IS_CMD(command, "Incantation")) {
            // TODO something
        }
        if (IS_CMD(command, "Broadcast")) {
            //std::string arg = command.substr(10, command.size() - 1);
        }
    }
    answers.clear();
}