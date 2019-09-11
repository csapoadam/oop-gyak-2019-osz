#pragma once
#include <iostream>

class Date {
	int d, m, y;
public:
	Date();
	Date(int day, int month, int year);
	// Lehetne void visszateresi tipus is, de akkor
	// nem mukodne, hogy d.addYears(5).addMonths(2);
	Date& addYears(int n);
	void print();
};

