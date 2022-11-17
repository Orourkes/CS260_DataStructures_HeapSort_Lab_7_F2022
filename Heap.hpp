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
#include <string>


class Heap
{
private:
	Node* Root;
	Node** heapArray;
	void resizeDouble();
	int heapSize = 10;
	int totalElements;
	int countedElements;
	bool isSorted;

	void addChild(int);
	void removeChild(int);
	void setSize(int newSize) { heapSize = newSize; }

public:
	Heap();
	Heap(int);
	~Heap();

	void addItem(int);
	int getItem();
	int getElement(Node*);
	void recDelete(Node*);
	void trickleUp(Node*);
	void bubbleDown(Node*);
	void bubbleUp(Node*);

	std::string printAll();
	void resize(int newSize);
	void resize();
};

