#include "Tree.h"
#include <cstdlib>

// Constructor
Tree::Tree() {
    root = NULL;
}

/*----------------------------------------------------------
 * find()
 * Searches for 'item' in BST.
 * Sets *loc  = node containing item  (NULL if not found)
 * Sets *par  = parent of that node   (NULL if item is root)
 *----------------------------------------------------------*/
void Tree::find(int item, node **par, node **loc) {
    node *ptr, *ptrsave;

    if (root == NULL) {  /* tree empty */
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->info) {  /* item is at root */
        *loc = root;
        *par = NULL;
        return;
    }

    /* Initialize ptr and ptrsave */
    if (item < root->info)
        ptr = root->lchild;
    else
        ptr = root->rchild;
    ptrsave = root;

    while (ptr != NULL) {
        if (item == ptr->info) {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item < ptr->info)
            ptr = ptr->lchild;
        else
            ptr = ptr->rchild;
    }  /* End of while */

    *loc = NULL;   /* item not found */
    *par = ptrsave;
}  /* End of find() */

/*----------------------------------------------------------
 * insert()
 *----------------------------------------------------------*/
void Tree::insert(int item) {
    node *tmp, *parent, *location;
    find(item, &parent, &location);
    if (location != NULL) {
        cout << "Item already present" << endl;
        return;
    }

    tmp = (node *)malloc(sizeof(node));
    tmp->info   = item;
    tmp->lchild = NULL;
    tmp->rchild = NULL;

    if (parent == NULL)
        root = tmp;
    else {
        if (item < parent->info)
            parent->lchild = tmp;
        else
            parent->rchild = tmp;
    }
}  /* End of insert() */

/*----------------------------------------------------------
 * deletion()
 *----------------------------------------------------------*/
void Tree::deletion(int item) {
    node *parent, *location;
    if (root == NULL) {
        cout << "Tree empty" << endl;
        return;
    }

    find(item, &parent, &location);
    if (location == NULL) {
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

    free(location);
}  /* End of del() */

/*----------------------------------------------------------
 * case_a(): node to delete is a leaf
 *----------------------------------------------------------*/
void Tree::case_a(node *par, node *loc) {
    if (par == NULL)  /* item to be deleted is root node */
        root = NULL;
    else {
        if (loc == par->lchild)
            par->lchild = NULL;
        else
            par->rchild = NULL;
    }
}  /* End of case_a() */

/*----------------------------------------------------------
 * case_b(): node to delete has one child
 *----------------------------------------------------------*/
void Tree::case_b(node *par, node *loc) {
    node *child;

    /* Initialize child */
    if (loc->lchild != NULL)  /* item to be deleted has lchild */
        child = loc->lchild;
    else                      /* item to be deleted has rchild */
        child = loc->rchild;

    if (par == NULL)  /* Item to be deleted is root node */
        root = child;
    else {
        if (loc == par->lchild)  /* item is lchild of its parent */
            par->lchild = child;
        else                     /* item is rchild of its parent */
            par->rchild = child;
    }
}  /* End of case_b() */

/*----------------------------------------------------------
 * case_c(): node to delete has two children
 * Strategy: replace with inorder successor
 *----------------------------------------------------------*/
void Tree::case_c(node *par, node *loc) {
    node *ptr, *ptrsave, *suc, *parsuc;

    /* Find inorder successor and its parent */
    ptrsave = loc;
    ptr = loc->rchild;
    while (ptr->lchild != NULL) {
        ptrsave = ptr;
        ptr = ptr->lchild;
    }
    suc    = ptr;
    parsuc = ptrsave;

    if (suc->lchild == NULL && suc->rchild == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);

    if (par == NULL)  /* if item to be deleted is root node */
        root = suc;
    else {
        if (loc == par->lchild)
            par->lchild = suc;
        else
            par->rchild = suc;
    }

    suc->lchild = loc->lchild;
    suc->rchild = loc->rchild;
}  /* End of case_c() */

/*----------------------------------------------------------
 * preorder()
 *----------------------------------------------------------*/
void Tree::preorder(node *ptr) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL) {
        cout << ptr->info << " ";
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}  /* End of preorder() */

/*----------------------------------------------------------
 * inorder()
 *----------------------------------------------------------*/
void Tree::inorder(node *ptr) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL) {
        inorder(ptr->lchild);
        cout << ptr->info << " ";
        inorder(ptr->rchild);
    }
}  /* End of inorder() */

/*----------------------------------------------------------
 * postorder()
 *----------------------------------------------------------*/
void Tree::postorder(node *ptr) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL) {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        cout << ptr->info << " ";
    }
}  /* End of postorder() */

/*----------------------------------------------------------
 * search() – recursive search
 * Initially value of ptr will be root.
 *----------------------------------------------------------*/
node* Tree::search(node *ptr, int info) {
    if (ptr != NULL) {
        if (info < ptr->info)
            ptr = search(ptr->lchild, info);
        else if (info > ptr->info)
            ptr = search(ptr->rchild, info);
    }
    return ptr;
}  /* End of search() */