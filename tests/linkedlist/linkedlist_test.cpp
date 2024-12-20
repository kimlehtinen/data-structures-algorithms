#include <gtest/gtest.h>
#include "linkedlist/linkedlist.h"

TEST (LinkedListTest, CanDisplayEmptyList) {
    LinkedList list;
    testing::internal::CaptureStdout();

    list.Display();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\n");
}

TEST (LinkedListTest, CanDisplayList) {
    LinkedList list;
    testing::internal::CaptureStdout();

    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Display();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 2 3 \n");
}

TEST (LinkedListTest, CanGetSizeEmptyList) {
    LinkedList list;

    EXPECT_EQ(list.GetSize(), 0);
}

TEST (LinkedListTest, CanGetSizeWhenHasElements) {
    LinkedList list;

    list.Add(1);
    list.Add(2);
    list.Add(3);

    EXPECT_EQ(list.GetSize(), 3);
}

TEST (LinkedListTest, CanGetINT32MINWhenEmptyList) {
    LinkedList list;

    EXPECT_EQ(list.GetMax(), INT32_MIN);
}

TEST (LinkedListTest, CanGetMaxWhenHasElementsOrdered) {
    LinkedList list;

    list.Add(1);
    list.Add(2);
    list.Add(3);

    EXPECT_EQ(list.GetMax(), 3);
}

TEST (LinkedListTest, CanGetMaxWhenHasElementsUnordered) {
    LinkedList list;

    list.Add(3);
    list.Add(1);
    list.Add(2);

    EXPECT_EQ(list.GetMax(), 3);
}

TEST (LinkedListTest, CanGetMaxWhenHasElementsNegative) {
    LinkedList list;

    list.Add(-3);
    list.Add(-1);
    list.Add(-2);

    EXPECT_EQ(list.GetMax(), -1);
}

TEST (LinkedListTest, CanGetMaxWhenHasElementsNegativeAndPositive) {
    LinkedList list;

    list.Add(-3);
    list.Add(1);
    list.Add(-2);

    EXPECT_EQ(list.GetMax(), 1);
}

TEST (LinkedListTest, CanGetMaxWhenHasElementsNegativeAndPositiveAndZero) {
    LinkedList list;

    list.Add(-3);
    list.Add(0);
    list.Add(1);
    list.Add(-2);

    EXPECT_EQ(list.GetMax(), 1);
}

TEST (LinkedListTest, CanGetMaxWhenAllSame) {
    LinkedList list;

    list.Add(1);
    list.Add(1);
    list.Add(1);

    EXPECT_EQ(list.GetMax(), 1);
}

TEST (LinkedListTest, CanGetSumEmptyList) {
    LinkedList list;

    EXPECT_EQ(list.GetSum(), 0);
}

TEST (LinkedListTest, CanGetSumWhenHasElements) {
    LinkedList list;

    list.Add(1);
    list.Add(2);
    list.Add(3);

    EXPECT_EQ(list.GetSum(), 6);
}
