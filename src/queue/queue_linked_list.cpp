#include "queue/queue.h"
#include <iostream>

QueueLinkedList::QueueLinkedList() {
    front_ = nullptr;
    rear_ = nullptr;
}

QueueLinkedList::~QueueLinkedList() {
    Node* temp = front_;
    while (front_ != nullptr) {
        front_ = front_->next;
        delete temp;
        temp = front_;
    }
}

void QueueLinkedList::Enqueue(int value) {
    // Insert happens at the rear
    // Time complexity: O(1) because we have a pointer to the rear
    Node* temp = new Node;
    temp->data = value;
    temp->next = nullptr;
    if (IsEmpty()) {
        front_ = rear_ = temp;
        return;
    }
    rear_->next = temp;
    rear_ = temp;
}

int QueueLinkedList::Dequeue() {
    // Delete happens at the front
    // Time complexity: O(1) because we have a pointer to the front
    int value = -1;
    if (IsEmpty()) {
        return -1;
    }
    Node* temp = front_;
    value = front_->data;
    front_ = front_->next;
    delete temp;

    return value;
}

int QueueLinkedList::Peek() {
    if (IsEmpty()) {
        return -1;
    }
    return front_->data;
}

bool QueueLinkedList::IsEmpty() {
    return front_ == nullptr;
}

void QueueLinkedList::Display() {
    Node* temp = front_;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
