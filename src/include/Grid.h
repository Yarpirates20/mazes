#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include <vector>

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
    Grid(int r, int c) : rows(r), columns(c), grid(r, std::vector<Cell *>(c, nullptr)) { prepare_grid(); }

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
    void for_each_row(FUNC &&fn);

    /**
     * @brief Const template function that calls fn(row) for each row.
     *
     * @tparam FUNC Callable type.
     * @param fn Function to call.
     */
    template <typename FUNC>
    void for_each_row(FUNC &&fn) const;

    /**
     * @brief Template function that calls fn(cell) for each cell in each
     * row in Grid.
     *
     * @tparam FUNC Callable type.
     * @param fn Function to call.
     */
    template <typename FUNC>
    void for_each_cell(FUNC &&fn);

    /**
     * @brief Const template function that calls fn(cell) for each cell
     * in each row in Grid.
     *
     * @tparam FUNC Callable type.
     * @param fn Function to call.
     */
    template <typename FUNC>
    void for_each_cell(FUNC &&fn) const;
};

#endif // GRID_H