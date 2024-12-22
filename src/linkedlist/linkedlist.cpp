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

void LinkedList::Concat(LinkedList &list)
{
    if (list.head_ == nullptr) {
        return;
    }
    if (head_ == nullptr) {
        head_ = list.head_;
        list.head_ = nullptr;
        return;
    }
    Node* temp = head_;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = list.head_;
    list.head_ = nullptr;
}

void LinkedList::Display() {
    Node* temp = head_;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void LinkedList::DeleteAt(int index)
{
    if (head_ == nullptr || index < 0 || index >= GetSize()) {
        return;
    }

    Node* temp = head_;
    if (index == 0) {
        head_ = head_->next;
        delete temp;
    } else {
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* to_delete = temp->next;
        temp->next = to_delete->next;
        delete to_delete;
    }
}

Node *LinkedList::FindAt(int index)
{
    if (index < 0 || index >= GetSize()) {
        return nullptr;
    }

    Node* temp = head_;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

int LinkedList::GetMax()
{
    int max = INT32_MIN;
    Node* temp = head_;
    while (temp != nullptr) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
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

void LinkedList::Insert(int index, int data)
{
    if (index < 0 || index > GetSize()) {
        return;
    }

    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;

    if (index == 0) {
        new_node->next = head_;
        head_ = new_node;
    } else {
        Node* temp = head_;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

bool LinkedList::IsSorted()
{
    Node* temp = head_;
    while (temp != nullptr && temp->next != nullptr) {
        if (temp->data > temp->next->data) {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

void LinkedList::Reverse()
{
    Node* prev = nullptr;
    Node* current = head_;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head_ = prev;
}

void LinkedList::ReverseRecursive(Node *node)
{
    if (node == nullptr) {
        return;
    }

    if (node->next == nullptr) {
        head_ = node;
        return;
    }

    ReverseRecursive(node->next);
    Node* temp = node->next;
    temp->next = node;
    node->next = nullptr;
}

Node *LinkedList::Search(int data)
{
    Node* temp = head_;
    while (temp != nullptr) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}
