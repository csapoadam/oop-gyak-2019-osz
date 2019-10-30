#include "stdafx.h"
#include <iostream>
#include <stdlib.h> // exit-hez kell
#include "climenu.h"
#include "climenuitem.h"
// fontos: a header file-ok csak interfeszt tartalmaznak
// a forrasfajlok implementaljak a fv-eket es minden headert include-olnak
// (amit szukseges)
// a header file-okban minden osztalyt forward deklaralunk, amit ott hasznalunk
// -> ekkor soha nem lehet baj, mind1, milyen sorrendben include-olunk

void exitFunction() {
	exit(EXIT_SUCCESS);
}

void menuDisplayFunction() {
	std::cout << "Here is the menu, dear guest" << std::endl;
}

void menuRefreshFunction() {
	std::cout << "Refreshing menu..." << std::endl;
}

void about() {
	std::cout << "I'm telling you I don't know anything" << std::endl;
}

int main() {
	CliMenu mainMenu;
	CliMenu helpSubmenu;

	CliMenuItem item1("Display restaurant menu", &menuDisplayFunction);
	CliMenuItem item2("Refresh menu", &menuRefreshFunction); // beolvassa a legujabb menut egy file-bol
	CliMenuItem item3("Help", &helpSubmenu); // help almenut jeleniti meg
	CliMenuItem item4("Exit", &exitFunction);

	mainMenu.addItem(&item1);
	mainMenu.addItem(&item2);
	mainMenu.addItem(&item3);
	mainMenu.addItem(&item4);

	CliMenuItem item5("About this restaurant", &about); // beolvassa az about-ot egy file-bol...
	CliMenuItem item6("Back to main menu", &mainMenu);

	helpSubmenu.addItem(&item5);
	helpSubmenu.addItem(&item6);

	// ---------------------

	mainMenu.display();
	CliMenu* whatMenuIsDisplayed = &mainMenu;
	
	int choice;
	while (true) {
		std::cin >> choice;
		CliMenu* nextMenuToDisplay = whatMenuIsDisplayed->selectItem(choice);

		nextMenuToDisplay->display();
		whatMenuIsDisplayed = nextMenuToDisplay;
	}

	std::cin.get();
	return 0;
}