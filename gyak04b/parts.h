#pragma once

#include <string>

class Part {
	std::string name;
	int amortizationTime;
	int amortizationTimeLeft;
	int age;
public:
	Part(std::string n, int atl) :
		name(n),
		amortizationTime(atl),
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

	void repair() {
		age = 0;
		amortizationTimeLeft = amortizationTime;
	}
};