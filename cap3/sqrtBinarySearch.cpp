//
// Created by Andrei on 26.12.2025.
//

#include "sqrtBinarySearch.h"
#include "iostream"

int sqrt(int x) {
    if (x == 0) return 0;

    int left = 0;
    int right = x;
    int ans = 1;

    while (left <= right) {
        long long mid = left + (right - left)/2;
        long long square = mid * mid;

        if (square == x) {
            return mid;
        }

        if (square < x) {
            ans = mid;
            left = mid + 1;
        }

        if (square > x) {
            right = mid - 1;
        }
    }

    return ans;
}

void sqrtBinarySearch() {
    std::cout << sqrt(2) << std::endl;
}