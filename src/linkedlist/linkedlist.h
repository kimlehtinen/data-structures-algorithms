#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    private:
        Node* head_;
        Node* tail_;
        int size_;
    public:
        LinkedList();
        ~LinkedList();
        void Add(int data);
        void Display();
        int GetSize();
        int GetSum();
};

#endif // LINKEDLIST_H