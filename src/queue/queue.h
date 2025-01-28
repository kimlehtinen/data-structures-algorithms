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

#endif // QUEUE_H
