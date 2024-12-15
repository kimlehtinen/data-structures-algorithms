#include <gtest/gtest.h>
#include "matrix/matrix.h"

TEST(SparseMatrix, CanDisplay) {
    SparseMatrix s(3, 3, 3);

    std::istringstream is("0 0 1\n1 1 2\n2 2 3\n");
    is >> s;
    testing::internal::CaptureStdout();
    std::cout << s;

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "1 0 0 \n0 2 0 \n0 0 3 \n");
}

TEST(SparseMatrix, CanAddMatricesWithSameSize) {
    SparseMatrix s1(3, 3, 3);
    SparseMatrix s2(3, 3, 3);

    std::istringstream is1("0 0 1\n1 1 2\n2 2 3\n");
    is1 >> s1;
    std::istringstream is2("0 0 4\n1 1 5\n2 2 6\n");
    is2 >> s2;
    SparseMatrix sum = s1 + s2;
    testing::internal::CaptureStdout();
    std::cout << sum;

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "5 0 0 \n0 7 0 \n0 0 9 \n");
}

TEST(SparseMatrix, NoOutputWhenAddingMatricesWithDifferentSize) {
    SparseMatrix s1(3, 3, 3);
    SparseMatrix s2(2, 2, 2);

    std::istringstream is1("0 0 1\n1 1 2\n2 2 3\n");
    is1 >> s1;
    std::istringstream is2("0 0 4\n1 1 5\n");
    is2 >> s2;
    SparseMatrix sum = s1 + s2;
    testing::internal::CaptureStdout();
    std::cout << sum;

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "");
}

TEST(SparseMatrix, KeepsValuesWhenNoMatchingNonZeroElements) {
    SparseMatrix s1(3, 3, 3);
    SparseMatrix s2(3, 3, 3);

    std::istringstream is1("0 0 1\n1 1 2\n2 2 3\n");
    is1 >> s1;
    std::istringstream is2("0 1 4\n1 0 5\n2 0 6\n");
    is2 >> s2;
    SparseMatrix sum = s1 + s2;
    testing::internal::CaptureStdout();
    std::cout << sum;

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "1 4 0 \n5 2 0 \n6 0 3 \n");
}

TEST(SparseMatrix, AddsSingleMatchingNonZeroAmonAndKeepsNonMatching) {
    SparseMatrix s1(3, 3, 3);
    SparseMatrix s2(3, 3, 3);

    std::istringstream is1("0 0 1\n1 1 2\n2 2 3\n");
    is1 >> s1;
    std::istringstream is2("0 1 4\n1 1 5\n2 0 6\n");
    is2 >> s2;
    SparseMatrix sum = s1 + s2;
    testing::internal::CaptureStdout();
    std::cout << sum;

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "1 4 0 \n0 7 0 \n6 0 3 \n");
}
