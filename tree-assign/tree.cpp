#include "Tree.h"
#include <cstdlib>
#include <climits>

Tree::Tree()
{
    root = NULL;
}

//  * find() — UNCHANGED
void Tree::find(int item, node **par, node **loc)
{
    node *ptr, *ptrsave;

    if (root == NULL)
    { /* tree empty */
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->info)
    { /* item is at root */
        *loc = root;
        *par = NULL;
        return;
    }

    // Initialize ptr and ptrsave to start traversal from root
    if (item < root->info)
        ptr = root->lchild;
    else
        ptr = root->rchild;
    ptrsave = root;

    while (ptr != NULL)
    {
        if (item == ptr->info)
        {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item < ptr->info)
            ptr = ptr->lchild;
        else
            ptr = ptr->rchild;
    }

    *loc = NULL; // item not found
    *par = ptrsave;
}

//  * insert() — UNCHANGED logic; extra fields zeroed safely
void Tree::insert(int item)
{
    node *tmp, *parent, *location;
    find(item, &parent, &location);
    if (location != NULL)
    {
        cout << "Item already present" << endl;
        return;
    }

    tmp = new node();
    tmp->info = item;
    tmp->count = 1;
    tmp->name = "";
    tmp->marks = 0.0f;
    tmp->lchild = NULL;
    tmp->rchild = NULL;

    if (parent == NULL)
        root = tmp;
    else
    {
        if (item < parent->info)
            parent->lchild = tmp;
        else
            parent->rchild = tmp;
    }
}

// deletion()
void Tree::deletion(int item)
{
    node *parent, *location;
    if (root == NULL)
    {
        cout << "Tree empty" << endl;
        return;
    }

    find(item, &parent, &location);
    if (location == NULL)
    {
        cout << "Item not present in tree" << endl;
        return;
    }

    if (location->lchild == NULL && location->rchild == NULL)
        case_a(parent, location);
    if (location->lchild != NULL && location->rchild == NULL)
        case_b(parent, location);
    if (location->lchild == NULL && location->rchild != NULL)
        case_b(parent, location);
    if (location->lchild != NULL && location->rchild != NULL)
        case_c(parent, location);

    delete location;
}

 //case_a() — UNCHANGED
void Tree::case_a(node *par, node *loc)
{
    if (par == NULL)
        root = NULL;
    else
    {
        if (loc == par->lchild)
            par->lchild = NULL;
        else
            par->rchild = NULL;
    }
} 

 //case_b() — UNCHANGED
void Tree::case_b(node *par, node *loc)
{
    node *child;

    if (loc->lchild != NULL)
        child = loc->lchild;
    else
        child = loc->rchild;

    if (par == NULL)
        root = child;
    else
    {
        if (loc == par->lchild)
            par->lchild = child;
        else
            par->rchild = child;
    }
} 

 //case_c() — UNCHANGED
void Tree::case_c(node *par, node *loc)
{
    node *ptr, *ptrsave, *suc, *parsuc;

    ptrsave = loc;
    ptr = loc->rchild;
    while (ptr->lchild != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->lchild;
    }
    suc = ptr;
    parsuc = ptrsave;

    if (suc->lchild == NULL && suc->rchild == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);

    if (par == NULL)
        root = suc;
    else
    {
        if (loc == par->lchild)
            par->lchild = suc;
        else
            par->rchild = suc;
    }

    suc->lchild = loc->lchild;
    suc->rchild = loc->rchild;
} 

 //preorder() — UNCHANGED
void Tree::preorder(node *ptr)
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
} /* End of preorder() */

 //inorder() — UNCHANGED
void Tree::inorder(node *ptr)
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

// postorder() — UNCHANGED
void Tree::postorder(node *ptr)
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

 //search() — UNCHANGED
node *Tree::search(node *ptr, int info)
{
    if (ptr != NULL)
    {
        if (info < ptr->info)
            ptr = search(ptr->lchild, info);
        else if (info > ptr->info)
            ptr = search(ptr->rchild, info);
    }
    return ptr;
}

/*==========================================================
 *  FEATURE 1 — Duplicate-aware insert & delete
 *
 *  Strategy: each node stores a `count` field.
 *  insertDup : if key exists, increment count; else insert normally.
 *  deletionDup: if count > 1, decrement count; else delete normally
 *              using the same case_a/b/c logic as the original.
 *==========================================================*/
