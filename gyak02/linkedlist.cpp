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

LinkedList::LinkedList(const LinkedList& other) {
	if (other.root) { // fontos!
		Node* currentNodeInOther = other.root;
		std::cout << "cloning node w/ value: " << currentNodeInOther->value << std::endl;
		addNode(currentNodeInOther->value);

		while (currentNodeInOther->next) {
			currentNodeInOther = currentNodeInOther->next;
			std::cout << "cloning node w/ value: " << currentNodeInOther->value << std::endl;
			addNode(currentNodeInOther->value);
		}
	}
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
	// ez nem konstruktor, hanem assignment, ertekadas
	// tehat: ez az objektum mar letezik!!
	// -> mar lehet lefoglalt mem.terulete, amit fel kell szabaditani
	// lehet ugy is, hogy elkezdjuk felulvagni - es ha maradt valami, azt toroljuk
	// de most inkabb a naiv implementaciot kovessuk!

	// destruktor kodja egy-az-egyben
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

	// DE: hogy ne legyen inkonzisztens allapot, nullptr-ek beallitasa kell!!
	// (destruktor csak a mem.teruletet szabaditja fel)
	root = nullptr;
	tail = nullptr;

	// copy constructor kodja egy-az-egyben
	if (other.root) { // fontos!
		Node* currentNodeInOther = other.root;
		std::cout << "cloning node w/ value: " << currentNodeInOther->value << std::endl;
		addNode(currentNodeInOther->value);

		while (currentNodeInOther->next) {
			currentNodeInOther = currentNodeInOther->next;
			std::cout << "cloning node w/ value: " << currentNodeInOther->value << std::endl;
			addNode(currentNodeInOther->value);
		}
	}

	/* Hazifeladat ezt az alternativ megoldast atnezni / javitani
	Node* currentNodeInThis = root;
	Node* currentNodeInOther = other.root;

	bool deleteRest = true;

	std::cout << "copy assignment called" << std::endl;

	while (true) {
		if (currentNodeInOther) {
			std::cout << "assigning " << currentNodeInOther->value << std::endl;
			if (currentNodeInThis) {
				std::cout << "a node for this exists" << std::endl;
				currentNodeInThis->value = currentNodeInOther->value;
				currentNodeInThis = currentNodeInThis->next;
				currentNodeInOther = currentNodeInOther->next;
			}
			else {
				std::cout << "this list is shorter, adding new node" << std::endl;
				addNode(currentNodeInOther->value);
				deleteRest = false;
				currentNodeInOther = currentNodeInOther->next;
			}
		}
		else { // mar nincs mit masolni vagy hozzaadni!
			// az a kerdes, kell-e meg valamit torolni:
			std::cout << "checking if something should be deleted" << std::endl;
			if (deleteRest) {
				std::cout << "yes" << std::endl;
				Node* nextNodeToDelete = currentNodeInThis;
				while (nextNodeToDelete) { // az is lehet h mar nullptr ha a ket lista egyforma hosszu volt
					Node* followingNode = nextNodeToDelete->next;
					delete nextNodeToDelete;
					nextNodeToDelete = followingNode;
				}
			}
			// mindenkeppen break:
			break;
		}
	}
	*/

	// ujdonsag a copy constructorhoz kepest:
	return *this;
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