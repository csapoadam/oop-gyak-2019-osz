#include <string>
#include <iostream>

class FileSystem {
	Folder* root;
public:
	FileSystem () : root(new Folder("root", 0)) {}
	Folder * getRoot() { return root; }
	//Folder * addFolder(std::string foldername, Folder* parent) {
	// igy lett volna a logikus, de a feladatkiiras miatt (amin nem
	// valtoztathatunk):
	Folder * addFolder(std::string foldername, Node* parent) {
		// mivel hulye volt a feladat keszitoje, ezert most
		// dynamic castolnunk kell
		Folder* parentAsFolder = dynamic_cast<Folder*>(parent);
		if (parentAsFolder) {
			Folder* newfolder = new Folder(foldername, parent->getIndentLevel() + 1);
			parentAsFolder->addChild(newfolder);
			return newfolder;
		}
	}

	void addFile(File* fp, Node * parent) {
		// mivel hulye volt a feladat keszitoje, ezert most
		// dynamic castolnunk kell
		Folder* parentAsFolder = dynamic_cast<Folder*>(parent);
		if (parentAsFolder) {
			parentAsFolder->addChild(fp);
		}
	}

	void print() {
		std::vector<Node*> nodesLeftToVisit;
		nodesLeftToVisit.push_back(root);
		while (nodesLeftToVisit.size() > 0) {
			int lastIndex = nodesLeftToVisit.size() - 1;
			Node* current = nodesLeftToVisit.at(lastIndex);
			nodesLeftToVisit.pop_back(); // kitoroljuk es majd belerakjuk current gyermekeit!
			// de csak akkor vannak gyermekei, ha folder es nem file
			if (Folder* currentAsFolder = dynamic_cast<Folder*>(current)) {
				for (Node* child : currentAsFolder->getChildren()) {
					nodesLeftToVisit.push_back(child);
				}
			}
			current->print();
		}
	}
};
