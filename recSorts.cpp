#include "recSorts.hpp"

recSorts::recSorts()
{
	mHeap = new Heap();
}

recSorts::recSorts(int hSize)
{
	mHeap = new Heap(hSize);
}

void recSorts::heapSort(int* hArray, int heapSize)
{
	recSorts(heapSize);
	for (int i = 0; i < heapSize; i++)
	{
		mHeap->addItem(hArray[i]);
	}
	for (int i = 0; i < heapSize; i++)
	{
		mHeap->getItem();
	}
}

void recSorts::mergeSort(int* hArray, int)
{
}

void recSorts::quickSort(int* hArray, int)
{
}

void recSorts::findNth(int* hArray, int)
{
}
