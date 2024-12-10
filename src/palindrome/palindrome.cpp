
bool IsPalindrome(char *str) {
    if (str == nullptr) {
        return false;
    }

    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    for (int i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return false;
        }
    }

    return true;
}
