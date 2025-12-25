//
// Created by Andrei on 23.12.2025.
//
#include <iostream>
#include <vector>

#include "test_mem.h"

void test_mem() {
    std::vector<int> v;

    // Pointer pentru a ține minte unde era vectorul înainte
    int* adresa_anterioara = nullptr;

    std::cout << "Incepem monitorizarea..." << std::endl;

    // Adăugăm 18 elemente, unul câte unul
    for (int i = 0; i < 18; i++) {
        v.push_back(i);

        // Obținem adresa actuală a datelor
        int* adresa_curenta = v.data();

        // Dacă adresa s-a schimbat, înseamnă că a avut loc o "Marea Mutare"
        if (adresa_curenta != adresa_anterioara) {
            std::cout << "\n[!] REALOCARE DETECTATA la elementul " << i << "!" << std::endl;
            std::cout << "   Capacitate noua: " << v.capacity() << " (Locuri totale)" << std::endl;
            std::cout << "   S-a mutat de la: " << adresa_anterioara
                      << " la: " << adresa_curenta << std::endl;

            adresa_anterioara = adresa_curenta;
        }
    }
}