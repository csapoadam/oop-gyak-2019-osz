#include <string>
#include <vector>
#include <iostream>

class Node {
	std::string name;
public:
	Node(std::string nm) : name(nm) {}
	std::string getName() { return name; }
	virtual void print() {} // vigyazat: e nelkul nem megy az, hogy
	// Folder* parentAsFolder = dynamic_cast<Folder*>(parent);
	// (marmint a filesystem.h fajlban)
};

class Folder : public Node {
	std::vector<Node*> children;
public:
	Folder(std::string nm) : Node(nm) {}
	void addChild(Node* fp) {
		children.push_back(fp);
	}
	const std::vector<Node*>& getChildren() {
		return children;
	}
	void print() {
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
	File(std::string fname) : Node(fname) {}
};

class BinaryFile : public File {
public:
	BinaryFile(std::string fname) : File(fname) {}
	void print() {
		std::cout << "Binary File w/ name: " << getName() << std::endl;
	}
};

class TextFile : public File {
public:
	TextFile(std::string fname) : File(fname) {}
	void print() {
		std::cout << "Text File w/ name: " << getName() << std::endl;
	}
};
