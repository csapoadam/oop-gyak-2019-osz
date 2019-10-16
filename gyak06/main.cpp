// tables.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "table.h"
#include "city.h"

void displayKey(TableItemType* anItem) {
	std::cout << anItem->toString() << std::endl;
}

int main()
{
	Table chart;
	const int numcities = 3;
	City* items[numcities];
	for (int i = 0; i < numcities; i++) {
		items[i] = new City;
		std::cin >> *items[i];
		chart.tableInsert(items[i]);
		std::cout << std::endl;
	}
	chart.traverseTable(displayKey); // bejaras sorrendben

	delete items[0];
	delete items[1];
	delete items[2];
	char c;
	std::cin >> c;
    return 0;
}

// Pelda kimenet:
/*
Enter name of city:
Gyor
Enter country in which city is located:
Hungary
Enter population of city:
130000

Enter name of city:
Boston
Enter country in which city is located:
USA
Enter population of city:
685000

Enter name of city:
Budapest
Enter country in which city is located:
Hungary
Enter population of city:
2000000


Boston - USA - 685000
Budapest - Hungary - 2000000
Gyor - Hungary - 130000
*/

