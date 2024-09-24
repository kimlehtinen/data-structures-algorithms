#include <stdio.h>

/**
 * Tree Recursion
 * 
 * Time Complexity: O(2^n)
 * Space Complexity: O(n)
 */

void treeRecursion(int n) {
    if (n > 0) {
        printf("%d\n",n);
        treeRecursion(n-1);
        treeRecursion(n-1);
    }
}

/*
int main() {
    treeRecursion(3);

    return 0;
}*/