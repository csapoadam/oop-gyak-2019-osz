#include <string>
#include <iostream>

class FileSystem {
	Folder* root;
public:
	FileSystem () : root(new Folder("root")) {}
	Folder * getRoot() { return root; }
	Folder * addFolder(std::string foldername, Folder* parent) {
		Folder* newfolder = new Folder(foldername);
		parent->addChild(newfolder);
		return newfolder;
	}
};
