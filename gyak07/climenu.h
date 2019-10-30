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
	void display();
	CliMenu* selectItem(int choice); // ez is csak kivul definialhato
	// mivel kell hozza CliMenuItem
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
		functionPointer = nullptr;
	}
	CliMenuItem(const std::string& text, void (*fp)()) {
		itemText = text;
		functionPointer = fp;
		itemSubMenu = nullptr;
	}
	std::string& getItemText() {
		return itemText;
	}
	void call() {
		if (functionPointer) {
			functionPointer();
		}
	}
	CliMenu* getSubMenu() {
		return itemSubMenu;
	}
};

void CliMenu::display() {
	int itemCounter = 1;
	// use of undefined type 'CliMenuItem'
	// -> nincs definialva!
	for (CliMenuItem* clip : menuItems) {
		std::cout << itemCounter << ": " << clip->getItemText()
			<< std::endl;
		itemCounter++;
	}
}

CliMenu* CliMenu::selectItem(int choice) {
	// ket opcio: menuItems[x], menuItems.at(x)
	// de az .at() az bound check-et is tartalmaz
	try {
		CliMenuItem* mip = menuItems.at(choice-1); // at az 0-tol szamoz
		mip->call();
		CliMenu* smp = mip->getSubMenu();
		if (smp) {
			return smp;
		}
		else {
			return this;
		}
	}
	catch (std::out_of_range e) {
		std::cout << "No such menu item, dodo!" << std::endl;
		return this;
	}
}