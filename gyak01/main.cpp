// Gyak01-2019-fall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

// class Date; // forward declaration - ez nem eleg, mert hasznaljuk is a main fv-ben!
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

int main()
{
	Date d;
	d.print();
	Date d2(32, 8, 1990);
	d2.print();
	std::cin.get();
    return 0;
}

