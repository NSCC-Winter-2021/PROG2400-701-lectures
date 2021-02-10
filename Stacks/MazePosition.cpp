
#include "MazePosition.h"

MazePosition::MazePosition() : row(-1), col(-1) {}

MazePosition::MazePosition(int row, int col)
    : row(row), col(col) {}

MazePosition::MazePosition(const MazePosition &pos)
    : MazePosition(pos.row, pos.col) {}

std::ostream& operator<<(std::ostream& output, MazePosition pos) {
    output << "(" << pos.row << "," << pos.col << ")";
    return output;
}
