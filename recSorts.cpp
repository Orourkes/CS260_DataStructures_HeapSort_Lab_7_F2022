#include "recSorts.hpp"
#include "Heap.hpp"
#include <iostream>

recSorts::recSorts()
{
	//mHeap = new Heap();
}

recSorts::recSorts(int hSize)
{
	//mHeap = new Heap(hSize);
}

std::string recSorts::printAll()
{
	return mHeap->printAll();
}

void recSorts::heapSort(int* hArray, int heapSize)
{
	mHeap = new Heap(heapSize);

	for (int i = 0; i < heapSize; i++)
	{
		mHeap->addItem(hArray[i]);
	}

	for (int i = 0; i < heapSize; i++)
	{
		hArray[i] = mHeap->getItem();
	}
}

void rSorts::mergeSort(int* mArray, int mSize)
{
	int* left = nullptr;
	int* right = nullptr;
	if (mSize > 3)
	{
		const int halfSize1 = (mSize / 2);
		const int halfSize2 = mSize - halfSize1;
		left = new int[halfSize1];
		right = new int[halfSize2];

		for (int i = 0; i < halfSize1; i++)
			left[i] = mArray[i];
		for (int i = 0; i < halfSize2; i++)
			right[i] = mArray[halfSize1 + i];

		if (halfSize1 > 3)
			mergeSort(left, halfSize1);
		if (halfSize2 > 3)
			mergeSort(right, halfSize2);

		int max, min;
		if (halfSize1 != halfSize2)
		{
			max = (halfSize1 > halfSize2) ? halfSize1 : halfSize2;
			min = (halfSize1 < halfSize2) ? halfSize1 : halfSize2;
		}
		else
			max = min = halfSize1;

		sort(left, halfSize1);
		sort(right, halfSize2);
		int l = 0;
		int r = 0;
		int m = 0;
		while (l < halfSize1 && r < halfSize2)
		{
			if (left[l] < right[r])
			{
				mArray[m] = left[l];
				l++, m++;
				if (l == halfSize1)
				{
					while (r < halfSize2)
					{
						mArray[m] = right[r];
						r++, m++;
					}
				}

			}
			else
			{
				mArray[m] = right[r];
				r++, m++;
				if (r == halfSize2)
				{
					while (l < halfSize1)
					{
						mArray[m] = left[l];
						l++, m++;
					}
				}
			}
		}
		if (halfSize1 > halfSize2)
		{
			for (int i = halfSize2; i < halfSize1; i++)
			{
				mArray[m] = left[i];
				m++;
			}
		}
		else if (halfSize2 > halfSize1)
		{
			for (int i = halfSize1; i < halfSize2; i++)
			{
				mArray[m] = right[i];
				m++;
			}
		}
	}
	else
	{
		sort(mArray, mSize);
	}
	//if (left != nullptr) { delete left; }
	//if (right != nullptr) {delete right;}
}

void rSorts::sort(int* mArray, int mSize)
{
	for (int i = 0; i < mSize; i++)
	{
		for (int k = i+1; k < mSize; k++)
		{
			if (mArray[i] > mArray[k])
			{
				int holder = mArray[i];
				mArray[i] = mArray[k];
				mArray[k] = holder;
			}
		}
	}
}

  
void rSorts::swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;

}

// partition the array using last element as pivot
int rSorts::partition(int* mArray, int left, int right)
{
	int pivot = mArray[right];    // pivot 
	int i = (left - 1);

	for (int j = left; j <= right - 1; j++)
	{
		//if current element is smaller than pivot, increment the left element
		//swap elements at i and j
		if (mArray[j] <= pivot)
		{
			i++;    // increment index of smaller element 
			swap(&mArray[i], &mArray[j]);
		}
	}
	swap(&mArray[i + 1], &mArray[right]);
	return (i + 1);
}

//quicksort algorithm
void rSorts::recQuickSort(int* mArray, int left, int right)
{
	if (left < right)
	{
		//partition the array 
		int pivot = partition(mArray, left, right);
		
		//sort the sub arrays independently 
		recQuickSort(mArray, left, pivot - 1);
		recQuickSort(mArray, pivot + 1, right);
	}
}
void rSorts::quickSort(int* mArray, int hSize)
{
	recQuickSort(mArray, 0, hSize - 1);
}


int rSorts::findNth(int* fArray, int fSize, int location)
{
	quickSort(fArray, fSize);
	return fArray[location];
}

rSorts::rSorts()
{

}

rSorts::~rSorts()
{

}
