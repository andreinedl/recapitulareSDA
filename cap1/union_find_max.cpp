//
// Created by Andrei on 22.12.2025.
// EX 1 pag 13 curs

#include "union_find_max.h"
#include <iostream>
#include <iomanip>

void afisareId(int id[], int N) {
    for (int i = 0; i < N; i++)
        std::cout << std::setw(2) << id[i] << " ";
    std::cout << "\n";
}

void union_find_max() {

    std::cout << "#### UNION FIND MAX ####" << std::endl;

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
    afisareId(id, N);

    for (int k = 0; k < nr_perechi; k++) {
        int p = perechi[k][0];
        int q = perechi[k][1];

        if (id[p] == id[q]) {
            std::cout << "Aceste noduri sunt deja conectate";
            continue;
        }


        int temp = std::min(id[p], id[q]);
        for (int i = 0; i < N; i++) {
            if (id[i] == temp) id[i] = std::max(id[q], id[p]);
        }

        std::cout << "Dupa conectarea (" << p << "," << q << "): ";
        afisareId(id, N);
    }

}