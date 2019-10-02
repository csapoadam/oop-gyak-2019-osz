#pragma once
#include <vector>
#include <iostream>
#include <string>

class Node {
	std::string name;
	int sizeInBytes;
public:
	Node(std::string name, int sz) : name(name), sizeInBytes(sz) { }
	void print() {
		std::cout << "I am node w/ name: " << name << std::endl;
	}
	std::string getName() { return name; }
	int getSize() { return sizeInBytes; }
};

class TextNode : public Node {
public:
	TextNode(std::string name, int sz) : Node(name, sz) {}
	void print() {
		std::cout << "I am a TextNode w/ name " << getName() << " and size " << getSize() << " bytes" << std::endl;
	}
};

class ImageNode : public Node {
	int height, width;
public:
	ImageNode(std::string name, int sz, int w, int h) : Node(name, sz) {
		height = h;
		width = w;
	}
	void print() {
		std::cout << "I am an ImageNode w/ name " << getName() << ", size " << getSize() << " bytes";
		std::cout << " and dimensions " << width << " x " << height << std::endl;
	}
};

class DocumentStore {
	std::vector<Node*> documents;
public:
	DocumentStore() {}
	void addDocument(Node* np) {
		documents.push_back(np);
	}
	void printAll() {
		for (Node* n : documents) {
			n->print();
		}
	}
};
