#include <gtest/gtest.h>
#include "ncrrecursion/ncrrecursion.h"

TEST(nCrRecursiveTest, ReturnsCorrectValue) {
    EXPECT_EQ(1, nCr_Recursive(0, 0));
    EXPECT_EQ(1, nCr_Recursive(1, 0));
    EXPECT_EQ(1, nCr_Recursive(1, 1));
    EXPECT_EQ(1, nCr_Recursive(2, 0));
    EXPECT_EQ(2, nCr_Recursive(2, 1));
    EXPECT_EQ(1, nCr_Recursive(2, 2));
    EXPECT_EQ(1, nCr_Recursive(3, 0));
    EXPECT_EQ(3, nCr_Recursive(3, 1));
    EXPECT_EQ(3, nCr_Recursive(3, 2));
    EXPECT_EQ(1, nCr_Recursive(3, 3));
    EXPECT_EQ(1, nCr_Recursive(4, 0));
    EXPECT_EQ(4, nCr_Recursive(4, 1));
    EXPECT_EQ(6, nCr_Recursive(4, 2));
    EXPECT_EQ(4, nCr_Recursive(4, 3));
    EXPECT_EQ(1, nCr_Recursive(4, 4));
    EXPECT_EQ(1, nCr_Recursive(5, 0));
    EXPECT_EQ(5, nCr_Recursive(5, 1));
    EXPECT_EQ(10, nCr_Recursive(5, 2));
    EXPECT_EQ(10, nCr_Recursive(5, 3));
    EXPECT_EQ(5, nCr_Recursive(5, 4));
    EXPECT_EQ(1, nCr_Recursive(5, 5));
    EXPECT_EQ(1, nCr_Recursive(6, 0));
    EXPECT_EQ(6, nCr_Recursive(6, 1));
    EXPECT_EQ(15, nCr_Recursive(6, 2));
    EXPECT_EQ(20, nCr_Recursive(6, 3));
    EXPECT_EQ(15, nCr_Recursive(6, 4));
    EXPECT_EQ(6, nCr_Recursive(6, 5));
    EXPECT_EQ(1, nCr_Recursive(6, 6));
    EXPECT_EQ(1, nCr_Recursive(7, 0));
    EXPECT_EQ(7, nCr_Recursive(7, 1));
}
