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
		tail->next = newTail;
		tail = newTail;
	}
}

void LinkedList::print() {
	Node* currentNode = root;
	while (currentNode->next) {
		std::cout << currentNode->value << ", ";
		currentNode = currentNode->next;
	}
	std::cout << currentNode->value << std::endl;
}