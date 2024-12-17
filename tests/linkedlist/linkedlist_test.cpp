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
