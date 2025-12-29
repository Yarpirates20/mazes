#include "Grid.h"
#include <gtest/gtest.h>

using namespace ::testing;

class GridCoordinates : public Test
{
public:
    Grid g{5, 5};
};

TEST_F(GridCoordinates, AccessGridByRowAndColumn)
{
    EXPECT_FALSE(g.atrc(0, 0).is_linked(&g.atrc(0, 1)));
    EXPECT_FALSE(g.atrc(0, 1).is_linked(&g.atrc(0, 0)));

    g.atrc(0, 0).link(&g.atrc(0, 1));

    EXPECT_TRUE(g.atrc(0, 0).is_linked(&g.atrc(0, 1)));
    EXPECT_TRUE(g.atrc(0, 1).is_linked(&g.atrc(0, 0)));
}

TEST_F(GridCoordinates, AccessOutOfRangeCell)
{
    EXPECT_THROW(g.atrc(6, 6), std::out_of_range);
}