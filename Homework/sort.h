#ifndef DSA_24022727_LEHASON_SORT_H
#define DSA_24022727_LEHASON_SORT_H
#include <vector>

bool mybinarySearch(std::vector <int> & arr, int left, int right, int x);

void selectionSort(std::vector <int> & arr);

void insertionSort(std::vector <int> & arr);

void bubbleSort(std::vector <int> & arr);

void mergeSort(std::vector<int> & arr);

void quickSort(std::vector<int> & arr);

void heapSort(std::vector<int> & arr);

void heapify(std::vector<int> & arr, int n, int i);

#endif //DSA_24022727_LEHASON_SORT_H
