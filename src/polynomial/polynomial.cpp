#include "polynomial.h"
#include <iostream>

Polynomial::Polynomial(int n, PolynomialTerm *terms) {
    n_ = n;
    terms_ = new PolynomialTerm[n_];
    for (int i = 0; i < n_; i++) {
        terms_[i] = terms[i];
    }
}

Polynomial::~Polynomial() {
    delete[] terms_;
}

void Polynomial::Display() {
    for (int i = 0; i < n_; i++) {
        if (terms_[i].exp == 0) {
            std::cout << terms_[i].coeff;
            continue;
        }
        std::cout << terms_[i].coeff << "x^" << terms_[i].exp;
        if (i < n_ - 1) {
            std::cout << " + ";
        }
    }
    std::cout << std::endl;
}

Polynomial Polynomial::Add(Polynomial &poly) {
    int i = 0, j = 0, k = 0;
    PolynomialTerm *terms = new PolynomialTerm[n_ + poly.n_];
    while (i < n_ && j < poly.n_) {
        if (terms_[i].exp > poly.terms_[j].exp) {
            terms[k++] = terms_[i++];
        } else if (terms_[i].exp < poly.terms_[j].exp) {
            terms[k++] = poly.terms_[j++];
        } else {
            terms[k].exp = terms_[i].exp;
            terms[k++].coeff = terms_[i++].coeff + poly.terms_[j++].coeff;
        }
    }
    for (; i < n_; i++) {
        terms[k++] = terms_[i];
    }
    for (; j < poly.n_; j++) {
        terms[k++] = poly.terms_[j];
    }
    Polynomial result(k, terms);
    delete[] terms;
    return result;
}