void Tree::insertDup(int item)
{
    node *tmp, *parent, *location;
    find(item, &parent, &location);

    if (location != NULL)
    {
        /* key already present — just increment duplicate count */
        location->count++;
        cout << "Duplicate detected. Count for " << item
             << " is now " << location->count << endl;
        return;
    }

    /* key is new — allocate and link exactly like original insert() */
    tmp = new node();
    tmp->info = item;
    tmp->count = 1;
    tmp->name = "";
    tmp->marks = 0.0f;
    tmp->lchild = NULL;
    tmp->rchild = NULL;

    if (parent == NULL)
        root = tmp;
    else
    {
        if (item < parent->info)
            parent->lchild = tmp;
        else
            parent->rchild = tmp;
    }
} 

void Tree::deletionDup(int item)
{
    node *parent, *location;

    if (root == NULL)
    {
        cout << "Tree empty" << endl;
        return;
    }

    find(item, &parent, &location);
    if (location == NULL)
    {
        cout << "Item not present in tree" << endl;
        return;
    }

    if (location->count > 1)
    {
        /* more duplicates remain — just decrement */
        location->count--;
        cout << "Duplicate removed. Count for " << item
             << " is now " << location->count << endl;
        return;
    }

    /* count == 1 — remove the node using original case logic */
    if (location->lchild == NULL && location->rchild == NULL)
        case_a(parent, location);
    if (location->lchild != NULL && location->rchild == NULL)
        case_b(parent, location);
    if (location->lchild == NULL && location->rchild != NULL)
        case_b(parent, location);
    if (location->lchild != NULL && location->rchild != NULL)
        case_c(parent, location);

    delete location;
} 

 //FEATURE 2 — Non-recursive traversals (stack-based)
/* Non-recursive Inorder: Left → Root → Right */
void Tree::inorderNR()
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    stack<node *> stk;
    node *ptr = root;

    while (ptr != NULL || !stk.empty())
    {
        /* reach the leftmost node */
        while (ptr != NULL)
        {
            stk.push(ptr);
            ptr = ptr->lchild;
        }
        ptr = stk.top();
        stk.pop();
        cout << ptr->info << " ";
        ptr = ptr->rchild;
    }
}

/* Non-recursive Preorder: Root → Left → Right */
void Tree::preorderNR()
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    stack<node *> stk;
    stk.push(root);

    while (!stk.empty())
    {
        node *ptr = stk.top();
        stk.pop();
        cout << ptr->info << " ";

        /* push right first so left is processed first */
        if (ptr->rchild != NULL)
            stk.push(ptr->rchild);
        if (ptr->lchild != NULL)
            stk.push(ptr->lchild);
    }
} /* End of preorderNR() */

/* Non-recursive Postorder: Left → Right → Root
   Uses two stacks: stack1 drives the traversal,
   stack2 collects nodes in reverse postorder, then we print stack2. */
void Tree::postorderNR()
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    stack<node *> stk1, stk2;
    stk1.push(root);

    while (!stk1.empty())
    {
        node *ptr = stk1.top();
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
} /* End of postorderNR() */

/*==========================================================
 *  FEATURE 3 — Reverse BST  (ReverseBST class)
 *  Left child > node,  Right child < node.
 *  Defined separately so the original Tree is untouched.
 *==========================================================*/
ReverseBST::ReverseBST()
{
    root = NULL;
}

void ReverseBST::insert(int item)
{
    RevNode *tmp = new RevNode();
    tmp->info = item;
    tmp->lchild = NULL;
    tmp->rchild = NULL;

    if (root == NULL)
    {
        root = tmp;
        return;
    }

    RevNode *ptr = root;
    RevNode *parent = NULL;

    while (ptr != NULL)
    {
        if (item == ptr->info)
        {
            cout << "Item already present (Reverse BST)" << endl;
            delete tmp;
            return;
        }
        parent = ptr;
        /* Reverse rule: larger values go LEFT */
        if (item > ptr->info)
            ptr = ptr->lchild;
        else
            ptr = ptr->rchild;
    }

    if (item > parent->info)
        parent->lchild = tmp;
    else
        parent->rchild = tmp;
}

/* Inorder of a Reverse BST prints values in DESCENDING order */
void ReverseBST::inorder(RevNode *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->lchild);
        cout << ptr->info << " ";
        inorder(ptr->rchild);
    }
}

/*==========================================================
 *  FEATURE 4 — Student Record BST
 *  Roll No is the key; name and marks are satellite data.
 *==========================================================*/
void Tree::insertStudent(int rollNo, const string &name, float marks)
{
    node *tmp, *parent, *location;
    find(rollNo, &parent, &location);

    if (location != NULL)
    {
        cout << "Student with Roll No " << rollNo << " already present" << endl;
        return;
    }

    tmp = new node();
    tmp->info = rollNo;
    tmp->count = 1;
    tmp->name = name;
    tmp->marks = marks;
    tmp->lchild = NULL;
    tmp->rchild = NULL;

    if (parent == NULL)
        root = tmp;
    else
    {
        if (rollNo < parent->info)
            parent->lchild = tmp;
        else
            parent->rchild = tmp;
    }
    cout << "Student record inserted successfully." << endl;
} /* End of insertStudent() */

