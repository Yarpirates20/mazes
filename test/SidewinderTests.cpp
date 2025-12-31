#include "Sidewinder.h"
#include <gtest/gtest.h>

using namespace ::testing;

class SidewinderFunctions : public Test
{
    public:
        Grid g{5, 5};
        Sidewinder side_wind;
};

TEST_F(SidewinderFunctions, SidewinderCreatesMaze)
{
    side_wind.on(g);
}