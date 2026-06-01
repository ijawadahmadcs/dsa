#include<iostream>
#include "heap.h"

node *start = NULL;

int main()
{
    int choice, item;

    do
    {
        cout << "===== HEAP MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Sort (Ascending)\n";
        cout << "5. Display Left Nodes\n";
        cout << "6. Display Right Nodes\n";
        cout << "7. Check Node Type\n";
        cout << "8. Find Predecessor & Successor\n";
        cout << "9. Count Nodes\n";
        cout << "10. Largest & Smallest Node\n";
        cout << "11. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter item: ";
                cin >> item;
                insert(item);
                break;

            case 2:
                cout << "Enter item to delete: ";
                cin >> item;
                del(item);
                break;

            case 3:
                display();
                break;

            case 4:
                sort();
                break;

            case 5:
                displayLeft();
                break;

            case 6:
                displayRight();
                break;

            case 7:
                cout << "Enter item: ";
                cin >> item;
                checkNodeType(item);
                break;

            case 8:
                cout << "Enter item: ";
                cin >> item;
                findNeighbor(item);
                break;

            case 9:
                cout << "Number of nodes: " << countNodes() << endl;
                break;

            case 10:
                findLargestAndSmallest();
                break;

            case 11:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 0);

    return 0;
}