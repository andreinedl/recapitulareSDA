//
// Created by Andrei on 22.12.2025.
// EX4 - curs pag 14

#include "ex4.h"
#include <vector>
#include <iostream>

void ex4() {
    int nr_elemente;

    std::cout << "Introduceti numarul de elemente dorite: ";
    std::cin >> nr_elemente;
    std::cout << std::endl;

    int *elemente = new int[nr_elemente];
    int suma = 0;
    for (int i = 0; i < nr_elemente; i++) {
        std::cout << "Introduceti valoarea elementului " << i + 1 << ": ";
        std::cin >> elemente[i];
        std::cout << std::endl;
        suma += elemente[i];
    }

    std::cout << "Suma elementelor este: " << suma << std::endl;
    delete[] elemente;
}