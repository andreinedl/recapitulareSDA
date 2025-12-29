//
// Created by Andrei on 29.12.2025.
//

#include "tracedFactorial.h"
#include <string>
#include <iostream>

thread_local int __depth = 0; // "__" se pun doarece este o variabila de sistem
std::string indent() {
    std::string s = std::string(__depth * 2, ' ');
    return s;
}

struct TraceGuard {
    const char* name;
    std::string info;

    TraceGuard(const char* name, std::string info): name(name), info(info) {
        std::cout << indent() << "-> ENTER: " << this->name << "(" << this->info << ")" << std::endl;
        __depth++;
    }

    ~TraceGuard() {
        std::cout << indent() << "<- LEAVE: " << this->name << "(" << this->info << ")" << std::endl;
        __depth--;
    }
};

long long factorial(int n) {
    TraceGuard tg("factorial", std::to_string(n));
    if (n == 1 || n == 0) {
        std::cout << "base-level = 1" << std::endl;
        return 1;
    }

    std::cout << indent() << "compute n * factorial(n-1) where n=" << n << "\n";
    long long res = n * factorial(n-1);
    std::cout << indent() << "return " << n << " * " << n - 1 << "!" << " = " << res << std::endl;
    return res;
}

void tracedFactorial() {
    int n = 4;
    std::cout << "Trace factorial (" << n << ")" << std::endl;
    std::cout << "Rezultat: " <<  factorial(n) << std::endl;
}