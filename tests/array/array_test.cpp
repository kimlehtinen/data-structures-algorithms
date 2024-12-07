#include <gtest/gtest.h>
#include "array/array.h"

TEST(ArrayAppendTest, CanAppendToArray) {
    Array arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    Append(&arr, 1);
    Append(&arr, 2);
    Append(&arr, 3);

    EXPECT_EQ(arr.data[0], 1);
    EXPECT_EQ(arr.data[1], 2);
    EXPECT_EQ(arr.data[2], 3);
    EXPECT_EQ(arr.length, 3);
}

TEST(ArrayAverageTest, CanCalculateAverage) {
    Array arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    EXPECT_FLOAT_EQ(Average(arr), 2.0);
}

TEST(ArrayDeleteTest, CanDeleteFromArray) {
    Array arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    Delete(&arr, 1);

    EXPECT_EQ(arr.data[0], 1);
    EXPECT_EQ(arr.data[1], 3);
    EXPECT_EQ(arr.length, 2);
}

TEST(ArrayDisplayTest, CanDisplayArray) {
    Array arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    testing::internal::CaptureStdout();
    Display(arr);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 2 3 \n");
}

TEST(ArrayGetTest, CanGetElementFromArray) {
    Array arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    EXPECT_EQ(Get(arr, 1), 2);
}

TEST(ArrayInsertTest, CanInsertIntoArray) {
    Array arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    Insert(&arr, 1, 5);

    EXPECT_EQ(arr.data[0], 1);
    EXPECT_EQ(arr.data[1], 5);
    EXPECT_EQ(arr.data[2], 2);
    EXPECT_EQ(arr.data[3], 3);
    EXPECT_EQ(arr.length, 4);
}

TEST(ArrayIsSortedTest, CanCheckSortedArrayIsSorted) {
    Array arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    EXPECT_TRUE(IsSorted(arr));
}

TEST(ArrayIsSortedTest, CanCheckUnsortedArrayIsNotSorted) {
    Array arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 3;
    arr.data[1] = 2;
    arr.data[2] = 1;
    arr.length = 3;

    EXPECT_FALSE(IsSorted(arr));
}

TEST(ArrayMaxTest, CanFindMaxInArray) {
    Array arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    EXPECT_EQ(Max(arr), 3);
}

TEST(ArrayMinTest, CanFindMinInArray) {
    Array arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    EXPECT_EQ(Min(arr), 1);
}

TEST(ArrayRearrangeTest, CanRearrangeArray) {
    Array arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 2;
    arr.data[1] = -3;
    arr.data[2] = 25;
    arr.data[3] = 10;
    arr.data[4] = -15;
    arr.data[5] = -7;
    arr.length = 6;

    Rearrange(&arr);

    EXPECT_EQ(arr.data[0], -7);
    EXPECT_EQ(arr.data[1], -3);
    EXPECT_EQ(arr.data[2], -15);
    EXPECT_EQ(arr.data[3], 10);
    EXPECT_EQ(arr.data[4], 25);
    EXPECT_EQ(arr.data[5], 2);
}

TEST(ArrayReverseTest, CanReverseArray) {
    Array arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    Reverse(&arr);

    EXPECT_EQ(arr.data[0], 3);
    EXPECT_EQ(arr.data[1], 2);
    EXPECT_EQ(arr.data[2], 1);
}

TEST(ArraySetTest, CanSetElementInArray) {
    Array arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    Set(&arr, 1, 5);

    EXPECT_EQ(arr.data[1], 5);
}

TEST(ArraySumTest, CanCalculateSumOfArray) {
    Array arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    EXPECT_EQ(Sum(arr), 6);
}
