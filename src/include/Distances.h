#ifndef DISTANCES_H
#define DISTANCES_H

#include "Cell.h"
#include <unordered_map>
#include <optional>

class Distances
{
private:
    Cell *root;
    std::unordered_map<Cell *, int> distances;

public:
    /**
     * @brief Construct a new Distances object.
     * 
     * @param root_cell Cell that is used as starting point for tracking 
     * distance.
     */
    Distances(Cell *root_cell) : root(root_cell)
    {
        distances[root] = 0;
    }

    /**
     * @brief Insert-on-access read/write operator overload which inserts/
     * assigns with a default value and missing keys are created with default 
     * value. 
     * 
     * @param c 
     * @return int& 
     */
    int &operator[](Cell *c);
    std::optional<int> get(Cell * c) const;
};

#endif // DISTANCES_H