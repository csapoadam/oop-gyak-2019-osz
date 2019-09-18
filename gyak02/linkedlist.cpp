#include "stdafx.h"
#include "linkedlist.h"
#include <iostream>

LinkedList::~LinkedList() {
	if (root) {
		Node* currentNode = root;
		Node* nextNode = root->next;
		std::cout << "deleting node w/ value" << currentNode->value << std::endl;
		delete currentNode;
		while (nextNode) {
			currentNode = nextNode;
			nextNode = currentNode->next;
			std::cout << "deleting node w/ value" << currentNode->value << std::endl;
			delete currentNode;
		}
	}
}

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
	if (root) { // fontos!
		Node* currentNode = root;
		while (currentNode->next) {
			std::cout << currentNode->value << ", ";
			currentNode = currentNode->next;
		}
		std::cout << currentNode->value << std::endl;
	}
}