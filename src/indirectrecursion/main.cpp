#include <stdio.h>

void second(int n);

void first(int n) {
    if (n > 0) {
        printf("%d\n",n);
        second(n-1);
    }
}

void second(int n) {
    if (n > 1) {
        printf("%d\n",n);
        first(n/2);
    }
}

int main() {
    first(20);

    return 0;
}