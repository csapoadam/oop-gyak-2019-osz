#pragma once

#include <string>
#include <iostream>

class TableItemType {
public:
	std::string toString() {
		return "dummy";
	}
};

class City : TableItemType {
private:
	std::string cityName;
	std::string country;
	int population;
public:
	City() {}
	City(std::string cn, std::string co, int pop) :
		cityName(cn), country(co), population(pop) {}
	friend std::istream& operator>>(std::istream& is, City& c);
	friend std::ostream& operator<<(std::ostream& os, City& c);
};

std::istream& operator>>(std::istream& is, City& c) {
	std::cout << "Enter name of city: ";
	is >> c.country;
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
