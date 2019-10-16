#pragma once

#include "solutionTableitems.h"

const int MAX_TABLE_SZ = 2;

class GyakTableException : public std::exception {
private:
	std::string reason;
public:
	GyakTableException(const std::string& reason)
		:
		reason("Table error!! " + reason) {}
	std::string getReason() { return reason; }
};

// Kovetelmenyek: sokfelekeppen meg lehetne oldani (pl. STL set)
// de most fix meretu tombot hasznalunk
// mi fogjuk shiftelni az elemeket a beszuraskor
// ha elerjuk a tomb maximalis meretet, akkor kivetelt dobunk
class Table {
private:
	TableItemType * data[MAX_TABLE_SZ];
	int currentSize;
public:
	Table () : currentSize(0) {}
	void tableInsert(TableItemType* newitem) {
		if (currentSize == MAX_TABLE_SZ) {
			// nincs tobb hely!
			throw GyakTableException("table full!");
		}
		data[currentSize] = newitem;
		currentSize++;
	}
};