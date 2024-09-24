#include "nestedrecursion.h"

int nestedRecursion(int n) {
    if (n > 100) {
        return n - 10;
    }

    return nestedRecursion(nestedRecursion(n + 11));
}
