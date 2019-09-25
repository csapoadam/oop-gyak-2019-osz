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

	std::cout << "index of 5 is: " << my_ll1.findNodeIndexByValue(5) << std::endl;
	std::cout << "index of 6 is: " << my_ll1.findNodeIndexByValue(6) << std::endl;
	std::cout << "index of 7 is: " << my_ll1.findNodeIndexByValue(7) << std::endl;
	std::cout << "index of 8 is: " << my_ll1.findNodeIndexByValue(8) << std::endl;

	std::cout << "inserting value of 15 after index -1" << std::endl;
	my_ll1.insertValueAfterIndex(15, -1); // rootba kell h tegye...
	my_ll1.print(); // 15, 5, 6, 7

	std::cout << "inserting value of 16 after index 2" << std::endl;
	my_ll1.insertValueAfterIndex(16, 2); // rootba kell h tegye...
	my_ll1.print(); // 15, 5, 6, 16, 7

	std::cout << "inserting value of 17 after index 4" << std::endl;
	my_ll1.insertValueAfterIndex(17, 4); // rootba kell h tegye...
	my_ll1.print(); // 15, 5, 6, 16, 7, 17

	std::cout << "inserting value of 18 after index 40" << std::endl;
	my_ll1.insertValueAfterIndex(18, 40); // rootba kell h tegye...
	my_ll1.print(); // 15, 5, 6, 16, 7, 17, 18

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

