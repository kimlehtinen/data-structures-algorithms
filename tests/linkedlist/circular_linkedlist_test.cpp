#include <gtest/gtest.h>
#include "linkedlist/linkedlist.h"

TEST (CircularLinkedListTest, CanInsertAtBeginning) {
    CircularLinkedList list;

    list.Insert(0, 1);

    EXPECT_EQ(list.GetSize(), 1);
    EXPECT_EQ(list.FindAt(0)->data, 1);
}

TEST (CircularLinkedListTest, CanInsertAtEnd) {
    CircularLinkedList list;

    list.Insert(0, 1);
    list.Insert(1, 2);

    EXPECT_EQ(list.GetSize(), 2);
    EXPECT_EQ(list.FindAt(0)->data, 1);
    EXPECT_EQ(list.FindAt(1)->data, 2);
}

TEST (CircularLinkedListTest, CanInsertInMiddle) {
    CircularLinkedList list;

    list.Insert(0, 1);
    list.Insert(1, 3);
    list.Insert(1, 2);

    EXPECT_EQ(list.GetSize(), 3);
    EXPECT_EQ(list.FindAt(0)->data, 1);
    EXPECT_EQ(list.FindAt(1)->data, 2);
    EXPECT_EQ(list.FindAt(2)->data, 3);
}

TEST (CircularLinkedListTest, CanDisplayList) {
    CircularLinkedList list;

    list.Insert(0, 1);
    list.Insert(1, 2);
    list.Insert(2, 3);

    testing::internal::CaptureStdout();
    list.Display();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1 2 3 \n");
}

TEST (CircularLinkedListTest, CannotDeleteFirstElement) {
    CircularLinkedList list;

    list.Insert(0, 1);
    list.Insert(1, 2);
    list.Insert(2, 3);

    list.DeleteAt(0);

    EXPECT_EQ(list.GetSize(), 2);
    EXPECT_EQ(list.FindAt(0)->data, 2);
    EXPECT_EQ(list.FindAt(1)->data, 3);
}

TEST (CircularLinkedListTest, CannotDeleteInMiddle) {
    CircularLinkedList list;

    list.Insert(0, 1);
    list.Insert(1, 2);
    list.Insert(2, 3);

    list.DeleteAt(1);

    EXPECT_EQ(list.GetSize(), 2);
    EXPECT_EQ(list.FindAt(0)->data, 1);
    EXPECT_EQ(list.FindAt(1)->data, 3);
}

TEST (CircularLinkedListTest, CannotDeleteLastElement) {
    CircularLinkedList list;

    list.Insert(0, 1);
    list.Insert(1, 2);
    list.Insert(2, 3);

    list.DeleteAt(2);

    EXPECT_EQ(list.GetSize(), 2);
    EXPECT_EQ(list.FindAt(0)->data, 1);
    EXPECT_EQ(list.FindAt(1)->data, 2);
}

