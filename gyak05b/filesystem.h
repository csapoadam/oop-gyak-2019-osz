#include <string>
#include <iostream>

class FileSystem {
	Folder* root;
public:
	FileSystem () : root(new Folder("root")) {}
	Folder * getRoot() { return root; }
	//Folder * addFolder(std::string foldername, Folder* parent) {
	// igy lett volna a logikus, de a feladatkiiras miatt (amin nem
	// valtoztathatunk):
	Folder * addFolder(std::string foldername, Node* parent) {
		// mivel hulye volt a feladat keszitoje, ezert most
		// dynamic castolnunk kell
		Folder* parentAsFolder = dynamic_cast<Folder*>(parent);
		if (parentAsFolder) {
			Folder* newfolder = new Folder(foldername);
			parentAsFolder->addChild(newfolder);
			return newfolder;
		}
	}
};
