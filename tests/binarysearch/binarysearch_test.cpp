#include <gtest/gtest.h>
#include "binarysearch/binarysearch.h"
#include "array/carray/carray.h"

TEST(BinarySearchTest, HandlesSmallCases) {
    CArray arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    EXPECT_EQ(BinarySearch(arr, 1), 0);
    EXPECT_EQ(BinarySearch(arr, 2), 1);
    EXPECT_EQ(BinarySearch(arr, 3), 2);
    EXPECT_EQ(BinarySearch(arr, 4), -1);
}

TEST(BinarySearchRecursiveTest, HandlesSmallCases) {
    CArray arr;
    arr.data = new int[10];
    arr.size = 10;
    arr.length = 0;

    arr.data[0] = 1;
    arr.data[1] = 2;
    arr.data[2] = 3;
    arr.length = 3;

    EXPECT_EQ(BinarySearchRecursive(arr, 0, 2, 1), 0);
    EXPECT_EQ(BinarySearchRecursive(arr, 0, 2, 2), 1);
    EXPECT_EQ(BinarySearchRecursive(arr, 0, 2, 3), 2);
    EXPECT_EQ(BinarySearchRecursive(arr, 0, 2, 4), -1);
}
