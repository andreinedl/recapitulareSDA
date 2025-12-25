//
// Created by Andrei on 23.12.2025.
// EX7 pag 14 CURS
#include <iostream>
#include "ex7.h"

struct Node {
    int data;
    Node* nextNode;
};

void push(Node** list, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->nextNode = *list;
    *list = newNode;
}

void pop(Node*& list) {
    if (list == nullptr) {
        std::cout << "Lista este goala." << std::endl;
        return;
    }

    Node* temp = list;
    list = (*list).nextNode;
    delete temp;
}

void ex7() {
    Node* list = nullptr;
    push(&list, 3);
    push(&list, 4);
    push(&list, 5);
    pop(list);
    push(&list, 3);
}