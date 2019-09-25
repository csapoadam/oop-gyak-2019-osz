#pragma once

#include <iostream>
#include <vector>
#include <string>

class Player {
	std::string name;
	int id;
public:
	Player(const std::string& name) : name(name) {
		static int idcnt = 0;
		id = idcnt;
		idcnt++;
	}
	int getId() { return id; }
	std::string getName() { return name; }
};

enum class POSITIONS {
	forward,
	midfield,
	defense,
	goalkeeper,
	none
};

class Team {
	std::vector<Player*> players;
	std::vector<int> jerseynums;
	std::vector<POSITIONS> positions;
public:
	void addPlayer(Player& p, int jerseyNum) {
		players.push_back(&p);
		jerseynums.push_back(jerseyNum);
		positions.push_back(POSITIONS::none);
	}
	void setPosition(Player& player, POSITIONS pos) {
		// meg kell keresni azt a jatekost a players vectorban
		// es kell tudni az indexet!!
		int inxcnt = 0;
		for (Player* pp : players) {
			if (player.getId() == pp->getId()) {
				positions.at(inxcnt) = pos;
				break;
			}
			inxcnt++;
		}
	};
	void printPlayers() {
		std::cout << "List of players in team:" << std::endl;
		for (int inx = 0; inx < players.size(); inx++) {
			std::cout << jerseynums.at(inx);
			std::cout << ": " << players.at(inx)->getName();
			switch (positions.at(inx)) {
				case POSITIONS::forward:
					std::cout << "(playing as a forward)";
					break;
				case POSITIONS::midfield:
					std::cout << "(playing as a midfielder)";
					break;
				case POSITIONS::defense:
					std::cout << "(playing as a defender)";
					break;
				case POSITIONS::goalkeeper:
					std::cout << "(playing as a goalkeeper)";
					break;
				default:
					std::cout << "(playing in an undefined role)";
					break;
			}
			
			std::cout << std::endl;
		}
	}
};
