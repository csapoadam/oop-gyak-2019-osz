#include "stdafx.h"
#include "linkedlist.h"
#include <iostream>

void LinkedList::addNode(int val) {
	if (!root) { // magyaran: nullptr
		std::cout << "creating root node w/ value " << val << std::endl;
		Node n(val);
		root = &n;
	}
}

void LinkedList::print() {
	std::cout << "root node value is: ";
	std::cout << root->getValue() << std::endl;
}