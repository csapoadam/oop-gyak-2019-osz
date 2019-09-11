#include "stdafx.h"
#include "date.h"

Date::Date() {
	d = 1; m = 1; y = 1970;
}

Date::Date(int day, int month, int year) {
	d = day;
	m = month;
	y = year;
}

void Date::print() {
	std::cout << d << "/" << m << "/" << y << std::endl;
}
