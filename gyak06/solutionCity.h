#pragma once

#include "solutionTableitems.h"

class City : public TableItemType {
private:
	std::string cityName;
	std::string country;
	int population;
public:
	City();
	City(std::string cn, std::string co, int pop);
	std::string toString() override;
	std::string getKey();
	friend std::istream& operator>>(std::istream& is, City& c);
	friend std::ostream& operator<<(std::ostream& os, City& c);
};
