#include <gtest/gtest.h>
#include "fizzbuzz/fizzbuzz.h"  // Include your FizzBuzz header if it's in a separate file

// Test cases for FizzBuzz function
TEST(FizzBuzzTest, ReturnsFizzForMultiplesOf3) {
    EXPECT_EQ(fizzBuzz(3), "Fizz");
    EXPECT_EQ(fizzBuzz(6), "Fizz");
    EXPECT_EQ(fizzBuzz(9), "Fizz");
}

TEST(FizzBuzzTest, ReturnsBuzzForMultiplesOf5) {
    EXPECT_EQ(fizzBuzz(5), "Buzz");
    EXPECT_EQ(fizzBuzz(10), "Buzz");
    EXPECT_EQ(fizzBuzz(20), "Buzz");
}

TEST(FizzBuzzTest, ReturnsFizzBuzzForMultiplesOf15) {
    EXPECT_EQ(fizzBuzz(15), "FizzBuzz");
    EXPECT_EQ(fizzBuzz(30), "FizzBuzz");
    EXPECT_EQ(fizzBuzz(45), "FizzBuzz");
}

TEST(FizzBuzzTest, ReturnsNumberForNonMultiplesOf3Or5) {
    EXPECT_EQ(fizzBuzz(1), "1");
    EXPECT_EQ(fizzBuzz(2), "2");
    EXPECT_EQ(fizzBuzz(4), "4");
}

// Additional boundary tests
TEST(FizzBuzzTest, HandlesBoundaryCases) {
    EXPECT_EQ(fizzBuzz(0), "FizzBuzz");  // Depending on if 0 should be considered divisible by both 3 and 5
}
