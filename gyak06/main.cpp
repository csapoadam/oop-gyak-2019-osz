// tables.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
//#include "tableA.h"
//#include "city.h"

#include "solutionCity.h" // ez rekurzivan behivja a solutionTableitems.h-t is
#include "solutionTable.h"

void displayKey(TableItemType* anItem) {
	std::cout << anItem->toString() << std::endl;
}

int main()
{
	Table chart;
	const int numcities = 6;
	City* items[numcities];
	std::ifstream file("cities.txt"); // igy is lehet...
	for (int i = 0; i < numcities; i++) {
		/*
		items[i] = new City;
		std::cin >> *items[i];
		try {
			chart.tableInsert(items[i]);
		}
		catch (GyakTableException& re) {
			std::cout << re.getReason() << std::endl;
		}
		std::cout << *items[i] << std::endl;
		std::cout << std::endl;
		*/
		std::string name;
		std::string country;
		int population;
		file >> name >> country >> population;
		items[i] = new City(name, country, population);
		try {
			chart.tableInsert(items[i]);
		}
		catch (GyakTableException& re) {
			std::cout << re.getReason() << std::endl;
		}
		std::cout << *items[i] << std::endl;
		std::cout << std::endl;
	}
	chart.traverseTable(displayKey); // bejaras sorrendben

	for (int i = 0; i < numcities; i++) {
		delete items[i];
	}
	char c;
	std::cin >> c;
    return 0;

	// Mi az amit tudunk?
	// Table egy osztaly, ami City pointereket tarol..
	// ... de amikor vegigmegyunk rajta (traverseTable), 
	// TableItemType pointereket varo fv-t adunk at
	// vagyis: City egyfajta TableItemType kell hogy legyen!

	// City tipusu objektumra definialva van operator>>

	// Table sorrendezve tarolja (vagy sorrendezve irja ki)
	// az elemeit
	// A sorrendezes alapja egy kituntetett mezo (cityName).
	// De mivel a City ose a TableItemType, a TableItemType 
	//osztalynak kell egy getKey() metodus, ami alapjan a
	// sorrendezes
	// tortenik
}

// Pelda kimenet:
/*
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

Enter name of city:
Gyor
Enter country in which city is located:
Hungary
Enter population of city:
130000

Boston - USA - 685000
Budapest - Hungary - 2000000
Gyor - Hungary - 130000
*/

