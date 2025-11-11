#ifndef CELL_H
#define CELL_H

#include <unordered_set>

class Cell
{
private:
    int row;
    int column;

    Cell *north;
    Cell *east;
    Cell *south;
    Cell *west;

    std::unordered_set<Cell *> links;

public:
    Cell() : row(0), column(0), north(nullptr), east(nullptr), south(nullptr), west(nullptr) {};

    Cell(int r, int c) : row(r), column(c), north(nullptr), east(nullptr), south(nullptr), west(nullptr) {};

    Cell* link(Cell* cell, bool bidi = true);

    void unlink(Cell* cell, bool bidi = true);

    bool is_linked(Cell* cell) const;
};
#endif