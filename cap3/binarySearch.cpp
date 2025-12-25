//
// Created by Andrei on 25.12.2025.
// https://www.geeksforgeeks.org/dsa/binary-search/

#include "binarySearch.h"
#include "iostream"

int search(int arr[], int x) {
    int left = 0;
    int right = (sizeof(arr)/sizeof(int)) - 1;
    while (left <= right) {
        int mid = left + (right-left)/2;

        if (arr[mid] == x) return mid;

        if (x > arr[mid]) {
            left = mid + 1;
        }

        if (x < arr[mid]) {
            right = mid - 1;
        }
    }

    return -1;
}

void binarySearch() {
    int arr[] {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};

    std::cout << search(arr, 23) << std::endl;

}
