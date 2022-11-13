#include "Heap.hpp"

Heap::Heap()
{
	heapArray = new Node * [heapSize];
	Root = nullptr;
	usedElements = 0;
}
Heap::Heap(int newSize)
{
	heapSize = newSize;
	heapArray = new Node* [heapSize];
	Root = nullptr;
	usedElements = 0;
}
Heap::~Heap()
{
	recDelete(Root);
}

void Heap::addItem(int addValue)
{
	usedElements++;
	if (Root == nullptr)
	{
		Root = new Node(addValue);
		heapArray[0] = Root;
		//Root->setValue(addValue);
	}
	else
	{
		addChild(addValue);
	}
		
}
int Heap::getItem()
{
	return heapArray[0]->getValue();
}
void Heap::addChild(int addValue)
{
	return;
}
void Heap::recDelete(Node* ptr)
{
	if (ptr != nullptr)
	{
		recDelete(ptr->getLeft());
		recDelete(ptr->getRight());
		delete ptr;
	}
}
