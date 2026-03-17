#include "linkedlist.h"

int main() {

    LinkedList deque1, deque2;
    int choice, value, position, dequeChoice;

    do {
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at Rear" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Delete from Front" << endl;
        cout << "5. Delete from Rear" << endl;
        cout << "6. Delete at Position" << endl;
        cout << "7. Search" << endl;
        cout << "8. Reverse" << endl;
        cout << "9. Count Elements" << endl;
        cout << "10. Display Deque" << endl;
        cout << "11. Find Largest" << endl;
        cout << "12. Find Smallest" << endl;
        cout << "13. Get Sum" << endl;
        cout << "14. Get Average" << endl;
        cout << "15. Split Deque" << endl;
        cout << "16. Concatenate" << endl;
        cout << "17. Find Third Largest" << endl;
        cout << "18. Check if Deque is Empty" << endl;
        cout << "19. View Front Element" << endl;
        cout << "20. View Rear Element" << endl;
        cout << "21. Display Both Deques" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice" << endl;
        cin >> choice;

        if (choice >= 1 && choice <= 14 || choice == 17 || choice == 18 || choice == 19 || choice == 20) {
            cout << "Select Deque (1 or 2): ";
            cin >> dequeChoice;
        }

        LinkedList* selectedDeque = nullptr;

        if (dequeChoice == 1)
            selectedDeque = &deque1;
        else if (dequeChoice == 2)
            selectedDeque = &deque2;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            selectedDeque->insertAtStart(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            selectedDeque->insertAtEnd(value);
            break;

        case 3:
            selectedDeque->insertAtPosition(value, position);
            break;

        case 4:
            selectedDeque->deleteAtStart();
            break;

        case 5:
            selectedDeque->deleteFromEnd();
            break;

        case 6:
            selectedDeque->deleteAtPosition(position);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            if (selectedDeque->search(value))
                cout << "Found!\n";
            else
                cout << "Not Found!\n";
            break;

        case 8:
            selectedDeque->reverse();
            break;

        case 9:
            cout << "Total Elements: " << selectedDeque->countNodes() << endl;
            break;

        case 10:
            selectedDeque->display();
            break;

        case 11:
            cout << "Largest: " << selectedDeque->findLargest() << endl;
            break;

        case 12:
            cout << "Smallest: " << selectedDeque->findSmallest() << endl;
            break;

        case 13:
            cout << "Sum: " << selectedDeque->getSum() << endl;
            break;

        case 14:
            cout << "Average: " << selectedDeque->getAverage() << endl;
            break;

        case 15: {
            int targetDeque;
            cout << "Split which deque? (1 or 2): ";
            cin >> dequeChoice;
            cout << "Enter position to split: ";
            cin >> position;
            cout << "Store second part in which deque? (1 or 2): ";
            cin >> targetDeque;

            if (dequeChoice == 1 && targetDeque == 2)
                deque1.split(position, deque2);
            else if (dequeChoice == 2 && targetDeque == 1)
                deque2.split(position, deque1);
            else
                cout << "Invalid selection!\n";

            break;
        }

        case 16: {
            int first, second;
            cout << "Concatenate:\n";
            cout << "Enter first deque (1 or 2): ";
            cin >> first;
            cout << "Enter second deque (1 or 2): ";
            cin >> second;

            if (first == 1 && second == 2)
                deque1.concatenate(deque2);
            else if (first == 2 && second == 1)
                deque2.concatenate(deque1);
            else
                cout << "Invalid selection!\n";

            break;
        }

        case 17:
            cout << "Third Largest: " << selectedDeque->findThirdLargest() << endl;
            break;

        case 18:
            if (selectedDeque->countNodes() == 0)
                cout << "Deque is Empty.\n";
            else
                cout << "Deque is NOT Empty.\n";
            break;

        case 19:
            cout << "Front Element: " << selectedDeque->peekFront() << endl;
            break;

        case 20:
            cout << "Rear Element: " << selectedDeque->peekRear() << endl;
            break;

        case 21:
            cout << "Deque1: ";
            deque1.display();
            cout << "Deque2: ";
            deque2.display();
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
