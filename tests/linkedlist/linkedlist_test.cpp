#include <gtest/gtest.h>
#include "linkedlist/linkedlist.h"

TEST (LinkedListTest, CanConcatEmptyLists) {
    LinkedList list1;
    LinkedList list2;

    list1.Concat(list2);

    EXPECT_EQ(list1.GetSize(), 0);
    EXPECT_EQ(list2.GetSize(), 0);
}

TEST (LinkedListTest, CanConcatEmptyListWithNonEmptyList) {
    LinkedList list1;
    LinkedList list2;

    list2.Add(1);
    list2.Add(2);
    list2.Add(3);

    list1.Concat(list2);

    EXPECT_EQ(list1.GetSize(), 3);
    EXPECT_EQ(list2.GetSize(), 0);
    EXPECT_EQ(list1.FindAt(0)->data, 1);
    EXPECT_EQ(list1.FindAt(1)->data, 2);
    EXPECT_EQ(list1.FindAt(2)->data, 3);
}

TEST (LinkedListTest, CanConcatNonEmptyListWithEmptyList) {
    LinkedList list1;
    LinkedList list2;

    list1.Add(1);
    list1.Add(2);
    list1.Add(3);

    list1.Concat(list2);

    EXPECT_EQ(list1.GetSize(), 3);
    EXPECT_EQ(list2.GetSize(), 0);
    EXPECT_EQ(list1.FindAt(0)->data, 1);
    EXPECT_EQ(list1.FindAt(1)->data, 2);
    EXPECT_EQ(list1.FindAt(2)->data, 3);
}

TEST (LinkedListTest, CanConcatNonEmptyLists) {
    LinkedList list1;
    LinkedList list2;

    list1.Add(1);
    list1.Add(2);
    list1.Add(3);

    list2.Add(4);
    list2.Add(5);
    list2.Add(6);

    list1.Concat(list2);

    EXPECT_EQ(list1.GetSize(), 6);
    EXPECT_EQ(list2.GetSize(), 0);
    EXPECT_EQ(list1.FindAt(0)->data, 1);
    EXPECT_EQ(list1.FindAt(1)->data, 2);
    EXPECT_EQ(list1.FindAt(2)->data, 3);
    EXPECT_EQ(list1.FindAt(3)->data, 4);
    EXPECT_EQ(list1.FindAt(4)->data, 5);
    EXPECT_EQ(list1.FindAt(5)->data, 6);
}

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

TEST (LinkedListTest, CannotDeleteAtNegativeIndex) {
    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);

    list.DeleteAt(-1);

    EXPECT_EQ(list.GetSize(), 3);
}

TEST (LinkedListTest, CannotDeleteAtIndexGreaterThanSize) {
    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);

    list.DeleteAt(3);

    EXPECT_EQ(list.GetSize(), 3);
}

TEST (LinkedListTest, CanDeleteAtBeginning) {
    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);

    list.DeleteAt(0);

    EXPECT_EQ(list.GetSize(), 2);
    EXPECT_EQ(list.FindAt(0)->data, 2);
    EXPECT_EQ(list.FindAt(1)->data, 3);
}

TEST (LinkedListTest, CanDeleteAtEnd) {
    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);

    list.DeleteAt(2);

    EXPECT_EQ(list.GetSize(), 2);
    EXPECT_EQ(list.FindAt(0)->data, 1);
    EXPECT_EQ(list.FindAt(1)->data, 2);
}

TEST (LinkedListTest, CanDeleteInMiddle) {
    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);

    list.DeleteAt(1);

    EXPECT_EQ(list.GetSize(), 2);
    EXPECT_EQ(list.FindAt(0)->data, 1);
    EXPECT_EQ(list.FindAt(1)->data, 3);
}

TEST (LinkedListTest, CanDeleteEmptyList) {
    LinkedList list;

    list.DeleteAt(0);

    EXPECT_EQ(list.GetSize(), 0);
}

TEST (LinkedListTest, CanFindAtEmptyList) {
    LinkedList list;

    EXPECT_EQ(list.FindAt(0), nullptr);
}

