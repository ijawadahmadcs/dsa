#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct node {
    int    info;        /* key / Roll No for student mode  */
    int    count;       /* duplicate counter (>= 1)        */
    string name;        /* student name  (blank in int mode)*/
    float  marks;       /* student marks (0 in int mode)   */
    struct node *lchild;
    struct node *rchild;
};

struct RevNode {
    int      info;
    RevNode *lchild;
    RevNode *rchild;
};

class ReverseBST {
public:
    RevNode *root;
    ReverseBST();
    void insert(int item);
    void inorder(RevNode *ptr);   /* prints descending order */
};

class Tree {
public:
    node *root;
    Tree();

    void  find(int item, node **par, node **loc);
    void  insert(int item);
    void  deletion(int item);
    void  case_a(node *par, node *loc);
    void  case_b(node *par, node *loc);
    void  case_c(node *par, node *loc);
    void  preorder(node *ptr);
    void  inorder(node *ptr);
    void  postorder(node *ptr);
    node* search(node *ptr, int info);

    /* 1:duplicate-aware insert/delete*/
    void  insertDup(int item);
    void  deletionDup(int item);

    /* 2:non-recursive traversals*/
    void  inorderNR();
    void  preorderNR();
    void  postorderNR();

    /* 4:student record BST*/
    void  insertStudent(int rollNo, const string &name, float marks);
    void  searchStudent(int rollNo);

    /* 5:terminal (leaf) nodes */
    void  displayLeaves(node *ptr);
    void  deleteLeaves();

    /* 6:inorder successor & predecessor */
    void  findSuccessorPredecessor(int item);

    /* 7:nodes at given level */
    void  nodesAtLevel(node *ptr, int target, int current);

    /* 8:all left-child nodes */
    void  displayLeftNodes(node *ptr);

    /* 9:largest value at given level */
    int   largestAtLevel(node *ptr, int target, int current);

    /* 10:all right-child nodes */
    void  displayRightNodes(node *ptr);

private:
    /* helpers for deleteLeaves */
    node* deleteLeavesHelper(node *ptr);
};

#endif