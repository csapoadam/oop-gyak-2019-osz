#include <string>
#include <vector>

class Node {
public:
	virtual void print() {} // vigyazat: e nelkul nem megy az, hogy
	// Folder* parentAsFolder = dynamic_cast<Folder*>(parent);
	// (marmint a filesystem.h fajlban)
};

class Folder : public Node {
	std::string name;
	std::vector<Folder*> children;
public:
	Folder(std::string nm) : name(nm) {}
	std::string getName() { return name; }
	void addChild(Folder* fp) {
		children.push_back(fp);
	}
	void print() {}
};
