#ifndef TREE_H
#define TREE_H
#include <iostream>

using namespace std;
struct node {
    int info;
    struct node *lchild;
    struct node *rchild;
};
class Tree {
public:
    node *root;
    Tree();
    // Core BST operations
    void find(int item, node **par, node **loc);
    void insert(int item);
    void deletion(int item);

    // Deletion helper cases
    void case_a(node *par, node *loc);
    void case_b(node *par, node *loc);
    void case_c(node *par, node *loc);

    // Traversals
    void preorder(node *ptr);
    void inorder(node *ptr);
    void postorder(node *ptr);

    // Recursive search
    node* search(node *ptr, int info);
};

#endif