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

#endif // LINKEDLIST_H