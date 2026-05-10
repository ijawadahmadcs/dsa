#include "AVL.h"
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

AVLTree::AVLTree() { root = NULL; }

int AVLTree::height(AVLNode *n)
{
    return (n == NULL) ? 0 : n->height;
}

int AVLTree::balanceFactor(AVLNode *n)
{
    return (n == NULL) ? 0 : height(n->lchild) - height(n->rchild);
}

/*  Right Rotation (fixes Left-Left imbalance)
 *
 *       y                x
 *      / \              / \
 *     x   T3   -->    T1   y
 *    / \                  / \
 *  T1   T2              T2   T3
 */
AVLNode *AVLTree::rotateRight(AVLNode *y)
{
    AVLNode *x = y->lchild;
    AVLNode *T2 = x->rchild;

    x->rchild = y;
    y->lchild = T2;

    // Update heights (y first — it's now lower)
    y->height = 1 + MAX(height(y->lchild), height(y->rchild));
    x->height = 1 + MAX(height(x->lchild), height(x->rchild));

    return x; // x is the new root of this subtree
}

/*  Left Rotation (fixes Right-Right imbalance)
 *
 *     x                  y
 *    / \                / \
 *  T1   y     -->     x   T3
 *      / \           / \
 *    T2   T3       T1   T2
 */
AVLNode *AVLTree::rotateLeft(AVLNode *x)
{
    AVLNode *y = x->rchild;
    AVLNode *T2 = y->lchild;

    y->lchild = x;
    x->rchild = T2;

    x->height = 1 + MAX(height(x->lchild), height(x->rchild));
    y->height = 1 + MAX(height(y->lchild), height(y->rchild));

    return y;
}

/*  balance() — Called after every insert/delete.
 *  Detects which of the 4 rotation cases is needed and applies it.
 *
 *  Case 1  LL  bf > +1 and left-heavy  → rotateRight
 *  Case 2  LR  bf > +1 and right-heavy → rotateLeft(left), rotateRight
 *  Case 3  RR  bf < -1 and right-heavy → rotateLeft
 *  Case 4  RL  bf < -1 and left-heavy  → rotateRight(right), rotateLeft
 */
AVLNode *AVLTree::balance(AVLNode *n)
{
    if (n == NULL)
        return NULL;

    // Update height of current node
    n->height = 1 + MAX(height(n->lchild), height(n->rchild));
    int bf = balanceFactor(n);

    // ── Left-Left (LL) ──────────────────────────────────
    if (bf > 1 && balanceFactor(n->lchild) >= 0)
        return rotateRight(n);

    // ── Left-Right (LR) ────────────────────────────────
    if (bf > 1 && balanceFactor(n->lchild) < 0)
    {
        n->lchild = rotateLeft(n->lchild);
        return rotateRight(n);
    }

    // ── Right-Right (RR) ────────────────────────────────
    if (bf < -1 && balanceFactor(n->rchild) <= 0)
        return rotateLeft(n);

    // ── Right-Left (RL) ────────────────────────────────
    if (bf < -1 && balanceFactor(n->rchild) > 0)
    {
        n->rchild = rotateRight(n->rchild);
        return rotateLeft(n);
    }

    return n; // Already balanced
}

//  Q1 — INSERT (no duplicates allowed — rejects duplicates)
AVLNode *AVLTree::insertNode(AVLNode *node, int item)
{
    // Standard BST insert
    if (node == NULL)
    {
        AVLNode *tmp = new AVLNode();
        tmp->info = item;
        tmp->count = 1;
        tmp->height = 1;
        tmp->name = "";
        tmp->marks = 0.0f;
        tmp->lchild = NULL;
        tmp->rchild = NULL;
        return tmp;
    }
    if (item < node->info)
        node->lchild = insertNode(node->lchild, item);
    else if (item > node->info)
        node->rchild = insertNode(node->rchild, item);
    else
    {
        cout << "Item already present" << endl;
        return node;
    }
    return balance(node);
}

void AVLTree::insert(int item)
{
    root = insertNode(root, item);
}

//  Q1 — DELETE (single instance)
// Returns the node with minimum value in the inorder subtree rooted at node
AVLNode *AVLTree::minValueNode(AVLNode *node)
{
    AVLNode *cur = node;
    while (cur->lchild != NULL)
        cur = cur->lchild;
    return cur;
}

AVLNode *AVLTree::deleteCaseA(AVLNode *node)
{
    delete node;
    return NULL;
}

