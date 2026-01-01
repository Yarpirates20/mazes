#include "Distances.h"
#include "Grid.h"

#include <gtest/gtest.h>

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

