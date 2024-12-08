#include <gtest/gtest.h>
#include "array/array.h"


TEST(ArrayAppendTest, CanAppendToArray) {
    Array arr(10);

    arr.Append(1);
    arr.Append(2);
    arr.Append(3);

    EXPECT_EQ(arr.Get(0), 1);
    EXPECT_EQ(arr.Get(1), 2);
    EXPECT_EQ(arr.Get(2), 3);
    EXPECT_EQ(arr.Get(3), -1); // Ensure no out-of-bounds access
}

TEST(ArrayAverageTest, CanCalculateAverage) {
    Array arr(10);

    arr.Append(1);
    arr.Append(2);
    arr.Append(3);

    EXPECT_FLOAT_EQ(arr.Average(), 2.0);
}

TEST(ArrayDeleteTest, CanDeleteFromArray) {
    Array arr(10);

    arr.Append(1);
    arr.Append(2);
    arr.Append(3);

    arr.Delete(1);

    EXPECT_EQ(arr.Get(0), 1);
    EXPECT_EQ(arr.Get(1), 3);
    EXPECT_EQ(arr.Get(2), -1); // Ensure no out-of-bounds access
}

TEST(ArrayDifferenceSortedTest, CanFindDifferenceOfTwoSortedArrays) {
    Array arr1(10);
    arr1.Append(1);
    arr1.Append(3);
    arr1.Append(5);

    Array arr2(10);
    arr2.Append(2);
    arr2.Append(3);
    arr2.Append(6);

    Array *arr = arr1.DifferenceSorted(arr2);

    EXPECT_EQ(arr->Get(0), 1);
    EXPECT_EQ(arr->Get(1), 5);
    EXPECT_EQ(arr->Get(2), -1); // Ensure no out-of-bounds access

    delete arr;
}

TEST(ArrayDisplayTest, CanDisplayArray) {
    Array arr(10);

    arr.Append(1);
    arr.Append(2);
    arr.Append(3);

    testing::internal::CaptureStdout();
    arr.Display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 2 3 \n");
}

TEST(ArrayGetTest, CanGetElementFromArray) {
    Array arr(10);

    arr.Append(1);
    arr.Append(2);
    arr.Append(3);

    EXPECT_EQ(arr.Get(1), 2);
}

TEST(ArrayInsertTest, CanInsertIntoArray) {
    Array arr(10);

    arr.Append(1);
    arr.Append(2);
    arr.Append(3);

    arr.Insert(1, 5);

    EXPECT_EQ(arr.Get(0), 1);
    EXPECT_EQ(arr.Get(1), 5);
    EXPECT_EQ(arr.Get(2), 2);
    EXPECT_EQ(arr.Get(3), 3);
}

TEST(ArrayIntersectionSortedTest, CanFindIntersectionOfTwoSortedArrays) {
    Array arr1(10);
    arr1.Append(1);
    arr1.Append(3);
    arr1.Append(5);

    Array arr2(10);
    arr2.Append(2);
    arr2.Append(3);
    arr2.Append(6);

    Array *arr = arr1.IntersectionSorted(arr2);

    EXPECT_EQ(arr->Get(0), 3);
    EXPECT_EQ(arr->Get(1), -1); // Ensure no out-of-bounds access

    delete arr;
}

TEST(ArrayIsSortedTest, CanCheckSortedArrayIsSorted) {
    Array arr(10);

    arr.Append(1);
    arr.Append(2);
    arr.Append(3);

    EXPECT_TRUE(arr.IsSorted());
}

TEST(ArrayIsSortedTest, CanCheckUnsortedArrayIsNotSorted) {
    Array arr(10);

    arr.Append(3);
    arr.Append(2);
    arr.Append(1);

    EXPECT_FALSE(arr.IsSorted());
}

TEST(ArrayMaxTest, CanFindMaxInArray) {
    Array arr(10);

    arr.Append(1);
    arr.Append(2);
    arr.Append(3);

    EXPECT_EQ(arr.Max(), 3);
}

TEST(ArrayMergeTest, CanMergeTwoArraysOfEqualLength) {
    Array arr1(10);
    arr1.Append(1);
    arr1.Append(3);
    arr1.Append(5);

    Array arr2(10);
    arr2.Append(2);
    arr2.Append(4);
    arr2.Append(6);

    Array *arr = arr1.Merge(arr2);

    EXPECT_EQ(arr->Get(0), 1);
    EXPECT_EQ(arr->Get(1), 2);
    EXPECT_EQ(arr->Get(2), 3);
    EXPECT_EQ(arr->Get(3), 4);
    EXPECT_EQ(arr->Get(4), 5);
    EXPECT_EQ(arr->Get(5), 6);

    delete arr;
}

TEST(ArrayMergeTest, CanMergeTwoArraysOfDifferentLength) {
    Array arr1(10);
    arr1.Append(1);
    arr1.Append(3);
    arr1.Append(5);

    Array arr2(10);
    arr2.Append(2);
    arr2.Append(4);

    Array *arr = arr1.Merge(arr2);

    EXPECT_EQ(arr->Get(0), 1);
    EXPECT_EQ(arr->Get(1), 2);
    EXPECT_EQ(arr->Get(2), 3);
    EXPECT_EQ(arr->Get(3), 4);
    EXPECT_EQ(arr->Get(4), 5);

    delete arr;
}

TEST(ArrayMinTest, CanFindMinInArray) {
    Array arr(10);

    arr.Append(1);
    arr.Append(2);
    arr.Append(3);

    EXPECT_EQ(arr.Min(), 1);
}

TEST(ArrayRearrangeTest, CanRearrangeArray) {
    Array arr(10);

    arr.Append(2);
    arr.Append(-3);
    arr.Append(25);
    arr.Append(10);
    arr.Append(-15);
    arr.Append(-7);

    arr.Rearrange();

    EXPECT_EQ(arr.Get(0), -7);
    EXPECT_EQ(arr.Get(1), -3);
    EXPECT_EQ(arr.Get(2), -15);
    EXPECT_EQ(arr.Get(3), 10);
    EXPECT_EQ(arr.Get(4), 25);
    EXPECT_EQ(arr.Get(5), 2);
}

TEST(ArrayReverseTest, CanReverseArray) {
    Array arr(10);

    arr.Append(1);
    arr.Append(2);
    arr.Append(3);

    arr.Reverse();

    EXPECT_EQ(arr.Get(0), 3);
    EXPECT_EQ(arr.Get(1), 2);
    EXPECT_EQ(arr.Get(2), 1);
}

TEST(ArraySetTest, CanSetElementInArray) {
    Array arr(10);

    arr.Append(1);
    arr.Append(2);
    arr.Append(3);

    arr.Set(1, 5);

    EXPECT_EQ(arr.Get(1), 5);
}

TEST(ArraySumTest, CanCalculateSumOfArray) {
    Array arr(10);

    arr.Append(1);
    arr.Append(2);
    arr.Append(3);

    EXPECT_EQ(arr.Sum(), 6);
}

TEST(ArrayUnionSortedTest, CanUnionTwoSortedArrays) {
    Array arr1(10);
    arr1.Append(1);
    arr1.Append(3);
    arr1.Append(5);

    Array arr2(10);
    arr2.Append(2);
    arr2.Append(3);
    arr2.Append(6);

    Array *arr = arr1.UnionSorted(arr2);

    EXPECT_EQ(arr->Get(0), 1);
    EXPECT_EQ(arr->Get(1), 2);
    EXPECT_EQ(arr->Get(2), 3);
    EXPECT_EQ(arr->Get(3), 5);
    EXPECT_EQ(arr->Get(4), 6);

    delete arr;
}