void Tree::searchStudent(int rollNo)
{
    node *ptr = search(root, rollNo);
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
} /* End of searchStudent() */

// *  FEATURE 5 — Terminal (leaf) nodes : display then delete
void Tree::displayLeaves(node *ptr)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL)
    {
        if (ptr->lchild == NULL && ptr->rchild == NULL)
            cout << ptr->info << " ";
        else
        {
            displayLeaves(ptr->lchild);
            displayLeaves(ptr->rchild);
        }
    }
} /* End of displayLeaves() */

/* Recursive helper: returns new subtree root after removing all leaves */
node *Tree::deleteLeavesHelper(node *ptr)
{
    if (ptr == NULL)
        return NULL;
    if (ptr->lchild == NULL && ptr->rchild == NULL)
    {
        delete ptr;
        return NULL;
    }
    ptr->lchild = deleteLeavesHelper(ptr->lchild);
    ptr->rchild = deleteLeavesHelper(ptr->rchild);
    return ptr;
}

void Tree::deleteLeaves()
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    root = deleteLeavesHelper(root);
    cout << "All leaf nodes deleted." << endl;
} /* End of deleteLeaves() */

/*==========================================================
 *  FEATURE 6 — Inorder Successor & Predecessor
 *==========================================================*/
void Tree::findSuccessorPredecessor(int item)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }

    node *ptr = root;
    node *successor = NULL;
    node *predecessor = NULL;

    /* --- find the node while tracking successor / predecessor --- */
    while (ptr != NULL)
    {
        if (item == ptr->info)
        {
            /* Inorder predecessor: rightmost in left subtree */
            if (ptr->lchild != NULL)
            {
                node *tmp = ptr->lchild;
                while (tmp->rchild != NULL)
                    tmp = tmp->rchild;
                predecessor = tmp;
            }
            /* Inorder successor: leftmost in right subtree */
            if (ptr->rchild != NULL)
            {
                node *tmp = ptr->rchild;
                while (tmp->lchild != NULL)
                    tmp = tmp->lchild;
                successor = tmp;
            }
            break;
        }
        else if (item < ptr->info)
        {
            successor = ptr; /* ptr is a candidate successor */
            ptr = ptr->lchild;
        }
        else
        {
            predecessor = ptr; /* ptr is a candidate predecessor */
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
} /* End of findSuccessorPredecessor() */

/*==========================================================
 *  FEATURE 7 — Nodes at a given level (root = level 1)
 *==========================================================*/
void Tree::nodesAtLevel(node *ptr, int target, int current)
{
    if (ptr == NULL)
        return;
    if (current == target)
    {
        cout << ptr->info << " ";
        return;
    }
    nodesAtLevel(ptr->lchild, target, current + 1);
    nodesAtLevel(ptr->rchild, target, current + 1);
} /* End of nodesAtLevel() */

/*==========================================================
 *  FEATURE 8 — Display all left-child nodes
 *==========================================================*/
void Tree::displayLeftNodes(node *ptr)
{
    if (ptr == NULL)
        return;
    if (ptr->lchild != NULL)
    {
        cout << ptr->lchild->info << " ";
        displayLeftNodes(ptr->lchild);
    }
    displayLeftNodes(ptr->rchild);
} /* End of displayLeftNodes() */

/*==========================================================
 *  FEATURE 9 — Largest value at a given level
 *  Returns INT_MIN if no node exists at that level.
 *==========================================================*/
int Tree::largestAtLevel(node *ptr, int target, int current)
{
    if (ptr == NULL)
        return INT_MIN;
    if (current == target)
        return ptr->info;

    int leftMax = largestAtLevel(ptr->lchild, target, current + 1);
    int rightMax = largestAtLevel(ptr->rchild, target, current + 1);

    if (leftMax > rightMax)
        return leftMax;
    return rightMax;
} /* End of largestAtLevel() */

/*==========================================================
 *  FEATURE 10 — Display all right-child nodes
 *==========================================================*/
void Tree::displayRightNodes(node *ptr)
{
    if (ptr == NULL)
        return;
    if (ptr->rchild != NULL)
    {
        cout << ptr->rchild->info << " ";
        displayRightNodes(ptr->rchild);
    }
    displayRightNodes(ptr->lchild);
} /* End of displayRightNodes() */