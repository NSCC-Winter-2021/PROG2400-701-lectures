cmake_minimum_required(VERSION 3.17)
project(PROG2400_701_lectures)

set(CMAKE_CXX_STANDARD 14)

add_executable(echo Echo/main.cpp)
add_executable(cmdline CommandLine/main.cpp)
add_executable(parser CommandParsing/main.cpp)
add_executable(dynarray DynamicArrays/main.cpp)
add_executable(linkedlist LinkedList/main.cpp)
add_executable(queues Queues/main.cpp Queues/Queue.cpp)
add_executable(stacks Stacks/main.cpp Stacks/MazeStack.cpp Stacks/MazeStack.h Stacks/MazePosition.cpp Stacks/MazePosition.h)
