#pragma once
#include "Heap.hpp"

class recSorts
{
private:
	Heap * mHeap;

public:
	recSorts();
	recSorts(int);
	void heapSort(int* hArray, int);
	void mergeSort(int* hArray, int);
	void quickSort(int* hArray, int);
	void findNth(int* hArray, int);

};

