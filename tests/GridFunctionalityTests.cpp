#include <gtest/gtest.h>
#include "../src/Cell.h"
#include "../src/Grid.h"
#include <iostream>

using namespace ::testing;

class ABasicGridCollection : public Test
{
public:
    Grid grid;
    Grid grid2;
    Grid grid3;

    ABasicGridCollection() : grid(2, 2), grid2(5, 5), grid3(6, 8) {}
};

TEST_F(ABasicGridCollection, CreateASingleGrid)
{
    ASSERT_EQ(grid.size(), 4);
    ASSERT_EQ(grid2.size(), 25);
    ASSERT_EQ(grid3.size(), 48);
}

TEST_F(ABasicGridCollection, RetrievesACell)
{
    // ASSERT_FALSE(grid.atrc(3, 4));
    ASSERT_EQ(grid.atrc(0, 1)->get_row(), 0);
    ASSERT_EQ(grid2.atrc(3, 4)->get_column(), 4);
}

TEST_F(ABasicGridCollection, IteratesCellsInRow)
{
    grid.each_cell([](Cell *c)
                   {
        ASSERT_NE(c, nullptr);
        std::cout << "Found cell!\n"; });
}

TEST_F(ABasicGridCollection, IteratesRows)
{
    grid.each_cell([](Cell *c)
                   {
        ASSERT_NE(c, nullptr);
        std::cout << "Found cell!\n"; });
}