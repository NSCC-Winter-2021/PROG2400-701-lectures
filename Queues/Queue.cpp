
#include "Queue.h"

Node::Node() : data(-1), next(nullptr) {}

Queue::Queue() : first(nullptr), last(nullptr) {}
Queue::~Queue() { Clear(); }

void Queue::Push(int data) {
    Node *node = new Node();
    node->data = data;

    if (first == nullptr) {
        // add first node
        first = node;
    } else {
        // add any other node
        last->next = node;
    }

    last = node;
}

int Queue::Peek() {
    if (first != nullptr)
        return first->data;
    return -1;
}

int Queue::Pop() {
    if (first != nullptr) {
        // disconnect first node
        Node *node = first;

        if (first == last) {
            // we are removing the last node
            last = nullptr;
        }
        first = node->next;

        int data = node->data;
        delete node;
        // return data from first node
        return data;
    }
    // no node to pop
    return -1;
}

void Queue::Clear() {
    while (first != nullptr) {
        Pop();
    }
}

std::ostream &operator<<(std::ostream &output, Queue &queue) {

    Node *node = queue.first;

    while (node != nullptr) {
        output << node->data << " ";
        node = node->next;
    }
    return output;
}
