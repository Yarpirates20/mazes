#include "Distances.h"
#include "Grid.h"

#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

class DistanceFunctions : public Test
{
    public:
        Grid g{5, 5};
        Cell *root = &g.atrc(0,0);
        Distances dst{root};
};

TEST_F(DistanceFunctions, InitializesRoot)
{
    ASSERT_EQ(dst[root], 0);
}

TEST_F(DistanceFunctions, SetAndGetDistance)
{
    Cell *next_cell = &g.atrc(0, 1);
    ASSERT_TRUE(dst.get(next_cell) == std::nullopt);

    Cell *test_cell = &g.atrc(4, 4);
    EXPECT_EQ(dst[test_cell], 0);

    EXPECT_EQ(dst[next_cell] = 1, 1);

}

TEST_F(DistanceFunctions, GetCellsContainsAllTracked)
{
    Cell a(1,0), b(2,2);
    dst[&a] = 7;
    dst[&b] = 9;

    auto cells = dst.get_cells();
    EXPECT_EQ(cells.size(), 3u);
    EXPECT_NE(std::find(cells.begin(), cells.end(), root), cells.end());
    EXPECT_NE(std::find(cells.begin(), cells.end(), &a), cells.end());
    EXPECT_NE(std::find(cells.begin(), cells.end(), &b), cells.end());


}

