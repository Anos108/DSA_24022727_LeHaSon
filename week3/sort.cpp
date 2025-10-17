#include "sort.h"
#include <bits/stdc++.h>
using namespace std;

bool mybinarySearch(vector<int> &arr, int left, int right, int x) {
    while (left <= right) {
        if (int mid = left + (right - left) / 2; arr[mid] == x) {
            return true;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else if (arr[mid] > x) {
            right = mid - 1;
        }
    }

    return false;
}


/**
 *
 * @param arr mảng ban đầu chưd sắp xếp
 */
void selectionSort(vector<int> &arr) {
    const int n = arr.size();
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

/**
 *
 * @param arr
 */
void insertionSort(vector<int> &arr) {
    const int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/**
 *
 * @param arr
 */
void bubbleSort(vector<int> &arr) {
    const int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void mergeSort(std::vector<int> &arr) {
}


void quickSort(std::vector<int> &arr, int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        partition(arr, left, pivot - 1);
        partition(arr, pivot + 1, right);
    }
}

int partition(std::vector<int> &arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}


void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
