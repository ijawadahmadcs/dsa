#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <stack>
#include <string>
#include <climits>
using namespace std;

struct AVLNode {
    int      info;      // Key value (also Roll No. in student mode)
    int      count;     // Duplicate counter
    int      height;    // Height of this node (for balancing)
    string   name;      // Student name  (Q4)
    float    marks;     // Student marks (Q4)
    AVLNode *lchild;
    AVLNode *rchild;
};

struct RevAVLNode {
    int         info;
    int         height;
    RevAVLNode *lchild;
    RevAVLNode *rchild;
};

class ReverseAVL {
public:
    RevAVLNode *root;
    ReverseAVL();
    int  height(RevAVLNode *n);
    int  balanceFactor(RevAVLNode *n);
    RevAVLNode* rotateRight(RevAVLNode *y);
    RevAVLNode* rotateLeft(RevAVLNode *x);
    RevAVLNode* insertRev(RevAVLNode *node, int item);
    void insert(int item);
    void inorder(RevAVLNode *ptr);   // prints descending order
};

class AVLTree {
public:
    AVLNode *root;

    AVLTree();

    int      height(AVLNode *n);
    int      balanceFactor(AVLNode *n);
    AVLNode* rotateRight(AVLNode *y);
    AVLNode* rotateLeft(AVLNode *x);
    AVLNode* balance(AVLNode *n);

    AVLNode* insertNode(AVLNode *node, int item);
    AVLNode* deleteNode(AVLNode *node, int item);
    AVLNode* minValueNode(AVLNode *node);
    AVLNode* deleteCaseA(AVLNode *node);
    AVLNode* deleteCaseB(AVLNode *node);
    AVLNode* deleteCaseC(AVLNode *node);
    void insert(int item);
    void deletion(int item);

    AVLNode* insertDupNode(AVLNode *node, int item);
    AVLNode* deleteDupNode(AVLNode *node, int item);
    void insertDup(int item);
    void deletionDup(int item);

    void inorder(AVLNode *ptr);
    void preorder(AVLNode *ptr);
    void postorder(AVLNode *ptr);

    void inorderNR();
    void preorderNR();
    void postorderNR();

    AVLNode* insertStudentNode(AVLNode *node, int rollNo,
                               const string &name, float marks);
    void insertStudent(int rollNo, const string &name, float marks);
    AVLNode* searchNode(AVLNode *ptr, int key);
    void searchStudent(int rollNo);

    void displayLeaves(AVLNode *ptr);
    AVLNode* deleteLeavesHelper(AVLNode *ptr);
    void deleteLeaves();

    void findSuccessorPredecessor(int item);

    void nodesAtLevel(AVLNode *ptr, int target, int current);

    void displayLeftNodes(AVLNode *ptr);

    int largestAtLevel(AVLNode *ptr, int target, int current);

    void displayRightNodes(AVLNode *ptr);

    void preorderRRL();
    void rightRootLeftNR();
    void displayNodeType(int item);
};

#endif
