#pragma once
#include <iostream>

class Date {
	int d, m, y;
public:
	Date() {
		d = 1; m = 1; y = 1970;
	}
	Date(int day, int month, int year) {
		d = day;
		m = month;
		y = year;
	}
	void print() {
		std::cout << d << "/" << m << "/" << y << std::endl;
	}
};

