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

/** @copydoc Cell::linked_cells() const */
std::vector<Cell *> Cell::linked_cells() const
{
    std::vector<Cell *> v(links.begin(), links.end());

    return v;
}

/** @copydoc Cell::neighbors const */
std::vector<Cell *> Cell::neighbors() const
{
    std::vector<Cell *> v;
    v.reserve(4);

    if (this->north != nullptr)
    {
        v.push_back(north);
    }

    if (this->east != nullptr)
    {
        v.push_back(east);
    }

    if (this->south != nullptr)
    {
        v.push_back(south);
    }

    if (this->west != nullptr)
    {
        v.push_back(west);
    }
    return v;
}

/** @copydoc Cell::get_row const */
int Cell::get_row() const
{
    return row;
}

/** @copydoc Cell::get_column const */
int Cell::get_column() const
{
    return column;
}
