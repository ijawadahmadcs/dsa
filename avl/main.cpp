#include "AVL.h"

int main() {
    AVLTree    tree;
    ReverseAVL revTree;

    int   choice, value, level;
    string sName;
    float  sMarks;

    while (true) {
        cout << "  1.  Insert"                          << endl;
        cout << "  2.  Delete"                          << endl;
        cout << "  3.  Inorder Traversal (recursive)"   << endl;
        cout << "  4.  Preorder Traversal (recursive)"  << endl;
        cout << "  5.  Postorder Traversal (recursive)" << endl;
        cout << "  6.  Quit"                            << endl;
        cout << "  7.  Non-Recursive Traversals (Q2)"   << endl;
        cout << "  8.  Reverse AVL - insert & display (Q3)" << endl;
        cout << "  9.  Student Record - insert/search (Q4)" << endl;
        cout << " 10.  Leaf Nodes - display & delete (Q5)"  << endl;
        cout << " 11.  Inorder Successor & Predecessor (Q6)" << endl;
        cout << " 12.  Nodes at Given Level (Q7)"        << endl;
        cout << " 13.  Display All Left-Child Nodes (Q8)" << endl;
        cout << " 14.  Largest Value at Given Level (Q9)" << endl;
        cout << " 15.  Display All Right-Child Nodes (Q10)" << endl;
        cout << " 16.  Insert with Duplicate Handling (Q1)" << endl;
        cout << " 17.  Delete with Duplicate Handling (Q1)" << endl;
        cout << " 18.  Show balance factors"  << endl;   
        cout << " 19.  Non Recursive Traversal Root->Right->Left " << endl; 
        cout << " 20.  Non RecursiveTraversal Right->Root->Left" <<endl;
        cout << " 21.  Check Node Type (leaf / one child / two child)" << endl;
        cout << "Enter your choice: ";
        cin  >> choice;

        switch (choice) {

            // ── CORE OPERATIONS ──────────────────────────
            case 1:
                cout << "Enter value to insert: ";
                cin  >> value;
                tree.insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin  >> value;
                tree.deletion(value);
                break;

            case 3:
                cout << "Inorder (recursive): ";
                tree.inorder(tree.root);
                cout << endl;
                break;

            case 4:
                cout << "Preorder (recursive): ";
                tree.preorder(tree.root);
                cout << endl;
                break;

            case 5:
                cout << "Postorder (recursive): ";
                tree.postorder(tree.root);
                cout << endl;
                break;

            case 6:
                cout << "Exiting..." << endl;
                return 0;

            // ── Q2: Non-recursive traversals ─────────────
            case 7: {
                int sub;
                cout << "  1. Inorder (NR)   2. Preorder (NR)   3. Postorder (NR)" << endl;
                cout << "  Sub-choice: ";
                cin  >> sub;
                if (sub == 1) {
                    cout << "Inorder (NR)  : ";
                    tree.inorderNR();
                    cout << endl;
                } else if (sub == 2) {
                    cout << "Preorder (NR) : ";
                    tree.preorderNR();
                    cout << endl;
                } else if (sub == 3) {
                    cout << "Postorder (NR): ";
                    tree.postorderNR();
                    cout << endl;
                } else {
                    cout << "Invalid sub-choice." << endl;
                }
                break;
            }

            // ── Q3: Reverse AVL ───────────────────────────
            case 8: {
                int sub;
                cout << "  1. Insert into Reverse AVL   2. Display (Inorder = Descending)" << endl;
                cout << "  Sub-choice: ";
                cin  >> sub;
                if (sub == 1) {
                    cout << "Enter value: ";
                    cin  >> value;
                    revTree.insert(value);
                } else if (sub == 2) {
                    cout << "Reverse AVL Inorder: ";
                    revTree.inorder(revTree.root);
                    cout << endl;
                } else {
                    cout << "Invalid sub-choice." << endl;
                }
                break;
            }

            // ── Q4: Student records ───────────────────────
            case 9: {
                int sub;
                cout << "  1. Insert Student Record   2. Search by Roll No" << endl;
                cout << "  Sub-choice: ";
                cin  >> sub;
                if (sub == 1) {
                    int rollNo;
                    cout << "Roll No : "; cin >> rollNo;
                    cout << "Name    : "; cin.ignore(); getline(cin, sName);
                    cout << "Marks   : "; cin >> sMarks;
                    tree.insertStudent(rollNo, sName, sMarks);
                } else if (sub == 2) {
                    int rollNo;
                    cout << "Roll No to search: ";
                    cin  >> rollNo;
                    tree.searchStudent(rollNo);
                } else {
                    cout << "Invalid sub-choice." << endl;
                }
                break;
            }

            // ── Q5: Leaf nodes ────────────────────────────
            case 10: {
                int sub;
                cout << "  1. Display Leaf Nodes   2. Delete All Leaf Nodes" << endl;
                cout << "  Sub-choice: ";
                cin  >> sub;
                if (sub == 1) {
                    cout << "Leaf Nodes: ";
                    tree.displayLeaves(tree.root);
                    cout << endl;
                } else if (sub == 2) {
                    tree.deleteLeaves();
                } else {
                    cout << "Invalid sub-choice." << endl;
                }
                break;
            }

            // ── Q6: Successor & Predecessor ───────────────
            case 11:
                cout << "Enter value: ";
                cin  >> value;
                tree.findSuccessorPredecessor(value);
                break;

            // ── Q7: Nodes at level ────────────────────────
            case 12:
                cout << "Enter level (root = 1): ";
                cin  >> level;
                cout << "Nodes at level " << level << ": ";
                tree.nodesAtLevel(tree.root, level, 1);
                cout << endl;
                break;

            // ── Q8: Left-child nodes ──────────────────────
            case 13:
                if (tree.root == NULL) {
                    cout << "Tree is empty" << endl;
                } else {
                    cout << "Left-child nodes: ";
                    tree.displayLeftNodes(tree.root);
                    cout << endl;
                }
                break;

            // ── Q9: Largest at level ──────────────────────
            case 14: {
                cout << "Enter level (root = 1): ";
                cin  >> level;
                int result = tree.largestAtLevel(tree.root, level, 1);
                if (result == INT_MIN)
                    cout << "No nodes at level " << level << endl;
                else
                    cout << "Largest value at level " << level << ": " << result << endl;
                break;
            }

            // ── Q10: Right-child nodes ────────────────────
            case 15:
                if (tree.root == NULL) {
                    cout << "Tree is empty" << endl;
                } else {
                    cout << "Right-child nodes: ";
                    tree.displayRightNodes(tree.root);
                    cout << endl;
                }
                break;

            // ── Q1: Duplicate-aware insert ────────────────
            case 16:
                cout << "Enter value to insert (duplicate-aware): ";
                cin  >> value;
                tree.insertDup(value);
                break;

            // ── Q1: Duplicate-aware delete ────────────────
            case 17:
                cout << "Enter value to delete (duplicate-aware): ";
                cin  >> value;
                tree.deletionDup(value);
                break;
            
            case 18: {
                cout << "Enter value to check balance factor: ";
                cin >> value;
                AVLNode *node = tree.searchNode(tree.root, value);
                if (node == NULL) {
                    cout << "Node not present" << endl;
                } else {
                    cout << "Balance factor of " << value << " is "
                         << tree.balanceFactor(node) << endl;
                }
                break;
            }

            case 19:
                cout << "Root->Right->Left traversal: ";
                tree.preorderRRL();
                cout << endl;
                break;

            case 20:
                cout << "Right->Root->Left traversal: ";
                tree.rightRootLeftNR();
                cout << endl;
                break;

            case 21:
                cout << "Enter value to check node type: ";
                cin >> value;
                tree.displayNodeType(value);
                break;
            
            

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
