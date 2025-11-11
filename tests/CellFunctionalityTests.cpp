#include <gtest/gtest.h>
#include "../src/Cell.h"

TEST(CellLinks, CreatesASingleLink)
{
    Cell cell(0, 0);
    ASSERT_TRUE(cell.linked_cells().empty());
    Cell cell_2(0, 1);
    
    cell.link(&cell_2);

    ASSERT_TRUE(cell.is_linked(&cell_2));
    ASSERT_EQ(cell.linked_cells().size(), 1);

}
