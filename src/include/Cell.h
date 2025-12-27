#ifndef CELL_H
#define CELL_H

#include <vector>
#include <unordered_set>
#include <functional>

/**
 * @brief Cell Class Declaration
 *
 * Each cell tracks which other cells they are next and and which cells are
 * linked via passageways.
 *
 */
class Cell
{
private:
    int row,
        column;

    Cell *north,
        *east,
        *south,
        *west;

    std::unordered_set<Cell *> links;

public:
    /**
     * @brief Cell constructor starts with no neighbors or links
     *
     * @param r Row where cell is located.
     * @param c Column where cell is located.
     */
    Cell(int r, int c) : row(r), column(c), north(nullptr), east(nullptr), south(nullptr), west(nullptr) {}

    /**
     * @brief Adds cell to current cell's links collection.
     *
     * @param other Cell to link.
     * @param bidirectional Boolean flag to prevent infinite recursion.
     * @return Cell& Reference to object operated on.
     */
    Cell &link(Cell *other, bool bidirectional = true);

    /**
     * @brief Removes cell from current cell's links collection.
     *
     * @param other Cell to unlink.
     * @param directional Boolean flag to prevent infinite recursion.
     * @return Cell& Reference to object operated on.
     */
    Cell &unlink(Cell *other, bool bidirectional = true);
};

#endif // CELL_H