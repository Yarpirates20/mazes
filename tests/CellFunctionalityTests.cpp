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