TEST (LinkedListTest, CannotFindAtNegativeIndex) {
    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);

    EXPECT_EQ(list.FindAt(-1), nullptr);
}

TEST (LinkedListTest, CannotFindAtIndexGreaterThanSize) {
    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);

    EXPECT_EQ(list.FindAt(3), nullptr);
}

TEST (LinkedListTest, CanFindAtFirst) {
    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);

    Node* node = list.FindAt(0);

    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node->data, 1);
}

TEST (LinkedListTest, CanFindAtLast) {
    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);

    Node* node = list.FindAt(2);

    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node->data, 3);
}

TEST (LinkedListTest, CanFindAtMiddle) {
    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);

    Node* node = list.FindAt(1);

    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node->data, 2);
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

TEST (LinkedListTest, CannotInsertNegativeIndex) {
    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);

    list.Insert(-1, 4);

    EXPECT_EQ(list.GetSize(), 3);
}

TEST (LinkedListTest, CannotInsertIndexGreaterThanSize) {
    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);

    list.Insert(4, 4);

    EXPECT_EQ(list.GetSize(), 3);
}

TEST (LinkedListTest, CanInsertAtBeginning) {
    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);

    list.Insert(0, 4);

    EXPECT_EQ(list.GetSize(), 4);
    EXPECT_EQ(list.FindAt(0)->data, 4);
    EXPECT_EQ(list.FindAt(1)->data, 1);
    EXPECT_EQ(list.FindAt(2)->data, 2);
    EXPECT_EQ(list.FindAt(3)->data, 3);
}

TEST (LinkedListTest, CanInsertAtEnd) {
    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);

    list.Insert(3, 4);

    EXPECT_EQ(list.GetSize(), 4);
    EXPECT_EQ(list.FindAt(0)->data, 1);
    EXPECT_EQ(list.FindAt(1)->data, 2);
    EXPECT_EQ(list.FindAt(2)->data, 3);
    EXPECT_EQ(list.FindAt(3)->data, 4);
}

TEST (LinkedListTest, CanInsertInMiddle) {
    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);

    list.Insert(1, 4);

    EXPECT_EQ(list.GetSize(), 4);
    EXPECT_EQ(list.FindAt(0)->data, 1);
    EXPECT_EQ(list.FindAt(1)->data, 4);
    EXPECT_EQ(list.FindAt(2)->data, 2);
    EXPECT_EQ(list.FindAt(3)->data, 3);
}

TEST (LinkedListTest, IsSortedWhenEmptyList) {
    LinkedList list;

    EXPECT_TRUE(list.IsSorted());
}

TEST (LinkedListTest, IsSortedWhenHasElementsOrdered) {
    LinkedList list;

    list.Add(1);
    list.Add(2);
    list.Add(3);

    EXPECT_TRUE(list.IsSorted());
}

TEST (LinkedListTest, IsNotSortedWhenHasElementsUnordered) {
    LinkedList list;

    list.Add(3);
    list.Add(1);
    list.Add(2);

    EXPECT_FALSE(list.IsSorted());
}

TEST (LinkedListTest, IsNotSortedWhenHasNegativeElementsUnordered) {
    LinkedList list;

    list.Add(-3);
    list.Add(-1);
    list.Add(-2);

    EXPECT_FALSE(list.IsSorted());
}

TEST (LinkedListTest, IsSortedWhenHasNegativeElementsOrdered) {
    LinkedList list;

    list.Add(-3);
    list.Add(-2);
    list.Add(-1);

    EXPECT_TRUE(list.IsSorted());
}

TEST (LinkedListTest, IsNotSortedWhenHasNegativeAndPositiveElementsUnordered) {
    LinkedList list;

    list.Add(-3);
    list.Add(1);
    list.Add(-2);

    EXPECT_FALSE(list.IsSorted());
}

TEST (LinkedListTest, IsNotSortedWhenHasNegativeAndPositiveAndZeroElementsUnordered) {
    LinkedList list;

    list.Add(-3);
    list.Add(0);
    list.Add(1);
    list.Add(-2);

    EXPECT_FALSE(list.IsSorted());
}

