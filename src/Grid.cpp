#include "include/Grid.h"
#include <stdexcept>
#include <random>

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
    for_each_cell([&](Cell &x)
                  {
                      int r = x.get_row();
                      int c = x.get_col();

                        if (r > 0)
                            x.north = &atrc(r - 1, c);
                        else
                            x.north = nullptr;
                    
                        if (r < rows - 1)
                            x.south = &atrc(r + 1, c);
                        else
                            x.south = nullptr;
                        
                        if (c > 0)
                            x.west = &atrc(r, c - 1);
                        else
                            x.west = nullptr;
                        
                        if (c < columns - 1)
                            x.east = &atrc(r, c + 1);
                        else
                            x.east = nullptr; });
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

/** @copydoc Grid::random_cell() */
Cell &Grid::random_cell()
{
    std::random_device rnd;
    std::uniform_int_distribution<int> row_dist{0, rows - 1};
    std::uniform_int_distribution<int> col_dist{0, columns - 1};

    int random_row = row_dist(rnd);
    int random_col = col_dist(rnd);

    return atrc(random_row, random_col);
}

/** @copydoc operator<<(std::ostream &os, const Grid &g) */
std::ostream &operator<<(std::ostream &os, const Grid &g)
{
    // Top boundary
    os << "+";
    for (int i = 0; i < g.columns; ++i)
    {
        os << "---+";
    }
    os << "\n";

    g.for_each_row([&os](const std::vector<Cell *> &row)
                   {
        std::string top = "|";
        std::string bottom = "+";

        for (Cell *cell : row)
        {
            bool east_open = cell && cell->east && cell->is_linked(cell->east);
            bool south_open = cell && cell->south && cell->is_linked(cell->south);

            top += "   ";
            top += (east_open ? " " : "|");

            bottom += (south_open ? "   " : "---");
            bottom += "+";
        }

        os << top << "\n" << bottom << "\n"; });

    return os;
}
