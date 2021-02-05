
#ifndef _STACK_H
#define _STACK_H

#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node();
};

class Stack {
private:
    Node* first;
    Node* last;

public:
    Stack();
    virtual ~Stack();

    void Push(int data);
    int Peek();
    int Pop();

    friend std::ostream& operator<<(std::ostream& output, Stack& stack);
};

std::ostream& operator<<(std::ostream& output, Stack& stack);

#endif // _STACK_H
