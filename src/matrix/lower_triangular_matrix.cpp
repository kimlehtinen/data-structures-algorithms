#include "matrix.h"
#include <cstdio>
#include <cstring>

LowerTriangularMatrix::LowerTriangularMatrix(int n) : Matrix(n) {
    A = new int[n * (n + 1) / 2];
}

LowerTriangularMatrix::~LowerTriangularMatrix() {
    delete[] A;
}

void LowerTriangularMatrix::Set(int i, int j, int x) {
    if (i >= j) {
        A[i * (i - 1) / 2 + j - 1] = x;
    }
}

int LowerTriangularMatrix::Get(int i, int j) {
    if (i >= j) {
        return A[i * (i - 1) / 2 + j - 1];
    }
    return 0;
}

void LowerTriangularMatrix::Display() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j) {
                printf("%d ", Get(i, j));
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
