#include "linkedlist.h"

int main() {

    LinkedList stack1, stack2;
    int choice, value, position, stackChoice;

    do {
        cout << "1. Insert at Top"<< endl;
        cout << "2. Insert at End"<< endl;
        cout << "3. Insert at Position"<<endl;
        cout << "4. Delete from Top"<<endl;
        cout << "5. Delete from End "<<endl;
        cout << "6. Delete at Position"<<endl;
        cout << "7. Search "<<endl;
        cout << "8. Reverse "<<endl;
        cout << "9. Count Elements"<<endl;
        cout << "10. Display Stack"<<endl;
        cout << "11. Find Largest"<<endl;
        cout << "12. Find Smallest"<<endl;
        cout << "13. Get Sum"<<endl;
        cout << "14. Get Average"<<endl;
        cout << "15. Split Stack"<<endl;
        cout << "16. Concatenate"<<endl;
        cout << "17. Find Third Largest"<<endl;
        cout << "18. Check if Stack is Empty"<<endl;
        cout << "19. View Top Element"<<endl;
        cout << "20. Display"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter choice"<<endl;
        cin >> choice;

        if (choice >= 1 && choice <= 14 || choice == 17 || choice == 18 || choice == 19) {
            cout << "Select Stack (1 or 2): ";
            cin >> stackChoice;
        }

        LinkedList* selectedStack = nullptr;

        if (stackChoice == 1)
            selectedStack = &stack1;
        else if (stackChoice == 2)
            selectedStack = &stack2;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            selectedStack->insertAtStart(value);
            break;

        case 2:
            selectedStack->insertAtEnd(value);
            break;

        case 3:
            selectedStack->insertAtPosition(value, position);
            break;

        case 4:
            selectedStack->deleteAtStart();
            break;

        case 5:
            selectedStack->deleteFromEnd();
            break;

        case 6:
            selectedStack->deleteAtPosition(position);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            if (selectedStack->search(value))
                cout << "Found!\n";
            else
                cout << "Not Found!\n";
            break;

        case 8:
            selectedStack->reverse();
            break;

        case 9:
            cout << "Total Elements: " << selectedStack->countNodes() << endl;
            break;

        case 10:
            selectedStack->display();
            break;

        case 11:
            cout << "Largest: " << selectedStack->findLargest() << endl;
            break;

        case 12:
            cout << "Smallest: " << selectedStack->findSmallest() << endl;
            break;

        case 13:
            cout << "Sum: " << selectedStack->getSum() << endl;
            break;

        case 14:
            cout << "Average: " << selectedStack->getAverage() << endl;
            break;

        case 15: {
            int targetStack;
            cout << "Split which stack? (1 or 2): ";
            cin >> stackChoice;
            cout << "Enter position to split: ";
            cin >> position;
            cout << "Store second part in which stack? (1 or 2): ";
            cin >> targetStack;

            if (stackChoice == 1 && targetStack == 2)
                stack1.split(position, stack2);
            else if (stackChoice == 2 && targetStack == 1)
                stack2.split(position, stack1);
            else
                cout << "Invalid selection!\n";

            break;
        }

        case 16: {
            int first, second;
            cout << "Concatenate:\n";
            cout << "Enter first stack (1 or 2): ";
            cin >> first;
            cout << "Enter second stack (1 or 2): ";
            cin >> second;

            if (first == 1 && second == 2)
                stack1.concatenate(stack2);
            else if (first == 2 && second == 1)
                stack2.concatenate(stack1);
            else
                cout << "Invalid selection!\n";

            break;
        }

        case 17:
            cout << "Third Largest: " << selectedStack->findThirdLargest() << endl;
            break;

        case 18:
            if (selectedStack->countNodes() == 0)
                cout << "Stack is Empty.\n";
            else
                cout << "Stack is NOT Empty.\n";
            break;

        case 19:
            cout << "Top Element: " << selectedStack->peek() << endl;
            break;

        case 20:
            cout << "Stack1: ";
            stack1.display();
            cout << "Stack2: ";
            stack2.display();
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
