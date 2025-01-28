#include "queue/queue.h"
#include <iostream>

/**
 * Drawbacks:
 * - Can't reuse deleted indexes in the array from which elements are deleted.
 * - Every location can be used only once.
 * - Queue is full when all elements are dequeued, front_ and rear_ are at the end of the array.
 * 
 * Better approach:
 * - Reset pointers
 * - Circular queue
 */

QueueArray::QueueArray(int size) {
    queue_ = new int[size];
    front_ = -1;
    rear_ = -1;
    size_ = size;
}

QueueArray::~QueueArray() {
    delete[] queue_;
}

void QueueArray::Enqueue(int value) {
    if (rear_ == size_ - 1) {
        return;
    }
    rear_++;
    queue_[rear_] = value;
}

int QueueArray::Dequeue() {
    int value = -1;
    if (IsEmpty()) {
        return -1;
    }
    front_++;
    value = queue_[front_];

    return value;
}

int QueueArray::Peek() {
    if (IsEmpty()) {
        return -1;
    }
    return queue_[front_+1];
}

bool QueueArray::IsEmpty() {
    return front_ == rear_;
}

void QueueArray::Display() {
    for (int i = front_ + 1; i <= rear_; i++) {
        std::cout << queue_[i] << " ";
    }
    std::cout << std::endl;
}
