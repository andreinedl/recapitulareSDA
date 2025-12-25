//
// Created by Andrei on 23.12.2025.
//

#include <iostream>
#include "doubleLinkedList.h"

struct Node {
    Node* prev;
    Node* next;
    int data;

    ~Node() {
        std::cout << "[DEBUG] Nodul " << data << " a fost sters din memorie." << std::endl;
    }
};

namespace dll {
    void push_back(Node*& head, int data) {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;

        if (head == nullptr) {
            new_node->prev = nullptr;
            new_node->next = nullptr;
            head = new_node;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        new_node->prev = temp;
        temp->next = new_node;
    }

    void push_front(Node*& head, int data) {
        Node* new_node = new Node{nullptr, nullptr, data};
        if (head == nullptr) {
            head = new_node;
            return;
        }

        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }

    void pop_front(Node*& head) {
        if (head == nullptr) return;

        Node* temp = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        delete temp;
    }

    void pop_back(Node*& head) {
        if (head == nullptr) return;

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->prev->next = nullptr;
        delete temp;
    }

}

void doubleLinkedList() {
    Node* head = nullptr;

    dll::push_back(head, 3);
    dll::push_back(head, 4);
    dll::push_back(head, 5);
    dll::push_back(head, 6);
    dll::push_front(head, 6);
    dll::pop_front(head);
    dll::pop_back(head);
}
