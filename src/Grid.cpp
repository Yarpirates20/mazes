#include "Grid.h"

/** @copydoc Grid::Grid(int r, int c) */
Grid::Grid(int r, int c) : rows(r), columns(c)
{
    prepare_grid();
    configure_cells();
}

/** @copydoc Grid::prepare_grid() */
void Grid::prepare_grid()
{
    grid = std::vector<std::vector<Cell *>>(rows, std::vector<Cell *>(columns));
}

/** @copydoc Grid::configure_cells() */
void Grid::configure_cells()
{
}
