#pragma once

class LinkedList {
	class Node {
	public:
		int value;
		Node* next;
		Node(int val) : value(val), next(nullptr) {}
	};
	Node* root;
	Node* tail;
public:
	LinkedList() : root(nullptr), tail(nullptr) {}
	void addNode(int val);
	void print();
};