AVLNode *AVLTree::deleteCaseB(AVLNode *node)
{
    AVLNode *child = (node->lchild != NULL) ? node->lchild : node->rchild;
    *node = *child;
    delete child;
    return node;
}

AVLNode *AVLTree::deleteCaseC(AVLNode *node)
{
    AVLNode *suc = minValueNode(node->rchild);
    node->info = suc->info;
    node->count = suc->count;
    node->name = suc->name;
    node->marks = suc->marks;
    node->rchild = deleteNode(node->rchild, suc->info);
    return node;
}

AVLNode *AVLTree::deleteNode(AVLNode *node, int item)
{
    if (node == NULL)
    {
        cout << "Item not present in tree" << endl;
        return NULL;
    }

    if (item < node->info)
        node->lchild = deleteNode(node->lchild, item);
    else if (item > node->info)
        node->rchild = deleteNode(node->rchild, item);
    else
    {
        if (node->lchild == NULL && node->rchild == NULL)
            return deleteCaseA(node);
        if (node->lchild == NULL || node->rchild == NULL)
            return deleteCaseB(node);
        return deleteCaseC(node);
    }
    return balance(node);
}

void AVLTree::deletion(int item)
{
    if (root == NULL)
    {
        cout << "Tree empty" << endl;
        return;
    }
    root = deleteNode(root, item);
}

//  Q1 — DUPLICATE-AWARE INSERT & DELETE
AVLNode *AVLTree::insertDupNode(AVLNode *node, int item)
{
    if (node == NULL)
    {
        AVLNode *tmp = new AVLNode();
        tmp->info = item;
        tmp->count = 1;
        tmp->height = 1;
        tmp->name = "";
        tmp->marks = 0.0f;
        tmp->lchild = NULL;
        tmp->rchild = NULL;
        return tmp;
    }
    if (item < node->info)
        node->lchild = insertDupNode(node->lchild, item);
    else if (item > node->info)
        node->rchild = insertDupNode(node->rchild, item);
    else
    {
        // Duplicate found — just increment counter, no new node
        node->count++;
        cout << "Duplicate detected. Count for " << item
             << " is now " << node->count << endl;
        return node; // No structural change — no need to rebalance
    }
    return balance(node);
}

void AVLTree::insertDup(int item)
{
    root = insertDupNode(root, item);
}

AVLNode *AVLTree::deleteDupNode(AVLNode *node, int item)
{
    if (node == NULL)
    {
        cout << "Item not present in tree" << endl;
        return NULL;
    }
    if (item < node->info)
        node->lchild = deleteDupNode(node->lchild, item);
    else if (item > node->info)
        node->rchild = deleteDupNode(node->rchild, item);
    else
    {
        if (node->count > 1)
        {
            // Still has duplicates — just decrement
            node->count--;
            cout << "Duplicate removed. Count for " << item
                 << " is now " << node->count << endl;
            return node;
        }
        if (node->lchild == NULL && node->rchild == NULL)
            return deleteCaseA(node);
        if (node->lchild == NULL || node->rchild == NULL)
            return deleteCaseB(node);
        return deleteCaseC(node);
    }
    return balance(node);
}

void AVLTree::deletionDup(int item)
{
    if (root == NULL)
    {
        cout << "Tree empty" << endl;
        return;
    }
    root = deleteDupNode(root, item);
}

//  Q2 — RECURSIVE TRAVERSALS
void AVLTree::inorder(AVLNode *ptr)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL)
    {
        inorder(ptr->lchild);
        cout << ptr->info << " ";
        inorder(ptr->rchild);
    }
}

void AVLTree::preorder(AVLNode *ptr)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL)
    {
        cout << ptr->info << " ";
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

void AVLTree::postorder(AVLNode *ptr)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        cout << ptr->info << " ";
    }
}

//  Q2 — NON-RECURSIVE TRAVERSALS (stack-based)

/* Non-recursive Inorder: Left → Root → Right */
void AVLTree::inorderNR()
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    stack<AVLNode *> stk;
    AVLNode *ptr = root;

    while (ptr != NULL || !stk.empty())
    {
        while (ptr != NULL)
        { // Push all left nodes
            stk.push(ptr);
            ptr = ptr->lchild;
        }
        ptr = stk.top();
        stk.pop();
        cout << ptr->info << " ";
        ptr = ptr->rchild; // Move to right subtree
    }
}

