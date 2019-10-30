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

void SubmenuCliMenuItem::select() {}

void FunctionalCliMenuItem::select() {
	functionPointer();
}

CliMenu* SubmenuCliMenuItem::getSubMenu() {
	return itemSubMenu;
}