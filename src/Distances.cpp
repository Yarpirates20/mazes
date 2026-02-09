#include "include/Distances.h"
#include <stdexcept>
#include <vector>

/** @copydoc Distances::operator[](Cell *c) */
int &Distances::operator[](Cell *c)
{
    if (c == nullptr)
    {
        throw std::invalid_argument("Distances::operator[] received null Cell*");
    }

    // Inserts default 0 if missing.
    return distances[c];
}
/** @copydoc Distances::get(Cell *c) const */
std::optional<int> Distances::get(Cell *c) const
{
    if (c == nullptr)
        return std::nullopt;

    if (distances.find(c) != distances.end())
    {

        return std::optional<int>(distances.at(c));
    }

    return std::nullopt;
}

/** @copydoc Distances::get_cells() const */
std::vector<Cell *> Distances::get_cells() const
{
    std::vector<Cell *> tracked_cells;
    tracked_cells.reserve(distances.size());

    for (const auto &pair : distances)
        tracked_cells.push_back(pair.first);

    return tracked_cells;
}
