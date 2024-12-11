#include <gtest/gtest.h>
#include "anagram/anagram.h"

TEST(Anagram, IsAnagram) {
    const char* str1 = "listen";
    const char* str2 = "silent";

    bool result = IsAnagram(str1, str2);

    EXPECT_TRUE(result);
}

TEST(Anagram, IsAnagramEmpty) {
    const char* str1 = "";
    const char* str2 = "";

    bool result = IsAnagram(str1, str2);

    EXPECT_TRUE(result);
}

TEST(Anagram, IsAnagramDifferentLength) {
    const char* str1 = "listen";
    const char* str2 = "silentt";

    bool result = IsAnagram(str1, str2);

    EXPECT_FALSE(result);
}

TEST(Anagram, IsAnagramNotAnagram) {
    const char* str1 = "hello";
    const char* str2 = "world";

    bool result = IsAnagram(str1, str2);

    EXPECT_FALSE(result);
}

TEST(Anagram, IsAnagramNullptr) {
    const char* str1 = nullptr;
    const char* str2 = "world";

    bool result = IsAnagram(str1, str2);

    EXPECT_FALSE(result);
}
