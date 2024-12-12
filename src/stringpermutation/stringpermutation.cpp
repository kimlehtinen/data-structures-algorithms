#include <stdio.h>
#include <iostream>

void StringPermutation(char *str, int k) {
    static int A[10] = {0};
    static char res[10];
    int i;
    if (str[k] == '\0') {
        res[k] = '\0';
        printf("%s\n", res);
    } else {
        for (i = 0; str[i] != '\0'; i++) {
            if (A[i] == 0) {
                res[k] = str[i];
                A[i] = 1;
                StringPermutation(str, k + 1);
                A[i] = 0;
            }
        }
    }
}

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void StringPermutationSwap(char *str, int l, int h) {
    int i;
    if (l == h) {
        printf("%s\n", str);
    } else {
        for (i = l; i <= h; i++) {
            swap(&str[l], &str[i]);
            StringPermutationSwap(str, l + 1, h);
            swap(&str[l], &str[i]);
        }
    }
}

int main_test() {
    char str[] = "ABC";
    std::cout << "String Permutations:" << std::endl;
    StringPermutation(str, 0);
    std::cout << "String Permutations with Swap:" << std::endl;
    StringPermutationSwap(str, 0, 2);
    return 0;
}

