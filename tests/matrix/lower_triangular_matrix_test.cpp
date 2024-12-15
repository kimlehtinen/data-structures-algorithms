#include <gtest/gtest.h>
#include "matrix/matrix.h"


TEST(LowerTriangularMatrix, CanGetDimension) {
    LowerTriangularMatrix m(3);

    ASSERT_EQ(m.GetDimension(), 3);
}

TEST(LowerTriangularMatrix, CanSetAndGet) {
    LowerTriangularMatrix m(3);

    m.Set(1, 1, 1);
    m.Set(2, 1, 2);
    m.Set(2, 2, 3);
    m.Set(3, 1, 4);
    m.Set(3, 2, 5);
    m.Set(3, 3, 6);

    ASSERT_EQ(m.Get(1, 1), 1);
    ASSERT_EQ(m.Get(2, 1), 2);
    ASSERT_EQ(m.Get(2, 2), 3);
    ASSERT_EQ(m.Get(3, 1), 4);
    ASSERT_EQ(m.Get(3, 2), 5);
    ASSERT_EQ(m.Get(3, 3), 6);
}

TEST(LowerTriangularMatrix, CanDisplay) {
    LowerTriangularMatrix m(3);

    m.Set(1, 1, 1);
    m.Set(2, 1, 2);
    m.Set(2, 2, 3);
    m.Set(3, 1, 4);
    m.Set(3, 2, 5);
    m.Set(3, 3, 6);
    testing::internal::CaptureStdout();
    m.Display();

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "1 0 0 \n2 3 0 \n4 5 6 \n");
}
