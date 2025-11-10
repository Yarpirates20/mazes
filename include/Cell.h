#ifndef CELL_H
#define CELL_H


class Cell
{
private:
    int row;
    int column;

    Cell* north;
    Cell* east;
    Cell* south;
    Cell* west;


public:
    Cell(/*args*/);
};
#endif