//
// Created by Andrei on 29.12.2025.
//

#include "recursiveCMMDC.h"
#include <iostream>
#include <string>
#include <algorithm>

int depth;

std::string indentCMMDC() {
    return std::string(depth * 2, ' ');
}

struct tracer {
    int a;
    int b;
    tracer(int a, int b): a(a), b(b) {
        std::cout << indentCMMDC() << std::string(depth * 2, ' ') << "-> ENTER: cmmdc (" << this->a << ", " << this->b << ")" << std::endl;
        depth++;
    }

    ~tracer() {
        depth--;
        std::cout << indentCMMDC() << std::string(depth * 2, ' ') << "<- LEAVE: cmmdc (" << this->a << ", " << this->b << ")" <<  std::endl;
    }
};

int cmmdc(int a, int b) {
    tracer t(a, b);
    if (a == b) {
        std::cout << indentCMMDC() << "base-level: " << a << std::endl;
        return a;
    }

    if (std::max(a, b) == b) {
        b = b - a;
    } else {
        a = a - b;
    }
    int res = cmmdc(a, b);
    std::cout << indentCMMDC() << "return: " << a << ", " << b << std::endl;
    return res;
}

void recursiveCMMDC() {
    std::cout << cmmdc(8, 24) << std::endl;
}
