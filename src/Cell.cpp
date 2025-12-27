#include "include/Cell.h"

/** @copydoc Cell::link(Cell *other, bool bidrectional) */
Cell &Cell::link(Cell *other, bool bidirectional)
{
    if (other != nullptr && other != this)
    {
        if (this->links.find(other) == this->links.end())
        {
            this->links.insert(other);
            if (bidirectional)
                other->link(this, false);
        }
    }

    return *this;
}

/** @copydoc Cell::unlink(Cell *other, bool directional) */
Cell &Cell::unlink(Cell *other, bool bidirectional)
{
    if (other != nullptr && other != this)
    {
        if (this->links.find(other) != this->links.end())
        {
            auto removed = this->links.erase(other);
            if (removed == 1)
            {
                if (bidirectional)
                {
                    other->unlink(this, false);
                }
            }
        }
    }

    return *this;
}