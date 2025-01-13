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
        void Concat(LinkedList &list);
        void Display();
        void DeleteAt(int index);
        Node* FindAt(int index);
        int GetMax();
        int GetSize();
        int GetSum();
        void Insert(int index, int data);
        bool IsSorted();
        void Reverse();
        void ReverseRecursive(Node* node);
        Node* Search(int data);
};

class CircularLinkedList {
    private:
        Node* head_;
        Node* tail_;
        int size_;
    public:
        CircularLinkedList();
        ~CircularLinkedList();
        void Display();
        void DeleteAt(int index);
        Node* FindAt(int index);
        int GetSize();
        void Insert(int index, int data);
};

struct DoublyNode {
    int data;
    DoublyNode* next;
    DoublyNode* prev;
};

class DoublyLinkedList {
    private:
        DoublyNode* head_;
        DoublyNode* tail_;
        int size_;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void Display();
        void DeleteAt(int index);
        DoublyNode* FindAt(int index);
        int GetSize();
        void Insert(int index, int data);
        void Reverse();
};

#endif // LINKEDLIST_H