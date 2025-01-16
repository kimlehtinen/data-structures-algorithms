#ifndef STACK_H
#define STACK_H

class Stack {
public:
    virtual void Push(int value) = 0; 
    virtual int Pop() = 0;           
    virtual int Peek() const = 0;    
    virtual bool IsEmpty() const = 0;
    virtual bool IsFull() const = 0;
    virtual ~Stack() {}             
};


class StackArray : public Stack {
private:
    int* stack_;
    int top_;
    int capacity_;
public:
    StackArray(int capacity);
    void Push(int value) override;
    int Pop() override;
    int Peek() const override;
    bool IsEmpty() const override;
    bool IsFull() const override;
    ~StackArray() override;
};

class StackLinkedList : public Stack {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head_;
public:
    StackLinkedList();
    void Push(int value) override;
    int Pop() override;
    int Peek() const override;
    bool IsEmpty() const override;
    bool IsFull() const override;
    ~StackLinkedList() override;
};

#endif  // STACK_H
