//
// Created by Andrei on 29.12.2025.
//

#include "recursiveArrayRev.h"
#include <iostream>

void reverse(int* arr, int i, int j) {
    if (i >= j) return;

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    reverse(arr, ++i, --j);
}

void print(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

void recursiveArrayRec() {
    int arr[10] = {0, 1, 2, 4, 5, 6, 7, 8, 9, 10};
    int arrSize = sizeof(arr)/sizeof(int);
    print(arr, arrSize);

    reverse(arr, 0, arrSize - 1);
    print(arr, arrSize);
}