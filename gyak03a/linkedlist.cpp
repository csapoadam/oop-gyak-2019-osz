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
		std::cout << "printing currentNode " << currentNode->value << std::endl;
		while (currentNode->next) {
			std::cout << currentNode->value << ", ";
			currentNode = currentNode->next;
		}
		std::cout << currentNode->value << std::endl;
	}
}

int LinkedList::findNodeIndexByValue(int val) {
	Node* currentNode = root;
	int count = 0;
	while (currentNode) {
		if (currentNode->value == val) {
			return count;
		}
		currentNode = currentNode->next;
		count++;
	}
	return -1;
}

void LinkedList::insertValueAfterIndex(int val, int inx) {
	// mindenkeppen letrehozunk egy uj Node-ot a heapen
	// utana az a kerdes, hova szurjuk be!
	Node* newNode = new Node(val);

	Node* nextNode = root;
	Node* previousNode = nullptr;
	int count = 0;
	while (nextNode) {
		if (inx < count) {
			// tulhaladtuk azt a helyet, ahol be kell szurni!
			// pl. ha a 0. utan akarjuk beszurni, inx erteke 0, count pedig mar 1
			// tehat: currentNode elotti node utan kell beszurni
			if (!previousNode) { // if (count == 0) is jo...
				// root helyere szurjuk be. Ez akkor lehetseges, a inx negativ erteku...
				Node* tmp = root; // tmp elnevezes jo, itt csak megjegyezzuk a korabbi root cimet
				root = newNode;
				root->next = tmp; // tail pedig marad valtozatlan...
				return;
			}
			else {
				previousNode->next = newNode;
				newNode->next = nextNode; // tail pedig marad valtozatlan...
				return;
			}
		}
		previousNode = nextNode;
		nextNode = nextNode->next;
		count++;
	}
	// ha meg itt vagyunk, akkor a vegere kell szurni...
	previousNode->next = newNode;
	tail = newNode;
}
