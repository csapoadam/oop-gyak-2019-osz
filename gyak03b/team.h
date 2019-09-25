#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "positions.h"


class Player {
	std::string name;
	int id;
	static int PLAYERID_CNT;
public:
	Player(const std::string& name) : name(name) {
		id = PLAYERID_CNT;
		PLAYERID_CNT++;
	}
	int getId() { return id; }
	std::string getName() { return name; }
	static void setPlayerIdStart(int pidcnt) { PLAYERID_CNT = pidcnt;  }
};

int Player::PLAYERID_CNT = 0;

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
			std::cout << "(playing as a "
				<< stringify_position(positions.at(inx))
				<< ")";
			std::cout << std::endl;
		}
	}
};
