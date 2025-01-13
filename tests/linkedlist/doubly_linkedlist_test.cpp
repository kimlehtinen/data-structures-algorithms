#include <gtest/gtest.h>
#include "linkedlist/linkedlist.h"

TEST(DoublyLinkedList, CanInsert) {
    DoublyLinkedList list;

    list.Insert(0, 10);
    list.Insert(1, 20);
    list.Insert(2, 30);
    list.Insert(3, 40);
    list.Insert(4, 50);

    EXPECT_EQ(list.FindAt(0)->data, 10);
    EXPECT_EQ(list.FindAt(1)->data, 20);
    EXPECT_EQ(list.FindAt(2)->data, 30);
    EXPECT_EQ(list.FindAt(3)->data, 40);
    EXPECT_EQ(list.FindAt(4)->data, 50);
    EXPECT_EQ(list.GetSize(), 5);
}

TEST(DoublyLinkedList, CanDelete) {
    DoublyLinkedList list;

    list.Insert(0, 10);
    list.Insert(1, 20);
    list.Insert(2, 30);
    list.Insert(3, 40);
    list.Insert(4, 50);

    list.DeleteAt(0);
    list.DeleteAt(3);

    EXPECT_EQ(list.FindAt(0)->data, 20);
    EXPECT_EQ(list.FindAt(1)->data, 30);
    EXPECT_EQ(list.FindAt(2)->data, 40);
    EXPECT_EQ(list.GetSize(), 3);
}

TEST(DoublyLinkedList, CanDisplay) {
    DoublyLinkedList list;

    list.Insert(0, 10);
    list.Insert(1, 20);
    list.Insert(2, 30);
    list.Insert(3, 40);
    list.Insert(4, 50);

    testing::internal::CaptureStdout();
    list.Display();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "10 20 30 40 50 \n");
}

TEST(DoublyLinkedList, CanReverse) {
    DoublyLinkedList list;

    list.Insert(0, 10);
    list.Insert(1, 20);
    list.Insert(2, 30);
    list.Insert(3, 40);
    list.Insert(4, 50);

    list.Reverse();

    EXPECT_EQ(list.FindAt(0)->data, 50);
    EXPECT_EQ(list.FindAt(1)->data, 40);
    EXPECT_EQ(list.FindAt(2)->data, 30);
    EXPECT_EQ(list.FindAt(3)->data, 20);
    EXPECT_EQ(list.FindAt(4)->data, 10);
}
