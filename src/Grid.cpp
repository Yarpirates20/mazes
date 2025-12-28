#include "include/Grid.h"

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
