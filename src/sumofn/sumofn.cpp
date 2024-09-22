
/*
Time Complexity: O(n)
Space Complexity: O(n)

sum(n) = 0 + 1 + 2 + 3 + ... + n-1 + n
sum(n) = sum(n-1) + n

sum(n):
    0, n = 0
    sum(n-1) + n, n > 0
*/
int sumOfN_Recursive(int n) {
    if (n == 0) {
        return 0;
    }

    return sumOfN_Recursive(n-1) + n;
}

/**
 * Time Complexity: O(1)
 * 
 */
int sumOfN_Formula(int n) {
    return n * (n + 1) / 2;
}

/**
 * Time Complexity: O(n)
 * 
 */
int sumOfN_Iterative(int n) {
    int sum = 0; // 1
    for (int i = 1; i <= n; i++) { // n+1
        sum += i; // n
    }

    return sum; // 1
    // Total time complexity: 1 + n + 1 + n + 1 = 2n + 3 = O(n)
}
