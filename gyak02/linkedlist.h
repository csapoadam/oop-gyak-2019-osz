#pragma once

class Node {
	int value;
	Node* next;
public:
	Node(int val) : value(val) {}
	int getValue() {
		return value;
	}
};

class LinkedList {
	Node* root;
public:
	LinkedList() : root(nullptr) {}
	void addNode(int val);
	void print();
};