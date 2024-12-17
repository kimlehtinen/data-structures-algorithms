#include "linkedlist.h"
#include <iostream>

LinkedList::LinkedList() {
    head_ = nullptr;
}

LinkedList::~LinkedList() {
    while (head_ != nullptr) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
    }
}

void LinkedList::Add(int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;

    if (head_ == nullptr) {
        head_ = new_node;
    } else {
        Node* temp = head_;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void LinkedList::Display() {
    Node* temp = head_;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int LinkedList::GetSize() {
    int size = 0;
    Node* temp = head_;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }
    return size;
}

int LinkedList::GetSum()
{
    int sum = 0;
    Node* temp = head_;
    while (temp != nullptr) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}
