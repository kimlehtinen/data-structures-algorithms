#ifndef STACK_H
#define STACK_H

#include <iostream>

template <typename T>
class Stack {
public:
    virtual void Display() = 0;
    virtual void Push(T value) = 0; 
    virtual T Pop() = 0;           
    virtual T Peek() const = 0;    
    virtual bool IsEmpty() const = 0;
    virtual bool IsFull() const = 0;
    virtual ~Stack() {}             
};


template <typename T>
class StackArray : public Stack<T> {
private:
    T* stack_;
    int top_;
    int capacity_;
public:
    StackArray(int capacity);
    void Display();
    void Push(T value) override;
    T Pop() override;
    T Peek() const override;
    bool IsEmpty() const override;
    bool IsFull() const override;
    ~StackArray() override;
};


template <typename T>
class StackLinkedList : public Stack<T> {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* top_;
    int max_size_;
    int current_size_;
public:
    StackLinkedList(int max_size = 100);
    void Display();
    void Push(T value) override;
    T Pop() override;
    T Peek() const override;
    bool IsEmpty() const override;
    bool IsFull() const override;
    ~StackLinkedList() override;
};


template <typename T>
StackArray<T>::StackArray(int capacity) {
    stack_ = new T[capacity];
    top_ = -1;
    capacity_ = capacity;
}

template <typename T>
void StackArray<T>::Display() {
    for (int i = top_; i >= 0; i--) {
        std::cout << stack_[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void StackArray<T>::Push(T value) {
    if (IsFull()) {
        return;
    }
    stack_[++top_] = value;
}

template <typename T>
T StackArray<T>::Pop() {
    if (IsEmpty()) {
        return -1;
    }
    return stack_[top_--];
}

template <typename T>
T StackArray<T>::Peek() const {
    if (IsEmpty()) {
        return -1;
    }
    return stack_[top_];
}

template <typename T>
bool StackArray<T>::IsEmpty() const {
    return top_ == -1;
}

template <typename T>
bool StackArray<T>::IsFull() const {
    return top_ == capacity_ - 1;
}

template <typename T>
StackArray<T>::~StackArray() {
    delete[] stack_;
}


template <typename T>
StackLinkedList<T>::StackLinkedList(int max_size) {
    top_ = nullptr;
    max_size_ = max_size;
    current_size_ = 0;
}

template <typename T>
void StackLinkedList<T>::Display() {
    Node* temp = top_;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template <typename T>
void StackLinkedList<T>::Push(T value) {
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

template <typename T>
T StackLinkedList<T>::Pop() {
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

template <typename T>
T StackLinkedList<T>::Peek() const {
    if (IsEmpty()) {
        return -1;
    }

    return top_->data;
}

template <typename T>
bool StackLinkedList<T>::IsEmpty() const {
    return current_size_ == 0;
}

template <typename T>
bool StackLinkedList<T>::IsFull() const {
    return current_size_ == max_size_;
}

template <typename T>
StackLinkedList<T>::~StackLinkedList() {
    Node* temp = top_;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
}


#endif  // STACK_H
