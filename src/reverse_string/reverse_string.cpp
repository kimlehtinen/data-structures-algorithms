#include "reverse_string.h"

std::string reverseString(const std::string& str) {
    return std::string(str.rbegin(), str.rend());
}

void reverseStringCharArray(char* str) {
    if (str == nullptr) {
        return;
    }

    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
