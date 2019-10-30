#pragma once

class CliMenu {

};

class CliMenuItem {
private:
	std::string itemText;
	CliMenu* itemSubMenu;
public:
	CliMenuItem(const std::string& text, CliMenu* submenu) {
		itemSubMenu = submenu;
	}
};