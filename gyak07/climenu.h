#pragma once

#include <iostream>
#include <vector>
#include <string>

class CliMenuItem;

class CliMenu {
private:
	std::vector<CliMenuItem*> menuItems;
public:
	void addItem(CliMenuItem* clip);
	void display();
	CliMenu* selectItem(int choice);
};
