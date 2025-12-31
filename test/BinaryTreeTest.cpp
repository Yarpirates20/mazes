#include "BinaryTree.h"
#include <gtest/gtest.h>

using namespace ::testing;

class BinaryTreeFunctions : public Test
{
public:
    Grid g{5, 5};
    BinaryTree bin_tree;
};

TEST_F(BinaryTreeFunctions, BinaryTreeCreatesMaze)
{
    bin_tree.on(g);
    EXPECT_TRUE(g.atrc(0,0).links_count() > 0);
    
}

TEST_F(BinaryTreeFunctions, AllCellsExceptBottomRightHaveLinks)
{
    const int R = 5, C = 5;
    bin_tree.on(g);
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (r == R - 1 && c == C - 1) continue; // bottom-right may have no north/east
            EXPECT_GT(g.atrc(r, c).links_count(), 0u) << "Empty links at (" << r << "," << c << ")";
        }
    }
}

TEST_F(BinaryTreeFunctions, LinksAreBidirectional)
{
    const int R = 5, C = 5;
    bin_tree.on(g);
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            Cell &cell = g.atrc(r, c);
            for (Cell *neigh : cell.get_links()) {
                ASSERT_NE(neigh, nullptr);
                EXPECT_TRUE(neigh->is_linked(&cell)) << "Link not reciprocal between (" << r << "," << c << ") and ("
                                                     << neigh->get_row() << "," << neigh->get_col() << ")";
            }
        }
    }
}

TEST_F(BinaryTreeFunctions, NoSelfLinks)
{
    const int R = 5, C = 5;
    bin_tree.on(g);
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            Cell &cell = g.atrc(r, c);
            EXPECT_FALSE(cell.is_linked(&cell)) << "Cell linked to itself at (" << r << "," << c << ")";
        }
    }
}