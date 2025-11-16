#ifndef GRID_H
#define GRID_H

#include "Cell.h"

/**
 * @brief A 2D array of Cell objects.
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
     * @brief Default constructor.
     *
     */
    Grid() : rows(0), columns(0) {}

    /**
     * @brief Construct a new Grid with r rows and c columns.
     *
     * @param r Number of rows.
     * @param c Number of columns.
     *
     * Prepares the grid and configures the cells.
     */
    Grid(int r, int c);

    /**
     * @brief Sets up 2D array of Cell instances.
     *
     */
    void prepare_grid();

    /**
     * @brief Tells each cell who its immediate neighbors are to North,
     * South, East, and West.
     *
     */
    void configure_cells();

    /**
     * @brief Safe accessor.
     *
     * @param r Row to check.
     * @param c Column to check.
     * @return Cell* A pointer to a cell if valid, else nullptr.
     */
    Cell *atrc(int r, int c);

    /**
     * @brief Returns a random cell at random row, random column.
     *
     * @return Cell* A pointer to random cell.
     */
    Cell *random_cell();

    /**
     * @brief Accesor for size of grid.
     * 
     * @return int Integer number of cells in grid.
     */
    int size();
};
#endif // GRID_H