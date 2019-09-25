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
	// egy megoldas: ne engedjuk a copy constructort!
	//LinkedList(LinkedList&) = delete;
	// masik lehetoseg: csinalunk egyet magunknak!
	// referencia lehet const, nem muszaj de igy elegansabb
	LinkedList(const LinkedList&);
	~LinkedList();
	// egyik opcio: ne engedjuk a copy assignmentet!
	//LinkedList& operator=(const LinkedList&) = delete;
	// masik opcio: definialjuk!
	LinkedList& operator=(const LinkedList&);
	void addNode(int val);
	int findNodeIndexByValue(int val);
	void insertValueAfterIndex(int val, int index);
	void print();
};