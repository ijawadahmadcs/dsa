#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

// ─── Node for BST ────────────────────────────────────────────────────────────
class TreeNode {
public:
    int      data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};


class Tree {
public:
    TreeNode* root;
    Tree() : root(nullptr) {}
    void insert(int value);
    void deletion(int value);
    void find(int value);
    void inorder(TreeNode* node);
    void preorder(TreeNode* node);
    void postorder(TreeNode* node);
private:
    void findNode(int item, TreeNode*& location, TreeNode*& parent);

    void case_a(TreeNode* parent, TreeNode* location);   // leaf node
    void case_b(TreeNode* parent, TreeNode* location);   // one child
    void case_c(TreeNode* parent, TreeNode* location);   // two children
};


#endif // TREE_H