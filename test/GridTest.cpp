#include "Grid.h"
#include <gtest/gtest.h>

using namespace ::testing;

class GridCoordinates : public Test
{
public:
    Grid g{5, 5};
};

TEST_F(GridCoordinates, ConfigureGrid)
{
    EXPECT_TRUE(g.atrc(0, 0).north == nullptr);
    auto x = g.atrc(0, 1).get_col();
    auto y = g.atrc(0, 0).east;
    EXPECT_TRUE(x == y->get_col());
}

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

TEST_F(GridCoordinates, RandomCellWithinBounds)
{
    for (int i = 0; i < 100; ++i)
    {
        Cell &cell = g.random_cell();
        int r = cell.get_row();
        int c = cell.get_col();

        EXPECT_GE(r, 0);
        EXPECT_LT(r, 5);
        EXPECT_GE(c, 0);
        EXPECT_LT(c, 5);
        EXPECT_EQ(&g.atrc(r, c), &cell);
    }
}

TEST_F(GridCoordinates, PrepareGridCreatesCells)
{
    for (int r = 0; r < 5; ++r)
    {
        for (int c = 0; c < 5; ++c)
        {
            Cell &cell = g.atrc(r, c);
            EXPECT_EQ(cell.get_row(), r);
            EXPECT_EQ(cell.get_col(), c);
        }
    }
}

TEST_F(GridCoordinates, NeighborsWiring)
{
    Cell &corner = g.atrc(0, 0);
    EXPECT_EQ(corner.north, nullptr);
    EXPECT_EQ(corner.west, nullptr);
    EXPECT_NE(corner.east, nullptr);
    EXPECT_NE(corner.south, nullptr);

    Cell &edge = g.atrc(0, 2);
    EXPECT_EQ(edge.north, nullptr);
    EXPECT_NE(edge.west, nullptr);
    EXPECT_NE(edge.east, nullptr);
    EXPECT_NE(edge.south, nullptr);

    Cell &mid = g.atrc(2, 2);
    EXPECT_NE(mid.north, nullptr);
    EXPECT_NE(mid.west, nullptr);
    EXPECT_NE(mid.east, nullptr);
    EXPECT_NE(mid.south, nullptr);
}

TEST_F(GridCoordinates, ForEachCounts)
{
    int row_count = 0;
    g.for_each_row([&](auto &row) {
        ++row_count;
        EXPECT_EQ(static_cast<int>(row.size()), 5);
    });

    EXPECT_EQ(row_count, 5);

    int cell_count = 0;
    g.for_each_cell([&](Cell &c) {
        ++cell_count;
    });

    EXPECT_EQ(cell_count, 25);
}

TEST_F(GridCoordinates, ConstAccess)
{
    Cell &c = g.atrc(1, 1);
    EXPECT_EQ(c.get_row(), 1);
    EXPECT_EQ(c.get_col(), 1);
}

TEST_F(GridCoordinates, LinkAndUnlinkAdjacency)
{
    Cell &a = g.atrc(3, 3);
    Cell &b = g.atrc(3, 4);

    EXPECT_FALSE(a.is_linked(&b));
    a.link(&b);
    EXPECT_TRUE(a.is_linked(&b));
    EXPECT_TRUE(b.is_linked(&a));

    a.unlink(&b);
    EXPECT_FALSE(a.is_linked(&b));
    EXPECT_FALSE(b.is_linked(&a));
}