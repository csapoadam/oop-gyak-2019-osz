#include "stdafx.h"
#include "climenuitem.h"
#include "climenu.h"

CliMenuItem::CliMenuItem(const std::string& text) {
	itemText = text;
}

SubmenuCliMenuItem::SubmenuCliMenuItem(const std::string& text,
	CliMenu* submenu) : CliMenuItem(text) {
	itemSubMenu = submenu;
}

FunctionalCliMenuItem::FunctionalCliMenuItem(const std::string& text,
	void(*fp)()) : CliMenuItem(text) {
	functionPointer = fp;
}

std::string& CliMenuItem::getItemText() {
	return itemText;
}

CliMenu* SubmenuCliMenuItem::selectAndReturnNextMenuBasedOnCurrentMenu(CliMenu* cmp) {
	return getSubMenu();
}

CliMenu* FunctionalCliMenuItem::selectAndReturnNextMenuBasedOnCurrentMenu(CliMenu* cmp) {
	functionPointer();
	return cmp;
}

CliMenu* SubmenuCliMenuItem::getSubMenu() {
	return itemSubMenu;
}