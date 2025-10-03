#include "sort.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool binarySearch(const vector<int> &a, int left, int right, int x) {
    int mid = left + (right - left) / 2;
    if (a[mid] == x) {
        return true;
    } else {
        while (left <= right) {
            if (a[mid] < x) {
                right = mid - 1;
            } else if (a[mid] > x) {
                left = mid + 1;
            }
        }
    }
    return false;
}

int swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 *
 * @param arr mảng ban đầu chưd sắp xếp
 */
void selectionSort(const vector<int> &arr) {
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
void insertionSort(const vector<int> &arr) {
    const int n = arr.size();
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
        }
    }
}

/**
 *
 * @param arr
 */
void bubbleSort(const vector<int> &arr) {
    const int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
