//
// Created by Andrei on 24.12.2025.
// EX C3 CURS PAG 20

#include "ex_c3.h"
#include "iostream"

struct Node {
    Node* next;
    int data;
};

void printList(Node* list) {
    while (list != nullptr) {
        std::cout << list->data << " ";
        list = list->next;
    }
    std::cout << std::endl;
}

int countNodes(Node* head) {
    if (head == nullptr) return 0;

    int count = 0;
    while (head != nullptr) {
        head = head->next;
        count++;
    }

    return count;
}

void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    //inversam legaturile
    while (current != nullptr) {
        next = current->next; // 2 3 nullptr
        current->next = prev;   // 3->2->1->nullptr
        prev = current; // se itereaza  1 2 3
        current = next; // 2 3 nullptr
    }

    head = prev;
}

void ex_c3() {
    Node* n1 = new Node{nullptr, 1};
    Node* n2 = new Node{nullptr, 2};
    Node* n3 = new Node{nullptr, 3};

    n1->next = n2;
    n2->next = n3;

    printList(n1);
    reverseList(n1);
    printList(n1);
}
