#include <vector>
#include "fibonacci.h"

/**
 * Time complexity: O(2^n)
 */
int fibonacci_Recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_Recursive(n-1) + fibonacci_Recursive(n-2);
}

/**
 * Time complexity: O(n)
 */
int fibonacci_Iterative(int n) {
    int a = 0, b = 1, sum; // 1
    if (n <= 1) { // 1
        return n;
    }
    for (int i = 2; i <= n; i++) { // n
        sum = a + b; // n-1
        a = b; // n-1
        b = sum; // n-1
    }
    return b; // 1
    // Total time complexity: 4n = O(n) 
}

int fibonacci_Memoized(int n, std::vector<int>& memo) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    
    if (memo[n-2] == -1) {
        memo[n-2] = fibonacci_Memoized(n-2, memo);
    }
    if (memo[n-1] == -1) {
        memo[n-1] = fibonacci_Memoized(n-1, memo);
    }

    memo[n] = memo[n-2] + memo[n-1];

    return memo[n];
}

/**
 * Time complexity: O(n)
 */
int fibonacci_Optimized(int n) {
    std::vector<int> memo(n + 1, -1);
    return fibonacci_Memoized(n, memo);
}
