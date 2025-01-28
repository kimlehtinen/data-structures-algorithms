#ifndef QUEUE_H
#define QUEUE_H

class QueueArray {
private:
    int* queue_;
    int front_;
    int rear_;
    int size_;
public:
    QueueArray(int size);
    ~QueueArray();
    void Enqueue(int value);
    int Dequeue();
    int Peek();
    bool IsEmpty();
    void Display();
};

class QueueCircular {
private:
    int* queue_;
    int front_;
    int rear_;
    int size_;
public:
    QueueCircular(int size);
    ~QueueCircular();
    void Enqueue(int value);
    int Dequeue();
    int Peek();
    bool IsEmpty();
    void Display();
};

class QueueLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* front_;
    Node* rear_;
public:
    QueueLinkedList();
    ~QueueLinkedList();
    void Enqueue(int value);
    int Dequeue();
    int Peek();
    bool IsEmpty();
    void Display();
};

#endif // QUEUE_H
