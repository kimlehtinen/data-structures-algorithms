#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

class BinarySearchTree {
private:
    BSTNode* root_;
public:
    BinarySearchTree();
    ~BinarySearchTree();
    BSTNode* Delete(BSTNode* node, int key);
    int GetHeight(BSTNode* node);
    BSTNode* GetInorderPredecessor(BSTNode* node);
    BSTNode* GetInorderSuccessor(BSTNode* node);
    BSTNode* GetRoot();
    void Insert(int key);
    BSTNode* Search(int key);
};

#endif // BINARY_SEARCH_TREE_H
