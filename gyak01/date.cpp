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
	d = day;
	m = month;
	y = year;
	int daysOverflow = this->sanitizeAndReturnOverflowInDays();
	std::cout << "overflowed " << daysOverflow << " days" << std::endl;
}

int Date::sanitizeAndReturnOverflowInDays() {
	int daysOriginal = d;

	m = squash(1, 12, m);

	bool isFebruary = (m == 2);
	bool hasThirtyDays = (m == 4 ||
		m == 6 ||
		m == 9 ||
		m == 11);
	bool isLeapYear = (y % 4) == 0;

	if (isFebruary) {
		d = isLeapYear
			? squash(1, 29, d)
			: d = squash(1, 28, d);
	}
	else {
		d = hasThirtyDays
			? squash(1, 30, d)
			: squash(1, 31, d);
	}

	return daysOriginal - d;
}

Date& Date::addYears(int n) {
	y += n;
	return *this;
}

Date& Date::addDays(int n) {
	d += n;
	int overflow = this->sanitizeAndReturnOverflowInDays();
	while (overflow > 0) {
		m += 1;
		d = overflow;
		overflow = this->sanitizeAndReturnOverflowInDays();
	}
	return *this;
}

void Date::print() {
	std::cout << d << "/" << m << "/" << y << std::endl;
}
