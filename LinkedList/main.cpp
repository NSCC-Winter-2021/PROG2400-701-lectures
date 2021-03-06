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
    int length;
    LinkedListNode* start;

public:
    class iterator {
    public:
        LinkedListNode *node;
        int index;

        explicit iterator(LinkedListNode* node = nullptr) : node(node), index(0) {}

        int operator*() const { return node->data; }
        iterator& operator++() { node = node->next; index++; return *this; }
        bool operator!=(iterator it) const { return this->node != it.node; }
    };

    LinkedList() : start(nullptr), length(0) {

    }

    iterator begin() { return iterator(start); }
    iterator end() { return iterator(nullptr); }
    int count() { return length; }

    void Add(int data) {
        auto* newNode = new LinkedListNode();
        newNode->data = data;

        length++;

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

    list.Add(1);
    cout << "Count: " << list.count() << endl;
    list.Add(2);
    cout << "Count: " << list.count() << endl;
    list.Add(3);
    cout << "Count: " << list.count() << endl;
    list.Add(4);
    cout << "Count: " << list.count() << endl;
    list.Add(5);
    cout << "Count: " << list.count() << endl;

    cout << "Test 1" << endl;
    cout << "------" << endl;
    cout << list << endl;

    // using new iterator, similar to STL classes
    for( LinkedList::iterator i = list.begin(); i != list.end(); ++i ) {

        cout << *i << ",";
    }
    cout << endl;

    // from STL <algorithm> using lambda function
    for_each( list.begin(), list.end(), [](int n) {
        cout << n << " ";
    });
    cout << endl;

    // C++11
    for (int n: list) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
