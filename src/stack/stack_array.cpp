#include "stack/stack.h"

StackArray::StackArray(int capacity) {
    stack_ = new int[capacity];
    top_ = -1;
    capacity_ = capacity;
}

void StackArray::Push(int value) {
    if (IsFull()) {
        return;
    }
    stack_[++top_] = value;
}

int StackArray::Pop() {
    if (IsEmpty()) {
        return -1;
    }
    return stack_[top_--];
}

int StackArray::Peek() const {
    if (IsEmpty()) {
        return -1;
    }
    return stack_[top_];
}

bool StackArray::IsEmpty() const {
    return top_ == -1;
}

bool StackArray::IsFull() const {
    return top_ == capacity_ - 1;
}

StackArray::~StackArray() {
    delete[] stack_;
}
