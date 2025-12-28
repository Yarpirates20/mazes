#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include <vector>

/**
 * @brief Grid is wrapper for a 2D array of Cells.
 *
 */
class Grid
{
private:
    int rows;
    int columns;

    std::vector<std::vector<Cell *>> grid;

public:
    /**
     * @brief Constructor.
     * 
     * @param r Number of rows.
     * @param c Number of columns.
     */
    Grid(int r, int c) : rows(r), columns(c), grid(r, std::vector<Cell *>(c, nullptr)) {}

    /**
     * @brief Prepares a 2D vector of Cell instances.
     * 
     */
    void prepare_grid();
    
    void configure_cells();
};

#endif // GRID_H