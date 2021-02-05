//
// Created by nscc on 2/5/2021.
//

#include "Stack.h"

Node::Node() : data(-1), next(nullptr), prev(nullptr) {}

Stack::Stack() : first(nullptr), last(nullptr) {}
Stack::~Stack() {
    while (first != nullptr) {
        Pop();
    }
}

void Stack::Push(int data) {
    Node* node = new Node();
    node->data = data;
    node->prev = last;

    if (first == nullptr) {
        // adding first node
        first = node;
    } else {
        // adding other nodes
        last->next = node;
    }

    last = node;
}

int Stack::Peek() {
    if (last != nullptr) {
        return last->data;
    }
    return -1;
}

int Stack::Pop() {
    if (last != nullptr) {

        Node* node = last;

        if (first == last) {
            // removing only node
            first = last = nullptr;
        } else {
            // removing other node
            node->prev->next = nullptr;
        }

        // make 2nd last new last
        last = node->prev;

        int data = node->data;

        delete node;
        // return data from old last
        return data;
    }
    return -1;
}

std::ostream& operator<<(std::ostream& output, Stack& stack) {
    Node* node = stack.last;

    while (node != nullptr) {
        output << node->data << " ";
        node = node->prev;
    }
    return output;
}
