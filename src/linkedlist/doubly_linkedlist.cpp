#include "linkedlist/linkedlist.h"
#include <iostream>


DoublyLinkedList::DoublyLinkedList() {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
    while (size_ > 0) {
        DeleteAt(0);
    }
}

void DoublyLinkedList::Display() {
    DoublyNode* temp = head_;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::DeleteAt(int index) {
    if (head_ == nullptr) {
        return;
    }

    if (index < 0 || index >= size_) {
        return;
    }

    DoublyNode* temp = head_;
    if (index == 0) {
        if (head_->next == nullptr) {
            delete head_;
            head_ = nullptr;
        } else {
            head_ = head_->next;
            delete head_->prev;
            head_->prev = nullptr;
        }
    } else {
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            temp->prev->next = nullptr;
            delete temp;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }
    size_--;
}

DoublyNode* DoublyLinkedList::FindAt(int index) {
    if (head_ == nullptr) {
        return nullptr;
    }

    if (index < 0 || index >= size_) {
        return nullptr;
    }

    DoublyNode* temp = head_;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

int DoublyLinkedList::GetSize() {
    return size_;
}

void DoublyLinkedList::Insert(int index, int data) {
    if (index < 0 || index > size_) {
        return;
    }

    DoublyNode* new_node = new DoublyNode;
    new_node->data = data;
    new_node->next = nullptr;
    new_node->prev = nullptr;

    if (head_ == nullptr) {
        head_ = new_node;
    } else if (index == 0) {
        new_node->next = head_;
        head_->prev = new_node;
        head_ = new_node;
    } else {
        DoublyNode* temp = head_;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = new_node;
        }
        temp->next = new_node;
    }
    size_++;
}

void DoublyLinkedList::Reverse() {
    DoublyNode* temp = head_;
    DoublyNode* prev = nullptr;
    while (temp != nullptr) {
        prev = temp->prev;
        temp->prev = temp->next;
        temp->next = prev;
        temp = temp->prev;
    }
    if (prev != nullptr) {
        head_ = prev->prev;
    }
}
