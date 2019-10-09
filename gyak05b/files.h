#include <string>
#include <vector>

class Node {

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
};