#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include <vector>

/**
 * @brief A 2D array of Cell objects.
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

    /**
     * @brief Safe accessor.
     *
     * @param r Row to check.
     * @param c Column to check.
     * @return Cell* A pointer to a cell if valid, else nullptr.
     */
    Cell *atrc(int r, int c);

    /**
     * @brief Returns a random cell at random row, random column.
     *
     * @return Cell* A pointer to random cell.
     */
    Cell *random_cell();

    /**
     * @brief Accesor for size of grid.
     *
     * @return int Integer number of cells in grid.
     */
    int size();

    /**
     * Iterator types to iterate over rows (each row is std::vector<Cell*>).
     */
    using Row = std::vector<Cell *>;
    using iterator = std::vector<Row>::iterator;
    using const_iterator = std::vector<Row>::const_iterator;

    // begin/end for range-based for and STL algorithms
    iterator begin() { return grid.begin(); }
    iterator end() { return grid.end(); }
    const_iterator begin() const { return grid.cbegin(); }
    const_iterator end() const { return grid.cend(); }
    const_iterator cbegin() const { return grid.cbegin(); }
    const_iterator cend() const { return grid.cend(); }

    /**
     * @brief Invoke callable for each row.
     *
     * @tparam Func Function/function-like object.
     * @param fn    The function to call.
     */
    template <typename Func>
    void each_row(Func &&fn)
    {
        for (auto &row : grid)
            fn(row);
    }

    /**
     * @brief Const: Invoke callable for each row.
     *
     * @tparam Func Function/function-like object.
     * @param fn    The function to call.
     */
    template <typename Func>
    void each_row(Func &&fn) const
    {
        for (const auto &row : grid)
            fn(row);
    }

    /**
     * @brief Invoke callable for each cell.
     *
     * @tparam Func Function/function-like object.
     * @param fn    The function to call.
     */
    template <typename Func>
    void each_cell(Func &&fn)
    {
        each_row([&fn](Grid::Row &row)
                 {
            for (Cell* c : row)
            {
                fn(c);
            } });
    }

    /**
     * @brief Const: Invoke callable for each cell.
     *
     * @tparam Func Function/function-like object.
     * @param fn    The function to call.
     */
    template <typename Func>
    void each_cell(Func &&fn) const
    {
        // const overload
        each_row([&fn](const Grid::Row &row)
                 {
                     for (Cell* c : row)
                     {
                         fn(c);
                     } });
    }

    int get_rows() { return rows; }
    int get_cols() { return columns; }
};

#endif // GRID_H