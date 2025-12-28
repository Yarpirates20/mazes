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

/** @copydoc Cell::get_links() const */
std::vector<Cell *> Cell::get_links() const
{
    return std::vector<Cell *>(this->links.begin(), this->links.end());
}

/** @copydoc Cell::is_linked(const Cell *other) const */
bool Cell::is_linked(const Cell *other) const
{
    if (other == nullptr) return false;

    return this->links.find(const_cast<Cell *>(other)) != this->links.end();
}

/** @copydoc Cell::neighbors() */
std::vector<Cell *> Cell::neighbors()
{
    std::vector<Cell *> neighbor_vec;
    if (this->north)
    {
        neighbor_vec.push_back(north);
    }

    if (this->east)
    {
        neighbor_vec.push_back(east);
    }

    if (this->south)
    {
        neighbor_vec.push_back(south);
    }

    if (this->west)
    {
        neighbor_vec.push_back(west);
    }


    return neighbor_vec;
}

/** @copydoc Cell::links_count() const */
std::size_t Cell::links_count() const
{
    return this->links.size();
}
