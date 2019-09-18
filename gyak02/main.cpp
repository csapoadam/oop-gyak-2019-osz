// LinkedLists-Example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "linkedlist.h"

int main()
{
	LinkedList my_ll;
	my_ll.addNode(5);
	my_ll.addNode(6);
	my_ll.addNode(7);
	my_ll.print();

	std::cin.get();
    return 0;
}

