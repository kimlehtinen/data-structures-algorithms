#include <gtest/gtest.h>
#include "polynomial/polynomial.h"

TEST (PolynomialTest, CanDisplayPolynomialWhenEndsWithConstant) {
    PolynomialTerm terms[] = {{1, 2}, {2, 1}, {3, 0}};
    Polynomial poly(3, terms);
    testing::internal::CaptureStdout();

    poly.Display();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1x^2 + 2x^1 + 3\n");
}

TEST (PolynomialTest, CanDisplayPolynomialWhenEndsWithVariable) {
    PolynomialTerm terms[] = {{1, 2}, {2, 1}};
    Polynomial poly(2, terms);
    testing::internal::CaptureStdout();

    poly.Display();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1x^2 + 2x^1\n");
}

TEST (PolynomialTest, CanDisplaySingleTermPolynomialConstant) {
    PolynomialTerm terms[] = {{3, 0}};
    Polynomial poly(1, terms);
    testing::internal::CaptureStdout();

    poly.Display();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "3\n");
}

TEST (PolynomialTest, CanDisplaySingleTermPolynomialVariable) {
    PolynomialTerm terms[] = {{3, 2}};
    Polynomial poly(1, terms);
    testing::internal::CaptureStdout();

    poly.Display();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "3x^2\n");
}

TEST (PolynomialTest, CanAddTwoPolynomials) {
    PolynomialTerm terms1[] = {{1, 2}, {2, 1}, {3, 0}}; // 1x^2 + 2x^1 + 3
    Polynomial poly1(3, terms1);
    PolynomialTerm terms2[] = {{1, 2}, {2, 1}, {3, 0}}; // 1x^2 + 2x^1 + 3
    Polynomial poly2(3, terms2);
    testing::internal::CaptureStdout();

    Polynomial result = poly1.Add(poly2);
    result.Display();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2x^2 + 4x^1 + 6\n");
}

TEST (PolynomialTest, CanAddTwoPolynomialsWithDifferentTerms) {
    PolynomialTerm terms1[] = {{1, 2}, {2, 1}, {3, 0}}; // 1x^2 + 2x^1 + 3
    Polynomial poly1(3, terms1);
    PolynomialTerm terms2[] = {{1, 3}, {2, 1}, {3, 0}}; // 1x^3 + 2x^1 + 3
    Polynomial poly2(3, terms2);
    testing::internal::CaptureStdout();

    Polynomial result = poly1.Add(poly2);
    result.Display();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1x^3 + 1x^2 + 4x^1 + 6\n");
}

TEST (PolynomialTest, CanAddTwoPolynomialsWhenFirstHasMoreTerms) {
    PolynomialTerm terms1[] = {{1, 2}, {2, 1}, {3, 0}}; // 1x^2 + 2x^1 + 3
    Polynomial poly1(3, terms1);
    PolynomialTerm terms2[] = {{1, 3}, {2, 1}}; // 1x^3 + 2x^1
    Polynomial poly2(2, terms2);
    testing::internal::CaptureStdout();

    Polynomial result = poly1.Add(poly2);
    result.Display();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1x^3 + 1x^2 + 4x^1 + 3\n");
}

TEST (PolynomialTest, CanAddTwoPolynomialsWhenSecondHasMoreTerms) {
    PolynomialTerm terms1[] = {{1, 2}, {2, 1}}; // 1x^2 + 2x^1
    Polynomial poly1(2, terms1);
    PolynomialTerm terms2[] = {{1, 3}, {2, 1}, {3, 0}}; // 1x^3 + 2x^1 + 3
    Polynomial poly2(3, terms2);
    testing::internal::CaptureStdout();

    Polynomial result = poly1.Add(poly2);
    result.Display();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1x^3 + 1x^2 + 4x^1 + 3\n");
}
