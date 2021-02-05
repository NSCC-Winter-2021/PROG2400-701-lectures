#include <iostream>
#include "Queue.h"

using namespace std;

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