TEST (LinkedListTest, IsSortedWhenAllSame) {
    LinkedList list;

    list.Add(1);
    list.Add(1);
    list.Add(1);

    EXPECT_TRUE(list.IsSorted());
}

TEST (LinkedListTest, CanInsertEmptylist) {
    LinkedList list;

    list.Insert(0, 1);

    EXPECT_EQ(list.GetSize(), 1);
    EXPECT_EQ(list.FindAt(0)->data, 1);
}

TEST (LinkedListTest, CanReverseEmptyList) {
    LinkedList list;

    list.Reverse();

    EXPECT_EQ(list.GetSize(), 0);
}

TEST (LinkedListTest, CanReverseList) {
    LinkedList list;

    list.Add(1);
    list.Add(2);
    list.Add(3);

    list.Reverse();

    EXPECT_EQ(list.GetSize(), 3);
    EXPECT_EQ(list.FindAt(0)->data, 3);
    EXPECT_EQ(list.FindAt(1)->data, 2);
    EXPECT_EQ(list.FindAt(2)->data, 1);
}

TEST (LinkedListTest, CanReverseRecursiveEmptyList) {
    LinkedList list;

    list.ReverseRecursive(list.FindAt(0));

    EXPECT_EQ(list.GetSize(), 0);
}

TEST (LinkedListTest, CanReverseRecursiveList) {
    LinkedList list;

    list.Add(1);
    list.Add(2);
    list.Add(3);

    list.ReverseRecursive(list.FindAt(0));

    EXPECT_EQ(list.GetSize(), 3);
    EXPECT_EQ(list.FindAt(0)->data, 3);
    EXPECT_EQ(list.FindAt(1)->data, 2);
    EXPECT_EQ(list.FindAt(2)->data, 1);
}

TEST (LinkedListTest, CanSearchEmptyList) {
    LinkedList list;

    EXPECT_EQ(list.Search(1), nullptr);
}

TEST (LinkedListTest, CanSearchWhenHasElements) {
    LinkedList list;

    list.Add(1);
    list.Add(2);
    list.Add(3);

    Node* node = list.Search(2);

    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node->data, 2);
}

TEST (LinkedListTest, CanSearchWhenHasElementsNotFound) {
    LinkedList list;

    list.Add(1);
    list.Add(2);
    list.Add(3);

    Node* node = list.Search(4);

    EXPECT_EQ(node, nullptr);
}

TEST (LinkedListTest, CanSearchWhenHasElementsFirst) {
    LinkedList list;

    list.Add(1);
    list.Add(2);
    list.Add(3);

    Node* node = list.Search(1);

    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node->data, 1);
}

TEST (LinkedListTest, CanSearchWhenHasElementsLast) {
    LinkedList list;

    list.Add(1);
    list.Add(2);
    list.Add(3);

    Node* node = list.Search(3);

    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node->data, 3);
}

TEST (LinkedListTest, CanSearchWhenHasElementsNegative) {
    LinkedList list;

    list.Add(-1);
    list.Add(-2);
    list.Add(-3);

    Node* node = list.Search(-2);

    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node->data, -2);
}

TEST (LinkedListTest, CanSearchWhenHasElementsNegativeAndPositive) {
    LinkedList list;

    list.Add(-1);
    list.Add(2);
    list.Add(-3);

    Node* node = list.Search(2);

    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node->data, 2);
}

TEST (LinkedListTest, CanSearchWhenHasElementsNegativeAndPositiveAndZero) {
    LinkedList list;

    list.Add(-1);
    list.Add(0);
    list.Add(2);
    list.Add(-3);

    Node* node = list.Search(0);

    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node->data, 0);
}

TEST (LinkedListTest, CanSearchWhenAllSame) {
    LinkedList list;

    list.Add(1);
    list.Add(1);
    list.Add(1);

    Node* node = list.Search(1);

    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node->data, 1);
}
