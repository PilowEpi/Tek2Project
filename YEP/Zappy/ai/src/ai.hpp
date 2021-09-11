#pragma once

#include <string>
#include <cstring>
#include <boost/algorithm/string/trim.hpp>
#include <unistd.h>
#include <mutex>
#include <map>
#include <vector>
#include <condition_variable>
#include <deque>
#include <thread>

#include "utils.hpp"

#include "friend.hpp"

class Ai {
public:
    Ai(std::string ip, int port, std::string team, bool nolog = false);

    int connnect();
    void startListening();
    int login();
    int compute();
    void stopListening(std::thread t);
    void startNew();
    
    void sendCommands();
    void setResponses();
    void traductAnswers();
    void automaticWorkflow();
    std::string getResponse();

    /* AI COMMANDS TO SERVER */
    void Forward();
    void Right();
    void Left();
    void Look();
    void Inventory();
    void Broadcast(std::string message);
    void Connect_nbr();
    void Fork();
    void Eject();
    void Take(std::string object);
    void Take(Object object);
    void Set(std::string object);
    void Set(Object object);
    void Incantation();

    /* Movement */
    void goToCell(Vec2 pos);
    void goToCellDelta(Vec2 posD);
    void turn(edir d);
    void goForward(int distance);

    /* Strategies */
    bool hasObjectToLevelUp();
    std::map<Object, int> getMissingObjectToLevelUp();
    bool canLevelUp();
    void goGetLevelUpItem();
    void goGetFood();
    //void goGetLevelUpItem();
    void goWandering();
    bool goTake(Object o);
    void lookAround();
    //void prepareIncantation();
    //void idleIncantation();
    void level2();
    Vec2 closestObject(Object o);

    /* From Server */
    std::deque<std::string> commands;
    std::deque<std::string> oldCommands;
    std::deque<std::string> responses;
    std::deque<std::pair<std::string, std::string>> answers;

    /* Variable Importante */
    int sock;
    std::string ip;
    int port;
    std::string team;
    bool nolog;
    Vec2 worldSize;
    Map map;
    int mapId;
    std::chrono::high_resolution_clock::time_point timeLast;
    int clientMax;

    /* Variable threading */
    std::mutex responseMutex;
    std::condition_variable responseVariable;
    bool shouldStopListening = false;

    /* Variable joueur */
    int rollId = 0;
    std::map<Object, int> inventory;
    Vec2 position = Vec2(0, 0);
    int playerId;
    enum edir dir = NORTH;
    int level = 1;
    
    /* Variable Simuler */
    Vec2 simulate_position = Vec2(0, 0);
    enum edir simulate_dir = NORTH;
};
