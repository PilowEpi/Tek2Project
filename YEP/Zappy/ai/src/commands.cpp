#include "ai.hpp"
#include "utils.hpp"

void Ai::Forward() {
	if (simulate_dir == NORTH) {
    	simulate_position.y -= 1;
    } else if (simulate_dir == EAST) {
    	simulate_position.x += 1;
    } else if (simulate_dir == SOUTH) {
        simulate_position.y += 1;
	} else if (simulate_dir == WEST) {
        simulate_position.x -= 1;
    } else {
        throw std::runtime_error("Invalid sdirection");
    }
    if (simulate_position.x < 0) {
        simulate_position.x = worldSize.x - 1;
    } else if (simulate_position.x == worldSize.x) {
        simulate_position.x = 0;
    }
    if (simulate_position.y < 0) {
    	simulate_position.y = worldSize.y - 1;
    } else if (simulate_position.y == worldSize.y) {
        simulate_position.y = 0;
    }
	commands.push_back("Forward\n");
}

void Ai::Right() {
	if (simulate_dir == NORTH) {
    	simulate_dir = EAST;
    } else if (simulate_dir == EAST) {
        simulate_dir = SOUTH;
    } else if (simulate_dir == SOUTH) {
        simulate_dir = WEST;
    } else if (simulate_dir == WEST) {
        simulate_dir = NORTH;
    } else {
        throw std::runtime_error("Invalid sdirection");
    }
	commands.push_back("Right\n");
}

void Ai::Left() {
	if (simulate_dir == NORTH) {
        simulate_dir = WEST;
    } else if (simulate_dir == WEST) {
        simulate_dir = SOUTH;
    } else if (simulate_dir == SOUTH) {
        simulate_dir = EAST;
    } else if (simulate_dir == EAST) {
        simulate_dir = NORTH;
    } else {
        throw std::runtime_error("Invalid sdirection");
    }
	commands.push_back("Left\n");
}

void Ai::Look() {
	commands.push_back("Look\n");
}

void Ai::Inventory() {
	commands.push_back("Inventory\n");
}

void Ai::Broadcast(std::string message) {
	commands.push_back(std::string("Broadcast " + message + "\n"));
}

void Ai::Connect_nbr() {
	commands.push_back("Connect_nbr\n");
}

void Ai::Fork() {
	commands.push_back("Fork\n");
}

void Ai::Eject() {
	commands.push_back("Eject\n");
}

void Ai::Take(std::string object) {
	commands.push_back(std::string("Take " + object + "\n"));
}

void Ai::Take(Object object) {
	std::string objName = enumToObjectName(object);
	commands.push_back(std::string("Take " + objName + "\n"));
}

void Ai::Set(std::string object) {
	commands.push_back(std::string("Set " + object + "\n"));
}


void Ai::Set(Object object) {
	std::string objName = enumToObjectName(object);
	commands.push_back(std::string("Set " + objName + "\n"));
}

void Ai::Incantation() {
	commands.push_back("Incantation\n");
}