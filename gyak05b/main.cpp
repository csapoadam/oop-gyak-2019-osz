// FileHierarchy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "files.h"
#include "filesystem.h"

#include <iostream>

void f() {
	FileSystem fs;
	Folder* root = fs.getRoot();
	Node* MyDocuments = fs.addFolder("MyDocuments", root);
	Node* Bin = fs.addFolder("bin", root);
	Node* Misc = fs.addFolder("misc", root);
	Node* Misc2 = fs.addFolder("misc2", Misc);

	BinaryFile bfile1("prog1");
	BinaryFile bfile2("prog2");
	TextFile tfile("readme.txt");
	TextFile tfile2("log.txt");

	fs.addFile(&bfile1, Bin);
	fs.addFile(&bfile2, Bin);
	fs.addFile(&tfile, MyDocuments);
	fs.addFile(&tfile2, Misc2);
	/*
	fs.print();*/

	// Kiirja, hogy:
	// Folder w/ name: root
	//		Folder w / name: misc
	//				Folder w / name : misc2
	//						File w / name : Text file w / name log.txt
	//		Folder w / name : bin
	//				File w / name : Binary file w / name prog2
	//				File w / name : Binary file w / name prog1
	//		Folder w / name : MyDocuments
	//				File w / name : Text file w / name readme.txt
}

int main()
{
	/*for (int i = 0; i < 10; i++) {
		f();
		char c; // vegig u.annyi mem.fogyasztas!
		std::cin >> c;
	}     */
	f();
	std::cin.get();
    return 0;
}

