#include "stdafx.h"

#include "solutionCity.h"

City::City() {}

City::City(std::string cn, std::string co, int pop) :
	cityName(cn), country(co), population(pop)
{}

std::string City::toString() {
	return cityName + " - " + country + " - " + std::to_string(population);
}

std::string City::getKey() {
	return cityName;
}

std::istream& operator>>(std::istream& is, City& c) {
	std::cout << "Enter name of city: ";
	is >> c.cityName;
	std::cout << "Enter name of country: ";
	is >> c.country;
	std::cout << "Enter population: ";
	is >> c.population;
	return is;
}

std::ostream& operator<<(std::ostream& os, City& c) {
	os << c.cityName << " - ";
	os << c.country << " - ";
	os << c.population;
	return os;
}
