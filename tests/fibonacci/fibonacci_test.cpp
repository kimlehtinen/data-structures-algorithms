#include <gtest/gtest.h>
#include "fibonacci/fibonacci.h"

TEST(Fibonacci_RecursiveTest, Fibonacci_Recursive) {
    EXPECT_EQ(0, fibonacci_Recursive(0));
    EXPECT_EQ(1, fibonacci_Recursive(1));
    EXPECT_EQ(1, fibonacci_Recursive(2));
    EXPECT_EQ(2, fibonacci_Recursive(3));
    EXPECT_EQ(3, fibonacci_Recursive(4));
    EXPECT_EQ(5, fibonacci_Recursive(5));
    EXPECT_EQ(8, fibonacci_Recursive(6));
    EXPECT_EQ(13, fibonacci_Recursive(7));
    EXPECT_EQ(21, fibonacci_Recursive(8));
    EXPECT_EQ(34, fibonacci_Recursive(9));
    EXPECT_EQ(55, fibonacci_Recursive(10));
}

TEST(Fibonacci_IterativeTest, Fibonacci_Iterative) {
    EXPECT_EQ(0, fibonacci_Iterative(0));
    EXPECT_EQ(1, fibonacci_Iterative(1));
    EXPECT_EQ(1, fibonacci_Iterative(2));
    EXPECT_EQ(2, fibonacci_Iterative(3));
    EXPECT_EQ(3, fibonacci_Iterative(4));
    EXPECT_EQ(5, fibonacci_Iterative(5));
    EXPECT_EQ(8, fibonacci_Iterative(6));
    EXPECT_EQ(13, fibonacci_Iterative(7));
    EXPECT_EQ(21, fibonacci_Iterative(8));
    EXPECT_EQ(34, fibonacci_Iterative(9));
    EXPECT_EQ(55, fibonacci_Iterative(10));
}

TEST(Fibonacci_OptimizedTest, Fibonacci_Optimized) {
    EXPECT_EQ(0, fibonacci_Optimized(0));
    EXPECT_EQ(1, fibonacci_Optimized(1));
    EXPECT_EQ(1, fibonacci_Optimized(2));
    EXPECT_EQ(2, fibonacci_Optimized(3));
    EXPECT_EQ(3, fibonacci_Optimized(4));
    EXPECT_EQ(5, fibonacci_Optimized(5));
    EXPECT_EQ(8, fibonacci_Optimized(6));
    EXPECT_EQ(13, fibonacci_Optimized(7));
    EXPECT_EQ(21, fibonacci_Optimized(8));
    EXPECT_EQ(34, fibonacci_Optimized(9));
    EXPECT_EQ(55, fibonacci_Optimized(10));
}
