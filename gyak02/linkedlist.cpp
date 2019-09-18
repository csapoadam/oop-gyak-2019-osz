#include "stdafx.h"
#include "linkedlist.h"
#include <iostream>

void LinkedList::addNode(int val) {
	if (!root) { // magyaran: nullptr
		std::cout << "creating root node w/ value " << val << std::endl;
		root = new Node(val);
	}
	else {
		std::cout << "creating non-root node w/ value " << val << std::endl;
		Node* currentNode = root;
		while (currentNode->getNext()) {
			currentNode = currentNode->getNext();
		}
		Node* addedNode = new Node(val);
		currentNode->setNext(addedNode);
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