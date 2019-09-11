// Gyak01-2019-fall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "date.h"

int main()
{
	Date d;
	d.print();
	Date d2(32, 13, 1990);
	//d2.print();
	std::cout << "adding 9 years and 32 days:" << std::endl;
	d2.addYears(9).addDays(32);
	d2.print();
	std::cout << "adding 5 days:" << std::endl;
	d2.addDays(5);
	d2.print();
	std::cout << "adding 30 days:" << std::endl;
	d2.addDays(30);
	d2.print();
	std::cout << "adding 1 year and 60 days:" << std::endl;
	d2.addYears(1).addDays(60); //a sorrend egyebkent nem mindegy! De ez mar a felhasznalo dolga...
	d2.print();
	std::cin.get();
    return 0;
}