/* Non-recursive Preorder: Root → Left → Right */
void AVLTree::preorderNR()
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    stack<AVLNode *> stk;
    stk.push(root);

    while (!stk.empty())
    {
        AVLNode *ptr = stk.top();
        stk.pop();
        cout << ptr->info << " ";
        // Push right first (LIFO) so left is processed first
        if (ptr->rchild != NULL)
            stk.push(ptr->rchild);
        if (ptr->lchild != NULL)
            stk.push(ptr->lchild);
    }
}

/* Non-recursive Postorder: Left → Right → Root (two stacks) */
void AVLTree::postorderNR()
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    stack<AVLNode *> stk1, stk2;
    stk1.push(root);

    while (!stk1.empty())
    {
        AVLNode *ptr = stk1.top();
        stk1.pop();
        stk2.push(ptr);

        if (ptr->lchild != NULL)
            stk1.push(ptr->lchild);
        if (ptr->rchild != NULL)
            stk1.push(ptr->rchild);
    }

    while (!stk2.empty())
    {
        cout << stk2.top()->info << " ";
        stk2.pop();
    }
}

//  Q4 — STUDENT RECORD BST (Roll No = key)
AVLNode *AVLTree::insertStudentNode(AVLNode *node, int rollNo,
                                    const string &name, float marks)
{
    if (node == NULL)
    {
        AVLNode *tmp = new AVLNode();
        tmp->info = rollNo;
        tmp->count = 1;
        tmp->height = 1;
        tmp->name = name;
        tmp->marks = marks;
        tmp->lchild = NULL;
        tmp->rchild = NULL;
        return tmp;
    }
    if (rollNo < node->info)
        node->lchild = insertStudentNode(node->lchild, rollNo, name, marks);
    else if (rollNo > node->info)
        node->rchild = insertStudentNode(node->rchild, rollNo, name, marks);
    else
    {
        cout << "Student with Roll No " << rollNo << " already present" << endl;
        return node;
    }
    return balance(node);
}

void AVLTree::insertStudent(int rollNo, const string &name, float marks)
{
    root = insertStudentNode(root, rollNo, name, marks);
    cout << "Student record inserted successfully." << endl;
}

AVLNode *AVLTree::searchNode(AVLNode *ptr, int key)
{
    if (ptr == NULL)
        return NULL;
    if (key < ptr->info)
        return searchNode(ptr->lchild, key);
    if (key > ptr->info)
        return searchNode(ptr->rchild, key);
    return ptr; // Found
}

void AVLTree::searchStudent(int rollNo)
{
    AVLNode *ptr = searchNode(root, rollNo);
    if (ptr == NULL)
    {
        cout << "Student with Roll No " << rollNo << " not found." << endl;
    }
    else
    {
        cout << "------------------------------" << endl;
        cout << "Roll No : " << ptr->info << endl;
        cout << "Name    : " << ptr->name << endl;
        cout << "Marks   : " << ptr->marks << endl;
        cout << "------------------------------" << endl;
    }
}

//  Q5 — TERMINAL (LEAF) NODES: DISPLAY & DELETE
void AVLTree::displayLeaves(AVLNode *ptr)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    stack<AVLNode *> stk;
    stk.push(ptr);

    while (!stk.empty())
    {
        AVLNode *node = stk.top();
        stk.pop();

        if (node == NULL)
            continue;

        if (node->lchild == NULL && node->rchild == NULL)
            cout << node->info << " ";
        else
        {
            if (node->rchild != NULL)
                stk.push(node->rchild);
            if (node->lchild != NULL)
                stk.push(node->lchild);
        }
    }
}

/* Iteratively removes the leaves that exist at the start of the call.
   The actual deletions reuse the normal AVL delete path so balancing stays
   consistent with the rest of the tree operations. */
AVLNode *AVLTree::deleteLeavesHelper(AVLNode *ptr)
{
    if (ptr == NULL)
        return NULL;

    stack<AVLNode *> stk;
    stack<int> leaves;
    stk.push(ptr);

    while (!stk.empty())
    {
        AVLNode *node = stk.top();
        stk.pop();

        if (node == NULL)
            continue;

        if (node->lchild == NULL && node->rchild == NULL)
            leaves.push(node->info);
        else
        {
            if (node->rchild != NULL)
                stk.push(node->rchild);
            if (node->lchild != NULL)
                stk.push(node->lchild);
        }
    }

    while (!leaves.empty())
    {
        ptr = deleteNode(ptr, leaves.top());
        leaves.pop();
    }

    return ptr;
}

