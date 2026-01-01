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
     * @param c Cell to map.
     * @return int& Reference that can be assigned/read.
     */
    int &operator[](Cell *c);

    /**
     * @brief Optional-returning lookup which does not modify map.
     * 
     * @param c Cell key to get value for.
     * @return std::optional<int> Returns no value when absent, else returns 
     * value.
     */
    std::optional<int> get(Cell * c) const;
};

#endif // DISTANCES_H