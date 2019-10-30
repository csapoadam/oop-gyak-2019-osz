#pragma once

#include <iostream>
#include <vector>
#include <string>

// forward deklaracio szukseges!
//class CliMenuItem;
// kulonben:
// CliMenuItem: undeclared identifier
// -> nincs deklaralva!
class CliMenuItem;

class CliMenu {
private:
	std::vector<CliMenuItem*> menuItems;
public:
	void addItem(CliMenuItem* clip) {
		menuItems.push_back(clip);
	}
	void display() {
		int itemCounter = 1;
		// use of undefined type 'CliMenuItem'
		// -> nincs definialva!
		for (CliMenuItem* clip : menuItems) {
			std::cout << itemCounter << ": " << clip->getItemText()
				<< std::endl;
			itemCounter++;
		}
	}
};

class CliMenuItem {
private:
	std::string itemText;
	CliMenu* itemSubMenu;
	void (*functionPointer)(); // main-ben levo exitFunction()
	// alapjan tudjuk, hogy ilyen fv pointer kell ide
public:
	CliMenuItem(const std::string& text, CliMenu* submenu) {
		itemText = text;
		itemSubMenu = submenu;
	}
	CliMenuItem(const std::string& text, void (*fp)()) {
		itemText = text;
		functionPointer = fp;
	}
	std::string& getItemText() {
		return itemText;
	}
};