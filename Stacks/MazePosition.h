
#ifndef _MAZEPOSITION_H
#define _MAZEPOSITION_H

#include <iostream>

class MazePosition {
public:
    int row;
    int col;

    MazePosition();
    MazePosition(int row, int col);
    MazePosition(const MazePosition& pos);

    friend std::ostream& operator<<(std::ostream& output, MazePosition pos);
};

std::ostream& operator<<(std::ostream& output, MazePosition pos);

#endif //_MAZEPOSITION_H
