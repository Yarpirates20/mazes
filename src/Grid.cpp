#include "include/Grid.h"
#include <stdexcept>

/** @copydoc Grid::prepare_grid() */
void Grid::prepare_grid()
{
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < columns; ++c)
        {
            grid[r][c] = new Cell(r, c);
        }
    }
}

/** @copydoc Grid::configure_cells() */
void Grid::configure_cells()
{
    // TODO: Configure cells are creating atrc() and each_cell
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
    if (r < 0 || r >= rows || c < 0 || c >= columns)
    {
        throw std::out_of_range("Coordinate row: " + std::to_string(r) + ", column: " + std::to_string(c) + " out of bounds");
    }

    return *grid[r][c];
}

/** @copydoc Grid::get_size() */
int Grid::get_size()
{
    return rows * columns;
}

/** @copydoc Grid::for_each_row(FUNC &&fn) */
template <typename FUNC>
void Grid::for_each_row(FUNC &&fn)
{
    for (auto &row : grid)
        fn(row);
}

/** @copydoc Grid::for_each_row(FUNC &&fn) const */
template <typename FUNC>
void Grid::for_each_row(FUNC &&fn) const
{
    for (auto &row : grid)
        fn(row);
}

/** @copydoc Grid::for_each_cell(FUNC &&fn) */
template <typename FUNC>
void Grid::for_each_cell(FUNC &&fn)
{
    for_each_row([&fn](auto &row)
                 {
        for (Cell *c : row)
            if (c) 
                fn(*c); });
}

/** @copydoc Grid::for_each_cell(FUNC &&fn) const */
template <typename FUNC>
void Grid::for_each_cell(FUNC &&fn) const
{
    for_each_row([&fn](auto const &row)
                 {
        for (Cell const *c : row)
            if (c) 
                fn(*c); });
}
