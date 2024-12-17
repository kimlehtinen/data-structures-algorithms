#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

struct PolynomialTerm {
    int coeff;
    int exp;
};

class Polynomial {
private:
    int n_;
    PolynomialTerm *terms_;
public:
    Polynomial(int n, PolynomialTerm *terms);
    ~Polynomial();
    void Display();
    Polynomial Add(Polynomial &poly);
};

#endif // POLYNOMIAL_H
