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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
