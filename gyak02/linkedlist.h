#pragma once

class Node {
	int value;
	Node* next;
	friend class LinkedList;
public:
	Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
	Node* root;
	Node* tail;
public:
	LinkedList() : root(nullptr), tail(nullptr) {}
	void addNode(int val);
	void print();
};