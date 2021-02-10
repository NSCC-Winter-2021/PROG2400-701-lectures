
#ifndef _STACK_H
#define _STACK_H

#include <iostream>
#include "MazePosition.h"

class Node {
public:
    MazePosition pos;
    Node* next;
    Node* prev;

    Node();
};

class MazeStack {
private:
    Node* first;
    Node* last;

public:
    MazeStack();
    virtual ~MazeStack();

    void Push(MazePosition pos);
    MazePosition Peek();
    MazePosition Pop();

    friend std::ostream& operator<<(std::ostream& output, MazeStack& stack);
};

std::ostream& operator<<(std::ostream& output, MazeStack& stack);

#endif // _STACK_H
