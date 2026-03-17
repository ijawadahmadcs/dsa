#include "linkedlist.h"

int main() {

    LinkedList list1, list2;
    int choice, value, position, listChoice;

    do {
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Search Element\n";
        cout << "8. Reverse List\n";
        cout << "9. Count Nodes\n";
        cout << "10. Display List\n";
        cout << "11. Find Largest\n";
        cout << "12. Find Smallest\n";
        cout << "13. Get Sum\n";
        cout << "14. Get Average\n";
        cout << "15. Split List\n";
        cout << "16. Concatenate Lists\n";
        cout << "17. Find Third Largest\n";
        cout << "18. Check if List is Empty\n";
        cout << "20. Copy List\n";
        cout << "21. Display Both Lists\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 14 || choice == 17 || choice == 18 || choice == 20) {
            cout << "Select List (1 or 2): ";
            cin >> listChoice;
        }

        LinkedList* selectedList = nullptr;

        if (listChoice == 1)
            selectedList = &list1;
        else if (listChoice == 2)
            selectedList = &list2;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            selectedList->insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            selectedList->insertAtEnd(value);
            break;

        case 3:
            cout << "Enter value and position: ";
            cin >> value >> position;
            selectedList->insertAtPosition(value, position);
            break;

        case 4:
            selectedList->deleteAtBeginning();
            break;

        case 5:
            selectedList->deleteFromEnd();
            break;

        case 6:
            cout << "Enter position: ";
            cin >> position;
            selectedList->deleteAtPosition(position);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            if (selectedList->search(value))
                cout << "Found!\n";
            else
                cout << "Not Found!\n";
            break;

        case 8:
            selectedList->reverse();
            cout << "List reversed.\n";
            break;

        case 9:
            cout << "Total Nodes: " << selectedList->countNodes() << endl;
            break;

        case 10:
            selectedList->display();
            break;

        case 11:
            cout << "Largest: " << selectedList->findLargest() << endl;
            break;

        case 12:
            cout << "Smallest: " << selectedList->findSmallest() << endl;
            break;

        case 13:
            cout << "Sum: " << selectedList->getSum() << endl;
            break;

        case 14:
            cout << "Average: " << selectedList->getAverage() << endl;
            break;

        case 15: {
            int targetList;
            cout << "Split which list? (1 or 2): ";
            cin >> listChoice;
            cout << "Enter position to split: ";
            cin >> position;
            cout << "Store second part in which list? (1 or 2): ";
            cin >> targetList;

            if (listChoice == 1 && targetList == 2)
                list1.split(position, list2);
            else if (listChoice == 2 && targetList == 1)
                list2.split(position, list1);
            else
                cout << "Invalid selection!\n";

            break;
        }

        case 16: {
            int first, second;
            cout << "Concatenate:\n";
            cout << "Enter first list (1 or 2): ";
            cin >> first;
            cout << "Enter second list (1 or 2): ";
            cin >> second;

            if (first == 1 && second == 2)
                list1.concatenate(list2);
            else if (first == 2 && second == 1)
                list2.concatenate(list1);
            else
                cout << "Invalid selection!\n";

            break;
        }

        case 17:
            cout << "Third Largest: " << selectedList->findThirdLargest() << endl;
            break;

        case 18:
            if (selectedList->countNodes() == 0)
                cout << "List is Empty.\n";
            else
                cout << "List is NOT Empty.\n";
            break;

        case 19: {
            int source, destination;
            cout << "Copy from which list? (1 or 2): ";
            cin >> source;
            cout << "Copy to which list? (1 or 2): ";
            cin >> destination;

            if (source == 1 && destination == 2)
                list2 = list1;
            else if (source == 2 && destination == 1)
                list1 = list2;
            else
                cout << "Invalid selection!\n";

            break;
        }

        case 20:
            cout << "List1: ";
            list1.display();
            cout << "List2: ";
            list2.display();
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}