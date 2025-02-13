#include "binary_tree_queue.h"
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class BinaryTree {
private:
    BinaryTreeNode* root_;
public:
    BinaryTree();
    ~BinaryTree();
    void Create();
    void Preorder(BinaryTreeNode* p);
    void Inorder(BinaryTreeNode* p);
    void Postorder(BinaryTreeNode* p);
    void Levelorder(BinaryTreeNode* p);
    int Height(BinaryTreeNode* p);
    void Display();
};

#endif // BINARY_TREE_H