#include "Heap.hpp"
#include <iomanip>
#include <stdexcept>

Heap::Heap()
{
	heapArray = new Node * [heapSize];
	Root = nullptr;
	totalElements = 0;
	countedElements = 0;
	isSorted = false;
}
Heap::Heap(int newSize)
{
	heapSize = newSize;
	heapArray = new Node* [heapSize];
	Root = nullptr;
	totalElements = 0;
	countedElements = 0;
	isSorted = false;
}
Heap::~Heap()
{
	recDelete(Root);
}

void Heap::addItem(int addValue)
{
	if (Root == nullptr)
	{
		totalElements++;
		Root = new Node(addValue);
		heapArray[0] = Root;
	}
	else
	{
		if (heapSize == (totalElements))
			resize();

		addChild(addValue);
	}
		
}
int Heap::getItem()
{
	if (Root != nullptr)
	{
		if (!isSorted)
			bubbleUp(Root);

		if ((isSorted) && (totalElements != 0))
		{
			countedElements++;
			return heapArray[(countedElements -1)]->getValue();
			
		}


	}
	//throw std::out_of_range("Index Error");
	return 0;
}
void Heap::addChild(int addValue)
 {
	heapArray[(totalElements)] = new Node(addValue);
	if (totalElements != 0)
	{
		if ((totalElements % 2) == 1)
		{	//is left child of totalElements/2.
			heapArray[(totalElements / 2)]->setLeft(heapArray[(totalElements)]);
		}
		else
		{	//is right child of (totalElements-2)/2.
			heapArray[((totalElements -2) / 2)]->setRight(heapArray[(totalElements)]);
		}
		trickleUp(Root);
	}
	totalElements++;

	return;
}
void Heap::removeChild(int removeMe)
{ //Remove links to this child. Leave value in array.
	if (totalElements != 0)
	{
		int lastPlace = totalElements - countedElements;
		if ((lastPlace % 2) == 1)
		{	//is left child of totalElements/2.
			heapArray[((totalElements -1) / 2)]->setLeft(nullptr);
		}
		else
		{	//is right child of (totalElements-2)/2.
			heapArray[((totalElements - 2) / 2)]->setRight(nullptr);
		}
	//	bubbleUp(Root);
	}
	//totalElements--;

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
void Heap::bubbleUp(Node* Parent)
{
	int saveVal = Parent->getValue();
	{
		countedElements++; //must be at least one for next line.

		Parent->setValue(heapArray[totalElements - countedElements]->getValue());
		heapArray[totalElements - countedElements]->setValue(saveVal);
		removeChild(totalElements - countedElements);
		int holdVal = Parent->getValue();
		if (nullptr != Parent->getLeft() && nullptr != Parent->getRight())
		{
 			if (holdVal < Parent->getLeft()->getValue()) //hold less than
			{
				if (Parent->getLeft()->getValue() > Parent->getRight()->getValue())
				{
					bubbleUp(Parent->getLeft());
				}
				else
					bubbleUp(Parent->getRight());
			}
		}
		else
		{
			if (nullptr != Parent->getLeft())
			{
				bubbleUp(Parent->getLeft());
				if (holdVal < Parent->getLeft()->getValue())
				{
					Parent->setValue(Parent->getLeft()->getValue());
					Parent->getLeft()->setValue(holdVal);
				}
			}
			if (nullptr != Parent->getRight())
			{
				bubbleUp(Parent->getRight());
				if (holdVal < Parent->getRight()->getValue())
				{
					Parent->setValue(Parent->getRight()->getValue());
					Parent->getRight()->setValue(holdVal);
				}
			}
		}
		if (countedElements == totalElements)
		{
			isSorted = true;
			countedElements = 0;
		}
		if (!isSorted)
			trickleUp(Parent);
	}
}

void Heap::bubbleDown(Node* currentNode)
{
}

void Heap::trickleUp(Node* parent)
{
	int holdVal = parent->getValue();
	if (nullptr != parent->getLeft())
	{
		trickleUp(parent->getLeft());
		if (holdVal < parent->getLeft()->getValue())
		{
			parent->setValue(parent->getLeft()->getValue());
			parent->getLeft()->setValue(holdVal);
		}
	}
	if (nullptr != parent->getRight())
	{
		trickleUp(parent->getRight());
		if (holdVal < parent->getRight()->getValue())
		{
			parent->setValue(parent->getRight()->getValue());
			parent->getRight()->setValue(holdVal);
		}
	}
	//if ((nullptr != parent->getRight()) && (nullptr != parent->getLeft()))
	//{
	//	if (parent->getLeft()->getValue() < parent->getRight()->getValue())
	//	{
	//		int swapVal = parent->getLeft()->getValue();
	//		parent->getLeft()->setValue(parent->getRight()->getValue());
	//		parent->getRight()->setValue(swapVal);
	//	}
	//}

}

std::string Heap::printAll()
{
	std::string outputArray;
	if (0 != totalElements)
	{
		for (int i = 0; i < totalElements; i++)
		{
			if(nullptr != heapArray[i])
				outputArray += std::to_string(heapArray[i]->getValue());
			if(i <= totalElements)
				outputArray += ", ";
		}
	}
	else
		outputArray = "Empty Array";
	return outputArray;
}

void Heap::resize(int newSize)
{
	setSize(newSize);
	/*********/
	Node** newArray = new Node* [heapSize];
	//Copy over old array to new array
	for (int i = 0; i < totalElements; i++)
	{
		newArray[i] = heapArray[i];
	}
	delete heapArray;
	heapArray = newArray;
}

void Heap::resize()
{
	resize(heapSize * 2);
}

