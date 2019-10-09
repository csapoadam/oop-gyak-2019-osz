#include <string>
#include <vector>

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
	void print() {}
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
};

class TextFile : public File {
public:
	TextFile(std::string fname) : File(fname) {}
};