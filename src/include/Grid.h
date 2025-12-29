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
    Grid(int r, int c) : rows(r), columns(c), grid(r, std::vector<Cell *>(c, nullptr)) { prepare_grid(); }

    /**
     * @brief Prepares a 2D vector of Cell instances.
     * 
     */
    void prepare_grid();
    
    /**
     * @brief Configures cell neighbors. 
     * 
     */
    void configure_cells();

    /**
     * @brief Accessor with bounds checking for grid coordinates using row, 
     * columns.
     * 
     * @param r Row. 
     * @param c Column.
     * @return Cell& Returns modifiable reference to Cell at r, c.
     */
    Cell &atrc(int r, int c);

    /**
     * @brief Const accessor with bounds checking for grid coordinates using 
     * row, columns.
     * 
     * @param r Row. 
     * @param c Column.
     * @return Cell& Returns const reference to Cell at r, c.
     */
    Cell &atrc(int r, int c) const;
    
};

#endif // GRID_H