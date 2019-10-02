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
	std::string createdAtToString() {
		return createdAt.toString();
	}
	std::string lastModifiedAtToString() {
		return lastModifiedAt.toString();
	}
public:
	Node(std::string name, int sz) : 
		name(name), 
		sizeInBytes(sz),
		createdAt(DateTime()),
		lastModifiedAt(DateTime(createdAt))
	{ }
	virtual void print(bool doPrintWithoutName = false) {
		if (!doPrintWithoutName) {
			std::cout << "I am node w/ name: " << name << ". ";
		}
		std::cout << "My size in bytes is: " << sizeInBytes << std::endl;
		std::cout << " I was created at: " << createdAtToString() << ". ";
		std::cout << "I was last modified at: " << lastModifiedAtToString() << std::endl;
	}
	std::string getName() { return name; }
	int getSize() { return sizeInBytes; }
	void touch() {
		lastModifiedAt = DateTime();
	}
	
};

class TextNode : public Node {
public:
	TextNode(std::string name, int sz) : Node(name, sz) {}
	void print() {
		std::cout << "I am a TextNode w/ name " << getName() << ". ";
		Node::print(true);	
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
		std::cout << "I am an ImageNode w/ name " << getName();
		std::cout << " and dimensions " << width << " x " << height << ". ";
		Node::print(true);
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
	void printImages() {
		for (Node* n : documents) {
			ImageNode* inp = dynamic_cast<ImageNode*>(n);
			if (inp != nullptr) {
				inp->print();
			}
		}
	}
};
