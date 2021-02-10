#include <iostream>
#include "MazeStack.h"

using namespace std;

int main() {

    MazeStack stack;

    stack.Push({1, 1});
    stack.Push({2, 1});
    stack.Push({3, 1});
    stack.Push({4, 1});
    stack.Push({5, 1});

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
    cout << "------" << endl;
    cout << stack << endl;

    // ----

    Maze maze;

    maze.ReadTextFile(filenameIn);
    maze.Solve();
    maze.WriteTextFile(filenameOut);

    return 0;
}