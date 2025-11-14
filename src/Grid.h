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
        std::vector<std::vector<Cell*>> grid;

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
};

#endif // GRID_H