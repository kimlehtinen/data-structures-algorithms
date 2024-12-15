#include "matrix.h"
#include <iostream>

SparseMatrix::SparseMatrix(int m, int n, int num) : m_(m), n_(n), num_(num) {
    elements_ = new SparseElement[num_];
}

SparseMatrix::~SparseMatrix() {
    delete[] elements_;
}

SparseMatrix SparseMatrix::operator+(const SparseMatrix &s) const {
    if (m_ != s.m_ || n_ != s.n_) {
        return SparseMatrix(0, 0, 0);
    }
    SparseMatrix *sum = new SparseMatrix(m_, n_, num_ + s.num_);
    int i = 0, j = 0, k = 0;
    while (i < num_ && j < s.num_) {
        // Compare row numbers
        if (elements_[i].i < s.elements_[j].i) {
            sum->elements_[k++] = elements_[i++];
        } else if (elements_[i].i > s.elements_[j].i) {
            sum->elements_[k++] = s.elements_[j++];
        } else {
            // Compare column numbers
            if (elements_[i].j < s.elements_[j].j) {
                sum->elements_[k++] = elements_[i++];
            } else if (elements_[i].j > s.elements_[j].j) {
                sum->elements_[k++] = s.elements_[j++];
            } else { // Add elements, if row and column numbers are equal
                sum->elements_[k] = elements_[i];
                sum->elements_[k++].x = elements_[i++].x + s.elements_[j++].x;
            }
        }
    }
    // Copy remaining elements from the first matrix
    for (; i < num_; i++) {
        sum->elements_[k++] = elements_[i];
    }
    // Copy remaining elements from the second matrix
    for (; j < s.num_; j++) {
        sum->elements_[k++] = s.elements_[j];
    }
    sum->num_ = k;

    // Debug output
    std::cout << "Sum matrix elements:\n";
    for (int idx = 0; idx < sum->num_; idx++) {
        std::cout << "(" << sum->elements_[idx].i << ", " << sum->elements_[idx].j << ", " << sum->elements_[idx].x << ")\n";
    }

    return *sum;
}

std::istream &operator>>(std::istream &is, SparseMatrix &s) {
    for (int i = 0; i < s.num_; i++) {
        is >> s.elements_[i].i >> s.elements_[i].j >> s.elements_[i].x;
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const SparseMatrix &s) {
    for (int i = 0; i < s.m_; i++) {
        for (int j = 0; j < s.n_; j++) {
            bool found = false;
            for (int k = 0; k < s.num_; k++) {
                if (s.elements_[k].i == i && s.elements_[k].j == j) {
                    os << s.elements_[k].x << " ";
                    found = true;
                    break;
                }
            }
            if (!found) {
                os << "0 ";
            }
        }
        os << "\n";
    }
    return os;
}