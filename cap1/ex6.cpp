//
// Created by Andrei on 22.12.2025.
// EX6 pag 14 CURS

#include "ex6.h"
#include <iostream>

void ex6() {
    int m = 3;
    int n = 3;

    //Initializare matrice
    int** matrice = new int*[m];
    for (int i = 0; i < m; i++) {
        matrice[i] = new int[n];
    }

    int nr = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrice[i][j] = nr;
            nr += 2;
        }
    }

    //Eliberare memorie
    for (int i = 0; i < m; i++) {
        delete[] matrice[i];
    }

    delete[] matrice;
}