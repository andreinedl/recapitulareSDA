//
// Created by Andrei on 24.12.2025.
//

#include "circularList.h"

#include <optional>

#include "iostream"

struct Node {
    Node* prev;
    Node* next;
    int data;
};

namespace cl {
    void push_front(Node*& head, int data) {
        Node* new_node = new Node{nullptr, nullptr, data};
        if (head == nullptr) {
            head = new_node;
            head->next = head;
            head->prev = head;
            return;
        }

        new_node->prev = head->prev;
        new_node->next = head;
        head->prev = new_node;

        new_node->prev->next = new_node; // nodul anterior lui new_node va avea ca valoare next noul nod

        head = new_node;
    }

    void push_back(Node*& head, int data) {
        Node* new_node = new Node{nullptr, nullptr, data};

        if (head == nullptr) {
            head = new_node;
            head->next = head;
            head->prev = head;
            return;
        }

        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
    }

    void pop_back(Node*& head) {
        if (head == nullptr) return;
        if (head->next == head || head->prev == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* poppedNode = head->prev;
        poppedNode->prev->next = head;
        head->prev = poppedNode->prev;
        delete poppedNode;
    }

    void pop_front(Node*& head) {
        if (head == nullptr) return;
        if (head->next == head || head->prev == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* poppedNode = head;
        poppedNode->next->prev = poppedNode->prev;
        poppedNode->prev->next = poppedNode->next;
        head = poppedNode->next;
        delete poppedNode;
    }
}

void circularList() {
    Node* head = nullptr;
    cl::push_front(head, 3);
    cl::push_front(head, 4);
    cl::push_front(head, 5);
    cl::push_front(head, 6);
    cl::push_back(head, 7);
    cl::pop_back(head);
    cl::pop_front(head);

    //curatare memorie
    while (head != nullptr) {
        cl::pop_back(head);
    }
}
