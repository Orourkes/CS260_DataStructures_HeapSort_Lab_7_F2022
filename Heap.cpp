#include "Heap.hpp"
#include <iomanip>
#include <iostream>
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
	if(!isSorted)
		removeRoot();
	if (heapArray[totalElements] != nullptr)
		return heapArray[totalElements++]->getValue();
	//else
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
		bubbleUp(totalElements);
	}
	totalElements++;

	return;
}
void Heap::removeRoot()
{ 
	if (Root != nullptr)
	{
		if((totalElements > 0) && (heapArray[(totalElements--)] != nullptr))
		{
			int rmRoot = Root->getValue();
			Root->setValue(heapArray[totalElements]->getValue());
			if (totalElements > 0)
			{
				int parent = getParent(totalElements);
				heapArray[totalElements]->setValue(rmRoot);
				if (heapArray[parent]->getLeft() == heapArray[totalElements])
				{
					std::cout << "removing node " << heapArray[parent]->getLeft()->getValue() << endl;
					heapArray[parent]->setLeft(nullptr);
					//totalElements--;
				}
				else if (heapArray[parent]->getRight() == heapArray[totalElements])
				{
					std::cout << "removing node " << heapArray[parent]->getRight()->getValue() << endl;
					heapArray[parent]->setRight(nullptr);
					//totalElements--;
				}
			}
			else
			{
				isSorted = true;
				return;
			}
				//throw std::out_of_range("Index Error");
		}
		trickleDown(Root);
		if(totalElements != 0)
			removeRoot();
	}
	return;
}
void Heap::recDelete(Node* ptr)
{
//	if (ptr != nullptr)
//	{
//		recDelete(ptr->getLeft());
//		recDelete(ptr->getRight());
//		delete ptr;
//	}
}

void Heap::bubbleUp(int kid)
{
	if (heapArray[kid] != Root)
	{
		int parent = getParent(kid);
		if (heapArray[parent]->getValue() < heapArray[kid]->getValue())
		{
			int smaller = heapArray[parent]->getValue();
			heapArray[parent]->setValue(heapArray[kid]->getValue());
			heapArray[kid]->setValue(smaller);

			if (1 <= parent)
				bubbleUp(parent);
		}
	}
}

int Heap::swap(int)
{

	return 0;
}

int Heap::getParent(int kid)
{
	if (heapArray[kid] != nullptr && (heapArray[kid] != Root))
	{
		if (2 >= kid )
			return 0;
		if (1 != kid % 2)
			return ((kid - 2) / 2);
		return ((kid - 1) / 2);
	}
	throw std::out_of_range("Index Error");
}

void Heap::trickleDown(Node* root)
{
	if (nullptr != root)
	{
		if ((nullptr != root->getLeft()) && (nullptr != root->getRight()))
		{
			if (root->getLeft()->getValue() > root->getRight()->getValue())
			{
				if (root->getLeft()->getValue() > root->getValue())
				{
					int smaller = root->getValue();
					root->setValue(root->getLeft()->getValue());
					root->getLeft()->setValue(smaller);
					trickleDown(root->getLeft());
					return;
				}
			}
			else if (root->getLeft()->getValue() < root->getRight()->getValue())
			{
				if (root->getRight()->getValue() > root->getValue())
				{
					int smaller = root->getValue();
					root->setValue(root->getRight()->getValue());
					root->getRight()->setValue(smaller);
					trickleDown(root->getRight());
					return;
				}
			}
		}
		else if (nullptr != root->getLeft())
		{
//			if (root->getLeft()->getValue() > root->getRight()->getValue())
//			{
				if (root->getLeft()->getValue() > root->getValue())
				{
					int smaller = root->getValue();
					root->setValue(root->getLeft()->getValue());
					root->getLeft()->setValue(smaller);
					trickleDown(root->getLeft());
					return;
				}
//			}
		}
		else if (nullptr != root->getRight())
		{
			if (root->getRight()->getValue() > root->getValue())
			{
				int smaller = root->getValue();
				root->setValue(root->getRight()->getValue());
				root->getRight()->setValue(smaller);
				trickleDown(root->getRight());
				return;
			}
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

