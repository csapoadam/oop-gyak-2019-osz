// TeamManager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "team.h"


int main()
{
	/*Player mb("Mbappe");
	Player bl("blabla");
	Player bu("blublu");
	std::cout << "id of Mbappe: " << mb.getId() << std::endl;
	std::cout << "id of bl: " << bl.getId() << std::endl;
	std::cout << "id of bu: " << bu.getId() << std::endl;*/

	
	Team team;

	Player mbappe("Mbappe");
	team.addPlayer(mbappe, 9);
	
	team.setPosition(mbappe, POSITIONS::forward);
	// lehetne pointerrel is, akkor team-ben meg lehetne keresni a jatekost id nelkul is
	// team.setPosition(&mbappe, POSITIONS::forward)
	team.setPosition(mbappe, POSITIONS::midfield); // mindig a legutolso pozicio szamit

	Player verratti("Verratti");
	team.addPlayer(verratti, 5);

	team.setPosition(verratti, POSITIONS::defense);
	team.setPosition(verratti, POSITIONS::midfield);

	Player ambigo("Ambigo Rando");
	team.addPlayer(ambigo, 15);

	team.printPlayers(); // kiirja a jatekosok nevet, mezszamat es lehetseges pozicioit
	
	std::cin.get();
    return 0;
}

