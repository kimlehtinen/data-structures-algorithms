#include <gtest/gtest.h>
#include "palindrome/palindrome.h"

TEST(PalindromeTest, HandlesEmptyString) {
    EXPECT_TRUE(IsPalindrome(""));
}

TEST(PalindromeTest, HandlesSingleCharacter) {
    EXPECT_TRUE(IsPalindrome("a"));
}

TEST(PalindromeTest, HandlesPalindromeEqualLength) {
    EXPECT_TRUE(IsPalindrome("abccba"));
}

TEST(PalindromeTest, HandlesPalindromeOddLength) {
    EXPECT_TRUE(IsPalindrome("abcba"));
}
