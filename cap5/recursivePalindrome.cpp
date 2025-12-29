//
// Created by Andrei on 29.12.2025.
//

#include "recursivePalindrome.h"
#include <iostream>
#include <string>

bool palindrome(std::string& str, int start, int stop) {
    if (start >= stop) return true;
    if (str[start] != str[stop]) return false;

    return palindrome(str, ++start, --stop);
}

void recursivePalindrome() {
    std::string s = "111222221";
    std::cout << palindrome(s, 0, s.length() - 1) << std::endl;
}
