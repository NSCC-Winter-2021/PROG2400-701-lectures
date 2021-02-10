//
// Created by nscc on 2/5/2021.
//

#include "MazeStack.h"

Node::Node() : next(nullptr), prev(nullptr) {}

MazeStack::MazeStack() : first(nullptr), last(nullptr) {}
MazeStack::~MazeStack() {
    while (first != nullptr) {
        Pop();
    }
}

void MazeStack::Push(MazePosition pos) {
    Node* node = new Node();
    node->pos = pos;
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

MazePosition MazeStack::Peek() {
    if (last != nullptr) {
        return last->pos;
    }
    return MazePosition();
}

MazePosition MazeStack::Pop() {
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

        MazePosition pos = node->pos;

        delete node;
        // return data from old last
        return pos;
    }
    return MazePosition();
}

std::ostream& operator<<(std::ostream& output, MazeStack& stack) {
    Node* node = stack.last;

    while (node != nullptr) {
        output << node->pos << std::endl;
        node = node->prev;
    }
    return output;
}
