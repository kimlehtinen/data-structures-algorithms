#include <gtest/gtest.h>
#include "recursion/nestedrecursion/nestedrecursion.h"

TEST(NestedRecursionTest, BaseCase) {
    EXPECT_EQ(91, nestedRecursion(95));
}

TEST(NestedRecursionTest, AboveThreshold) {
    EXPECT_EQ(100, nestedRecursion(110));
}
