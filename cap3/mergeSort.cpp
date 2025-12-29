//
// Created by Andrei on 26.12.2025.
// https://www.geeksforgeeks.org/dsa/merge-sort/
// A se vedea capitolul 5 - recursivitatea din curs

#include "mergeSort.h"
#include "iostream"
#include "vector"

namespace mSort {
    void print(int arr[], int arrSize) {
        for (int i = 0; i < arrSize; i++) {
            std::cout << arr[i] << " ";
        }

        std::cout << std::endl;
    }

    void merge(int* arr, int left, int right) {
        int mid = left + (right-left)/2;

        int leftElements = mid - left + 1; //de la 0 pana la mijloc
        int rightElements = right - mid; //de la mijloc pana la maxim

        // se creeaza 2 vectori in care se copiaza jumatatile
        std::vector<int> L(leftElements);
        std::vector<int> R(rightElements);

        // se copiaza elementele din stanga si din dreapta in cei 2 vectori
        int counter = left; // se contorizeaza pozitia din array-ul initial

        for (int i = 0; i < leftElements; i++) {
            L.at(i) = arr[counter];
            counter++;
        }

        for (int j = 0; j < rightElements; j++) {
            R.at(j) = arr[counter];
            counter++;
        }

        // se insereaza elementele
        int i = 0, j = 0;
        counter = left;
        while (i < leftElements && j < rightElements && counter <= right) {
            if (L.at(i) <= R.at(j)) {
                arr[counter] = L.at(i);
                i++;
            } else {
                arr[counter] = R.at(j);
                j++;
            }
            counter++;
        }

        // se copiaza elementele ramase, daca mai sunt
        while (i < leftElements && counter <= right) {
            arr[counter] = L.at(i);
            i++;
            counter++;
        }

        while (j < rightElements && counter <= right) {
            arr[counter] = R.at(j);
            j++;
            counter++;
        }

        std::cout << "Merge interval [" << left << " - " << right << "]: ";
        for(int k = left; k <= right; k++) {
            std::cout << arr[k] << " ";
        }
        std::cout << std::endl;
    };

    void sort(int* arr, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left)/2;

        sort(arr, left, mid);
        sort(arr, mid + 1, right);
        merge(arr, left, right);
    }
}

void mergeSort() {
    int arr[]{1, 4, 5, 2, 8, 11, 9, 20, 0, 0, 0};

    int arrSize = sizeof(arr)/sizeof(int);
    int mid = 0 + arrSize/2;
    mSort::sort(arr, 0, arrSize - 1);
}