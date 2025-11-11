#include "../include/Cell.h"
#include "Cell.h"

Cell *Cell::link(Cell *cell, bool bidi)
{
    if (!cell)
    {
        return this;
    }

    links.insert(cell);

    if (bidi)
    {
        cell->link(this, false);
    }

    return this;
}

void Cell::unlink(Cell *cell, bool bidi)
{
    if (!cell)
    {
        return; 
    }

    links.erase(cell);

    if (bidi)
    {
        cell->unlink(this, false);
    }
}

bool Cell::is_linked(Cell *cell) const
{
    return links.find(cell) != links.end();
}