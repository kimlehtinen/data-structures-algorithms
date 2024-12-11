#include <gtest/gtest.h>
#include <bitset>
#include "duplicatesstring/duplicatesstring.h"

TEST(DuplicatesString, GetDuplicatesInString) {
    char str[] = "hello";
    
    long int result = GetDuplicatesInString(str);
    
    // The expected result is 2048, which corresponds to the binary 00000000000000000000100000000000
    // indicating that 'l' is a duplicate.
    EXPECT_EQ(result, 2048);
    std::bitset<32> resultBitset(result);
    std::string resultString = resultBitset.to_string();
    std::string expectedString = "00000000000000000000100000000000";
    EXPECT_EQ(resultString, expectedString);
}

TEST(DuplicatesString, GetDuplicatesInStringEmpty) {
    char str[] = "";
    
    long int result = GetDuplicatesInString(str);
    
    // The expected result is 0, which corresponds to the binary
    // indicating that there are no duplicates.
    EXPECT_EQ(result, 0);
    std::bitset<32> resultBitset(result);
    std::string resultString = resultBitset.to_string();
    std::string expectedString = "00000000000000000000000000000000";
    EXPECT_EQ(resultString, expectedString);
}

TEST(DuplicatesString, GetDuplicatesInStringNoDuplicates) {
    char str[] = "abcdefg";
    
    long int result = GetDuplicatesInString(str);
    
    // The expected result is 0, which corresponds to the binary
    // indicating that there are no duplicates.
    EXPECT_EQ(result, 0);
    std::bitset<32> resultBitset(result);
    std::string resultString = resultBitset.to_string();
    std::string expectedString = "00000000000000000000000000000000";
    EXPECT_EQ(resultString, expectedString);
}

TEST (DuplicatesString, GetDuplicatesInStringAllDuplicates) {
    char str[] = "aaaaaa";
    
    long int result = GetDuplicatesInString(str);
    
    // The expected result is 1, which corresponds to the binary 00000000000000000000000000000001
    // indicating that 'a' is a duplicate.
    EXPECT_EQ(result, 1);
    std::bitset<32> resultBitset(result);
    std::string resultString = resultBitset.to_string();
    std::string expectedString = "00000000000000000000000000000001";
    EXPECT_EQ(resultString, expectedString);
}

TEST (DuplicatesString, GetDuplicatesInStringMixedDuplicates) {
    char str[] = "ababcdcdefe";
    
    long int result = GetDuplicatesInString(str);
    
    // The expected result is 31, which corresponds to the binary 00000000000000000000000000011111
    // indicating that 'a', 'b', 'c', 'd', and 'e' are duplicates.
    EXPECT_EQ(result, 31);
    std::bitset<32> resultBitset(result);
    std::string resultString = resultBitset.to_string();
    std::string expectedString = "00000000000000000000000000011111";
    EXPECT_EQ(resultString, expectedString);
}
