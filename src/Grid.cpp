#include "Grid.h"

#include <random>

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

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            grid[i][j] = new Cell(i, j);
        }
    }
}

/** @copydoc Grid::configure_cells() */
void Grid::configure_cells()
{
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < columns; ++c)
        {
            Cell *curr = grid[r][c];
            curr->north = atrc(r - 1, c);
            curr->south = atrc(r + 1, c);
            curr->west = atrc(r, c - 1);
            curr->east = atrc(r, c + 1);
        }
    }
}

/** @copydoc Grid::atrc(int r, int c) */
Cell *Grid::atrc(int r, int c)
{
    if (r < 0 || r >= rows || c < 0 || c >= columns)
    {
        return nullptr;
    }

    Cell *ptr = grid[r][c];

    return ptr;
}

/** @copydoc Grid::random_cell() */
Cell *Grid::random_cell()
{
    if (rows == 0 || columns == 0)
    {
        return nullptr;
    }

    int r = rand() % rows;
    int c = rand() % columns;

    return grid[r][c];
}

int Grid::size()
{
    return rows * columns;
}
