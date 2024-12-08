#include <gtest/gtest.h>
#include "array/carray/carray.h"

TEST(CArrayAppendTest, CanAppendToArray) {
    CArray arr;
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

TEST(CArrayAverageTest, CanCalculateAverage) {
    CArray arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    EXPECT_FLOAT_EQ(Average(arr), 2.0);
}

TEST(CArrayDeleteTest, CanDeleteFromArray) {
    CArray arr;
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

TEST(CArrayDifferenceSortedTest, CanFindDifferenceOfTwoSortedArrays) {
    CArray arr1;
    arr1.data = new int[10];
    arr1.size = 10;
    arr1.length = 0;

    arr1.data[0] = 1;
    arr1.data[1] = 3;
    arr1.data[2] = 5;
    arr1.length = 3;

    CArray arr2;
    arr2.data = new int[10];
    arr2.size = 10;
    arr2.length = 0;

    arr2.data[0] = 2;
    arr2.data[1] = 3;
    arr2.data[2] = 6;
    arr2.length = 3;

    CArray *arr = DifferenceSorted(arr1, arr2);

    EXPECT_EQ(arr->data[0], 1);
    EXPECT_EQ(arr->data[1], 5);
    EXPECT_EQ(arr->length, 2);
}

TEST(CArrayDisplayTest, CanDisplayArray) {
    CArray arr;
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

TEST(CArrayGetTest, CanGetElementFromArray) {
    CArray arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    EXPECT_EQ(Get(arr, 1), 2);
}

TEST(CArrayInsertTest, CanInsertIntoArray) {
    CArray arr;
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

TEST(CArrayIntersectionSortedTest, CanFindIntersectionOfTwoSortedArrays) {
    CArray arr1;
    arr1.data = new int[10];
    arr1.size = 10;
    arr1.length = 0;

    arr1.data[0] = 1;
    arr1.data[1] = 3;
    arr1.data[2] = 5;
    arr1.length = 3;

    CArray arr2;
    arr2.data = new int[10];
    arr2.size = 10;
    arr2.length = 0;

    arr2.data[0] = 2;
    arr2.data[1] = 3;
    arr2.data[2] = 6;
    arr2.length = 3;

    CArray *arr = IntersectionSorted(arr1, arr2);

    EXPECT_EQ(arr->data[0], 3);
    EXPECT_EQ(arr->length, 1);
}

TEST(CArrayIsSortedTest, CanCheckSortedArrayIsSorted) {
    CArray arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    EXPECT_TRUE(IsSorted(arr));
}

TEST(CArrayIsSortedTest, CanCheckUnsortedArrayIsNotSorted) {
    CArray arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 3;
    arr.data[1] = 2;
    arr.data[2] = 1;
    arr.length = 3;

    EXPECT_FALSE(IsSorted(arr));
}

TEST(CArrayMaxTest, CanFindMaxInArray) {
    CArray arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    EXPECT_EQ(Max(arr), 3);
}

TEST(CArrayMergeTest, CanMergeTwoArraysOfEqualLength) {
    CArray arr1;
    arr1.data = new int[10];
    arr1.size = 10;

    arr1.data[0] = 1;
    arr1.data[1] = 3;
    arr1.data[2] = 5;
    arr1.length = 3;

    CArray arr2;
    arr2.data = new int[10];
    arr2.size = 10;

    arr2.data[0] = 2;
    arr2.data[1] = 4;
    arr2.data[2] = 6;
    arr2.length = 3;

    CArray *arr = Merge(arr1, arr2);

    EXPECT_EQ(arr->data[0], 1);
    EXPECT_EQ(arr->data[1], 2);
    EXPECT_EQ(arr->data[2], 3);
    EXPECT_EQ(arr->data[3], 4);
    EXPECT_EQ(arr->data[4], 5);
    EXPECT_EQ(arr->data[5], 6);
    EXPECT_EQ(arr->length, 6);
}

TEST(CArrayMergeTest, CanMergeTwoArraysOfDifferentLength) {
    CArray arr1;
    arr1.data = new int[10];
    arr1.size = 10;

    arr1.data[0] = 1;
    arr1.data[1] = 3;
    arr1.data[2] = 5;
    arr1.length = 3;

    CArray arr2;
    arr2.data = new int[10];
    arr2.size = 10;

    arr2.data[0] = 2;
    arr2.data[1] = 4;
    arr2.length = 2;

    CArray *arr = Merge(arr1, arr2);

    EXPECT_EQ(arr->data[0], 1);
    EXPECT_EQ(arr->data[1], 2);
    EXPECT_EQ(arr->data[2], 3);
    EXPECT_EQ(arr->data[3], 4);
    EXPECT_EQ(arr->data[4], 5);
    EXPECT_EQ(arr->length, 5);
}

TEST(CArrayMinTest, CanFindMinInArray) {
    CArray arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    EXPECT_EQ(Min(arr), 1);
}

TEST(CArrayRearrangeTest, CanRearrangeArray) {
    CArray arr;
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

TEST(CArrayReverseTest, CanReverseArray) {
    CArray arr;
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

TEST(CArraySetTest, CanSetElementInArray) {
    CArray arr;
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

TEST(CArraySumTest, CanCalculateSumOfArray) {
    CArray arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    EXPECT_EQ(Sum(arr), 6);
}

TEST(CArrayUnionSortedTest, CanUnionTwoSortedArrays) {
    CArray arr1;
    arr1.data = new int[10];
    arr1.size = 10;

    arr1.data[0] = 1;
    arr1.data[1] = 3;
    arr1.data[2] = 5;
    arr1.length = 3;

    CArray arr2;
    arr2.data = new int[10];
    arr2.size = 10;

    arr2.data[0] = 2;
    arr2.data[1] = 3;
    arr2.data[2] = 6;
    arr2.length = 3;

    CArray *arr = UnionSorted(arr1, arr2);

    EXPECT_EQ(arr->data[0], 1);
    EXPECT_EQ(arr->data[1], 2);
    EXPECT_EQ(arr->data[2], 3);
    EXPECT_EQ(arr->data[3], 5);
    EXPECT_EQ(arr->data[4], 6);
    EXPECT_EQ(arr->length, 5);
}
