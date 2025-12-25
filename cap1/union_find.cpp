//
// Created by Andrei on 22.12.2025.
// EX pag 11 curs

#include "union_find.h"
#include <iostream>
#include <iomanip>

void afisare_id(int id[], int N) {
    for (int i = 0; i < N; i++)
        std::cout << std::setw(2) << id[i] << " ";
    std::cout << "\n";
}

void union_find() {
    int N = 10;
    int id[N];

    //se initializeaza id[i] cu i
    for (int i = 0; i < N; ++i) {
        id[i] = i;
    }

    int perechi[][2] ={
        {3,4}, {4,9}, {8,0}, {2,3}, {5,6}, {5,9}, {7,3}, {4,8}, {6,1}
    };
    int nr_perechi = sizeof(perechi) / sizeof(perechi[0]);

    //Afisarea id urilor initiale
    afisare_id(id, N);

    for (int k = 0; k < nr_perechi; k++) {
        int p = perechi[k][0];
        int q = perechi[k][1];

        if (id[p] == id[q]) {
            std::cout << "Aceste noduri sunt deja conectate";
            continue;
        }

        int temp = id[p];
        for (int i = 0; i < N; i++) {
            if (id[i] == temp) id[i] = id[q];
        }

        std::cout << "Dupa conectarea (" << p << "," << q << "): ";
        afisare_id(id, N);
    }

}