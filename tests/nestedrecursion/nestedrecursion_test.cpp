#include <gtest/gtest.h>
#include "nestedrecursion/nestedrecursion.h"

TEST(NestedRecursionTest, BelowThreshold) {
    EXPECT_EQ(91, nestedRecursion(0));
    EXPECT_EQ(91, nestedRecursion(20));
    EXPECT_EQ(91, nestedRecursion(95));
    EXPECT_EQ(91, nestedRecursion(99));
}

TEST(NestedRecursionTest, AtThreshold) {
    EXPECT_EQ(91, nestedRecursion(100));
}

TEST(NestedRecursionTest, AboveThreshold) {
    EXPECT_EQ(100, nestedRecursion(110));
    EXPECT_EQ(110, nestedRecursion(120));
}
