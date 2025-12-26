//
// Created by Andrei on 26.12.2025.
// https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/

#include "iostream"
#include "vector"
#include "insertionSort.h"

namespace insSort {
    void sort(int* arr, int arrSize) {
        //incepem de la 1, in teorie primul element este deja "sortat"
        for (int i = 1; i < arrSize; i++) {
            int key = arr[i];
            int j = i - 1; // indexul anterior

            while (j >= 0 && key < arr[j]) {
                arr[j+1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    };

    void print(int* arr, int arrSize) {
        for (int i = 0; i < arrSize; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
}

void insertionSort() {
    int arr[] {1, 4, 5, 2, 8, 11, 9, 20, 0};
    insSort::sort(arr, sizeof(arr)/sizeof(int));
    insSort::print(arr, sizeof(arr)/sizeof(int));
}