#include "Heap.hpp"

Heap::Heap()
{
	heapArray = new int[heapSize];
	Root = nullptr;
	usedElements = 0;
}
Heap::Heap(int newSize)
{
	heapSize = newSize;
	heapArray = new int[heapSize];
	Root = nullptr;
	usedElements = 0;
}
Heap::~Heap()
{
	delete heapArray;
}

void Heap::addItem(int addValue)
{
	usedElements++;
	if (Root = nullptr)
	{
		Root->setValue(addValue);
		heapArray[0] = Root;
	}
	else
	{
		heapArray[(usedElements - 1)] = addValue;
	}
		
}
int Heap::getItem()
{
	return heapArray[0];
}