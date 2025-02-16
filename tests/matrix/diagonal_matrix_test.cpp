#include <gtest/gtest.h>
#include "matrix/matrix.h"

TEST(DiagonalMatrix, CanGetDimension) {
    DiagonalMatrix m(3);

    ASSERT_EQ(m.GetDimension(), 3);
}

TEST(DiagonalMatrix, CanSetAndGet) {
    DiagonalMatrix m(3);

    m.Set(1, 1, 1);
    m.Set(2, 2, 2);
    m.Set(3, 3, 3);

    ASSERT_EQ(m.Get(1, 1), 1);
    ASSERT_EQ(m.Get(2, 2), 2);
    ASSERT_EQ(m.Get(3, 3), 3);
}

TEST(DiagonalMatrix, CanDisplay) {
    DiagonalMatrix m(3);

    m.Set(1, 1, 1);
    m.Set(2, 2, 2);
    m.Set(3, 3, 3);
    testing::internal::CaptureStdout();
    m.Display();

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "1 0 0 \n0 2 0 \n0 0 3 \n");
}
