#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include "bitmap_image.hpp"

#include <vector>
#include <iostream>

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
    Grid(int r, int c) : rows(r), columns(c), grid(r, std::vector<Cell *>(c, nullptr))
    {
        prepare_grid();
        configure_cells();
    }

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

    /**
     * @brief Get the size of the grid.
     *
     * @return int Number of Cell that Grid contains.
     */
    int get_size();

    /**
     * @brief Accesses random cell.
     *
     * @return Cell& Reference to chosen Cell.
     */
    Cell &random_cell();

    /**
     * @brief Template function that calls fn(row) for each row.
     *
     * @tparam FUNC Callable type.
     * @param fn Function to call.
     */
    template <typename FUNC>
    void for_each_row(FUNC &&fn)
    {
        for (auto &row : grid)
            fn(row);
    }

    /**
     * @brief Const template function that calls fn(row) for each row.
     *
     * @tparam FUNC Callable type.
     * @param fn Function to call.
     */
    template <typename FUNC>
    void for_each_row(FUNC &&fn) const
    {
        for (auto &row : grid)
            fn(row);
    }

    /**
     * @brief Template function that calls fn(cell) for each cell in each
     * row in Grid.
     *
     * @tparam FUNC Callable type.
     * @param fn Function to call.
     */
    template <typename FUNC>
    void for_each_cell(FUNC &&fn)
    {
        for_each_row([&fn](auto &row)
                     {
        for (Cell *c : row)
            if (c) 
                fn(*c); });
    }

    /**
     * @brief Const template function that calls fn(cell) for each cell
     * in each row in Grid.
     *
     * @tparam FUNC Callable type.
     * @param fn Function to call.
     */
    template <typename FUNC>
    void for_each_cell(FUNC &&fn) const
    {
        for_each_row([&fn](auto const &row)
                     {
        for (Cell const *c : row)
            if (c) 
                fn(*c); });
    }

    /**
     * @brief Overloaded insertion operator to print out grid.
     * 
     * @param os Stream to ouput to.
     * @param g  Grid.
     * @return std::ostream& Output stream. 
     */
    friend std::ostream& operator <<(std::ostream &os, const Grid& g);

    /**
     * @brief Renders a bitmap image of the grid.
     * 
     */
    void render_bitmap();
};

#endif // GRID_H