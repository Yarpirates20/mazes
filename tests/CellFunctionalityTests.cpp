#include <gtest/gtest.h>
#include "../src/Cell.h"

using namespace ::testing;

class ACellLinkCollection: public Test {
    public:
        Cell cell;
        Cell neighbor_cell;
        Cell non_neighbor_cell;

        ACellLinkCollection()
            : cell(0, 0), neighbor_cell(0, 1), non_neighbor_cell(5, 5) {}
};

TEST_F(ACellLinkCollection, CreatesASingleLink)
{
    ASSERT_TRUE(cell.linked_cells().empty());
    
    cell.link(&neighbor_cell);

    ASSERT_TRUE(cell.is_linked(&neighbor_cell));
    ASSERT_EQ(cell.linked_cells().size(), 1);
}

TEST_F(ACellLinkCollection, CreatesBidirectionalLink)
{
    cell.link(&neighbor_cell);
    ASSERT_TRUE(neighbor_cell.is_linked(&cell));
}

TEST_F(ACellLinkCollection, CreatesUnidirectionalLink)
{
    cell.link(&neighbor_cell, false);
    ASSERT_TRUE(cell.is_linked(&neighbor_cell));
    ASSERT_FALSE(neighbor_cell.is_linked(&cell));
}

TEST_F(ACellLinkCollection, LinkReturnsSelf)
{
    ASSERT_EQ(&cell, cell.link(&neighbor_cell));
}

TEST_F(ACellLinkCollection, DuplicateLinkDoesNotIncreaseSize)
{
    cell.link(&neighbor_cell);
    cell.link(&neighbor_cell);
    ASSERT_EQ(cell.linked_cells().size(), 1);
}

TEST_F(ACellLinkCollection, UnlinkRemovesBidirectionalLink)
{
    cell.link(&neighbor_cell);
    cell.unlink(&neighbor_cell);
    ASSERT_FALSE(cell.is_linked(&neighbor_cell));
    ASSERT_FALSE(neighbor_cell.is_linked(&cell));
}

TEST_F(ACellLinkCollection, UnlinkNonBidiLeavesReverse)
{
    cell.link(&neighbor_cell);
    cell.unlink(&neighbor_cell, false);
    ASSERT_FALSE(cell.is_linked(&neighbor_cell));
    ASSERT_TRUE(neighbor_cell.is_linked(&cell));
}

TEST_F(ACellLinkCollection, LinkedCellsContainsNeighbor)
{
    cell.link(&neighbor_cell);
    auto v = cell.linked_cells();
    ASSERT_NE(std::find(v.begin(), v.end(), &neighbor_cell), v.end());
}

TEST_F(ACellLinkCollection, IsLinkedWithNullReturnsFalse)
{
    ASSERT_FALSE(cell.is_linked(nullptr));
}