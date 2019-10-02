#pragma once

#include <string>

class Part {
	std::string name;
	int amortizationTimeLeft;
	int age;
public:
	Part(std::string n, int atl) :
		name(n),
		amortizationTimeLeft(atl),
		age(0)
	{}

	void print() {
		std::cout << "\t" << name << " (" << age << " years old)" << std::endl;
	}
};
