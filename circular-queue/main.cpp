#include "linkedlist.h"

int main() {

    LinkedList queue1, queue2;
    int choice, value, position, queueChoice;

    do {
        cout << "1. Enqueue (Insert at Rear)" << endl;
        cout << "2. Insert at Front" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Dequeue (Delete from Front)" << endl;
        cout << "5. Delete from Rear" << endl;
        cout << "6. Delete at Position" << endl;
        cout << "7. Search" << endl;
        cout << "8. Reverse" << endl;
        cout << "9. Count Elements" << endl;
        cout << "10. Display Queue" << endl;
        cout << "11. Find Largest" << endl;
        cout << "12. Find Smallest" << endl;
        cout << "13. Get Sum" << endl;
        cout << "14. Get Average" << endl;
        cout << "15. Split Queue" << endl;
        cout << "16. Concatenate" << endl;
        cout << "17. Find Third Largest" << endl;
        cout << "18. Check if Queue is Empty" << endl;
        cout << "19. View Front Element" << endl;
        cout << "20. Display Both Queues" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice" << endl;
        cin >> choice;

        if (choice >= 1 && choice <= 14 || choice == 17 || choice == 18 || choice == 19) {
            cout << "Select Queue (1 or 2): ";
            cin >> queueChoice;
        }

        LinkedList* selectedQueue = nullptr;

        if (queueChoice == 1)
            selectedQueue = &queue1;
        else if (queueChoice == 2)
            selectedQueue = &queue2;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            selectedQueue->enqueue(value);
            break;

        case 2:
            selectedQueue->insertAtStart(value);
            break;

        case 3:
            selectedQueue->insertAtPosition(value, position);
            break;

        case 4:
            selectedQueue->dequeue();
            break;

        case 5:
            selectedQueue->deleteFromEnd();
            break;

        case 6:
            selectedQueue->deleteAtPosition(position);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            if (selectedQueue->search(value))
                cout << "Found!\n";
            else
                cout << "Not Found!\n";
            break;

        case 8:
            selectedQueue->reverse();
            break;

        case 9:
            cout << "Total Elements: " << selectedQueue->countNodes() << endl;
            break;

        case 10:
            selectedQueue->display();
            break;

        case 11:
            cout << "Largest: " << selectedQueue->findLargest() << endl;
            break;

        case 12:
            cout << "Smallest: " << selectedQueue->findSmallest() << endl;
            break;

        case 13:
            cout << "Sum: " << selectedQueue->getSum() << endl;
            break;

        case 14:
            cout << "Average: " << selectedQueue->getAverage() << endl;
            break;

        case 15: {
            int targetQueue;
            cout << "Split which queue? (1 or 2): ";
            cin >> queueChoice;
            cout << "Enter position to split: ";
            cin >> position;
            cout << "Store second part in which queue? (1 or 2): ";
            cin >> targetQueue;

            if (queueChoice == 1 && targetQueue == 2)
                queue1.split(position, queue2);
            else if (queueChoice == 2 && targetQueue == 1)
                queue2.split(position, queue1);
            else
                cout << "Invalid selection!\n";

            break;
        }

        case 16: {
            int first, second;
            cout << "Concatenate:\n";
            cout << "Enter first queue (1 or 2): ";
            cin >> first;
            cout << "Enter second queue (1 or 2): ";
            cin >> second;

            if (first == 1 && second == 2)
                queue1.concatenate(queue2);
            else if (first == 2 && second == 1)
                queue2.concatenate(queue1);
            else
                cout << "Invalid selection!\n";

            break;
        }

        case 17:
            cout << "Third Largest: " << selectedQueue->findThirdLargest() << endl;
            break;

        case 18:
            if (selectedQueue->countNodes() == 0)
                cout << "Circular Queue is Empty.\n";
            else
                cout << "Circular Queue is NOT Empty.\n";
            break;

        case 19:
            cout << "Front Element: " << selectedQueue->peek() << endl;
            break;

        case 20:
            cout << "Queue1: ";
            queue1.display();
            cout << "Queue2: ";
            queue2.display();
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
