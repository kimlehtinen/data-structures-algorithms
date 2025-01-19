#include <gtest/gtest.h>
#include "stack/stack.h"

TEST(StackLinkedListTest, CanDisplay) {
    StackLinkedList<int> stack(5);

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);

    testing::internal::CaptureStdout();
    stack.Display();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "50 40 30 20 10 \n");
}

TEST(StackLinkedListTest, CanPush) {
    StackLinkedList<int> stack(5);

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);

    EXPECT_EQ(stack.Peek(), 50);
    EXPECT_EQ(stack.IsFull(), true);
}

TEST(StackLinkedListTest, CanPop) {
    StackLinkedList<int> stack(5);

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);

    EXPECT_EQ(stack.Pop(), 50);
    EXPECT_EQ(stack.Pop(), 40);
    EXPECT_EQ(stack.Pop(), 30);
    EXPECT_EQ(stack.Pop(), 20);
    EXPECT_EQ(stack.Pop(), 10);
    EXPECT_EQ(stack.IsEmpty(), true);
}

TEST(StackLinkedListTest, CanPeek) {
    StackLinkedList<int> stack(5);

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);

    EXPECT_EQ(stack.Peek(), 50);
    EXPECT_EQ(stack.Peek(), 50);
}

TEST(StackLinkedListTest, IsEmptyWhenNotPushedAnything) {
    StackLinkedList<int> stack(5);

    EXPECT_EQ(stack.IsEmpty(), true);
}

TEST(StackLinkedListTest, IsEmptyWhenAllElementsArePopped) {
    StackLinkedList<int> stack(5);

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();

    EXPECT_EQ(stack.IsEmpty(), true);
}

TEST(StackLinkedListTest, IsNotEmptyWhenPushedSomething) {
    StackLinkedList<int> stack(5);

    stack.Push(10);

    EXPECT_EQ(stack.IsEmpty(), false);
}

TEST(StackLinkedListTest, IsFullWhenMaxCapacityReached) {
    StackLinkedList<int> stack(5);

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);

    EXPECT_EQ(stack.IsFull(), true);
}

TEST(StackLinkedListTest, IsNotFullWhenNotReachedMaxCapacity) {
    StackLinkedList<int> stack(5);

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);

    EXPECT_EQ(stack.IsFull(), false);
}


