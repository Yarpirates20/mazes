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