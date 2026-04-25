#include "Tree.h"

int main() {
    Tree tree;
    int choice, value;

    while (true) {
        cout << "1. Insert:" << endl;
        cout << "2. Delete:" << endl;
        cout << "3. Inorder Traversal:" << endl;
        cout << "4. Preorder Traversal:" << endl;
        cout << "5. Postorder Traversal:" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
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
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}