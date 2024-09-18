#include <stdio.h>

void tailRecursion(int n) {
    if (n > 0) {
        printf("%d\n", n);
        // no processing after the recursive call
        tailRecursion(n-1);
    }
}

int main() {
    int x = 5;
    tailRecursion(x);

    return 0;
}
