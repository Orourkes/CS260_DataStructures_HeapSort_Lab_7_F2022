//
//  main.cpp
//  SortingLab
//
//  Created by jim bailey on 11/15/19.
//  Copyright © 2019 jim bailey. All rights reserved.
//

#include <iostream>
#include <stdexcept>

// TESTHEAP and TESTPRIORITYQ are Base Lab
#define TESTHEAP
#define TESTPRIORITYQ

// TESTHEAPSORT, TESTMERGESORT, TESTQUICKSORT are Advanced Lab
#define TESTHEAPSORT
#define TESTMERGESORT
#define TESTQUICKSORT


// TESTFINDNTH is Thinking Problem
#define TESTFINDNTH

#ifdef TESTHEAP
#include "Heap.hpp"
#endif

#ifdef TESTPRIORITYQ
#include "PriorityQ.hpp"
#endif

//#if defined TESTHEAPSORT || defined TESTMERGESORT || defined TESTQUICKSORT
#include "recSorts.hpp"
//#endif

using std::cout;
using std::endl;


int main()
{
    const int NUM_VALUES = 17;

#ifdef TESTHEAP
    int heapVals[NUM_VALUES] = { 10, 5, 30, 15, 20, 40, 60, 25, 50, 35, 45, 65, 70, 75, 55, -1, 0 };

    cout << "Creating heap of default size (10)" << endl;
    Heap pile;

    // load the heap with values
    cout << "Now filling it with 17 values, should cause doubling of size" << endl << endl;
    for (int i = 0; i < NUM_VALUES; i++)
    {
        pile.addItem(heapVals[i]);
        cout << heapVals[i] << " ";
    }
    cout << endl << endl;
    cout << "New Heap array contains: " << endl;
    cout << pile.printAll() << endl;

    // remove values, should be in ascending order
    cout << "Now removing values to see if properly ordered" << endl;
    cout << " In order s/b: -1 0 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75" << endl;
    cout << " Actual order: ";
    for (int i = 0; i < NUM_VALUES; i++)
        cout << pile.getItem() << " ";
        cout << "New Heap array contains: " << endl;
        cout << pile.printAll() << endl;
    cout << endl << endl;

    // now test for taking one too many
    cout << "Now testing for exception on removing" << endl;
    try {
        pile.getItem();
        cout << "Should have failed, but did not" << endl;
    }
    catch (std::exception& ex) {
        cout << "Caught error message: " << ex.what() << endl;
    }

    cout << endl << "Done with testing heap" << endl << endl;

#endif // TESTHEAP

#ifdef TESTPRIORITYQ
    int pqVals[NUM_VALUES] = { 2, 4, 6, 8, 10, 1, 3, 5, 7, 9, 11, 15, 12, 14, 13, -1, 0 };

    cout << "Creating priority queue of default size (10)" << endl;
    PriorityQ pList;

    // load the heap with values
    cout << "Now filling it with 17 values, should cause doubling of size" << endl << endl;
    for (int i = 0; i < NUM_VALUES; i++)
        pList.addItem(pqVals[i]);

    // remove values, should be in ascending order
    cout << "Now removing values to see if properly ordered" << endl;
    cout << " In order s/b: -1 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15" << endl;
    cout << " Actual order: ";
    for (int i = 0; i < NUM_VALUES; i++)
        cout << pList.getItem() << " ";
    cout << endl << endl;

    // now test for taking one too many
    cout << "Now testing for exception on removing" << endl;
    try {
        pList.getItem();
        cout << "Should have failed, but did not" << endl;
    }
    catch (std::exception& ex) {
        cout << "Caught error message: " << ex.what() << endl;
    }

    cout << endl << "Done with testing priority queue" << endl << endl;

#endif // TESTPRIORITYQ

#ifdef TESTHEAPSORT
    int heapArray[NUM_VALUES] = { 41, 2, 3, 5, 13, 17, 43, 23, 29, 7, 11, 19, 31, 37, 47, -1, 0 };

    // show starting array
    cout << "Starting array is " << endl;
    for (int i = 0; i < NUM_VALUES; i++)
        cout << heapArray[i] << " ";
    cout << endl;

    recSorts rSort;
    // now sort it
    rSort.heapSort(heapArray, NUM_VALUES);

    // show updated array, should be in ascending order
    cout << "Now the array should be sorted" << endl;
    cout << " expected: -1 0 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47" << endl;
    cout << " actually: ";
    for (int i = 0; i < NUM_VALUES; i++)
        cout << heapArray[i] << " ";
    cout << endl;
    cout << rSort.printAll() << endl;

    cout << endl << "Done with testing heap sort" << endl << endl;

#endif // TESTHEAPSORT

#ifdef TESTMERGESORT
    int mergeArray[NUM_VALUES] = { 41, 2, 3, 5, 13, 17, 43, 23, 29, 7, 11, 19, 31, 37, 47, -1, 0 };
    rSorts mSort;
    //int mergeArray[3] = { 41, 2, 3, 5, 13, 17, 43, 23, 29, 7, 11, 19, 31, 37, 47, -1, 0};


    // show starting array
    cout << "Starting array is " << endl;
    for (int i = 0; i < NUM_VALUES; i++)
        cout << mergeArray[i] << " ";
    cout << endl;

    // now sort it
    mSort.mergeSort(mergeArray, NUM_VALUES);

    // show updated array, should be in ascending order
    cout << "Now the array should be sorted" << endl;
    cout << " expected: -1 0 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47" << endl;
    cout << " actually: ";
    for (int i = 0; i < NUM_VALUES; i++)
        cout << mergeArray[i] << " ";
    cout << endl;

    cout << endl << "Done with testing merge sort" << endl << endl;

#endif // TESTMERGESORT

#ifdef TESTQUICKSORT
    int quickArray[NUM_VALUES] = { 41, 2, 3, 5, 13, 17, 43, 23, 29, 7, 11, 19, 31, 37, 47, -1, 0 };
    rSorts qSort;

    // show starting array
    cout << "Starting array is " << endl;
    for (int i = 0; i < NUM_VALUES; i++)
        cout << quickArray[i] << " ";
    cout << endl;

    // now sort it
    qSort.quickSort(quickArray, NUM_VALUES);

    // show updated array, should be in ascending order
    cout << "Now the array should be sorted" << endl;
    cout << " expected: -1 0 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47" << endl;
    cout << " actually: ";
    for (int i = 0; i < NUM_VALUES; i++)
        cout << quickArray[i] << " ";
    cout << endl;

    cout << endl << "Done with testing quick sort" << endl << endl;

#endif // TESTQUICKSORT

#ifdef TESTFINDNTH
    int findArray[NUM_VALUES] = { 41, 2, 3, 5, 13, 17, 43, 23, 29, 7, 11, 19, 31, 37, 47, -1, 0 };

    // show starting array
    cout << "Starting array is " << endl;
    for (int i = 0; i < NUM_VALUES; i++)
        cout << findArray[i] << " ";
    cout << endl;
    rSorts fSort;
    

    // now find the value
    cout << "Finding 7th value, should be 13 " << endl;
    cout << " actually is: ";
    cout << fSort.findNth(findArray, NUM_VALUES, 7) << endl;


    // show updated array, should be in partially sorted order
    cout << "Now the array should be partially sorted" << endl;
    cout << " actually: ";
    for (int i = 0; i < NUM_VALUES; i++)
        cout << findArray[i] << " ";
    cout << endl;

    cout << endl << "Done with testing findNth " << endl << endl;

#endif // TESTFINDNTH

    return 0;
}