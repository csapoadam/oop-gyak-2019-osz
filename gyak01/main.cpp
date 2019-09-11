// Gyak01-2019-fall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "date.h"

int main()
{
	Date d;
	d.print();
	Date d2(32, 8, 1990);
	d2.print();
	d2.addYears(10).addYears(2);
	d2.print();
	std::cin.get();
    return 0;
}

