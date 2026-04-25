#include "Tree.h"
#include <climits>

int main() {
    Tree       tree;
    ReverseBST revTree;

    int   choice, value, level;
    string sName;
    float  sMarks;

    while (true) {
        cout << "\n========== Binary Search Tree Menu ==========" << endl;
        cout << "  1. Insert"                                     << endl;
        cout << "  2. Delete"                                     << endl;
        cout << "  3. Inorder Traversal (recursive)"             << endl;
        cout << "  4. Preorder Traversal (recursive)"            << endl;
        cout << "  5. Postorder Traversal (recursive)"           << endl;
        cout << "  6. Quit"                                       << endl;
        cout << "  7. Non-Recursive Traversals"                  << endl;
        cout << "  8. Reverse BST (insert & display)"            << endl;
        cout << "  9. Student Record (insert / search)"          << endl;
        cout << " 10. Terminal Nodes (display & delete)"         << endl;
        cout << " 11. Inorder Successor & Predecessor"           << endl;
        cout << " 12. Nodes at Given Level"                      << endl;
        cout << " 13. Display All Left-Child Nodes"              << endl;
        cout << " 14. Largest Value at Given Level"              << endl;
        cout << " 15. Display All Right-Child Nodes"             << endl;
        cout << " 16. Insert with Duplicate Handling"            << endl;
        cout << " 17. Delete with Duplicate Handling"            << endl;
        cout << "Enter your choice: ";
        cin  >> choice;

        switch (choice) {


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
                cout << "Inorder Traversal: ";
                tree.inorder(tree.root);
                cout << endl;
                break;

            case 4:
                cout << "Preorder Traversal: ";
                tree.preorder(tree.root);
                cout << endl;
                break;

            case 5:
                cout << "Postorder Traversal: ";
                tree.postorder(tree.root);
                cout << endl;
                break;

            case 6:
                cout << "Exiting..." << endl;
                return 0;


            /* --- Feature 2 : Non-recursive traversals --- */
            case 7: {
                int subChoice;
                cout << "  1. Inorder (Non-Recursive)"   << endl;
                cout << "  2. Preorder (Non-Recursive)"  << endl;
                cout << "  3. Postorder (Non-Recursive)" << endl;
                cout << "  Enter sub-choice: ";
                cin  >> subChoice;
                switch (subChoice) {
                    case 1:
                        cout << "Inorder (NR)  : ";
                        tree.inorderNR();
                        cout << endl;
                        break;
                    case 2:
                        cout << "Preorder (NR) : ";
                        tree.preorderNR();
                        cout << endl;
                        break;
                    case 3:
                        cout << "Postorder (NR): ";
                        tree.postorderNR();
                        cout << endl;
                        break;
                    default:
                        cout << "Invalid sub-choice." << endl;
                }
                break;
            }

            /* --- Feature 3 : Reverse BST --- */
            case 8: {
                int subChoice;
                cout << "  1. Insert into Reverse BST" << endl;
                cout << "  2. Display Reverse BST (Inorder = Descending)" << endl;
                cout << "  Enter sub-choice: ";
                cin  >> subChoice;
                if (subChoice == 1) {
                    cout << "Enter value to insert into Reverse BST: ";
                    cin  >> value;
                    revTree.insert(value);
                } else if (subChoice == 2) {
                    cout << "Reverse BST Inorder: ";
                    revTree.inorder(revTree.root);
                    cout << endl;
                } else {
                    cout << "Invalid sub-choice." << endl;
                }
                break;
            }

            /* --- Feature 4 : Student Record BST --- */
            case 9: {
                int subChoice;
                cout << "  1. Insert Student Record" << endl;
                cout << "  2. Search Student by Roll No" << endl;
                cout << "  Enter sub-choice: ";
                cin  >> subChoice;
                if (subChoice == 1) {
                    int rollNo;
                    cout << "Enter Roll No  : ";  cin >> rollNo;
                    cout << "Enter Name     : ";  cin.ignore(); getline(cin, sName);
                    cout << "Enter Marks    : ";  cin >> sMarks;
                    tree.insertStudent(rollNo, sName, sMarks);
                } else if (subChoice == 2) {
                    int rollNo;
                    cout << "Enter Roll No to search: ";
                    cin  >> rollNo;
                    tree.searchStudent(rollNo);
                } else {
                    cout << "Invalid sub-choice." << endl;
                }
                break;
            }

            /* --- Feature 5 : Terminal nodes display & delete --- */
            case 10: {
                int subChoice;
                cout << "  1. Display Leaf Nodes"   << endl;
                cout << "  2. Delete All Leaf Nodes" << endl;
                cout << "  Enter sub-choice: ";
                cin  >> subChoice;
                if (subChoice == 1) {
                    cout << "Leaf Nodes: ";
                    tree.displayLeaves(tree.root);
                    cout << endl;
                } else if (subChoice == 2) {
                    tree.deleteLeaves();
                } else {
                    cout << "Invalid sub-choice." << endl;
                }
                break;
            }

            /* --- Feature 6 : Successor & Predecessor --- */
            case 11:
                cout << "Enter value: ";
                cin  >> value;
                tree.findSuccessorPredecessor(value);
                break;

            /* --- Feature 7 : Nodes at given level --- */
            case 12:
                cout << "Enter level (root = 1): ";
                cin  >> level;
                cout << "Nodes at level " << level << ": ";
                tree.nodesAtLevel(tree.root, level, 1);
                cout << endl;
                break;

            /* --- Feature 8 : Display all left-child nodes --- */
            case 13:
                if (tree.root == NULL) {
                    cout << "Tree is empty" << endl;
                } else {
                    cout << "Left-child nodes: ";
                    tree.displayLeftNodes(tree.root);
                    cout << endl;
                }
                break;

            /* --- Feature 9 : Largest at given level --- */
            case 14: {
                cout << "Enter level (root = 1): ";
                cin  >> level;
                int result = tree.largestAtLevel(tree.root, level, 1);
                if (result == INT_MIN)
                    cout << "No nodes exist at level " << level << endl;
                else
                    cout << "Largest value at level " << level << ": " << result << endl;
                break;
            }

            /* --- Feature 10 : Display all right-child nodes --- */
            case 15:
                if (tree.root == NULL) {
                    cout << "Tree is empty" << endl;
                } else {
                    cout << "Right-child nodes: ";
                    tree.displayRightNodes(tree.root);
                    cout << endl;
                }
                break;

            /* --- Feature 1a : Insert with duplicate handling --- */
            case 16:
                cout << "Enter value to insert (duplicate-aware): ";
                cin  >> value;
                tree.insertDup(value);
                break;

            /* --- Feature 1b : Delete with duplicate handling --- */
            case 17:
                cout << "Enter value to delete (duplicate-aware): ";
                cin  >> value;
                tree.deletionDup(value);
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}