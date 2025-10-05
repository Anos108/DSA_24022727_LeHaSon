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
            swap(arr[j], arr[j + 1]);
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
