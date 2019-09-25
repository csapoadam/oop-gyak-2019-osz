// LinkedLists-Example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "linkedlist.h"

void f() { // szimulaljuk a main()-tol eltero fv-ek hasznalatat
	LinkedList my_ll;
	my_ll.addNode(5);
	my_ll.addNode(6);
	my_ll.addNode(7);
	my_ll.print();
}


int main()
{
	LinkedList my_ll1;
	my_ll1.addNode(5);
	my_ll1.addNode(6);
	my_ll1.addNode(7);
	my_ll1.print();

	LinkedList my_ll2;
	my_ll2.addNode(8);
	my_ll2.addNode(9);
	my_ll2.print();

	LinkedList my_ll3;
	my_ll3.addNode(11);
	my_ll3.addNode(12);
	my_ll3.addNode(13);
	my_ll3.addNode(14);
	my_ll3.print();

	LinkedList my_ll4;
	my_ll4.addNode(15);
	my_ll4.addNode(16);
	my_ll4.addNode(17);
	my_ll4.print();

	std::cout << "copying 1 to 2" << std::endl;
	my_ll2 = my_ll1;
	my_ll2.print();

	std::cout << "copying 1 to 3" << std::endl;
	my_ll3 = my_ll1;
	my_ll3.print();

	std::cout << "copying 1 to 4" << std::endl;
	my_ll4 = my_ll1;
	my_ll4.print();

	std::cout << "adding a different node to each one" << std::endl;
	my_ll1.addNode(100);
	my_ll2.addNode(101);
	my_ll3.addNode(102);
	my_ll4.addNode(103);

	my_ll1.print();
	my_ll2.print();
	my_ll3.print();
	my_ll4.print();

	std::cout << "done" << std::endl;


	/*
	for (int i = 0; i < 10000; i++) {
		f();
		if (i % 100 == 0) {
			std::cin.get();
		}
	}
	*/

	// ha Node kulon osztaly letrehozhatjuk, de nem sok mindent tudunk vele csinalni
	// ha raadasul privat beagyazott, nem tudjuk peldanyositani kivulrol!
	// ez a legjobb!
	// Node n(55);
	

	std::cin.get();
    return 0;
}

