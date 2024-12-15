#include "matrix.h"
#include <cstdio>
#include <cstring>

Matrix::Matrix(int dimension) : n(dimension) {}

Matrix::~Matrix() {}

int Matrix::GetDimension() {
    return n;
}
