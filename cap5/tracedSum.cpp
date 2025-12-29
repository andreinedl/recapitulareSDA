//
// Created by Andrei on 29.12.2025.
//

#include "tracedSum.h"
#include <iostream>
#include <string>

thread_local int depth = 0;
std::string indentation() {
    return std::string(depth * 2, ' ');
}

struct TraceGuard {
    const char* name;
    std::string info; // iteration or smth else

    TraceGuard(const char* name, std::string info): name(name), info(info) {
        std::cout << indentation() << "-> ENTER: " << this->name << "(" << this->info << ")" << std::endl;
        depth++;
    }

    ~TraceGuard() {
        depth--;
        std::cout << indentation() << "<- LEAVE " << this->name << "(" << this->info << ")" << std::endl;
    }
};

int sum(int n) {
    TraceGuard tg("sum", std::to_string(n));
    if (n == 0) {
        std::cout << indentation() << "base-case = 0" << std::endl;
        return 0;
    }

    std::cout << indentation() << "calculating " << n << " + suma(" << n-1 << ")" << std::endl;
    int res = n + sum(n-1);
    std::cout << indentation() << "return " << n << " + suma(" << n-1 << ") = " << res << std::endl;
    return res;
}

void tracedSum() {
    std::cout << "--- Start Trace ---" << std::endl;
    std::cout << "Rezultat final: " << sum(3) << std::endl; // Testam cu 3 ca e mai scurt
}