void AVLTree::deleteLeaves()
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    root = deleteLeavesHelper(root);
    cout << "All leaf nodes deleted." << endl;
}

//  Q6 — INORDER SUCCESSOR & PREDECESSOR
void AVLTree::findSuccessorPredecessor(int item)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }

    AVLNode *ptr = root;
    AVLNode *successor = NULL;
    AVLNode *predecessor = NULL;

    while (ptr != NULL)
    {
        if (item == ptr->info)
        {
            // Predecessor = rightmost node in left subtree
            if (ptr->lchild != NULL)
            {
                AVLNode *tmp = ptr->lchild;
                while (tmp->rchild != NULL)
                    tmp = tmp->rchild;
                predecessor = tmp;
            }
            // Successor = leftmost node in right subtree
            if (ptr->rchild != NULL)
            {
                AVLNode *tmp = ptr->rchild;
                while (tmp->lchild != NULL)
                    tmp = tmp->lchild;
                successor = tmp;
            }
            break;
        }
        else if (item < ptr->info)
        {
            successor = ptr; // ptr is a candidate successor
            ptr = ptr->lchild;
        }
        else
        {
            predecessor = ptr; // ptr is a candidate predecessor
            ptr = ptr->rchild;
        }
    }

    if (ptr == NULL)
    {
        cout << "Item " << item << " not found in tree." << endl;
        return;
    }
    if (predecessor != NULL)
        cout << "Inorder Predecessor of " << item << " : " << predecessor->info << endl;
    else
        cout << "No Inorder Predecessor for " << item << endl;

    if (successor != NULL)
        cout << "Inorder Successor   of " << item << " : " << successor->info << endl;
    else
        cout << "No Inorder Successor for " << item << endl;
}

//  Q7 — NODES AT A GIVEN LEVEL (root = level 1)
void AVLTree::nodesAtLevel(AVLNode *ptr, int target, int current)
{
    if (ptr == NULL)
        return;

    queue<AVLNode *> q;
    q.push(ptr);

    int level = current;
    while (!q.empty() && level < target)
    {
        int levelSize = static_cast<int>(q.size());
        while (levelSize-- > 0)
        {
            AVLNode *node = q.front();
            q.pop();

            if (node->lchild != NULL)
                q.push(node->lchild);
            if (node->rchild != NULL)
                q.push(node->rchild);
        }
        level++;
    }

    if (level != target)
        return;

    while (!q.empty())
    {
        cout << q.front()->info << " ";
        q.pop();
    }
}

//  Q8 — DISPLAY ALL LEFT-CHILD NODES
void AVLTree::displayLeftNodes(AVLNode *ptr)
{
    if (ptr == NULL)
        return;

    stack<AVLNode *> stk;
    stk.push(ptr);

    while (!stk.empty())
    {
        AVLNode *node = stk.top();
        stk.pop();

        if (node->lchild != NULL)
        {
            cout << node->lchild->info << " ";
            stk.push(node->lchild);
        }
        if (node->rchild != NULL)
            stk.push(node->rchild);
    }
}

//  Q9 — LARGEST VALUE AT A GIVEN LEVEL
int AVLTree::largestAtLevel(AVLNode *ptr, int target, int current)
{
    if (ptr == NULL)
        return INT_MIN;

    queue<AVLNode *> q;
    q.push(ptr);

    int level = current;
    while (!q.empty() && level < target)
    {
        int levelSize = static_cast<int>(q.size());
        while (levelSize-- > 0)
        {
            AVLNode *node = q.front();
            q.pop();

            if (node->lchild != NULL)
                q.push(node->lchild);
            if (node->rchild != NULL)
                q.push(node->rchild);
        }
        level++;
    }

    if (level != target || q.empty())
        return INT_MIN;

    int largest = q.front()->info;
    while (!q.empty())
    {
        if (q.front()->info > largest)
            largest = q.front()->info;
        q.pop();
    }
    return largest;
}

//  Q10 — DISPLAY ALL RIGHT-CHILD NODES
void AVLTree::displayRightNodes(AVLNode *ptr)
{
    if (ptr == NULL)
        return;

    stack<AVLNode *> stk;
    stk.push(ptr);

    while (!stk.empty())
    {
        AVLNode *node = stk.top();
        stk.pop();

        if (node->rchild != NULL)
        {
            cout << node->rchild->info << " ";
            stk.push(node->rchild);
        }
        if (node->lchild != NULL)
            stk.push(node->lchild);
    }
}

