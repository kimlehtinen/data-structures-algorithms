#include <istream>

#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
protected:
    int n;
public:
    Matrix(int dimension);
    virtual ~Matrix();
    virtual void Display() = 0;
    virtual void Set(int i, int j, int x) = 0;
    virtual int Get(int i, int j) = 0;
    virtual int GetDimension();
};

class DiagonalMatrix : public Matrix {
private:
    int* A;
public:
    DiagonalMatrix(int n);
    ~DiagonalMatrix();
    void Set(int i, int j, int x) override;
    int Get(int i, int j) override;
    void Display() override;
};

class LowerTriangularMatrix : public Matrix {
private:
    int* A;
public:
    LowerTriangularMatrix(int n);
    ~LowerTriangularMatrix();
    void Set(int i, int j, int x) override;
    int Get(int i, int j) override;
    void Display() override;
};

struct SparseElement {
    int i;
    int j;
    int x;
};

class SparseMatrix {
private:
    int m_, n_, num_;
    SparseElement* elements_;
public:
    SparseMatrix(int m, int n, int num);
    ~SparseMatrix();
    SparseMatrix operator+(const SparseMatrix &s) const;
    friend std::istream &operator>>(std::istream &is, SparseMatrix &s);
    friend std::ostream &operator<<(std::ostream &os, const SparseMatrix &s);
};

#endif // MATRIX_H