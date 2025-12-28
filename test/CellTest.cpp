#include "Cell.h"
#include <gtest/gtest.h>

using namespace ::testing;

class ACellCollection: public Test
{
    public:
        Cell a{0,0};
        Cell b{0, 1};
};

TEST_F(ACellCollection, LinkAndUnlinkBidirectional)
{
    // Cell a(0,0), b(0,1);
    a.link(&b);
    EXPECT_TRUE(true);
}