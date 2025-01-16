#include "stack/stack.h"
#include <iostream>

StackLinkedList::StackLinkedList(int max_size = 100) {
    top_ = nullptr;
    max_size_ = max_size;
    current_size_ = 0;
}

void StackLinkedList::Display() {
    Node* temp = top_;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void StackLinkedList::Push(int value) {
    Node* new_node = new Node;
    if (new_node == nullptr) {
        std::cout << "Stack is full" << std::endl;
        return;
    }

    new_node->data = value;
    new_node->next = top_;
    top_ = new_node;
    current_size_++;
}

int StackLinkedList::Pop() {
    if (IsEmpty()) {
        return -1;
    }

    Node* temp = top_;
    int value = temp->data;
    top_ = top_->next;
    delete temp;
    current_size_--;

    return value;
}

int StackLinkedList::Peek() const {
    if (IsEmpty()) {
        return -1;
    }

    return top_->data;
}

bool StackLinkedList::IsEmpty() const {
    return current_size_ == 0;
}

bool StackLinkedList::IsFull() const {
    return current_size_ == max_size_;
}

StackLinkedList::~StackLinkedList() {
    Node* temp = top_;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
}
