#include <gtest/gtest.h>
#include "reverse_string/reverse_string.h"

TEST(ReverseStringTest, HandlesEmptyString) {
    EXPECT_EQ(reverseString(""), "");
}

TEST(ReverseStringTest, HandlesSingleCharacter) {
    EXPECT_EQ(reverseString("a"), "a");
}

TEST(ReverseStringTest, HandlesMultipleCharacters) {
    EXPECT_EQ(reverseString("hello"), "olleh");
}
