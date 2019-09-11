#pragma once
#include <iostream>

class Date {
	int d, m, y;
	int sanitizeAndReturnOverflowInDays();
public:
	Date();
	Date(int day, int month, int year);
	// Lehetne void visszateresi tipus is, de akkor
	// nem mukodne, hogy d.addYears(5).addMonths(2);
	Date& addYears(int n);
	Date& addDays(int n);
	void print();
};

