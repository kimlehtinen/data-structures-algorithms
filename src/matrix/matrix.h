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

#endif // MATRIX_H