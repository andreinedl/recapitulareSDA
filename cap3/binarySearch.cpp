//
// Created by Andrei on 25.12.2025.
// https://www.geeksforgeeks.org/dsa/binary-search/
// Include verificarea in cazul in care sunt mai multe elemente identice in acelasi array

#include "binarySearch.h"
#include "iostream"

int search(int arr[], int arraySize, int x) {
    int left = 0;
    int right = arraySize - 1;
    int result = -1; // negasit by default

    while (left <= right) {
        int mid = left + (right-left)/2;
        std::cout << "Mid :" << mid << std::endl;
        std::cout << "Left :" << left << std::endl;
        std::cout << "Right :" << mid << std::endl;

        // daca array-ul contine mai multe elemente identice, se ia primul din array
        if (arr[mid] == x) {
            result = mid;
            std::cout << "rezultat gasit: " << result << " cand mid = " << mid << std::endl;

            right = mid - 1;
        }

        if (x > arr[mid]) {
            left = mid + 1;
        }

        if (x < arr[mid]) {
            right = mid - 1;
        }
    }

    return result;
}

void binarySearch() {
    int arr[] {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int arr2[] {0, 0, 0, 0, 0, 0, 2, 3, 4, 5};

    int arrSize = sizeof(arr)/sizeof(int);
    int arr2Size = sizeof(arr2)/sizeof(int);

    std::cout << search(arr, arrSize, 23) << std::endl;
    std::cout << search(arr2, arr2Size, 2) << std::endl;

}
