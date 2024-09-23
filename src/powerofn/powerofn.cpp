#include "powerofn.h"

int powerOfN_Recursive(int n, int p) {
    if (p == 0) {
        return 1;
    }

    return powerOfN_Recursive(n, p-1) * n;
}

int powerOfN_Optimized(int n, int p) {
    if (p == 0) {
        return 1;
    }

    if (p % 2 == 0) {
        return powerOfN_Optimized(n*n, p/2);
    }

    return n * powerOfN_Optimized(n*n, (p-1)/2);
}
