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
		std::cout << "\t" << name << " (" << age << " years old)";
		if (amortizationTimeLeft == 0) {
			std::cout << " - (needs repair!)";
		}
		std::cout << std::endl;
	}

	void amortize() {
		age++;
		amortizationTimeLeft = amortizationTimeLeft - 1 > -1 ?
			amortizationTimeLeft - 1 :
			0;
	}
};