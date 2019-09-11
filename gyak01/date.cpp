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
	std::cout << d << "/" << m << "/" << y << " -> ";
	int daysOverflow = this->sanitizeAndReturnOverflowInDays();
	std::cout << d << "/" << m << "/" << y << std::endl;
	std::cout << "overflowed " << daysOverflow << " days" << std::endl;
}

int Date::sanitizeAndReturnOverflowInDays() {
	int daysOriginal = d;
	int monthsOriginal = m;

	m = squash(1, 12, m);
	d = squash(1, this->daysInThisMonth(), d);

	int overflowInDays = daysOriginal - d > 0
		? daysOriginal - d
		: 0;

	int monthsRemaining = monthsOriginal - m;
	if (monthsRemaining > 0) {
		overflowInDays += daysInFirstNMonthsOfYearZ(monthsRemaining, y + 1);
	}

	return overflowInDays;
}

int Date::daysInThisMonth() {
	return daysInMonthXYearZ(m,y);
}

int Date::daysInMonthXYearZ(int x, int z) {
	bool isFebruary = (x == 2);
	bool isLeapYear = (z % 4) == 0;
	bool hasThirtyDays = (x == 4 ||
		x == 6 ||
		x == 9 ||
		x == 11);
	if (isFebruary) {
		return isLeapYear ? 29 : 28;
	}
	else {
		return hasThirtyDays ? 30 : 31;
	}
}

int Date::daysInFirstNMonthsOfYearZ(int n, int z) {
	int daysCounted = 0;
	int yearOfMonthCounted = z;
	int currentMonth = 1;
	while (n > 0) {
		daysCounted += daysInMonthXYearZ(currentMonth, yearOfMonthCounted);
		currentMonth++;
		if (currentMonth > 12) {
			currentMonth = 1;
			yearOfMonthCounted++;
		}
		n--;
	}
	return daysCounted;
}

Date& Date::addYears(int n) {
	y += n;
	return *this;
}

Date& Date::addDays(int n) {
	d += n;
	int overflow = this->sanitizeAndReturnOverflowInDays();
	while (overflow > 0) {
		m = m + 1 > 12 ? 1 : m + 1;
		d = overflow;
		overflow = this->sanitizeAndReturnOverflowInDays();
	}
	return *this;
}

void Date::print() {
	std::cout << d << "/" << m << "/" << y << std::endl;
}
