//
// Created by Andrei on 28.12.2025.
//

#include <iostream>
#include <string>
#include <stack>
#include "postfixToInfix.h"

bool isOperand(char x) {
    return  (x >= 'a' && x <= 'z') ||
            (x >= 'A' && x <= 'Z') ||
            (x >= '0' && x <= '9');
}

void convert(const char* expr) {
    int capacity = 10;
    int i = 0;
    std::stack<std::string> strings;
    while (expr[i] != '\0') {
        if (isOperand(expr[i])) {
            std::string s(1, expr[i]);
            strings.push(s);
        } else if (expr[i] == ' ') {
            i++;
            continue;
        }
        else {
            if (strings.size() < 2) {
                std::cout << "Expresie invalida!" << std::endl;
                return;
            }

            std::string opB = strings.top(); strings.pop();
            std::string opA = strings.top(); strings.pop();

            strings.push("(" + opA + expr[i] + opB + ")");
        }
        i++;
    }

    if (!strings.empty()) {
        std::string result = strings.top();

        if (result.length() >= 2 && result.front() == '(' && result.back() == ')') {
            result = result.substr(1, result.length() - 2);
        }

        std::cout << result << std::endl;
    }
}

void postfixToInfix() {
    const char* expr = "34+56 + *";
    std::cout << expr << std::endl;
    convert(expr);
}
