#pragma once

#include <string>
#include <iostream>

class TableItemType {
public:
	virtual std::string toString() = 0;
	virtual std::string getKey() = 0;
};

