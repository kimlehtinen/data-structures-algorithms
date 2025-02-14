#include "binary_search_tree.h"

BinarySearchTree::BinarySearchTree() {
    root_ = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
}

BSTNode* BinarySearchTree::Delete(BSTNode *node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->left == nullptr && node->right == nullptr){
        if (node == root_){
            root_ = nullptr;
        }
        delete node;
        return nullptr;
    }

    if (key < node->data) {
        node->left = Delete(node->left, key);
    } else if (key > node->data) {
        node->right = Delete(node->right, key);
    } else {
        BSTNode* temp = nullptr;
        if (GetHeight(node->left) > GetHeight(node->right)) {
            temp = GetInorderPredecessor(node->left);
            node->data = temp->data;
            node->left = Delete(node->left, temp->data);
        } else {
            temp = GetInorderSuccessor(node->right);
            node->data = temp->data;
            node->right = Delete(node->right, temp->data);
        }
    }

    return node;
}

int BinarySearchTree::GetHeight(BSTNode *node){
    if (node == nullptr) {
        return 0;
    }

    int left_height = GetHeight(node->left);
    int right_height = GetHeight(node->right);

    return left_height > right_height ? left_height + 1 : right_height + 1;
}

BSTNode *BinarySearchTree::GetInorderPredecessor(BSTNode *node) {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

BSTNode *BinarySearchTree::GetInorderSuccessor(BSTNode *node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

BSTNode* BinarySearchTree::GetRoot() {
    return root_;
}

void BinarySearchTree::Insert(int key) {
    BSTNode* new_node = new BSTNode;
    new_node->data = key;
    new_node->left = nullptr;
    new_node->right = nullptr;

    if (root_ == nullptr) {
        root_ = new_node;
        return;
    }

    BSTNode* current = root_;
    BSTNode* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (key < parent->data) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
}

BSTNode* BinarySearchTree::Search(int key) {
    BSTNode* current = root_;

    while (current != nullptr) {
        if (key == current->data) {
            return current;
        } else if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return nullptr;
}
