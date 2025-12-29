//
// Created by Andrei on 27.12.2025.
//

#include "postfixEvaluation.h"

#include <cctype> //isdigit
#include <iostream>
#include <stack>

int evaluate(const char* expr) {
    std::stack<int> data;
    int i = 0;

    while (expr[i] != '\0') {
        if (isdigit(expr[i])) {
            int number = expr[i] - '0'; // '0' are codul ascii 48 => numarul ascii - 48 va fi egal cu numarul
            data.push(number);
        } else {
            int b = data.top(); data.pop();
            int a = data.top(); data.pop();

            switch (expr[i]) {
                case '+': data.push(a+b); break;
                case '-': data.push(a-b); break;
                case '*': data.push(a*b); break;
                case 'x': data.push(a*b); break;
                case '/': data.push(a/b); break;
                default: ;
            }
        }
        i++;
    }

    return data.top();
}

void postfixEvaluation() {
    const char* expr = "512+4*+3-";
    std::cout << evaluate(expr) << std::endl;
}
