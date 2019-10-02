#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "datetime.h"

class Node {
	std::string name;
	int sizeInBytes;
	DateTime createdAt;
	DateTime lastModifiedAt;
public:
	Node(std::string name, int sz) : 
		name(name), 
		sizeInBytes(sz),
		createdAt(DateTime()),
		lastModifiedAt(DateTime(createdAt))
	{ }
	virtual void print() {
		std::cout << "I am node w/ name: " << name << std::endl;
	}
	std::string getName() { return name; }
	int getSize() { return sizeInBytes; }
	std::string getCreatedAt() {
		return createdAt.toString();
	}
	std::string getLastModifiedAt() {
		return lastModifiedAt.toString();
	}
};

class TextNode : public Node {
public:
	TextNode(std::string name, int sz) : Node(name, sz) {}
	void print() {
		std::cout << "I am a TextNode w/ name " << getName() << " and size " << getSize() << " bytes";
		std::cout << " I was created at: " << getCreatedAt() << std::endl;
		std::cout << " I was last modified at: " << getLastModifiedAt() << std::endl;
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
		std::cout << " and dimensions " << width << " x " << height;
		std::cout << " I was created at: " << getCreatedAt() << std::endl;
		std::cout << " I was last modified at: " << getLastModifiedAt() << std::endl;
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
