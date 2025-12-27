#ifndef CELL_H
#define CELL_H

class Cell
{
private:
    int row,
        column;
    Cell *north,
        *east,
        *south,
        *west;

public:
    Cell() {}
};

#endif // CELL_H