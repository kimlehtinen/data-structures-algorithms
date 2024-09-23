#include <gtest/gtest.h>
#include "factorial/factorial.h"

TEST(Factorial_RecursiveTest, HandlesSmallCases) {
    EXPECT_EQ(factorial_Recursive(0), 1);
    EXPECT_EQ(factorial_Recursive(1), 1);
}

TEST(Factorial_RecursiveTest, HandlesTypicalCases) {
    EXPECT_EQ(factorial_Recursive(5), 120);
    EXPECT_EQ(factorial_Recursive(10), 3628800);
}

TEST(Factorial_RecursiveTest, HandlesLargeCases) {
    EXPECT_EQ(factorial_Recursive(12), 479001600);
}

TEST(Factorial_IterativeTest, HandlesSmallCases) {
    EXPECT_EQ(factorial_Iterative(0), 1);
    EXPECT_EQ(factorial_Iterative(1), 1);
}

TEST(Factorial_IterativeTest, HandlesTypicalCases) {
    EXPECT_EQ(factorial_Iterative(5), 120);
    EXPECT_EQ(factorial_Iterative(10), 3628800);
}

TEST(Factorial_IterativeTest, HandlesLargeCases) {
    EXPECT_EQ(factorial_Iterative(12), 479001600);
}
