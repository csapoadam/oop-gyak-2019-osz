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
	// egy megoldas: ne engedjuk a copy-t!
	//LinkedList(LinkedList&) = delete;
	// masik lehetoseg: csinalunk egyet magunknak!
	// referencia lehet const, nem muszaj de igy elegansabb
	LinkedList(const LinkedList&);
	~LinkedList();
	void addNode(int val);
	void print();
};