//  ReverseAVL — Q3  (Left > node, Right < node)
ReverseAVL::ReverseAVL() { root = NULL; }

int ReverseAVL::height(RevAVLNode *n)
{
    return (n == NULL) ? 0 : n->height;
}

int ReverseAVL::balanceFactor(RevAVLNode *n)
{
    return (n == NULL) ? 0 : height(n->lchild) - height(n->rchild);
}

RevAVLNode *ReverseAVL::rotateRight(RevAVLNode *y)
{
    RevAVLNode *x = y->lchild;
    RevAVLNode *T2 = x->rchild;
    x->rchild = y;
    y->lchild = T2;
    y->height = 1 + MAX(height(y->lchild), height(y->rchild));
    x->height = 1 + MAX(height(x->lchild), height(x->rchild));
    return x;
}

RevAVLNode *ReverseAVL::rotateLeft(RevAVLNode *x)
{
    RevAVLNode *y = x->rchild;
    RevAVLNode *T2 = y->lchild;
    y->lchild = x;
    x->rchild = T2;
    x->height = 1 + MAX(height(x->lchild), height(x->rchild));
    y->height = 1 + MAX(height(y->lchild), height(y->rchild));
    return y;
}

RevAVLNode *ReverseAVL::insertRev(RevAVLNode *node, int item)
{
    if (node == NULL)
    {
        RevAVLNode *tmp = new RevAVLNode();
        tmp->info = item;
        tmp->height = 1;
        tmp->lchild = NULL;
        tmp->rchild = NULL;
        return tmp;
    }
    if (item == node->info)
    {
        cout << "Item already present (Reverse AVL)" << endl;
        return node;
    }

    // Reverse rule: LARGER values go LEFT, SMALLER go RIGHT
    if (item > node->info)
        node->lchild = insertRev(node->lchild, item);
    else
        node->rchild = insertRev(node->rchild, item);

    // Update height
    node->height = 1 + MAX(height(node->lchild), height(node->rchild));

    // Balance using standard rotations — the ordering is reversed
    // but the balance factor logic is identical.
    int bf = balanceFactor(node);

    // LL — left-heavy, left child also left-heavy
    if (bf > 1 && balanceFactor(node->lchild) >= 0)
        return rotateRight(node);
    // LR
    if (bf > 1 && balanceFactor(node->lchild) < 0)
    {
        node->lchild = rotateLeft(node->lchild);
        return rotateRight(node);
    }
    // RR
    if (bf < -1 && balanceFactor(node->rchild) <= 0)
        return rotateLeft(node);
    // RL
    if (bf < -1 && balanceFactor(node->rchild) > 0)
    {
        node->rchild = rotateRight(node->rchild);
        return rotateLeft(node);
    }
    return node;
}

void ReverseAVL::insert(int item)
{
    root = insertRev(root, item);
}

/* Inorder of a ReverseAVL prints values in DESCENDING order */
void ReverseAVL::inorder(RevAVLNode *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->lchild);
        cout << ptr->info << " ";
        inorder(ptr->rchild);
    }
}


void AVLTree::preorderRRL()
{
    if(root==NULL)
    {
        cout<<"This tree is empty"<<endl;
        return;
    }
    stack<AVLNode *>stack;
    stack.push(root);
    while(!stack.empty()){
        AVLNode *ptr = stack.top();
        stack.pop();
         cout << ptr->info;

        if (ptr->lchild != NULL)
            stack.push(ptr->lchild);
        if (ptr->rchild != NULL)
            stack.push(ptr->rchild);
    }

}
    


void AVLTree::rightRootLeftNR()
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }

    stack<AVLNode *> stk;
    AVLNode *ptr = root;

    while (ptr != NULL || !stk.empty())
    {
        while (ptr != NULL)
        {
            stk.push(ptr);
            ptr = ptr->rchild;
        }

        ptr = stk.top();
        stk.pop();
        cout << ptr->info << " ";
        ptr = ptr->lchild;
    }
}
// 

       

void AVLTree::displayNodeType(int item)
{
    AVLNode *node = searchNode(root, item);

    if (node == NULL)
    {
        cout << "Node not present" << endl;
        return;
    }

    bool hasLeft = (node->lchild != NULL);
    bool hasRight = (node->rchild != NULL);

    if (!hasLeft && !hasRight)
        cout << item << " is a leaf node" << endl;
    else if (hasLeft && hasRight)
        cout << item << " is a two child node" << endl;
    else
        cout << item << " is a one child node" << endl;
}
