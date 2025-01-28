#include "queue/queue.h"
#include <iostream>

/**
 * Modulus table for circular queue of size 5:
 * 0 % 5 = 0
 * 1 % 5 = 1
 * 2 % 5 = 2
 * 3 % 5 = 3
 * 4 % 5 = 4
 * 5 % 5 = 0 start from the beginning
 */

QueueCircular::QueueCircular(int size) {
    queue_ = new int[size];
    front_ = -1;
    rear_ = -1;
    size_ = size;
}

QueueCircular::~QueueCircular() {
    delete[] queue_;
}

void QueueCircular::Enqueue(int value) {
    // Check if queue is full 
    if ((rear_ + 1) % size_ == front_) {
        return;
    }

    rear_ = (rear_ + 1) % size_;
    queue_[rear_] = value;
}

int QueueCircular::Dequeue() {
    int value = -1;
    if (IsEmpty()) {
        return -1;
    }
    front_ = (front_ + 1) % size_;
    value = queue_[front_];

    return value;
}

int QueueCircular::Peek() {
    if (IsEmpty()) {
        return -1;
    }
    return queue_[front_+1];
}

bool QueueCircular::IsEmpty() {
    return front_ == rear_;
}

void QueueCircular::Display() {
    for (int i = front_ + 1; i <= rear_; i++) {
        std::cout << queue_[i] << " ";
    }
    std::cout << std::endl;
}
