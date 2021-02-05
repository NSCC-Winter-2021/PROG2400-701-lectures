#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() : data(-1), next(nullptr) {}
};

class Queue {
private:
    Node* first;
    Node* last;

public:
    Queue() : first(nullptr), last(nullptr) {}
    virtual ~Queue() { Clear(); }

    void Push(int data) {
        Node* node = new Node();
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

    int Peek() {
        if (first != nullptr)
            return first->data;
        return -1;
    }

    int Pop() {
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

    void Clear() {
        while (first != nullptr) {
            Pop();
        }
    }

    friend ostream& operator<<(ostream& output, Queue& queue);
};

ostream& operator<<(ostream& output, Queue& queue) {

    Node* node = queue.first;

    while (node != nullptr) {
        output << node->data << " ";
        node = node->next;
    }
    return output;
}

int main() {

    Queue queue;

    queue.Push(1);
    queue.Push(2);
    queue.Push(3);
    queue.Push(4);
    queue.Push(5);

    // Test 1
    cout << "Test 1" << endl;
    cout << "------" << endl;
    cout << queue << endl;

    // Test 2
    cout << "Test 2" << endl;
    cout << "------" << endl;
    cout << queue.Peek() << endl;

    // Test 3
    cout << "Test 3" << endl;
    cout << "------" << endl;
    cout << queue.Pop() << endl;
    cout << queue << endl;

    // Test 4
    cout << "Test 4" << endl;
    cout << "------" << endl;
    while (queue.Peek() != -1) {
        cout << queue.Pop() << endl;
        cout << queue << endl;
    }

    // Test 5
    cout << "Test 5" << endl;
    cout << "------" << endl;
    queue.Push(1);
    queue.Push(2);
    cout << "Before Clear: ";
    cout << queue << endl;
    queue.Clear();
    cout << "After Clear: ";
    cout << queue << endl;

    return 0;
}