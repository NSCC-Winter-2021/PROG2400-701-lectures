#include <iostream>
#include <algorithm>

using namespace std;

class LinkedListNode {
public:
    int data;               // the data to be stored
    LinkedListNode* next;   // a pointer to the next node in the chain

    LinkedListNode() : data(-1), next(nullptr) {}
};

class LinkedList {
private:
    LinkedListNode* start;

public:
    class iterator {
    public:
        LinkedListNode* node;

        iterator() : node(nullptr) {}
        iterator(LinkedListNode* node) : node(node) {}
        int operator*() { return node->data; }
        bool operator!=(iterator it) { return this->node != it.node; }
        iterator& operator++() { node = node->next; return *this; }
    };

    LinkedList() : start(nullptr) {

    }

    virtual ~LinkedList() {
        LinkedListNode* node = start;

        while (node != nullptr) {
            LinkedListNode* temp = node;
            node = node->next;
            delete temp;
        }
    }

    iterator begin() { return iterator(start); }
    iterator end() { return iterator(nullptr); }

    void Add(int data) {
        LinkedListNode* newNode = new LinkedListNode();
        newNode->data = data;

        if (start == nullptr) {
            // start a new chain
            start = newNode;
        } else {
            // add to end of existing chain
            LinkedListNode* node = start;
            LinkedListNode* prev = nullptr;

            // loop until the end of the chain
            while (node != nullptr) {
                prev = node;
                // move to next node
                node = node->next;
            }

            // if the end was found, attach new node
            if (prev != nullptr) {
                prev->next = newNode;
            }
        }
    }

    void Delete(int value) {
        LinkedListNode* node = start;
        LinkedListNode* prev = nullptr;

        // find the node to delete
        while (node != nullptr) {
            if (node->data == value) {
                // found the node, so exit the loop
                break;
            }
            prev = node;
            node = node->next;
        }

        // was the node found?
        if (node != nullptr) {
            // are we deleting the first node?
            if (prev == nullptr) {
                // update start of chain to second node
                start = node->next;
            } else {
                // deleting any other node
                prev->next = node->next;
            }

            delete node;

        } else {
            cout << "Node not found." << endl;
        }
    }

    void Insert(int data, int before) {
        LinkedListNode* newNode = new LinkedListNode();
        newNode->data = data;

        LinkedListNode* node = start;
        LinkedListNode* prev = nullptr;

        // find node to insert before
        while (node != nullptr) {
            if (node->data == before) {
                // found node, so exit loop
                break;
            }
            prev = node;
            node = node->next;
        }

        // did we find the node?
        if (node != nullptr) {
            // are we inserting before the first node?
            if (prev == nullptr) {
                // make the new node the new starting node
                newNode->next = start;
                start = newNode;
            } else {
                // insert the new node in the chain
                newNode->next = prev->next;
                prev->next = newNode;
            }
        }
    }

    friend ostream& operator<<(ostream& output, LinkedList& list);
};

ostream& operator<<(ostream& output, LinkedList& list) {

    LinkedListNode* node = list.start;

    while (node != nullptr) {
        output << node->data << " ";
        node = node->next;
    }
    return output;
}

int main() {

    LinkedList list;

    // test 1 - adding nodes
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Add(4);
    list.Add(5);

    cout << "Test 1" << endl;
    cout << "------" << endl;
    cout << list << endl;

    // test 2 - deleting nodes
    list.Delete(3); // delete the node with the value 3

    cout << endl;
    cout << "Test 2" << endl;
    cout << "------" << endl;
    cout << list << endl;

    // test 3 - inserting nodes
    list.Insert(6, 4); // insert the value 6 between 2 and 4
    list.Insert(0, 1); // insert 0 as the new first node

    cout << endl;
    cout << "Test 3" << endl;
    cout << "------" << endl;
    cout << list << endl;

    // test 4 - using an STL-like iterator

    // using an iterator, similar to STL
    for (LinkedList::iterator i = list.begin(); i != list.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;

    // using STL for_each algorithm
    for_each(list.begin(), list.end(), [](int n) {
       cout << n << " ";
    });
    cout << endl;

    // using range-based loop
    for (int n: list) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
