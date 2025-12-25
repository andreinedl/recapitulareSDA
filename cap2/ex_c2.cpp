//
// Created by Andrei on 24.12.2025.
// EX C2 - pag 20 curs

#include "ex_c2.h"
#include <iostream>

struct Node {
    Node* next;
    int data;
};

void clearMemory(Node* list) {
    while (list != nullptr) {
        Node* temp = list;
        list = list->next;
        delete temp;
    }
}

void print_list(Node*& list) {
    Node* temp = list;

    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << std::endl;
    temp = nullptr;
}

Node* merge_lists(Node* a, Node*b) {
    Node* head = nullptr;
    Node* tail = nullptr;

    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (b == nullptr) {
        return a;
    }
    if (a == nullptr) {
        return b;
    }

    if (a->data < b->data) {
        head = a;
        a = a->next;
        tail = head;
    } else {
        head = b;
        b = b->next;
        tail = head;
    }

    while (a != nullptr && b != nullptr) {
        if (a->data < b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    if (a != nullptr) {
        tail->next = a;
    } else if (b != nullptr) {
        tail->next = b;
    }

    return head;
}

void ex_c2() {
    Node* l1 = new Node{nullptr, 1};
    Node* l11 = new Node{nullptr, 3};
    Node* l12 = new Node{nullptr, 5};

    l1->next = l11;
    l11->next = l12;

    Node* l2 = new Node{nullptr, 2};
    Node* l21 = new Node{nullptr, 4};
    Node* l22 = new Node{nullptr, 6};

    l2->next = l21;
    l21->next = l22;

    print_list(l1);
    print_list(l2);
    Node* mergedList = merge_lists(l1, l2);
    print_list(mergedList);

    clearMemory(mergedList);
}
