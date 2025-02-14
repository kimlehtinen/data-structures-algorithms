#include <gtest/gtest.h>
#include "trees/binary_search_tree.h"

TEST(BinarySearchTree, Constructor) {
    BinarySearchTree bst;

    EXPECT_EQ(nullptr, bst.GetRoot());
}

TEST(BinarySearchTree, Insert) {
    BinarySearchTree bst;

    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(15);
    bst.Insert(3);
    bst.Insert(7);
    bst.Insert(12);
    bst.Insert(17);

    BSTNode* root = bst.GetRoot();
    EXPECT_EQ(10, root->data);
    EXPECT_EQ(5, root->left->data);
    EXPECT_EQ(15, root->right->data);
    EXPECT_EQ(3, root->left->left->data);
    EXPECT_EQ(7, root->left->right->data);
    EXPECT_EQ(12, root->right->left->data);
    EXPECT_EQ(17, root->right->right->data);
}

TEST(BinarySearchTree, Search) {
    BinarySearchTree bst;

    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(15);
    bst.Insert(3);
    bst.Insert(7);
    bst.Insert(12);
    bst.Insert(17);

    BSTNode* node = bst.Search(10);
    EXPECT_EQ(10, node->data);

    node = bst.Search(5);
    EXPECT_EQ(5, node->data);

    node = bst.Search(15);
    EXPECT_EQ(15, node->data);

    node = bst.Search(3);
    EXPECT_EQ(3, node->data);

    node = bst.Search(7);
    EXPECT_EQ(7, node->data);

    node = bst.Search(12);
    EXPECT_EQ(12, node->data);

    node = bst.Search(17);
    EXPECT_EQ(17, node->data);

    node = bst.Search(100);
    EXPECT_EQ(nullptr, node);
}

TEST(BinarySearchTree, CanDeleteLeafNode) {
    BinarySearchTree bst;

    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(15);
    bst.Insert(3);
    bst.Insert(7);

    bst.Delete(bst.GetRoot(), 3);

    EXPECT_EQ(nullptr, bst.Search(3));
    EXPECT_EQ(10, bst.GetRoot()->data);
    EXPECT_EQ(5, bst.GetRoot()->left->data);
    EXPECT_EQ(15, bst.GetRoot()->right->data);
    EXPECT_EQ(7, bst.GetRoot()->left->right->data);
    EXPECT_EQ(nullptr, bst.GetRoot()->left->left);
}

TEST(BinarySearchTree, CanDeleteRootNode) {
    BinarySearchTree bst;

    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(15);
    bst.Insert(3);
    bst.Insert(7);

    bst.Delete(bst.GetRoot(), 10);

    EXPECT_EQ(nullptr, bst.Search(10));
    EXPECT_EQ(7, bst.GetRoot()->data);
    EXPECT_EQ(5, bst.GetRoot()->left->data);
    EXPECT_EQ(15, bst.GetRoot()->right->data);
    EXPECT_EQ(3, bst.GetRoot()->left->left->data);
    EXPECT_EQ(nullptr, bst.GetRoot()->left->right);
}
