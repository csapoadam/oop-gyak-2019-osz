#pragma once

class CliMenu {

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
};