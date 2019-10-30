#pragma once

#include <string>

class CliMenu; // a main miatt erre nem lenne szukseg,
// es: climenu.cpp-ben sincs ra szukseg,
// DE: climenuitem.cpp-ben eloszor include-oljuk ezt, mint a climenu.h-t

class CliMenuItem {
private:
	std::string itemText;
public:
	CliMenuItem(const std::string& text);
	std::string& getItemText();
	virtual void select() = 0;
};

class FunctionalCliMenuItem : public CliMenuItem {
private:
	void(*functionPointer)(); // main-ben levo exitFunction()
							  // alapjan tudjuk, hogy ilyen fv pointer kell ide
public:
	FunctionalCliMenuItem(const std::string& text, void(*fp)());
	virtual void select();
};

class SubmenuCliMenuItem : public CliMenuItem {
private:
	CliMenu * itemSubMenu;
public:
	SubmenuCliMenuItem(const std::string& text, CliMenu* submenu);
	CliMenu* getSubMenu();
	virtual void select();
};