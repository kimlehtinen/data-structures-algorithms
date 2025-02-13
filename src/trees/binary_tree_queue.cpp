#include "binary_tree_queue.h"
#include <iostream>

BinaryTreeQueue::BinaryTreeQueue(int size) {
    queue_ = new BinaryTreeNode*[size];
    front_ = -1;
    rear_ = -1;
    size_ = size;
}

BinaryTreeQueue::~BinaryTreeQueue() {
    delete[] queue_;
}

void BinaryTreeQueue::Enqueue(BinaryTreeNode* x) {
    if (rear_ == size_ - 1) {
        return;
    }
    rear_++;
    queue_[rear_] = x;
}

BinaryTreeNode* BinaryTreeQueue::Dequeue() {
    BinaryTreeNode* x = nullptr;
    if (IsEmpty()) {
        return nullptr;
    }
    front_++;
    x = queue_[front_];

    return x;
}

int BinaryTreeQueue::Peek() {
    if (IsEmpty()) {
        return -1;
    }
    return queue_[front_+1]->data;
}

bool BinaryTreeQueue::IsEmpty() {
    return front_ == rear_;
}

void BinaryTreeQueue::Display() {
    for (int i = front_ + 1; i <= rear_; i++) {
        std::cout << queue_[i] << " ";
    }
    std::cout << std::endl;
}
