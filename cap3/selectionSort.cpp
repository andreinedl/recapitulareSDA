//
// Created by Andrei on 26.12.2025.
// https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/
// Pagina 28 in curs

#include "iostream"
#include "vector"
#include "selectionSort.h"

namespace selSort {
    void sort(int* arr, int arrSize) {
        for (int i = 0; i < arrSize; i++) {
            int minElement = i; // se presupune ca cel mai mic element este cel de la pozitia curenta
            for (int j = i + 1; j < arrSize; j++) { // se restrange cautarea in dreapta celui mai mic element
                if (arr[j] < arr[minElement]) {
                    minElement = j; // daca se gaseste un element mai mic in dreapta lui, acesta este salvat
                }
            }

            // se muta cel mai mic element pe pozitia i, iar elementul care era pe
            // pozitia i este mutat pe pozitia anterioara a celui mai mic element
            if (minElement != i) {
                int temp = arr[i];
                arr[i] = arr[minElement];
                arr[minElement] = temp;
            }
        }
    }

    void print(int arr[], int arrSize) {
        for (int i = 0; i < arrSize; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
}

void selectionSort() {
    int arr[] {1, 4, 5, 2, 8, 11, 9, 20, 0, 0, 0};
    selSort::sort(arr, sizeof(arr)/sizeof(int));
    selSort::print(arr, sizeof(arr)/sizeof(int));
}
