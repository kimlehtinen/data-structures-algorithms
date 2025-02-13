#ifndef BINARY_TREE_QUEUE_H
#define BINARY_TREE_QUEUE_H

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

class BinaryTreeQueue {
private:
    BinaryTreeNode **queue_;
    int front_;
    int rear_;
    int size_;
public:
    BinaryTreeQueue(int size);
    ~BinaryTreeQueue();
    void Enqueue(BinaryTreeNode* x);
    BinaryTreeNode* Dequeue();
    int Peek();
    bool IsEmpty();
    void Display();
};

#endif // BINARY_TREE_QUEUE_H
