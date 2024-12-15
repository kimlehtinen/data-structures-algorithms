#include "matrix.h"
#include <cstdio>
#include <cstring>


DiagonalMatrix::DiagonalMatrix(int n) : Matrix(n) {
    A = new int[n];
}

DiagonalMatrix::~DiagonalMatrix() {
    delete[] A;
}

void DiagonalMatrix::Set(int i, int j, int x) {
    if (i == j) {
        A[i - 1] = x;
    }
}

int DiagonalMatrix::Get(int i, int j) {
    if (i == j) {
        return A[i - 1];
    }
    return 0;
}

void DiagonalMatrix::Display() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                printf("%d ", A[i]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}