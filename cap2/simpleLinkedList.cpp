//
// Created by Andrei on 23.12.2025.
//

#include "simpleLinkedList.h"
#include "iostream"

struct Node {
    int data;
    Node* next;
};

void simpleLinkedList() {
    Node* head = nullptr;
    Node* n1 = new Node;
    Node* n2 = new Node;
    Node* n3 = new Node;

    n1->data = 1;
    n2->data = 2;
    n3->data = 3;

    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;

    head = n1;

    std::cout << "Lista: ";
    while (head != nullptr) {
        std::cout << head->data << "->";
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    std::cout << "NULL" << std::endl;

}
