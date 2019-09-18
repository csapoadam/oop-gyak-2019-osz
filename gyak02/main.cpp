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
	for (int i = 0; i < 10000; i++) {
		f();
		if (i % 100 == 0) {
			std::cin.get();
		}
	}

	// ha Node kulon osztaly letrehozhatjuk, de nem sok mindent tudunk vele csinalni
	// ha raadasul privat beagyazott, nem tudjuk peldanyositani kivulrol!
	// ez a legjobb!
	// Node n(55);
	

	std::cin.get();
    return 0;
}

