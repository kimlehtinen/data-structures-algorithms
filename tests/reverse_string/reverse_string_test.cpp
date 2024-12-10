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

TEST(ReverseStringCharArrayTest, HandlesEmptyString) {
    char str[] = "";

    reverseStringCharArray(str);

    EXPECT_STREQ(str, "");
}

TEST(ReverseStringCharArrayTest, HandlesSingleCharacter) {
    char str[] = "a";

    reverseStringCharArray(str);

    EXPECT_STREQ(str, "a");
}

TEST(ReverseStringCharArrayTest, HandlesMultipleCharacters) {
    char str[] = "hello";

    reverseStringCharArray(str);

    EXPECT_STREQ(str, "olleh");
}
