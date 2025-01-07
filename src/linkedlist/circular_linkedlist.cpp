#include <iostream>
#include "linkedlist.h"

CircularLinkedList::CircularLinkedList() {
    head_ = nullptr;
}

CircularLinkedList::~CircularLinkedList() {
    while (GetSize() > 0) {
        DeleteAt(0);
    }
}

void CircularLinkedList::Display() {
    if (head_ == nullptr) {
        return;
    }

    Node* temp = head_;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head_);
    std::cout << std::endl;
}

void CircularLinkedList::DeleteAt(int index) {
    if (head_ == nullptr) {
        return;
    }

    if (index < 0 || index >= GetSize()) {
        return;
    }

    Node* temp = head_;
    if (index == 0) {
        if (head_->next == head_) {
            delete head_;
            head_ = nullptr;
        } else {
            while (temp->next != head_) {
                temp = temp->next;
            }
            Node* to_delete = head_;
            temp->next = head_->next;
            head_ = head_->next;
            delete to_delete;
        }
    } else {
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* to_delete = temp->next;
        temp->next = to_delete->next;
        delete to_delete;
    }
}

Node* CircularLinkedList::FindAt(int index) {
    if (head_ == nullptr) {
        return nullptr;
    }

    if (index < 0 || index >= GetSize()) {
        return nullptr;
    }

    Node* temp = head_;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

int CircularLinkedList::GetSize() {
    int size = 0;
    if (head_ == nullptr) {
        return size;
    }

    Node* temp = head_;
    do {
        size++;
        temp = temp->next;
    } while (temp != head_);
    return size;
}

void CircularLinkedList::Insert(int index, int data) {
    if (index < 0 || index > GetSize()) {
        return;
    }

    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;

    if (head_ == nullptr) {
        head_ = new_node;
        head_->next = head_;
    } else {
        Node* temp = head_;
        if (index == 0) {
            while (temp->next != head_) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = head_;
            head_ = new_node;
        } else {
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}


