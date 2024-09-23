#include "factorial.h"

int factorial_Recursive(int n) {
    if (n == 0) {
        return 1;
    }

    return factorial_Recursive(n-1) * n;
}

int factorial_Iterative(int n) {
    int result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}
