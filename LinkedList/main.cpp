#include <iostream>

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
    LinkedList() : start(nullptr) {

    }

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
    list.Add(2);
    list.Add(3);
    list.Add(4);
    list.Add(5);

    cout << "Test 1" << endl;
    cout << "------" << endl;
    cout << list << endl;

    return 0;
}
