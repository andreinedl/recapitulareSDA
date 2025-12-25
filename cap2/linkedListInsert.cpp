//
// Created by Andrei on 23.12.2025.
//

#include <iostream>
#include "linkedListInsert.h"

struct Node {
    int data;
    Node* next;

    ~Node() {
        std::cout << "[DEBUG] Nodul " << data << " a fost sters din memorie" << std::endl;
    }
};

void push_front(Node*& head, int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void push_back(Node*& head, int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;

    if (head == nullptr) {
        head = new_node;
        return;
    }

    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = new_node;
}

void pop_back(Node*& head) {
    Node* currentNode = head;
    Node* prevNode = nullptr;
    while (currentNode->next != nullptr) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    delete currentNode;
    prevNode->next = nullptr;
}

void pop_front(Node*& head) {
    Node* poppedNode = head;
    head = poppedNode->next;
    delete poppedNode;
}

void linkedListInsert() {
    Node* head = nullptr;
    push_front(head, 3);
    push_front(head, 5);
    pop_front(head);
    push_front(head, 7);
    pop_back(head);
    push_back(head, 9);
}
