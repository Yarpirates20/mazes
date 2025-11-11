#include "Cell.h"

/**
 * @copydoc Cell::link(Cell*, bool)
 * 
 * Implementation notes: 
 *  - Does nothing if 'cell' is null.
 *  - Inserts pointer into the internal unordered_set and optionally links back.
 */
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

/** @copydoc Cell::unlink(Cell*, bool) */
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

/** @copydoc Cell::is_linked(Cell*) const */
bool Cell::is_linked(Cell *cell) const
{
    return links.find(cell) != links.end();
}