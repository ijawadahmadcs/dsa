#include "Tree.h"

void Tree::findNode(int item, TreeNode*& location, TreeNode*& parent) {
    location = root;
    parent   = nullptr;

    while (location != nullptr) {
        if (item == location->data)
            return;                          // found
        parent   = location;
        location = (item < location->data)
                       ? location->left
                       : location->right;
    }
}

void Tree::find(int value) {
    TreeNode* location = nullptr;
    TreeNode* parent   = nullptr;

    findNode(value, location, parent);

    if (location == nullptr && parent == nullptr)
        cout << "Tree is empty.\n";
    else if (location == nullptr)
        cout << "Item " << value << " not found in tree.\n";
    else
        cout << "Item " << value << " found in tree.\n";
}

void Tree::insert(int value) {
    TreeNode* location = nullptr;
    TreeNode* parent   = nullptr;

    findNode(value, location, parent);

    if (location != nullptr) {
        cout << "Item " << value << " already present in tree.\n";
        return;
    }

    TreeNode* tmp = new TreeNode(value);

    if (parent == nullptr) {          // tree was empty
        root = tmp;
    } else if (value < parent->data) {
        parent->left  = tmp;
    } else {
        parent->right = tmp;
    }
}

void Tree::case_a(TreeNode* par, TreeNode* loc) {
    if (par == nullptr) {             // deleting root (only node)
        root = nullptr;
    } else if (loc == par->left) {
        par->left  = nullptr;
    } else {
        par->right = nullptr;
    }
    delete loc;
}

void Tree::case_b(TreeNode* par, TreeNode* loc) {
    TreeNode* child = (loc->left != nullptr) ? loc->left : loc->right;

    if (par == nullptr) {             // deleting root
        root = child;
    } else if (loc == par->left) {
        par->left  = child;
    } else {
        par->right = child;
    }
    delete loc;
}
void Tree::case_c(TreeNode* par, TreeNode* loc) {
    (void)par;
    TreeNode* ptrsave = loc;
    TreeNode* ptr     = loc->right;

    while (ptr->left != nullptr) {
        ptrsave = ptr;
        ptr     = ptr->left;
    }
    loc->data = ptr->data;
    if (ptr->left == nullptr && ptr->right == nullptr)
        case_a(ptrsave, ptr);   // successor is a leaf
    else
        case_b(ptrsave, ptr); // successor has one (right) child
}
void Tree::deletion(int value) {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }
    TreeNode* location = nullptr;
    TreeNode* parent   = nullptr;
    findNode(value, location, parent);
    if (location == nullptr) {
        cout << "Item " << value << " not present in tree.\n";
        return;
    }
    if (location->left != nullptr && location->right != nullptr)
        case_c(parent, location);   // Case 3: two children
    else if (location->left == nullptr && location->right == nullptr)
        case_a(parent, location);  // Case 1 (leaf): no child
    else
        case_b(parent, location);    // Case 2: one child

    cout << "Item " << value << " deleted successfully.\n";
}

void Tree::inorder(TreeNode* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void Tree::preorder(TreeNode* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void Tree::postorder(TreeNode* node) {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}


