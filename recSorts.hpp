#pragma once
#include "Heap.hpp"

class recSorts
{
private:
	Heap* mHeap = nullptr;
public:
	recSorts();
	recSorts(int);
	std::string printAll();
	void heapSort(int*, int);
};

class rSorts
{
private:

public:
	rSorts();
	~rSorts();

	void mergeSort(int*, int);
	void sort(int*, int);
	void startMSort(int );
	void swap(int* a, int* b);
	int partition(int* mArray, int left, int right);
	void recQuickSort(int* mArray, int left, int right);
	void displayArray(int* mArray, int size);
	void quickSort(int*, int);
	int findNth(int*, int, int);

};

