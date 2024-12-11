#include <cstring>
#include "anagram.h"

/**
 * Check if two strings are anagrams of each other.
 * Note: This implementation assumes that the strings are in lowercase.
 */

bool IsAnagram(const char* str1, const char* str2) {
    if (str1 == nullptr || str2 == nullptr) {
        return false;
    }

    int length1 = std::strlen(str1);
    int length2 = std::strlen(str2);

    if (length1 != length2) {
        return false;
    }
    
    int i, hashTable[26] = {0};

    for (i = 0; str1[i] != '\0'; i++) {
        hashTable[str1[i] - 97]++;
    }
    for (i = 0; str2[i] != '\0'; i++) {
        hashTable[str2[i] - 97]--;
        if (hashTable[str2[i] - 97] < 0) {
            return false;
        }
    }

    return true;
}
