#pragma once

#include "solutionTableitems.h"

const int MAX_TABLE_SZ = 10;


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
	int getInsertPosition(std::string keyValue) {
		for (int inx = 0; inx < currentSize; inx++) {
			if (data[inx]->getKey() >= keyValue) {
				return inx;
			}
		}
		return currentSize;
	}
public:
	Table () : currentSize(0) {}
	void tableInsert(TableItemType* newitem) {
		if (currentSize == MAX_TABLE_SZ) {
			// nincs tobb hely!
			throw GyakTableException("table full!");
		}

		int place = getInsertPosition(newitem->getKey());
		for (int inx = currentSize; inx > place; inx--) {
			// minden elem = az ot megelozovel
			// data[place]-t is masoljuk, de mar nem irjuk
			data[inx] = data[inx - 1];
		}
		data[place] = newitem;
		currentSize++;
	}
	void traverseTable(void(*funcPtr)(TableItemType*)) {
		for (int inx = 0; inx < currentSize; inx++) {
			funcPtr(data[inx]);
		}
	}
};