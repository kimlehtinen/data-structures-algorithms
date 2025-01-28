#include <gtest/gtest.h>
#include "queue/queue.h"

TEST(QueueArrayTest, CanEnqueueAndDisplayFilledValues) {
    QueueArray queue(5);

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);

    testing::internal::CaptureStdout();
    queue.Display();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "1 2 3 4 5 \n");
}

TEST(QueueArrayTest, CanDequeueAndDisplayRemaining) {
    QueueArray queue(5);

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    queue.Dequeue();
    queue.Dequeue();

    testing::internal::CaptureStdout();
    queue.Display();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "3 4 5 \n");
}

TEST(QueueArrayTest, CanDequeueAllEnquedValuesAndDisplayEmpty) {
    QueueArray queue(5);

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();

    testing::internal::CaptureStdout();
    queue.Display();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "\n");
    ASSERT_EQ(queue.IsEmpty(), true);
}

TEST(QueueArrayTest, CanPeek) {
    QueueArray queue(5);

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);

    ASSERT_EQ(queue.Peek(), 1);
}

TEST(QueueArrayTest, CanCheckIfEmptyWhenNoValuesFilled) {
    QueueArray queue(5);

    ASSERT_TRUE(queue.IsEmpty());
}

TEST(QueueArrayTest, CanCheckIfEmptyWhenValuesFilled) {
    QueueArray queue(5);

    queue.Enqueue(1);

    ASSERT_FALSE(queue.IsEmpty());
}
