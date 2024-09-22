#include <stdio.h>

void headRecursion(int n) {
    if (n > 0) {
        // no processing before the recursive call
        headRecursion(n-1);
        printf("%d\n", n);
    }
}
/*
int main() {
    int x = 5;
    headRecursion(x);

    return 0;
}*/
