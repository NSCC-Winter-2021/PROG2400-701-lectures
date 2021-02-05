
#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node();
};

class Queue {
private:
    Node* first;
    Node* last;

public:
    Queue();
    virtual ~Queue();

    void Push(int data);
    int Peek();
    int Pop();
    void Clear();

    friend std::ostream& operator<<(std::ostream& output, Queue& queue);
};

std::ostream& operator<<(std::ostream& output, Queue& queue);

#endif //_QUEUE_H
