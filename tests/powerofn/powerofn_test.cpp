#include <gtest/gtest.h>
#include "powerofn/powerofn.h"

TEST(PowerOfN_RecursiveTest, HandlesSmallCases) {
    EXPECT_EQ(powerOfN_Recursive(2, 0), 1);
    EXPECT_EQ(powerOfN_Recursive(2, 1), 2);
    EXPECT_EQ(powerOfN_Recursive(2, 2), 4);
}

TEST(PowerOfN_RecursiveTest, HandlesTypicalCases) {
    EXPECT_EQ(powerOfN_Recursive(2, 5), 32);
    EXPECT_EQ(powerOfN_Recursive(2, 8), 256);
    EXPECT_EQ(powerOfN_Recursive(2, 9), 512);
    EXPECT_EQ(powerOfN_Recursive(2, 10), 1024);
}

TEST(PowerOfN_RecursiveTest, HandlesLargeCases) {
    EXPECT_EQ(powerOfN_Recursive(2, 20), 1048576);
}

TEST(PowerOfN_OptimizedTest, HandlesSmallCases) {
    EXPECT_EQ(powerOfN_Optimized(2, 0), 1);
    EXPECT_EQ(powerOfN_Optimized(2, 1), 2);
    EXPECT_EQ(powerOfN_Optimized(2, 2), 4);
}

TEST(PowerOfN_OptimizedTest, HandlesTypicalCases) {
    EXPECT_EQ(powerOfN_Optimized(2, 5), 32);
    EXPECT_EQ(powerOfN_Recursive(2, 8), 256);
    EXPECT_EQ(powerOfN_Recursive(2, 9), 512);
    EXPECT_EQ(powerOfN_Optimized(2, 10), 1024);
}

TEST(PowerOfN_OptimizedTest, HandlesLargeCases) {
    EXPECT_EQ(powerOfN_Optimized(2, 20), 1048576);
}
