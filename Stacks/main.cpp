#include <iostream>
#include "Stack.h"

using namespace std;

int main() {

    Stack stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);

    // Test 1
    cout << "Test 1" << endl;
    cout << "------" << endl;
    cout << stack << endl;

    // Test 2
    cout << "Test 2" << endl;
    cout << "------" << endl;
    cout << stack.Peek() << endl;

    // Test 3
    cout << "Test 3" << endl;
    cout << "------" << endl;
    cout << stack.Pop() << endl;
    cout << stack << endl;

    return 0;
}