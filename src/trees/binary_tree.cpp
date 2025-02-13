#include "binary_tree.h"
#include <iostream>

BinaryTree::BinaryTree() {
    root_ = nullptr;
}

BinaryTree::~BinaryTree() {
}

void BinaryTree::Create() {
    BinaryTreeNode* p;
    BinaryTreeNode* t;
    int x;
    BinaryTreeQueue q(100);

    std::cout << "Enter root value: ";
    std::cin >> x;
    root_ = new BinaryTreeNode;
    root_->data = x;
    root_->left = nullptr;
    root_->right = nullptr;
    q.Enqueue(root_);

    while (!q.IsEmpty()) {
        p = q.Dequeue();
        std::cout << "Enter left child of " << p->data << ": ";
        std::cin >> x;
        if (x != -1) {
            t = new BinaryTreeNode;
            t->data = x;
            t->left = nullptr;
            t->right = nullptr;
            p->left = t;
            q.Enqueue(t);
        }

        std::cout << "Enter right child of " << p->data << ": ";
        std::cin >> x;
        if (x != -1) {
            t = new BinaryTreeNode;
            t->data = x;
            t->left = nullptr;
            t->right = nullptr;
            p->right = t;
            q.Enqueue(t);
        }
    }
}

void BinaryTree::Preorder(BinaryTreeNode* p) {
    if (p) {
        std::cout << p->data << " ";
        Preorder(p->left);
        Preorder(p->right);
    }
}

void BinaryTree::Inorder(BinaryTreeNode* p) {
    if (p) {
        Inorder(p->left);
        std::cout << p->data << " ";
        Inorder(p->right);
    }
}

void BinaryTree::Postorder(BinaryTreeNode* p) {
    if (p) {
        Postorder(p->left);
        Postorder(p->right);
        std::cout << p->data << " ";
    }
}

void BinaryTree::Levelorder(BinaryTreeNode* p) {
    BinaryTreeQueue q(100);
    std::cout << p->data << " ";
    q.Enqueue(p);

    while (!q.IsEmpty()) {
        p = q.Dequeue();
        if (p->left) {
            std::cout << p->left->data << " ";
            q.Enqueue(p->left);
        }
        if (p->right) {
            std::cout << p->right->data << " ";
            q.Enqueue(p->right);
        }
    }
}

int BinaryTree::Height(BinaryTreeNode* p) {
    int x = 0;
    int y = 0;
    if (!p) {
        return 0;
    }
    x = Height(p->left);
    y = Height(p->right);
    if (x > y) {
        return x + 1;
    } else {
        return y + 1;
    }
}

void BinaryTree::Display() {
    std::cout << "Preorder: ";
    Preorder(root_);
    std::cout << std::endl;

    std::cout << "Inorder: ";
    Inorder(root_);
    std::cout << std::endl;

    std::cout << "Postorder: ";
    Postorder(root_);
    std::cout << std::endl;

    std::cout << "Levelorder: ";
    Levelorder(root_);
    std::cout << std::endl;

    std::cout << "Height: " << Height(root_) << std::endl;
}

