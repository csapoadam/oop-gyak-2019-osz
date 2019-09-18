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
	LinkedList my_ll;
	my_ll.addNode(5);
	my_ll.addNode(6);
	my_ll.addNode(7);
	my_ll.print();

	LinkedList my_ll2(my_ll); // copy constructor - automatikusan generalt!
	my_ll2.print();

	LinkedList* my_ll3 = new LinkedList();
	my_ll3->addNode(8);
	my_ll3->addNode(9);
	my_ll3->addNode(10);
	my_ll3->print();

	LinkedList my_ll4(*my_ll3); // copy constructor - automatikusan generalt!
	delete my_ll3;
	my_ll4.print();


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

