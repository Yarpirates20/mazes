#ifndef CELL_H
#define CELL_H

#include <unordered_set>
#include <vector>
/**
 * @brief A cell in the maze grid.
 *
 * Stores grid coordinates, pointers to neighbors, and links to other cells.
 *
 */
class Cell
{
private:
    int row;
    int column;

    std::unordered_set<Cell *> links;

public:
    
    Cell *north;
    Cell *east;
    Cell *south;
    Cell *west;

    /**
     * @brief Default constructor.
     *
     */
    Cell() : row(0), column(0), north(nullptr), east(nullptr), south(nullptr), west(nullptr), links{} {};

    /**
     * @brief Construct a Cell object with coordinates.
     *
     * @param r Row coordinates.
     * @param c Column coordinates.
     */
    Cell(int r, int c) : row(r), column(c), north(nullptr), east(nullptr), south(nullptr), west(nullptr), links{} {}

    /**
     * @brief Link this cell to another.
     *
     * @param cell Pointer to the other cell to link to.
     * @param bidi If true, create a bidirectional link (default: true).
     * @return Cell* Pointer to this cell (allows chaining).
     */
    Cell *link(Cell *cell, bool bidi = true);

    /**
     * @brief Remove a link to another cell.
     *
     * @param cell Pointer to the cell to unlink.
     * @param bidi If true, remove the reverse link too (default: true).
     */
    void unlink(Cell *cell, bool bidi = true);

    /**
     * @brief Check whether this cell is linked to another.
     *
     * @param cell Pointer to the cell to check.
     * @return true True if linked.
     * @return false False if not linked.
     */
    bool is_linked(Cell *cell) const;

    /**
     * @brief Gets all the cells linked to this cell.
     *
     * @return std::vector<Cell*> A vector copy of pointers to linked Cells.
     */
    std::vector<Cell *> linked_cells() const;

    /**
     * @brief Gets a list of a cell's neighbors.
     *
     * @return std::vector<Cell*> Vector of pointers to neighbor cells, listed
     * in order: North, East, South, West.
     *
     * Note: use iteration or presence checks and do not rely on hardcoded
     * indices as nullptr neighbors are not pushed to vector.
     */
    std::vector<Cell *> neighbors() const;
};
#endif