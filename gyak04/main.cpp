// FileSystem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "filesystem.h"
#include <chrono>
#include <thread>


int main()
{
  TextNode t1 = TextNode("MyTextFile1.txt", 30);
  t1.print();
  ImageNode i1 = ImageNode("MyImage.jpg", 650, 200, 150);
  i1.print();
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  i1.touch();

  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  ImageNode i2 = ImageNode("MyImage2.jpg", 6500, 250, 150);
  i2.print();
  std::cout << "--------------------------" << std::endl;

  DocumentStore ds;
  ds.addDocument(&t1);
  ds.addDocument(&i1);
  ds.addDocument(&i2);

  // ds.printAll();
  ds.printImages();

  std::cin.get();
    return 0;
}

