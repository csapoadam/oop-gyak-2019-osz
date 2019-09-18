#include "stdafx.h"
#include "linkedlist.h"
#include <iostream>

void LinkedList::addNode(int val) {
	std::cout << "creating node w/ value " << val << std::endl;
	Node* newTail = new Node(val);
	if (!root) { // magyaran: nullptr
		root = newTail;
		tail = newTail;
	}
	else {
		tail->setNext(newTail);
		tail = newTail;
	}
}

void LinkedList::print() {
	Node* currentNode = root;
	while (currentNode->getNext()) {
		std::cout << currentNode->getValue() << ", ";
		currentNode = currentNode->getNext();
	}
	std::cout << currentNode->getValue() << std::endl;
}