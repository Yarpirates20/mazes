#include <gtest/gtest.h>
#include "../src/BinaryTree.h"
#include "../src/Grid.h"
#include "../src/Cell.h"

using namespace ::testing;

class ABasicBinaryTreeCollection : public Test
{
protected:
    Grid g;
    BinaryTree maze;
    
    ABasicBinaryTreeCollection() : g(5, 5), maze() {}
    
};

TEST_F(ABasicBinaryTreeCollection, ChecksBinaryTree)
{
    maze.on(g);

    // Check that every cell is linked to at most two neighbors (north or east)
    for (int row = 0; row < g.get_rows(); ++row) {
        for (int col = 0; col < g.get_cols(); ++col) {
            Cell* cell = g.atrc(row, col);
            ASSERT_NE(cell, nullptr);

            // In BinaryTree, each cell is linked to at most one of north/east
            int links = 0;
            if (cell->is_linked(cell->north)) ++links;
            if (cell->is_linked(cell->east)) ++links;

            // Should not be linked to both north and east at the same time
            ASSERT_LE(links, 1);
        }
    }
}