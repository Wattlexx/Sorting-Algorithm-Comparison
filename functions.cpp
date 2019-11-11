#include <iostream>
#include <time.h>
#include <fstream>
#include "functions.h"

#define LIST_SIZE 50000

int* buildList (std::string myFile)
{
    int* listPtr = (int*)calloc(LIST_SIZE, sizeof(int));

    std::fstream fileList;
    fileList.open(myFile, std::ios::in);

    if (!fileList)
    {
        std::cout << "error opening the file";
        exit(100);
    }

    int a, i = 0;
    while (fileList >> a)
    {
        listPtr[i] = a;
        ++i;
    }
    fileList.close();
    return listPtr;
}

void printList(int numList[])
{
    for (int i = 0; i < LIST_SIZE; i++)
    {
        std::cout << numList[i] << "\t";
    }
}

int reheapUp (int* heap, int newNode)
{
    int parent;
    int hold;

    if (newNode)
    {
        parent = (newNode - 1)/2;
        if (heap[newNode] > heap[parent])
        {
            hold = heap[parent];
            heap[parent] = heap[newNode];
            heap[newNode] = hold;
            reheapUp (heap, parent);
        }
    }
    return +1;
}

int reheapDown (int* heap, int root, int last)
{
    int hold;
    int leftKey;
    int rightKey;
    int largeChildKey;
    int largeChildIndex;

    if ((root*2 + 1) <= last)
    {
        leftKey = heap[root*2+1];
        if((root*2 + 2) <= last)
            rightKey = heap[root*2+2];
        else
            rightKey = -1;

        if (leftKey > rightKey)
        {
            largeChildKey = leftKey;
            largeChildIndex = root*2+1;
        }
        else
        {
            largeChildKey = rightKey;
            largeChildIndex = root*2+2;
        }

        if (heap[root] < heap[largeChildIndex])
        {
            hold = heap[root];
            heap[root] = heap[largeChildIndex];
            heap[largeChildIndex] = hold;
            reheapDown(heap, largeChildIndex, last);
        }
    }
    return +1;
}

int heapSort(int* heapList, int last)
{

    int iterations = 0;
    int sorted;
    int holdData;

    for (int walker = 1; walker <= last; walker++)
    {
        iterations += reheapUp(heapList, walker);
    }

    sorted = last;
    while (sorted > 0)
    {
        holdData = heapList[0];
        heapList[0] = heapList[sorted];
        heapList[sorted] = holdData;
        sorted--;
        iterations += reheapDown(heapList, 0, sorted);
    }
    return iterations;
}

bool createSortedFile(int sortedList[], std::string fileName)
{
    std::fstream numberFile;
    numberFile.open (fileName, std::ios::out);

    if (!numberFile)
        return false;

    for (int i = 0; i < LIST_SIZE; i++)
    {
        int num = sortedList[i];
        numberFile << num << "\n";
    }
    numberFile.close();
    return true;
}

int bubbleSort (int randList[], int last)
{
    int iterations = 0, temp;
    for (int current = 0, sorted = 0; current <= last && !sorted; current++, iterations++)
    {
        for (int walker = last, sorted = 1; walker > current; walker--, iterations++)
        {
            if (randList[walker] < randList[walker-1])
            {
                sorted = 0;
                temp = randList[walker];
                randList[walker] = randList[walker-1];
                randList[walker-1] = temp;
            }
        }
    }
    return iterations;
}

int selectionSort (int randList[], int last)
{
    int smallest;
    int holdData;
    int iterations = 0;

    for(int current = 0; current < last; current++, iterations++)
    {
        smallest = current;
        for (int walker = current + 1; walker <= last; walker++, iterations++)
            if (randList[walker] < randList[smallest])
                smallest = walker;

        holdData = randList[current];
        randList[current] = randList[smallest];
        randList[smallest] = holdData;
    }
    return iterations;
}

void createItrFile (int hItr, int bItr, int sItr)
{
    std::fstream itrFile;
    itrFile.open ("comparison.txt", std::ios::out);

    itrFile << "Bubble\t\tSelection\tHeap\n";
    itrFile << bItr <<"\t" << sItr << "\t" << hItr << "\n";

    itrFile.close();
    return;
}
