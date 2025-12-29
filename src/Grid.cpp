#include "include/Grid.h"
#include <stdexcept>

/** @copydoc Grid::prepare_grid() */
void Grid::prepare_grid()
{
    for(int r = 0; r < rows; ++r)
    {
        for(int c = 0; c < columns; ++c)
        {
            grid[r][c] = new Cell(r, c);
        }
    }
}

// TODO: Configure cells are creating atrc() and each_cell
/** @copydoc Grid::configure_cells() */
void Grid::configure_cells()
{
    return;
}

/** @copydoc Grid::atrc(int r, int c) */
Cell &Grid::atrc(int r, int c)
{
    if (r < 0 || r >= rows || c < 0 || c >= columns)
    {
        throw std::out_of_range("Coordinate row: " + std::to_string(r) + ", column: " + std::to_string(c) + " out of bounds"); 
    }

    return *grid[r][c];
}

/** @copydoc Grid::atrc(int r, int c) const */
Cell &Grid::atrc(int r, int c) const
{
    // TODO: insert return statement here
}
