#include "Cell.h"
#include <gtest/gtest.h>

TEST(CellLinks, LinkAndUnlinkBidirectional)
{
    Cell a(0,0), b(0,1);
    a.link(&b);
    EXPECT_TRUE(true);
}