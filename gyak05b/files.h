#include <string>
#include <vector>
#include <iostream>

class Node {
	std::string name;
	int indent;
public:
	Node(std::string nm, int indent) : name(nm), indent(indent) {}
	std::string getName() { return name; }
	int getIndentLevel() { return indent; }
	void setIndentLevel(int val) { indent = val; }
	virtual void print() {} // vigyazat: e nelkul nem megy az, hogy
	// Folder* parentAsFolder = dynamic_cast<Folder*>(parent);
	// (marmint a filesystem.h fajlban)
};

class Folder : public Node {
	std::vector<Node*> children;
public:
	Folder(std::string nm, int indent) : Node(nm, indent) {}
	void addChild(Node* fp) {
		children.push_back(fp);
		fp->setIndentLevel(getIndentLevel() + 1);
	}
	const std::vector<Node*>& getChildren() {
		return children;
	}
	void print() {
		for (int i = 0; i < getIndentLevel(); i++) {
			std::cout << "\t";
		}
		std::cout << "Folder w/ name: " << getName() << std::endl;
	}
};

// mivel mukodik mindketto:
// fs.addFile(&bfile1, Bin);
// fs.addFile(&bfile2, Bin);
// fs.addFile(&tfile, MyDocuments);
// innnen latszik, hogy nemcsak BinaryFile meg TextFile kell,
// hanem egy sima File tipus is:
class File : public Node {
public:
	File(std::string fname, int indent) : Node(fname, indent) {}
};

class BinaryFile : public File {
public:
	BinaryFile(std::string fname, int indent) : File(fname, indent) {}
	void print() {
		for (int i = 0; i < getIndentLevel(); i++) {
			std::cout << "\t";
		}
		std::cout << "Binary File w/ name: " << getName() << std::endl;
	}
};

class TextFile : public File {
public:
	TextFile(std::string fname, int indent) : File(fname, indent) {}
	void print() {
		for (int i = 0; i < getIndentLevel(); i++) {
			std::cout << "\t";
		}
		std::cout << "Text File w/ name: " << getName() << std::endl;
	}
};
