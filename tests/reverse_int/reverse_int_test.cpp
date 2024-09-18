#include <gtest/gtest.h>
#include "reverse_int/reverse_int.h"

TEST(ReverseIntTest, PositiveNumber) {
    EXPECT_EQ(reverseInt(1234), 4321);
    EXPECT_EQ(reverseInt(9876), 6789);
}

TEST(ReverseIntTest, NegativeNumber) {
    EXPECT_EQ(reverseInt(-1234), -4321);
    EXPECT_EQ(reverseInt(-9876), -6789);
}

TEST(ReverseIntTest, SingleDigit) {
    EXPECT_EQ(reverseInt(0), 0);
    EXPECT_EQ(reverseInt(5), 5);
    EXPECT_EQ(reverseInt(-9), -9);
}

TEST(ReverseIntTest, TrailingZeros) {
    EXPECT_EQ(reverseInt(1200), 21);
    EXPECT_EQ(reverseInt(-9000), -9);
}

