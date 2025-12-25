//
// Created by Andrei on 24.12.2025.
// EX C1 - pag 20 curs
// reverse pe segment, complexitate O(n) timp si O(1) spatiu
// complexitatea in spatiu = O(1) - oricat de mare ar fi vectorul, folosim aceeasi memorie pentru a roti vectorul
// complexitatea in timp = fiecare element este atins de 2 ori => O(2n), dar constantele sunt ignorate => O(n)

#include "ex_c1.h"
#include "iostream"
#include "vector"
#include "algorithm" // pentru reverse

void reverse(std::vector<int>& v, int start, int end) { // [1, 2, 3, 4, 5]
    while (start < end) {
        int temp = v[start];
        v[start] = v[end];
        v[end] = temp;

        start++;
        end--;
    }
}

void rotate_left(std::vector<int>& a, int k) { // [0 1 2 3 4]
    if (a.size() == 0) return;

    reverse(a, 0, k - 1);      // [1 0 2 3 4]
    reverse(a, k, a.size() - 1); // [1 0 4 3 2]
    reverse(a, 0, a.size() - 1); // [2 3 4 0 1]
}

void ex_c1() {
    std::vector<int> a = {0, 1, 2, 3, 4};
    rotate_left(a, 2);
    for (int i = 0; i < a.size(); i++) {
        std::cout << a.at(i) << " ";
    }
}