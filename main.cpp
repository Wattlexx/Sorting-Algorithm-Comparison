/*
Assignment 4
Source code that contains the main function
Nicholas Pinney
Student ID: 0696399
*/
#include <iostream>
#include <time.h>
#include <fstream>
#include "functions.h"

#define LIST_SIZE 50000 //change this number and the one in functions.cpp to change the list size

using namespace std;

int main()
{
    srand(time(NULL));

    string file = "nums.txt";
    fstream randNums;
    randNums.open (file, ios::out);

    for (int i = 0; i < LIST_SIZE; i++)
    {
        int num = rand()%1000;
        randNums << num << "\n";
    }
    randNums.close();

    int *nList = buildList(file);

    //heap sort
    int heapIterations = heapSort(nList, LIST_SIZE-1);

    //create heap file
    bool hSuccess = createSortedFile(nList, "heap.txt");
    if (!hSuccess)
    {
         cout << "Problem creating heap file";
         exit(100);
    }
    free(nList);

    int *nList1 = buildList(file);

    //bubble sort
    int bubbleIterations = bubbleSort(nList1, LIST_SIZE-1);

    //create bubble file
    bool bSuccess = createSortedFile(nList1, "bubble.txt");
    if (!bSuccess)
    {
         cout << "Problem creating bubble file";
         exit(100);
    }
    free(nList1);

    int *nList2 = buildList(file);

    //selection sort
    int selectionIterations = selectionSort(nList2, LIST_SIZE-1);

    //create selection file
    bool sSuccess = createSortedFile(nList2, "selection.txt");
    if (!sSuccess)
    {
         cout << "Problem creating selection file";
         exit(100);
    }
    free(nList2);

    cout << "DONE!\n";

    //create comparisons file
    createItrFile (heapIterations, bubbleIterations, selectionIterations);

    return 0;
}
