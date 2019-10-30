#pragma once

#include <string>

class CliMenu; // a main miatt erre nem lenne szukseg,
// es: climenu.cpp-ben sincs ra szukseg,
// DE: climenuitem.cpp-ben eloszor include-oljuk ezt, mint a climenu.h-t

class CliMenuItem {
private:
	std::string itemText;
	CliMenu* itemSubMenu;
	void(*functionPointer)(); // main-ben levo exitFunction()
							  // alapjan tudjuk, hogy ilyen fv pointer kell ide
public:
	CliMenuItem(const std::string& text, CliMenu* submenu);
	CliMenuItem(const std::string& text, void(*fp)());
	std::string& getItemText();
	void call();
	CliMenu* getSubMenu();
};
