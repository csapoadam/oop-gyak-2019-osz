#include "stdafx.h"
#include "climenuitem.h"
#include "climenu.h"

CliMenuItem::CliMenuItem(const std::string& text, CliMenu* submenu) {
	itemText = text;
	itemSubMenu = submenu;
	functionPointer = nullptr;
}

CliMenuItem::CliMenuItem(const std::string& text, void(*fp)()) {
	itemText = text;
	functionPointer = fp;
	itemSubMenu = nullptr;
}

std::string& CliMenuItem::getItemText() {
	return itemText;
}

void CliMenuItem::call() {
	if (functionPointer) {
		functionPointer();
	}
}

CliMenu* CliMenuItem::getSubMenu() {
	return itemSubMenu;
}