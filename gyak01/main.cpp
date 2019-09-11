// Gyak01-2019-fall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "date.h"

int main()
{
	Date d;
	d.print();
	// Date d2(32, 13, 1990); // hupsz: a honapokat egyszeruen levagtuk
	Date d2(32, 12, 1990);
	d2.print();
	std::cout << "adding 10 years and 32 days:" << std::endl;
	d2.addYears(10).addDays(32);
	d2.print();
	std::cout << "adding 5 days:" << std::endl;
	d2.addDays(5);
	d2.print();
	std::cout << "adding 30 days:" << std::endl;
	d2.addDays(30);
	d2.print();
	std::cin.get();
    return 0;
}

