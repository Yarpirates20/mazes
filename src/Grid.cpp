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

/** @copydoc Grid::render_bitmap() */
void Grid::render_bitmap()
{
    const std::size_t wall_size_x = 10;
    const std::size_t wall_size_y = 8;
    const std::size_t pen_size = 2;

    bitmap_image image(
        (columns)*wall_size_x + (pen_size - 1),
        (rows)*wall_size_y + (pen_size - 1));

    image.clear();

    {
        // Render background using Plasma effect
        const double c1 = 0.9;
        const double c2 = 0.5;
        const double c3 = 0.3;
        const double c4 = 0.7;

        ::srand(0xA5AA5AA5);

        plasma(image, 0, 0, image.width(), image.height(), c1, c2, c3, c4, 3.0, jet_colormap);
    }

    image_drawer draw(image);

    draw.pen_width(2);
    draw.pen_color(0, 0, 0);

    draw.rectangle(0, 0, image.width() - pen_size, image.height() - pen_size);

    // Draw maze
    for (std::size_t y = 0; y < rows; ++y)
    {
        for (std::size_t x = 0; x < columns; ++x)
        {
            // Cell(x, y) coordinates
            const int x0 = x * wall_size_x;
            const int y0 = y * wall_size_y;
            const int x1 = x * wall_size_x + wall_size_x;
            const int y1 = y * wall_size_y + wall_size_y;

            const auto cell = atrc(y, x);

            if (cell.north && !cell.is_linked(cell.north))
            {
                draw.line_segment(x0, y0, x1, y0);
            }

            if (cell.south && !cell.is_linked(cell.south))
            {
                draw.line_segment(x0, y1, x1, y1);
            }

            if (cell.east && !cell.is_linked(cell.east))
            {
                draw.line_segment(x1, y0, x1, y1);
            }

            if (cell.west && !cell.is_linked(cell.west))
            {
                draw.line_segment(x0, y0, x0, y1);
            }
        }
    }

    image.save_image("maze.bmp");
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
