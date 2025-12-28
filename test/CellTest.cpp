#include "Cell.h"
#include <gtest/gtest.h>

using namespace ::testing;

class CellLinks : public Test
{
public:
    Cell a{0, 0};
    Cell b{0, 1};
};

TEST_F(CellLinks, BirectionalLinkLink)
{
    EXPECT_FALSE(a.is_linked(&b));
    EXPECT_FALSE(b.is_linked(&a));
    EXPECT_EQ(a.links_count(), 0u);
    EXPECT_EQ(b.links_count(), 0u);

    a.link(&b);

    EXPECT_TRUE(a.is_linked(&b));
    EXPECT_TRUE(b.is_linked(&a));
    EXPECT_EQ(a.links_count(), 1u);
    EXPECT_EQ(b.links_count(), 1u);
}

TEST_F(CellLinks, Unlink)
{
    a.link(&b);
    a.unlink(&b);

    EXPECT_FALSE(a.is_linked(&b));
    EXPECT_FALSE(b.is_linked(&a));

    EXPECT_EQ(a.links_count(), 0u);
    EXPECT_EQ(b.links_count(), 0u);
}

TEST_F(CellLinks, GetLinks)
{
    a.link(&b);

    EXPECT_EQ(a.get_links().size(), 1);
    EXPECT_EQ(*(a.get_links().begin()), const_cast<Cell *>(&b));

    EXPECT_EQ(b.get_links().size(), 1);
    EXPECT_EQ(*(b.get_links().begin()), const_cast<Cell *>(&a));

}

TEST_F(CellLinks, GetNeighbor)
{
    auto n = a.neighbors();

    EXPECT_EQ(n.size(), 1);

    

}