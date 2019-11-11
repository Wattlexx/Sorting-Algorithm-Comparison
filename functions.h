#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

int* buildList (std::string myFile);
void printList (int numList[]);
int reheapUp (int* heap, int newNode);
int reheapDown (int* heap, int root, int last);
int heapSort (int heapList[], int last);
bool createSortedFile (int sortedList[], std::string fileName);
int bubbleSort (int randList[], int last);
int selectionSort (int randList[], int last);
void createItrFile (int hItr, int bItr, int sItr);

#endif // FUNCTIONS_H_INCLUDED
