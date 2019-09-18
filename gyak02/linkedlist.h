#pragma once

class Node {
	int value;
	Node* next;
public:
	Node(int val) : value(val), next(nullptr) {}
	int getValue() {
		return value;
	}
	Node* getNext() {
		return next;
	}
	void setNext(Node* np) {
		next = np;
	}
};

class LinkedList {
	Node* root;
public:
	LinkedList() : root(nullptr) {}
	void addNode(int val);
	void print();
};