#include "stdafx.h"
#include <iostream>
#include <stdlib.h> // exit-hez kell
#include "climenu.h"

void exitFunction() {
	exit(EXIT_SUCCESS)
}

int main() {
	CliMenu mainMenu;
	CliMenu helpSubmenu;

	CliMenuItem item1("Display restaurant menu", &menuDisplayFunction);
	CliMenuItem item2("Refresh menu", &menuRefreshFunction); // beolvassa a legujabb menut egy file-bol
	CliMenuItem item3("Help", &helpSubmenu); // help almenut jeleniti meg
	CliMenuItem item4("Exit", &exitFunction);

	mainMenu.addItem(item1);
	mainMenu.addItem(item2);
	mainMenu.addItem(item3);
	mainMenu.addItem(item4);

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
		CliMenu* perhapsNewMenu = whatMenuIsDisplayed->selectItem(choice);

		// ha almenure kattintottunk, az ujat kell megjeleniteni...
		// ellenkezo esetben a regit...
		// ezzel meg ki kell egesziteni ezt a while ciklust!
		// selectItem persze gondoskodik a fv meghivasarol is, ha arrol van szo
	}

	std::cin.get();
    return 0;
}