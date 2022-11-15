#include "Heap.hpp"
#include <iomanip>
#include <stdexcept>

Heap::Heap()
{
	heapArray = new Node * [heapSize];
	Root = nullptr;
	totalElements = 0;
	sortedElements = 0;
}
Heap::Heap(int newSize)
{
	heapSize = newSize;
	heapArray = new Node* [heapSize];
	Root = nullptr;
	totalElements = 0;
	sortedElements = 0;
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
//	if (Root != nullptr)
//	{
//		if ((sortedElements == totalElements) && (totalElements != 0))
//		{
//			sortedElements--;
//			int retVal = heapArray[0]->getValue();
//			//if (retVal > heapArray[((totalElements - 1))])
//			//if ((heapArray[0]->getRight() != nullptr) || heapArray[0]->getLeft() != nullptr)
//			//{
//			//}
//
//		}
//
//		int retVal = heapArray[0]->getValue();
//		
//		{
//			heapArray[0]->setValue(heapArray[((totalElements - 1) - sortedElements)]->getValue());
//			heapArray[((totalElements - 1) - sortedElements)]->setValue(retVal);
//			sortedElements ++;
//		}
//		if (Root->getRight() != nullptr)
//		{
//			Root = trickleUp(Root);
//			heapArray[0] = Root;
//		}
//			if(Root->getLeft() != nullptr)
//		{
//			Root = trickleUp(Root);
//			heapArray[0] = Root;
//		}
//		totalElements--;
//		return retVal;
//
//	throw std::out_of_range("Index Error");
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
		bubbleUp(Root);
	}
	totalElements++;

	return;
}
void Heap::removeChild()
{
	//heapArray[(totalElements)] = new Node(addValue);
	if (totalElements != 0)
	{
		if ((totalElements % 2) == 1)
		{	//is left child of totalElements/2.
			heapArray[(totalElements / 2)]->setLeft(nullptr);
		}
		else
		{	//is right child of (totalElements-2)/2.
			heapArray[((totalElements - 2) / 2)]->setRight(nullptr);
		}
		bubbleUp(Root);
	}
	totalElements++;

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
Node* Heap::trickleUp(Node* currentNode)
{
	int saveVal = currentNode->getValue();
	if (totalElements != 0)
	{
		if ((totalElements % 2) == 1)
		{	//is left child of totalElements/2.
			heapArray[(totalElements / 2)]->setLeft(heapArray[(totalElements)]);
		}
		else
		{	//is right child of (totalElements-2)/2.
			heapArray[((totalElements - 2) / 2)]->setRight(heapArray[(totalElements)]);
		}
		bubbleUp(Root);
	}
	return Root;
}

void Heap::bubbleDown(Node* currentNode)
{
}

void Heap::bubbleUp(Node* parent)
{
	int holdVal = parent->getValue();
	if (nullptr != parent->getLeft())
	{
		bubbleUp(parent->getLeft());
		if (holdVal < parent->getLeft()->getValue())
		{
			parent->setValue(parent->getLeft()->getValue());
			parent->getLeft()->setValue(holdVal);
		}
	}
	if (nullptr != parent->getRight())
	{
		bubbleUp(parent->getRight());
		if (holdVal < parent->getRight()->getValue())
		{
			parent->setValue(parent->getRight()->getValue());
			parent->getRight()->setValue(holdVal);
		}
	}

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

