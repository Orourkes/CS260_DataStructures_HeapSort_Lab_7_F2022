#pragma once
/**********************
* class Heap
* Creates a Heap using an array. The values are stored at locations 1 – N as described in the document on Heaps. You will need to code trickle-up and bubble-down algorithms.
* • constructor (init) – creates an array equal to the parameter passed in (default 10)
* • addItem – adds a new item to the heap
* • getItem – removes and returns the smallest item from the heap
* • heap should throw exception on take from empty and double when full
* 
********************/
#include "Node.hpp"

class Heap
{
private:
	Node* Root;
	int* heapArray;
	void resizeDouble();
	int heapSize = 10;
	int usedElements;

public:
	Heap();
	Heap(int);
	~Heap();

	void addItem(int);
	int getItem();

};

