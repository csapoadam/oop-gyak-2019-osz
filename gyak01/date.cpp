#include "stdafx.h"
#include "date.h"

int squash(int lowerlim, int upperlim, int val) {
	if (val > upperlim) {
		return upperlim;
	}
	if (val < lowerlim) {
		return lowerlim;
	}
	return val;
}

Date::Date() {
	d = 1; m = 1; y = 1970;
}

Date::Date(int day, int month, int year) {
	m = squash(1, 12, month);

	bool isFebruary = (m == 2);
	bool hasThirtyDays = (m == 4 ||
		m == 6 ||
		m == 9 ||
		m == 11);
	bool isLeapYear = (year % 4) == 0;

	if (isFebruary) {
		d = isLeapYear
			? squash(1, 29, day)
			: d = squash(1, 28, day);
	}
	else {
		d = hasThirtyDays
			? squash(1, 30, day)
			: squash(1, 31, day);
	}

	y = year;
}

Date& Date::addYears(int n) {
	y += n;
	return *this;
}

void Date::print() {
	std::cout << d << "/" << m << "/" << y << std::endl;
}
