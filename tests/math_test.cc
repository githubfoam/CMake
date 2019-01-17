#include <gtest/gtest.h>
#include "../src/math.h"

TEST(MathAddTest, PositiveNum) {
    EXPECT_EQ(2, math::add(1, 1));
    EXPECT_EQ(10, math::add(2, 8));
    EXPECT_EQ(100, math::add(50, 50));
}

TEST(MathAddTest, ZeroB) {
    EXPECT_EQ(1, math::add(1, 0));
    EXPECT_EQ(10, math::add(10, 0));
    EXPECT_EQ(100, math::add(100, 0));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
